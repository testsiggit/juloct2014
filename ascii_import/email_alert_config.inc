<?php
function get_email_alert_conditions() {
    $query = db_select('ea_condition', 'c');
    $query->fields('c');
    $result = $query->execute()->fetchAll();    
    return $result;
}

function check_alert($alert_name) {
    global $user;
    $query = db_select('ea_user_alerts', 'ua');
    $query->condition('ua.uid', $user->uid, '=');
    $query->condition('ua.alert_name', $alert_name, '=');
    $query->fields('ua');
    $result = $query->execute()->fetch();
    return $result;    
}

function check_alert_config($alert_id,$condition_id,$additional_notes='') {    
    $query = db_select('ea_alert_config', 'ac');
    $query->condition('ac.alert_id', $alert_id, '=');
    $query->condition('ac.condition_id', $condition_id, '=');
    if($additional_notes!=''){
        $query->condition('ac.additional_notes', $additional_notes, '=');
    }
    $query->fields('ac');
    $result = $query->execute()->fetch();
    return $result;    
}

function add_email_alert($alert_name, $alert_description,$status) {
    global $user;
    $alert_id = db_insert('ea_user_alerts')
            ->fields(array(
                'uid' => $user->uid,
                'alert_name' => $alert_name,
                'alert_description' => $alert_description,
                'status' => $status
            ))
            ->execute();
    return $alert_id;
}

function update_email_alert($alert_name, $alert_description,$status,$alert_id) {    
    $al_updated = db_update('ea_user_alerts')
            ->fields(array(                
                'alert_name' => $alert_name,
                'alert_description' => $alert_description,
                'status' => $status
            ))->condition('alert_id', $alert_id , '=')
            ->execute();
    return $al_updated;
}

function add_user_alert_conditions($data) {
    $id = db_insert('ea_alert_config')->fields(array('alert_id' => $data['alert_id'], 'condition_id' => $data['condition_id'],
                'condition_value' => $data['condition_value'], 'additional_notes' => $data['additional_notes']))
            ->execute();
    return $id;
}

function update_user_alert_conditions($data) {     
    try{
        $upd_query = db_update('ea_alert_config')->fields(array('condition_value' => $data['condition_value']));
        $upd_query->condition('alert_id', $data['alert_id'] , '=');
        $upd_query->condition('condition_id', $data['condition_id'] , '=');
        if($data['additional_notes']!=''){
            $upd_query->condition('additional_notes', $data['additional_notes'] , '=');
        }
        $upd_query->execute();
        //print_r($upd_query->__toString()); echo '\n-------------\n'; print_r($upd_query->arguments()); 
        return $upd_query;
    }catch(Exception $e){
        error_log( date('Y-m-d H:i').' : '.$e->getMessage().PHP_EOL , 3 , drupal_get_path('module','ascii_import')."/logs/eac_errors.log");
    }
}

function eac_list_add() {        
    global $user;

    if (isset($_POST['submit'])) {
        //print_r($_POST); exit;

        $alert_name = trim($_POST['alert_name']);
        $alert_description = trim($_POST['alert_description']);
        $play = trim($_POST['play']);
        $status_of_app_flag = trim($_POST['status_of_app_flag']);
        $field_application_well_code = trim($_POST['field_application_well_code']);
        $county_code = trim($_POST['county_code']);        
        $operator_name = trim($_POST['operator_name']);
        $permit_total_depth_MIN = trim($_POST['permit_total_depth_MIN']);
        $permit_total_depth_MAX = trim($_POST['permit_total_depth_MAX']);
        $wp_code = trim($_POST['wp_code']);
        $status = (isset($_POST['status'])) ? $_POST['status'] : 0;

        $err = 0;
        if ($alert_name == '') {
            drupal_set_message(t('Please enter alert name.'), 'error');
            $err++;
        }

        $checkalert = check_alert($alert_name);
        if($checkalert){
            drupal_set_message(t('Entered alert name is already exists. Please add different alert name.'), 'error');
            $err++;
        }

        if ($play=='' && $status_of_app_flag == '' && $field_application_well_code == '' && $county_code == '' && $operator_name == '' && $permit_total_depth_MIN == '' && $permit_total_depth_MAX == '' && $wp_code == '') {
            drupal_set_message(t('Please select/enter atleast one configuration.'), 'error');
            $err++;
        }

        if ($err == 0) {

            $conditions = get_email_alert_conditions();

            $cids = array();
            foreach ($conditions as $cond) {
                $cids[$cond->condition_id] = $cond->form_field;
            }

            $alert_id = add_email_alert($alert_name, $alert_description,$status);

            if ($alert_id) {

                if ($play != '') {
                    $condition_id = array_search('play', $cids);
                    $input_data = array('alert_id' => $alert_id, 'condition_id' => $condition_id,
                        'condition_value' => $play, 'additional_notes' => '');
                    add_user_alert_conditions($input_data);
                }
                if ($status_of_app_flag != '') {
                    $condition_id = array_search('status_of_app_flag', $cids);
                    $input_data = array('alert_id' => $alert_id, 'condition_id' => $condition_id,
                        'condition_value' => $status_of_app_flag, 'additional_notes' => '');
                    add_user_alert_conditions($input_data);
                }
                if ($field_application_well_code != '') {
                    $condition_id = array_search('field_application_well_code', $cids);
                    $input_data = array('alert_id' => $alert_id, 'condition_id' => $condition_id,
                        'condition_value' => $field_application_well_code, 'additional_notes' => '');
                    add_user_alert_conditions($input_data);
                }
                if ($county_code != '') {
                    $condition_id = array_search('county_code', $cids);
                    $input_data = array('alert_id' => $alert_id, 'condition_id' => $condition_id,
                        'condition_value' => $county_code, 'additional_notes' => '');
                    add_user_alert_conditions($input_data);
                }
                if ($operator_name != '') {
                    $condition_id = array_search('operator_name', $cids);
                    $input_data = array('alert_id' => $alert_id, 'condition_id' => $condition_id,
                        'condition_value' => $operator_name, 'additional_notes' => '');
                    add_user_alert_conditions($input_data);
                }
                if ($permit_total_depth_MIN != '') {
                    $condition_id = array_search('permit_total_depth', $cids);
                    $input_data = array('alert_id' => $alert_id, 'condition_id' => $condition_id,
                        'condition_value' => $permit_total_depth_MIN, 'additional_notes' => 'MIN');
                    add_user_alert_conditions($input_data);
                }
                if ($permit_total_depth_MAX != '') {
                    $condition_id = array_search('permit_total_depth', $cids);
                    $input_data = array('alert_id' => $alert_id, 'condition_id' => $condition_id,
                        'condition_value' => $permit_total_depth_MAX, 'additional_notes' => 'MAX');
                    add_user_alert_conditions($input_data);
                }
                if ($wp_code != '') {
                    $condition_id = array_search('wp_code', $cids);
                    $input_data = array('alert_id' => $alert_id, 'condition_id' => $condition_id,
                        'condition_value' => $wp_code, 'additional_notes' => '');
                    add_user_alert_conditions($input_data);
                }
            }

            //drupal_goto('email_alert_config');
            drupal_set_message(t('Email alert configuration is saved.'));
        }
    }

    try{
        $query = db_select('ea_user_alerts', 'ua');
        //$query->join("ea_alert_config", "ac", "ua.alert_id = ac.alert_id");
        $query->fields('ua');
        $query->condition('ua.uid', $user->uid, '=');
        $query->orderBy('ua.alert_id', 'DESC');
        $result = $query->execute();
        $no_of_rows = $result->rowCount();
    }catch(Exception $e){
        echo $e->getMessage();
    }

//print_r($no_of_rows);

    $app_status = get_app_status();    
    $welltypes = get_well_types();    
    $counties = get_counties();    
    $wellbore_profiles = get_wellbore_profiles();    
    $play_list = get_plays();   
    $reports = array('result' => $result, 'no_of_rows' => $no_of_rows,
        'app_status' => $app_status, 'welltypes' => $welltypes, 'counties' => $counties, 'wellbore_profiles' => $wellbore_profiles , 'play_list' => $play_list);
    return theme('eaclistadd', $reports);
}
 
function eac_edit($alert_id) {
    if(user_is_logged_in()){
        
        global $user;
        
        $query = db_select('ea_user_alerts', 'ua');
        $query->condition('ua.alert_id', $alert_id, '=')->condition('ua.uid', $user->uid, '=');        
        $query->fields('ua',array('alert_name'));        
        $query->range(0, 1);        
        $al_res = $query->execute();         
        $res = $al_res->fetch();        
        
        if( isset($res->alert_name) && $res->alert_name!=''){

            if (isset($_POST['submit'])) {
                //print_r($_POST); exit;
                $alert_id = $_POST['alert_id'];
                $alert_name = trim($_POST['alert_name']);
                $alert_description = trim($_POST['alert_description']);

                $play = trim($_POST['play']);
                $status_of_app_flag = trim($_POST['status_of_app_flag']);
                $field_application_well_code = trim($_POST['field_application_well_code']);
                $county_code = trim($_POST['county_code']);        
                $operator_name = trim($_POST['operator_name']);
                $permit_total_depth_MIN = trim($_POST['permit_total_depth_MIN']);
                $permit_total_depth_MAX = trim($_POST['permit_total_depth_MAX']);
                $wp_code = trim($_POST['wp_code']);
                $status = (isset($_POST['status'])) ? $_POST['status'] : 0;

                $err = 0;
                if ($alert_name == '') {
                    drupal_set_message(t('Please enter alert name.'), 'error');
                    $err++;
                }
                if ($play == '' && $status_of_app_flag == '' && $field_application_well_code == '' && $county_code == '' && $operator_name == '' && $permit_total_depth_MIN == '' && $permit_total_depth_MAX == '' && $wp_code == '') {
                    drupal_set_message(t('Please select/enter atleast one configuration.'), 'error');
                    $err++;
                }

                if ($err == 0) {

                    $conditions = get_email_alert_conditions();

                    $cids = array();
                    foreach ($conditions as $cond) {
                        $cids[$cond->condition_id] = $cond->form_field;
                    }
                    //print_r($cids); exit;
                    update_email_alert($alert_name, $alert_description,$status,$alert_id);

                    if ($alert_id) {

                        // Play
                        $play_condition_id = array_search('play', $cids);
                        $play_check = check_alert_config($alert_id,$play_condition_id);
                        if($play_check){
                            $upd_data = array('alert_id' => $alert_id, 'condition_id' => $play_condition_id,
                                'condition_value' => $play, 'additional_notes' => '');
                            update_user_alert_conditions($upd_data);
                        }else{                        
                            $input_data = array('alert_id' => $alert_id, 'condition_id' => $play_condition_id,
                            'condition_value' => $play, 'additional_notes' => '');
                            add_user_alert_conditions($input_data);
                        }

                        // Status                
                        $status_condition_id = array_search('status_of_app_flag', $cids);
                        $status_check = check_alert_config($alert_id,$status_condition_id);
                        if($status_check){
                            $upd_data = array('alert_id' => $alert_id, 'condition_id' => $status_condition_id,
                                'condition_value' => $status_of_app_flag, 'additional_notes' => '');
                            update_user_alert_conditions($upd_data);
                        }else{                        
                            $input_data = array('alert_id' => $alert_id, 'condition_id' => $status_condition_id,
                            'condition_value' => $status_of_app_flag, 'additional_notes' => '');
                            add_user_alert_conditions($input_data);
                        }

                        // Well Code                                 
                        $wc_condition_id = array_search('field_application_well_code', $cids);    
                        $wc_check = check_alert_config($alert_id,$wc_condition_id);
                        if($wc_check){
                            $upd_data = array('alert_id' => $alert_id, 'condition_id' => $wc_condition_id,
                                'condition_value' => $field_application_well_code, 'additional_notes' => '');
                            update_user_alert_conditions($upd_data);
                        }else{                        
                            $input_data = array('alert_id' => $alert_id, 'condition_id' => $wc_condition_id,
                            'condition_value' => $field_application_well_code, 'additional_notes' => '');
                            add_user_alert_conditions($input_data);
                        }


                        // County Code
                        $county_condition_id = array_search('county_code', $cids);
                        $county_check = check_alert_config($alert_id,$county_condition_id);
                        if($county_check){
                            $upd_data = array('alert_id' => $alert_id, 'condition_id' => $county_condition_id,
                                'condition_value' => $county_code, 'additional_notes' => '');
                            update_user_alert_conditions($upd_data);
                        }else{                        
                            $input_data = array('alert_id' => $alert_id, 'condition_id' => $county_condition_id,
                            'condition_value' => $county_code, 'additional_notes' => '');
                            add_user_alert_conditions($input_data);
                        }

                        //Operator
                        $op_condition_id = array_search('operator_name', $cids);
                        $op_check_status = check_alert_config($alert_id,$op_condition_id);
                        if($op_check_status){
                            $upd_data = array('alert_id' => $alert_id, 'condition_id' => $op_condition_id,
                                'condition_value' => $operator_name, 'additional_notes' => '');
                            update_user_alert_conditions($upd_data);
                        }else{                        
                            $input_data = array('alert_id' => $alert_id, 'condition_id' => $op_condition_id,
                            'condition_value' => $operator_name, 'additional_notes' => '');
                            add_user_alert_conditions($input_data);
                        }

                        // depth min
                        $ptmin_condition_id = array_search('permit_total_depth', $cids);
                        $ptmin_check = check_alert_config($alert_id,$ptmin_condition_id,'MIN');
                        if($ptmin_check){
                            $upd_data = array('alert_id' => $alert_id, 'condition_id' => $ptmin_condition_id,
                                'condition_value' => $permit_total_depth_MIN, 'additional_notes' => 'MIN');
                            update_user_alert_conditions($upd_data);
                        }else{                        
                            $input_data = array('alert_id' => $alert_id, 'condition_id' => $ptmin_condition_id,
                            'condition_value' => $permit_total_depth_MIN, 'additional_notes' => 'MIN');
                            add_user_alert_conditions($input_data);
                        }

                        // depth max
                        $ptmax_condition_id = array_search('permit_total_depth', $cids);
                        $ptmax_check = check_alert_config($alert_id,$ptmax_condition_id,'MAX');
                        if($ptmax_check){
                            $upd_data = array('alert_id' => $alert_id, 'condition_id' => $ptmax_condition_id,
                                'condition_value' => $permit_total_depth_MAX, 'additional_notes' => 'MAX');
                            update_user_alert_conditions($upd_data);
                        }else{                        
                            $input_data = array('alert_id' => $alert_id, 'condition_id' => $ptmax_condition_id,
                            'condition_value' => $permit_total_depth_MAX, 'additional_notes' => 'MAX');
                            add_user_alert_conditions($input_data);
                        }

                        // wpcode
                        $wp_condition_id = array_search('wp_code', $cids);
                        $wp_check = check_alert_config($alert_id,$wp_condition_id);
                        if($wp_check){
                            $upd_data = array('alert_id' => $alert_id, 'condition_id' => $wp_condition_id,
                                'condition_value' => $wp_code, 'additional_notes' => '');
                            update_user_alert_conditions($upd_data);
                        }else{                        
                            $input_data = array('alert_id' => $alert_id, 'condition_id' => $wp_condition_id,
                            'condition_value' => $wp_code, 'additional_notes' => '');
                            add_user_alert_conditions($input_data);
                        }

                    }

                    drupal_set_message(t('Email alert configuration is updated.'));
                    drupal_goto('email-alert-config');            
                }
            }    


            $query = db_select('ea_user_alerts', 'ua');
            $query->join("ea_alert_config", "ac", "ua.alert_id = ac.alert_id");
            $query->join("ea_condition", "c", "ac.condition_id = c.condition_id");
            $query->fields('ua')->fields('ac')->fields('c');
            $query->condition('ua.uid', $user->uid, '=');
            $query->condition('ua.alert_id', $alert_id, '=');
            //print_r($query->__toString()); echo '\n'; print_r($query->arguments()); exit;
            $result = $query->execute()->fetchAll();   

            $editdata = array();

            $conditions = get_email_alert_conditions();
            foreach($conditions as $cond){
                $editdata[$cond->form_field] = '';
            }

            if($result){
                $editdata['alert_id'] = $result[0]->alert_id;
                $editdata['alert_name'] = $result[0]->alert_name;
                $editdata['alert_description'] = $result[0]->alert_description;
                $editdata['status'] = $result[0]->status;

                foreach($result as $row){
                    if(array_key_exists($row->form_field, $editdata)){
                        if($row->additional_notes!=''){
                            $editdata[$row->form_field.'_'.$row->additional_notes] = $row;
                        }else{
                            $editdata[$row->form_field] = $row;
                        }
                    }
                }

            }

            //print_r($editdata); exit;

            $app_status = get_app_status();
            $welltypes = get_well_types();
            $counties = get_counties();
            $wellbore_profiles = get_wellbore_profiles();
            $play_list = get_plays();   
            $reports = array('editdata' => $editdata, 'app_status' => $app_status, 'welltypes' => $welltypes, 'counties' => $counties, 
                        'wellbore_profiles' => $wellbore_profiles, 'play_list' => $play_list);
            return theme('eacedit', $reports);
        
        }else{            
            drupal_set_message('You are not authorized to edit the alert.','error');
            drupal_goto('email-alert-config');
        }
        
    }else{
        drupal_goto('email-alert-config');
        /*$options = array('query' => drupal_get_destination());
        drupal_set_message('You have to login.','error');
        drupal_goto('user', $options);*/
    }
}

function eac_delete($alert_id) {
    if(user_is_logged_in()){        
        global $user;
        
        $query = db_select('ea_user_alerts', 'ua');
        $query->condition('ua.alert_id', $alert_id, '=')->condition('ua.uid', $user->uid, '=');        
        $query->fields('ua',array('alert_name'));        
        $query->range(0, 1);        
        $al_res = $query->execute();         
        $res = $al_res->fetch();        
        
        if( isset($res->alert_name) && $res->alert_name!=''){
            $acdeleted = db_delete('ea_alert_config')->condition('alert_id', $alert_id)->execute();
            $uadeleted = db_delete('ea_user_alerts')->condition('alert_id', $alert_id)->execute();
            drupal_set_message(t('Email alert configuration is deleted.'));
            drupal_goto('email-alert-config');
        }else{            
            drupal_set_message(t('You are not authorized to delete the alert.'),'error');
            drupal_goto('email-alert-config');
        }        
    }else{
        drupal_goto('email-alert-config');
        /*$options = array('query' => drupal_get_destination());
        drupal_set_message(t('You have to login.'),'error');
        drupal_goto('user', $options);*/
    }
}
