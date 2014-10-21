<?php
function addPlay($playName) {    
    $play_id = db_insert('oa_play')
            ->fields(array(
                'play_name' => $playName
            ))
            ->execute();
    return $play_id;    
}

function getPlayByName($playName) {
    $query = db_select('oa_play', 'p');
    $query->condition('p.play_name', $playName, '=');
    $query->fields('p');
    $result = $query->execute()->fetch();
    return $result;
}

function company_data_columns() {
    $col_fields = array('company_name' => '', 'ticker' => 'Ticker', 'exchange' => 'Exchange', 'next_report' => 'Next report',
        'website_text' => 'Website', 'updated_on' => 'Updated',
        'production' => 'Production', 'acreage' => 'Acreage', 'reserves' => 'Reserves',
        'wells_drilled' => 'Wells Drilled', 'other_comments' => 'Other');
    return $col_fields;
}

function addCompany($data,$worksheetTitle,$row,$file_id) {
    try {
        $company_id = db_insert('oa_company')
                ->fields(array(
                    'company_name' => $data['company_name'], 'ticker' => $data['ticker'], 'exchange' => $data['exchange'],
                    'website_text' => $data['website_text'], 'website_url' => $data['website_url'], 'updated_on' => $data['updated_on'],
                    'production' => $data['production'], 'acreage' => $data['acreage'], 'reserves' => $data['reserves'],
                    'wells_drilled' => $data['wells_drilled'], 'other_comments' => $data['other_comments'],
                    'latest_presentation_text' => $data['latest_presentation_text'], 'latest_presentaion_url' => $data['latest_presentaion_url']
                ))
                ->execute();
        return $company_id;
    } catch (Exception $e) {
        $logMsg = 'Sheet:'.$worksheetTitle.';Row:'.$row.';Data:'.implode(',',$data).PHP_EOL;
        //error_log( date('Y-m-d H:i').' : '.$e->getMessage().$logMsg , 3 , drupal_get_path('module','hart_excelread')."/logs/errors.log");
        error_log( date('Y-m-d H:i').' : '.$e->getMessage().$logMsg , 3 , file_directory_temp().'/hart_excelread_errors.log');
        $logData = array('fid' => $file_id,'sheet_title' => $worksheetTitle,'sheet_column' => '','sheet_row' => $row, 'message' => 'INVALID DATA :-'.$e->getMessage() );
        addLogData($logData);        
    }
}


function updateCompany($data,$company_id,$worksheetTitle,$row,$file_id) {
    try {
        $comp_updated = db_update('oa_company')
                ->fields(array(
                    'company_name' => $data['company_name'], 'ticker' => $data['ticker'], 'exchange' => $data['exchange'],
                    'website_text' => $data['website_text'], 'website_url' => $data['website_url'], 'updated_on' => $data['updated_on'],
                    'production' => $data['production'], 'acreage' => $data['acreage'], 'reserves' => $data['reserves'],
                    'wells_drilled' => $data['wells_drilled'], 'other_comments' => $data['other_comments'],
                    'latest_presentation_text' => $data['latest_presentation_text'], 'latest_presentaion_url' => $data['latest_presentaion_url']
                ))->condition('company_id', $company_id, '=')
                ->execute();
        return $comp_updated;
        
    } catch (Exception $e) {
        $logMsg = 'Sheet:'.$worksheetTitle.';Row:'.$row.';Data:'.implode(',',$data).PHP_EOL;
        //error_log( date('Y-m-d H:i').' : '.$e->getMessage().$logMsg , 3 , drupal_get_path('module','hart_excelread')."/logs/errors.log");
        error_log( date('Y-m-d H:i').' : '.$e->getMessage().$logMsg , 3 , file_directory_temp().'/hart_excelread_errors.log');
        $logData = array('fid' => $file_id,'sheet_title' => $worksheetTitle,'sheet_column' => '','sheet_row' => $row, 'message' => 'INVALID DATA :- '.$e->getMessage() );
        addLogData($logData); 
    }
}

// Company / Operator
function getCompanyByName($companyName) {
    $query = db_select('oa_company', 'c');
    $query->condition('c.company_name', $companyName, '=');
    $query->fields('c');
    $query->range(0, 1);
    $result = $query->execute()->fetch();
    return $result;
}

function addCompanyAnnualReport($data, $company_id) {
    try {
        $annual_report_id = db_insert('oa_company_annual_report')
                ->fields(array(
                    'company_id' => $company_id, 'year' => $data['year'], 'report_url' => $data['report_url']
                ))
                ->execute();
        return $annual_report_id;
    } catch (Exception $e) {
        echo 'Line:'.__LINE__.',Message:'. $e->getMessage() .'<br/>';
    }
}

function getCompanyAnnualReport($company_id,$year) {
    $query = db_select('oa_company_annual_report');
    $query->condition('company_id', $company_id, '=');
    $query->condition('year', $year, '=');
    $query->fields('oa_company_annual_report');
    $result = $query->execute()->fetch();
    return $result;
}

function updateCompanyAnnualReport($data, $company_id) {
    try {
        $car_updated = db_update('oa_company_annual_report')
                ->fields(array(
                    'company_id' => $company_id, 'year' => $data['year'], 'report_url' => $data['report_url']
                ))->condition('company_id', $company_id, '=')
                ->execute();
        return $car_updated;
    } catch (Exception $e) {
        echo 'Line:'.__LINE__.',Message:'. $e->getMessage() .'<br/>';
    }
}

function addCompanyQuarterReport($data, $company_id) {
    try {
        $quarter_report_id = db_insert('oa_company_quarter_report')
                ->fields(array(
                    'company_id' => $company_id, 'quarter_code' => $data['quarter_code'], 'year' => $data['year'],
                    'quarter_report_url' => $data['quarter_report_url'],'presentation_text'=>$data['presentation_text'],
                    'presentation_url' => $data['presentation_url']
                ))
                ->execute();
        return $quarter_report_id;
    } catch (Exception $e) {
        echo 'Line:'.__LINE__.',Message:'. $e->getMessage() .'<br/>';
    }
}


function getCompanyQuarterReport($company_id,$year,$quarter_code) {
    $query = db_select('oa_company_quarter_report');
    $query->condition('company_id', $company_id, '=');
    $query->condition('year', $year, '=');
    $query->condition('quarter_code', $quarter_code, '=');
    $query->fields('oa_company_quarter_report');
    $result = $query->execute()->fetch();
    return $result;
}

function updateCompanyQuarterReport($data, $company_id,$year,$quarter_code) {
    try {
        $cqr_updated = db_update('oa_company_quarter_report')
                ->fields(array(                    
                    'quarter_report_url' => $data['quarter_report_url'],'presentation_text'=>$data['presentation_text'],
                    'presentation_url' => $data['presentation_url']
                ))->condition('company_id', $company_id, '=')->condition('quarter_code', $quarter_code, '=')
                ->condition('year', $year, '=')
                ->execute();
        return $cqr_updated;
    } catch (Exception $e) {
        echo 'Line:'.__LINE__.',Message:'. $e->getMessage() .'<br/>';
    }
}


function addCompanyAnnualCapex($data, $company_id) {
    try {
        $ca_capex_id = db_insert('oa_company_annual_capex')
                ->fields(array(
                    'company_id' => $company_id, 'year' => $data['year'], 'capex' => $data['capex'],'estimated' => $data['estimated']
                ))
                ->execute();
        return $ca_capex_id;
    } catch (Exception $e) {
        echo 'Line:'.__LINE__.',Message:'. $e->getMessage() .'<br/>';
    }
}

function getCompanyAnnualCapex($company_id,$year) {
    $query = db_select('oa_company_annual_capex');
    $query->condition('company_id', $company_id, '=');
    $query->condition('year', $year, '=');    
    $query->fields('oa_company_annual_capex');
    $result = $query->execute()->fetch();
    return $result;
}

function updateCompanyAnnualCapex($data, $company_id,$year) {
    try {
        $cac_updated = db_update('oa_company_annual_capex')
                ->fields(array(
                    'company_id' => $company_id, 'year' => $data['year'], 'capex' => $data['capex'],'estimated' => $data['estimated']
                ))->condition('company_id', $company_id, '=')->condition('year', $year, '=')
                ->execute();
        return $cac_updated;
    } catch (Exception $e) {
        echo 'Line:'.__LINE__.',Message:'. $e->getMessage() .'<br/>';
    }
}


function addCompanyAnnualEbidax($data, $company_id) {
    try {
        $ca_ebidax_id = db_insert('oa_company_annual_ebidax')
                ->fields(array(
                    'company_id' => $company_id, 'year' => $data['year'], 'ebidax' => $data['ebidax'],'estimated' => $data['estimated']
                ))
                ->execute();
        return $ca_ebidax_id;
    } catch (Exception $e) {
        echo 'Line:'.__LINE__.',Message:'. $e->getMessage() .'<br/>';
    }
}


function getCompanyAnnualEbidax($company_id,$year) {
    $query = db_select('oa_company_annual_ebidax');
    $query->condition('company_id', $company_id, '=');
    $query->condition('year', $year, '=');    
    $query->fields('oa_company_annual_ebidax');
    $result = $query->execute()->fetch();
    return $result;
}

function updateCompanyAnnualEbidax($data, $company_id, $year) {
    try {
        $cae_updated = db_update('oa_company_annual_ebidax')
                ->fields(array(
                    'ebidax' => $data['ebidax'],'estimated' => $data['estimated']
                ))->condition('company_id', $company_id, '=')->condition('year', $year, '=')
                ->execute();
        return $cae_updated;
    } catch (Exception $e) {
        echo 'Line:'.__LINE__.',Message:'. $e->getMessage() .'<br/>';
    }
}




function company_play_data_columns(){
    $col_fields = array( 'location' => 'Location St/Cos' , 'project_field' => 'Project/Field', 'entered_play' => 'Entered Play', 'depth' => 'Depth', 
        'acres_gross_net' => 'Acres Gross/Net', 'jvs'=> 'JVs', 'well_cost'=> 'Well Cost','most_recent_quarter' => '',
        'number_of_rigs'=> '# Rigs','well_spacing'=> 'Well Spacing', 'inventory'=> 'Inventory','completions'=> 'Completions',        
        'ip'=> 'IP', 'eur'=> 'EUR','total_prod_wells'=> 'Total Prod Wells','reserves'=> 'Reserves','resource_potential'=> 'Resource Potential',
        'comment'=> 'COMMENTS'
    );
    return $col_fields;
}

function addCompanyPlay($company_id,$play_id) {
    $company_play_id = db_insert('oa_company_play')
            ->fields(array(
                'company_id' => $company_id,
                'play_id' => $play_id
            ))
            ->execute();
    return $company_play_id;
}

function getCompanyPlayId($company_id,$play_id) {
    $query = db_select('oa_company_play', 'cp');    
    $query->condition('cp.company_id', $company_id, '=');
    $query->condition('cp.play_id', $play_id, '=');
    $query->fields('cp');
    $query->range(0, 1);
    $result = $query->execute()->fetch();
    return $result;
}

function addCompanyPlayDetails($data,$company_play_id,$worksheetTitle,$row,$file_id) {
    try {        
        $cpd_id = db_insert('oa_company_play_details')
                ->fields(array(
                    'company_play_id'=> $company_play_id,
                    'location' => $data['location'] , 'project_field' => $data['project_field'], 'entered_play' => $data['entered_play'], 'depth' => $data['depth'], 
                        'acres_gross_net' => $data['acres_gross_net'], 'jvs'=> $data['jvs'], 'well_cost'=> $data['well_cost'],'most_recent_quarter' => $data['most_recent_quarter'],
                        'number_of_rigs'=> $data['number_of_rigs'],'well_spacing'=> $data['well_spacing'], 'inventory'=> $data['inventory'],'completions'=> $data['completions'],        
                        'ip'=> $data['ip'], 'eur'=> $data['eur'],'total_prod_wells'=> $data['total_prod_wells'],'reserves'=> $data['reserves'],'resource_potential'=> $data['resource_potential'],
                        'comment'=> $data['comment']
                ))
                ->execute();
        return $cpd_id;        
    } catch (Exception $e) {             
        $logMsg = 'Sheet:'.$worksheetTitle.';Row:'.$row.';Data:'.implode(',',$data).PHP_EOL;
        //error_log( date('Y-m-d H:i').' : '.$e->getMessage().$logMsg , 3 , drupal_get_path('module','hart_excelread')."/logs/errors.log");   
        error_log( date('Y-m-d H:i').' : '.$e->getMessage().$logMsg , 3 , file_directory_temp().'/hart_excelread_errors.log');   
        $logData = array('fid' => $file_id,'sheet_title' => $worksheetTitle,'sheet_column' => '','sheet_row' => $row, 'message' => 'INVALID DATA :-'.$e->getMessage() );
        addLogData($logData); 
    }
}

function addCompanyPlayAnnualCapex($data, $company_play_id, $cpd_id) {    
    try {
        $cpa_capex_id = db_insert('oa_company_play_annual_capex')
                ->fields(array(
                    'company_play_id' => $company_play_id, 'cpd_id' =>$cpd_id , 'year' => $data['year'], 'capex' => $data['capex'],'estimated' => $data['estimated']
                ))
                ->execute();
        return $cpa_capex_id;
    } catch (Exception $e) {
        echo 'Line:'.__LINE__.',Message:'. $e->getMessage() .'<br/>';
    }
}

function addCompanyPlayAnnualWells($data, $company_play_id, $cpd_id) {
    try {
        $cpa_wells_id = db_insert('oa_company_play_annual_wells')
                ->fields(array(
                    'company_play_id' => $company_play_id, 'cpd_id' =>$cpd_id , 'year' => $data['year'], 'well' => $data['well'],'estimated' => $data['estimated']
                ))
                ->execute();
        return $cpa_wells_id;
    } catch (Exception $e) {
        echo 'Line:'.__LINE__.',Message:'. $e->getMessage() .'<br/>';
    }
}

function addCompanyPlayAnnualProduction($data, $company_play_id, $cpd_id) {
    try {
        $cpa_production_id = db_insert('oa_company_play_annual_production')
                ->fields(array(
                    'company_play_id' => $company_play_id , 'cpd_id' =>$cpd_id , 'year' => $data['year'], 'production' => $data['production'],'estimated' => $data['estimated']
                ))
                ->execute();
        return $cpa_production_id;
    } catch (Exception $e) {
        echo 'Line:'.__LINE__.',Message:'. $e->getMessage() .'<br/>';
    }
}


// Company / Operator Exists or not
function getCompanyPlayDetails($companyName,$playName,$location,$projectField) {
    $query = db_select('oa_company_play_details', 'cpd');
    $query->join('oa_company_play', 'cp', 'cpd.company_play_id = cp.company_play_id');
    $query->join('oa_company', 'c', 'cp.company_id = c.company_id');
    $query->join('oa_play', 'p', 'cp.play_id = p.play_id');
    $query->condition('c.company_name', $companyName, '=');
    $query->condition('p.play_name', $playName, '=');
    $query->condition('cpd.location', $location, '=');
    $query->condition('cpd.project_field', $projectField, '=');
    $query->fields('cpd');
    $query->range(0, 1);
    $result = $query->execute()->fetch();
    return $result;
}


function updateCompanyPlayDetails($data,$cpd_id,$worksheetTitle,$row,$file_id) {
    try {
        $cpd_updated = db_update('oa_company_play_details')
                ->fields(array(                    
                        'entered_play' => $data['entered_play'], 'depth' => $data['depth'], 
                        'acres_gross_net' => $data['acres_gross_net'], 'jvs'=> $data['jvs'], 'well_cost'=> $data['well_cost'],'most_recent_quarter' => $data['most_recent_quarter'],
                        'number_of_rigs'=> $data['number_of_rigs'],'well_spacing'=> $data['well_spacing'], 'inventory'=> $data['inventory'],'completions'=> $data['completions'],        
                        'ip'=> $data['ip'], 'eur'=> $data['eur'],'total_prod_wells'=> $data['total_prod_wells'],'reserves'=> $data['reserves'],'resource_potential'=> $data['resource_potential'],
                        'comment'=> $data['comment']
                ))->condition('cpd_id', $cpd_id, '=')
                ->execute();
        return $cpd_updated;        
    } catch (Exception $e) {     
        $logMsg = 'Sheet:'.$worksheetTitle.';Row:'.$row.';Data:'.implode(',',$data).PHP_EOL;
        //error_log( date('Y-m-d H:i').' : UPDATE '.$e->getMessage().$logMsg , 3 , drupal_get_path('module','hart_excelread')."/logs/errors.log");  
        error_log( date('Y-m-d H:i').' : UPDATE '.$e->getMessage().$logMsg , 3 , file_directory_temp().'/hart_excelread_errors.log');  
        $logData = array('fid' => $file_id,'sheet_title' => $worksheetTitle,'sheet_column' => '','sheet_row' => $row, 'message' => 'INVALID DATA :- '.$e->getMessage() );
        addLogData($logData);
    }
}


function getCompanyPlayAnnualCapex($company_play_id, $cpd_id,$year) {   
    $query = db_select('oa_company_play_annual_capex','cpac');
    $query->condition('cpac.company_play_id', $company_play_id, '=');
    $query->condition('cpac.cpd_id', $cpd_id, '=');
    $query->condition('cpac.year', $year, '=');
    $query->fields('cpac');
    $query->range(0, 1);
    $result = $query->execute()->fetch();
    return $result;
}


function updateCompanyPlayAnnualCapex($data, $cpa_capex_id) {    
    try {
        $cpa_capex_updated = db_update('oa_company_play_annual_capex')
                ->fields(array(
                    'capex' => $data['capex'],'estimated' => $data['estimated']
                ))->condition('cpa_capex_id', $cpa_capex_id, '=')
                ->execute();
        return $cpa_capex_updated;
    } catch (Exception $e) {
        echo 'Line:'.__LINE__.',Message:'. $e->getMessage() .'<br/>';
    }
}

function getCompanyPlayAnnualWells($company_play_id, $cpd_id,$year) {   
    $query = db_select('oa_company_play_annual_wells','cpaw');
    $query->condition('cpaw.company_play_id', $company_play_id, '=');
    $query->condition('cpaw.cpd_id', $cpd_id, '=');
    $query->condition('cpaw.year', $year, '=');
    $query->fields('cpaw');
    $query->range(0, 1);
    $result = $query->execute()->fetch();
    return $result;
}

function updateCompanyPlayAnnualWells($data, $cpa_wells_id) {    
    try {
        $cpa_capex_updated = db_update('oa_company_play_annual_wells')
                ->fields(array(
                    'well' => $data['well'],'estimated' => $data['estimated']
                ))->condition('cpa_wells_id', $cpa_wells_id, '=')
                ->execute();
        return $cpa_capex_updated;
    } catch (Exception $e) {
        echo 'Line:'.__LINE__.',Message:'. $e->getMessage() .'<br/>';
    }
}

function getCompanyPlayAnnualProduction($company_play_id, $cpd_id,$year) {   
    $query = db_select('oa_company_play_annual_production','cpap');
    $query->condition('cpap.company_play_id', $company_play_id, '=');
    $query->condition('cpap.cpd_id', $cpd_id, '=');
    $query->condition('cpap.year', $year, '=');
    $query->fields('cpap');
    $query->range(0, 1);
    $result = $query->execute()->fetch();
    return $result;
}

function updateCompanyPlayAnnualProduction($data, $cpa_production_id) {    
    try {
        $cpa_capex_updated = db_update('oa_company_play_annual_production')
                ->fields(array(
                    'production' => $data['production'],'estimated' => $data['estimated']
                ))->condition('cpa_production_id', $cpa_production_id, '=')
                ->execute();
        return $cpa_capex_updated;
    } catch (Exception $e) {
        echo 'Line:'.__LINE__.',Message:'. $e->getMessage() .'<br/>';
    }
}

function addLogData($data) {
    $id ='';
    try{
        $id = db_insert('oa_log_table')
            ->fields(array(
                'fid' => $data['fid'],
                'sheet_title' => $data['sheet_title'],
                'sheet_column' => $data['sheet_column'],
                'sheet_row' => $data['sheet_row'],
                'message' => $data['message']
            ))
            ->execute();
    } catch (Exception $e){        
        //error_log( date('Y-m-d H:i').' : '.$e->getMessage().PHP_EOL , 3 , drupal_get_path('module','hart_excelread')."/logs/logtableerr.log");
        error_log( date('Y-m-d H:i').' : '.$e->getMessage().PHP_EOL , 3 , file_directory_temp().'/hart_excelread_logtableerr.log');
    }
    return $id;
}

function add_processing_fileinfo($fileName,$mod_time,$processtime){
    $fid = db_insert('oa_processed_files')->fields(array('filename' => $fileName, 'modtime'=>$mod_time , 'processtime'=> $processtime ))->execute();    
    return $fid;
}

function update_processing_fileinfo($file_id){
    db_update('oa_processed_files')->fields(array('process_end_time' => date('Y-m-d H:i:s') ))->condition('fid', $file_id , '=')->execute();        
}


// Edit/Add Begins *************************************************************************/
function getCompanyById($company_id) {
    $query = db_select('oa_company', 'c');
    $query->condition('c.company_id', $company_id, '=');
    $query->fields('c');
    $query->range(0, 1);
    $result = $query->execute()->fetch();
    return $result;
}

function edit_company_form($form, &$form_state, $company_id) {
    $company = getCompanyById($company_id);
    $form['company_name'] = array(
        '#type' => 'textfield',
        '#title' => t('Company Name'),        
        '#value' => $company->company_name,
        '#attributes' => array('disabled' => TRUE)
    );
    $form['ticker'] = array(
        '#type' => 'textarea',
        '#title' => t('Ticker'),        
        '#value' => $company->ticker
    );
    $form['exchange'] = array(
        '#type' => 'textfield',
        '#title' => t('Exchange'),        
        '#value' => $company->exchange
    );
    $form['production'] = array(
        '#type' => 'textarea',
        '#title' => t('Production'),        
        '#value' => $company->production
    );
    $form['acreage'] = array(
        '#type' => 'textarea',
        '#title' => t('Acreage'),        
        '#value' => $company->acreage
    );
    $form['reserves'] = array(
        '#type' => 'textarea',
        '#title' => t('Reserves'),        
        '#value' => $company->reserves
    );
    $form['wells_drilled'] = array(
        '#type' => 'textarea',
        '#title' => t('Wells Drilled'),        
        '#value' => $company->wells_drilled
    );
    $form['other_comments'] = array(
        '#type' => 'textarea',
        '#title' => t('Other Comments'),        
        '#value' => $company->other_comments
    );
    $form['website_url'] = array(
        '#type' => 'textfield',
        '#title' => t('Website Url'),        
        '#value' => $company->website_url
    );
//    $form['updated_on'] = array(
//        '#type' => 'date_select',
//        '#title' => t('Updated On'),
//        '#default_value' => $company->updated_on,
//        '#date_format' => 'm\d\Y',
//        '#date_label_position' => 'within',                        
//        '#date_year_range' => '-3:+3',
//        '#datepicker_options' => array(),
//    );
    
    $form['updated_on'] = array(
        '#title' => t('Updated On'),
        '#type' => 'date_popup',
        '#default_value' => $company->updated_on,
        '#date_type' => DATE_DATETIME,        
        '#date_format' => 'm/d/Y',
        '#date_label_position' => 'within',
        '#date_increment' => 1,
        '#date_year_range' => '-5',
    );
    
    $form['company_id'] = array(
        '#type' => 'hidden',
        '#value' => $company_id
    );
    $form['submit'] = array(
        '#type' => 'submit',
        '#value' => t('Update')
    );
//    $form['cancel'] = array(
//        '#type' => 'button',
//        '#value' => t('Cancel'),
//        '#prefix' => '&nbsp; &nbsp; &nbsp;',
//        '#attributes' => array('onClick' => 'history.go(-1); return true;'),
//        '#post_render' => array('change_button_type'),
//    );
    return $form;
}

function change_button_type($markup, $element) {
    $markup = str_replace('type="submit', 'type="button', $markup);
    return $markup;
}

function edit_company_form_submit($form, &$form_state) {    
    $company_id = $form_state['values']['company_id'];
    //$company_name = $form_state['input']['company_name'];  
    $ticker = $form_state['input']['ticker'];  
    $exchange = $form_state['input']['exchange'];  
    $production = $form_state['input']['production'];  
    $acreage = $form_state['input']['acreage'];  
    $reserves = $form_state['input']['reserves'];  
    $wells_drilled = $form_state['input']['wells_drilled'];  
    $other_comments = $form_state['input']['other_comments'];  
    $website_url = $form_state['input']['website_url'];  
    $updated_on = $form_state['input']['updated_on']['date'];      
    $updated_on = (trim($updated_on)!='') ? date('Y-m-d',strtotime($updated_on)) : NULL;   
    
    $comp_updated = db_update('oa_company')
            ->fields(array(
                'ticker' => $ticker, 'exchange' => $exchange,
                'website_url' => $website_url, 'updated_on' => $updated_on,
                'production' => $production, 'acreage' => $acreage, 'reserves' => $reserves,
                'wells_drilled' => $wells_drilled, 'other_comments' => $other_comments                    
            ))->condition('company_id', $company_id, '=')
            ->execute();
    
    drupal_set_message(t('Company details updated.'));
}


function add_company_form($form, &$form_state) {   
    $form['company_name'] = array(
        '#type' => 'textfield',
        '#title' => t('Company Name'),                
    );
    $form['ticker'] = array(
        '#type' => 'textarea',
        '#title' => t('Ticker'),                
    );
    $form['exchange'] = array(
        '#type' => 'textfield',
        '#title' => t('Exchange'),                
    );
    $form['production'] = array(
        '#type' => 'textarea',
        '#title' => t('Production'),    
    );
    $form['acreage'] = array(
        '#type' => 'textarea',
        '#title' => t('Acreage'),                
    );
    $form['reserves'] = array(
        '#type' => 'textarea',
        '#title' => t('Reserves'),                
    );
    $form['wells_drilled'] = array(
        '#type' => 'textarea',
        '#title' => t('Wells Drilled'),                
    );
    $form['other_comments'] = array(
        '#type' => 'textarea',
        '#title' => t('Other Comments'),                
    );
    $form['website_url'] = array(
        '#type' => 'textfield',
        '#title' => t('Website Url'),                
    );
//    $form['updated_on'] = array(
//        '#type' => 'textfield',
//        '#title' => t('Updated On'),                
//    );   
    $form['updated_on'] = array(
        '#type' => 'date_popup',
        '#title' => t('Updated On'),        
        '#date_type' => DATE_DATETIME,        
        '#date_format' => 'm/d/Y',
        '#date_label_position' => 'within',
        '#date_increment' => 1,
        '#date_year_range' => '-5',
    );
    $form['submit'] = array(
        '#type' => 'submit',
        '#value' => t('Submit')
    );
//    $form['cancel'] = array(
//        '#type' => 'button',
//        '#value' => t('Cancel'),
//        '#prefix' => '&nbsp; &nbsp; &nbsp;',
//        '#attributes' => array('onClick' => 'history.go(-1); return true;'),
//        '#post_render' => array('change_button_type'),
//    );
    return $form;
}

function add_company_form_validate($form, &$form_state) {      
    $company_name = $form_state['input']['company_name']; 
    if(trim($company_name)==''){
        form_set_error('company_name',t('Please enter company name.'));
    }        
    $compCheck=getCompanyByName($company_name);
    if($compCheck){
        form_set_error('company_name',t('Company name already exists.'));
    }    
}

function add_company_form_submit($form, &$form_state) {          
    $company_name = $form_state['input']['company_name'];  
    $ticker = $form_state['input']['ticker'];  
    $exchange = $form_state['input']['exchange'];  
    $production = $form_state['input']['production'];  
    $acreage = $form_state['input']['acreage'];  
    $reserves = $form_state['input']['reserves'];  
    $wells_drilled = $form_state['input']['wells_drilled'];  
    $other_comments = $form_state['input']['other_comments'];  
    $website_url = $form_state['input']['website_url'];  
    $updated_on = $form_state['input']['updated_on']['date'];
    $updated_on = (trim($updated_on)!='') ? date('Y-m-d',strtotime($updated_on)) : NULL;
    
    $company_id = db_insert('oa_company')
            ->fields(array(
                'company_name' => $company_name, 'ticker' => $ticker, 'exchange' => $exchange,
                'website_text' => 'Website',
                'website_url' => $website_url, 'updated_on' => $updated_on,
                'production' => $production, 'acreage' => $acreage, 'reserves' => $reserves,
                'wells_drilled' => $wells_drilled, 'other_comments' => $other_comments                    
            ))->execute();
    
    drupal_set_message(t('Company details added.'));
}


function add_play_form($form, &$form_state) {    
    $form['play_name'] = array(
        '#type' => 'textfield',
        '#title' => t('Play Name'),                
    );       
    $form['submit'] = array(
        '#type' => 'submit',
        '#value' => t('Submit')
    );
//    $form['cancel'] = array(
//        '#type' => 'button',
//        '#value' => t('Cancel'),
//        '#prefix' => '&nbsp; &nbsp; &nbsp;',
//        '#attributes' => array('onClick' => 'history.go(-1); return true;'),
//        '#post_render' => array('change_button_type'),
//    );
    return $form;
}

function add_play_form_validate($form, &$form_state) {      
    $play_name = $form_state['input']['play_name']; 
    if(trim($play_name)==''){
        form_set_error('play',t('Please enter play name.'));
    }        
    $playCheck=getPlayByName($play_name);
    if($playCheck){
        form_set_error('play',t('Play name already exists.'));
    }    
}

function add_play_form_submit($form, &$form_state) {          
    $play_name = $form_state['input']['play_name'];      
    
    $play_id = db_insert('oa_play')
            ->fields(array(
                'play_name' => $play_name                  
            ))->execute();
    
    drupal_set_message(t('Play details added.'));
}

function add_region_form($form, &$form_state) { 
    $companies = get_companies();
    $compArr = array();
    foreach ($companies as $comp){
        $compArr[$comp->company_id] = $comp->company_name;
    }
    $plays = get_op_plays();
    $playArr = array();
    foreach ($plays as $play){
        $playArr[$play->play_id] = $play->play_name;
    }
    $form['company_id'] = array(
       '#type' => 'select',
       '#title' => t('Company'),
       '#options' => $compArr
   );
    
    $form['play_id'] = array(
       '#type' => 'select',
       '#title' => t('Play'),
       '#options' => $playArr
   );
    $form['location'] = array(
        '#type' => 'textarea',
        '#title' => t('Location'),                
    );
    $form['project_field'] = array(
        '#type' => 'textarea',
        '#title' => t('Project Field'),                
    );
    $form['entered_play'] = array(
        '#type' => 'textarea',
        '#title' => t('Entered Play'),                
    );
    $form['depth'] = array(
        '#type' => 'textarea',
        '#title' => t('Depth'),                
    );
    $form['acres_gross_net'] = array(
        '#type' => 'textarea',
        '#title' => t('Acres Gross Net'),                
    );
    $form['jvs'] = array(
        '#type' => 'textarea',
        '#title' => t('JVs'),                
    );
    $form['well_cost'] = array(
        '#type' => 'textarea',
        '#title' => t('Well Cost'),                
    );
    $form['most_recent_quarter'] = array(
        '#type' => 'textarea',
        '#title' => t('Most Recent Quarter'),                
    );
    $form['number_of_rigs'] = array(
        '#type' => 'textarea',
        '#title' => t('Number of Rigs'),                
    );
    $form['well_spacing'] = array(
        '#type' => 'textarea',
        '#title' => t('Well Spacing'),                
    );
    $form['inventory'] = array(
        '#type' => 'textarea',
        '#title' => t('Inventory'),                
    );
    $form['completions'] = array(
        '#type' => 'textarea',
        '#title' => t('Completions'),                
    );
    $form['ip'] = array(
        '#type' => 'textarea',
        '#title' => t('IP'),                
    );
    $form['eur'] = array(
        '#type' => 'textarea',
        '#title' => t('EUR'),                
    );
    $form['total_prod_wells'] = array(
        '#type' => 'textarea',
        '#title' => t('Total Prod Wells'),                
    );
    $form['reserves'] = array(
        '#type' => 'textarea',
        '#title' => t('Reserves'),                
    );
    $form['resource_potential'] = array(
        '#type' => 'textarea',
        '#title' => t('Resource Potential'),                
    );
    $form['comment'] = array(
        '#type' => 'textarea',
        '#title' => t('Comment'),                
    );
    $form['submit'] = array(
        '#type' => 'submit',
        '#value' => t('Submit')
    );
//    $form['cancel'] = array(
//        '#type' => 'button',
//        '#value' => t('Cancel'),
//        '#prefix' => '&nbsp; &nbsp; &nbsp;',
//        '#attributes' => array('onClick' => 'history.go(-1); return true;'),
//        '#post_render' => array('change_button_type'),
//    );
    return $form;
}

function add_region_form_submit($form, &$form_state) { 
    $company_id = $form_state['input']['company_id']; 
    $play_id = $form_state['input']['play_id']; 
    $location = $form_state['input']['location']; 
    $project_field = $form_state['input']['project_field']; 
    $entered_play = $form_state['input']['entered_play']; 
    $depth = $form_state['input']['depth']; 
    $acres_gross_net = $form_state['input']['acres_gross_net']; 
    $jvs = $form_state['input']['jvs']; 
    $well_cost = $form_state['input']['well_cost']; 
    $most_recent_quarter = $form_state['input']['most_recent_quarter']; 
    $number_of_rigs = $form_state['input']['number_of_rigs']; 
    $well_spacing = $form_state['input']['well_spacing']; 
    $inventory = $form_state['input']['inventory']; 
    $completions = $form_state['input']['completions']; 
    $ip = $form_state['input']['ip']; 
    $eur = $form_state['input']['eur']; 
    $total_prod_wells = $form_state['input']['total_prod_wells']; 
    $reserves = $form_state['input']['reserves']; 
    $resource_potential = $form_state['input']['resource_potential'];
    $comment = $form_state['input']['comment'];
    
    $company = get_company_by_id($company_id);
    $play = get_play_by_id($play_id);
    
    $cpd = getCompanyPlayDetails($company->company_name,$play->play_name,$location,$project_field);
    
    if(!$cpd){  // Add
        
        $cp = getCompanyPlayId($company_id,$play_id);
        if($cp){
            $company_play_id = $cp->company_play_id;
        }else{                                         
            $company_play_id = addCompanyPlay($company_id,$play_id);
        }
        
        $cpd_id = db_insert('oa_company_play_details')
                ->fields(array(
                    'company_play_id'=> $company_play_id,
                    'location' => $location , 'project_field' => $project_field, 'entered_play' => $entered_play, 'depth' => $depth, 
                        'acres_gross_net' => $acres_gross_net, 'jvs'=> $jvs, 'well_cost'=> $well_cost,'most_recent_quarter' => $most_recent_quarter,
                        'number_of_rigs'=> $number_of_rigs,'well_spacing'=> $well_spacing, 'inventory'=> $inventory,'completions'=> $completions,        
                        'ip'=> $ip, 'eur'=> $eur,'total_prod_wells'=> $total_prod_wells,'reserves'=> $reserves,'resource_potential'=> $resource_potential,
                        'comment'=> $comment
                ))->execute();        
        
    }else{  // Update
        
        $cpd_id = $cpd->cpd_id;        
        
        $cpd_updated = db_update('oa_company_play_details')
                ->fields(array(                                            
                        'location' => $location , 'project_field' => $project_field, 'entered_play' => $entered_play, 'depth' => $depth, 
                        'acres_gross_net' => $acres_gross_net, 'jvs'=> $jvs, 'well_cost'=> $well_cost,'most_recent_quarter' => $most_recent_quarter,
                        'number_of_rigs'=> $number_of_rigs,'well_spacing'=> $well_spacing, 'inventory'=> $inventory,'completions'=> $completions,        
                        'ip'=> $ip, 'eur'=> $eur,'total_prod_wells'=> $total_prod_wells,'reserves'=> $reserves,'resource_potential'=> $resource_potential,
                        'comment'=> $comment
                ))->condition('cpd_id', $cpd_id, '=')
                ->execute();
          
    }
    
    drupal_set_message(t('Region details added.'));
}

function edit_region_form($form, &$form_state, $cpd_id){
    
    $cpdetails = get_comp_play_details_by_cpd_id($cpd_id);    
    
    $companies = get_companies();
    $compArr = array();
    foreach ($companies as $comp){
        $compArr[$comp->company_id] = $comp->company_name;
    }
    $plays = get_op_plays();
    $playArr = array();
    foreach ($plays as $play){
        $playArr[$play->play_id] = $play->play_name;
    }
    $form['company_id'] = array(
       '#type' => 'select',
       '#title' => t('Company'),
       '#options' => $compArr,
        '#default_value' => $cpdetails->company_id,
        '#attributes' => array('disabled' => TRUE)
   );
    
    $form['play_id'] = array(
       '#type' => 'select',
       '#title' => t('Play'),
       '#options' => $playArr,
        '#default_value' => $cpdetails->play_id,
        '#attributes' => array('disabled' => TRUE)
   );
    $form['location'] = array(
        '#type' => 'textarea',
        '#title' => t('Location'),  
        '#value' => $cpdetails->location
    );
    $form['project_field'] = array(
        '#type' => 'textarea',
        '#title' => t('Project Field'),   
        '#value' => $cpdetails->project_field
    );
    $form['entered_play'] = array(
        '#type' => 'textarea',
        '#title' => t('Entered Play'),  
        '#value' => $cpdetails->entered_play
    );
    $form['depth'] = array(
        '#type' => 'textarea',
        '#title' => t('Depth'),         
        '#value' => $cpdetails->depth
    );
    $form['acres_gross_net'] = array(
        '#type' => 'textarea',
        '#title' => t('Acres Gross Net'),
        '#value' => $cpdetails->acres_gross_net
    );
    $form['jvs'] = array(
        '#type' => 'textarea',
        '#title' => t('JVs'),           
        '#value' => $cpdetails->jvs
    );
    $form['well_cost'] = array(
        '#type' => 'textarea',
        '#title' => t('Well Cost'),     
        '#value' => $cpdetails->well_cost
    );
    $form['most_recent_quarter'] = array(
        '#type' => 'textarea',
        '#title' => t('Most Recent Quarter'),                
        '#value' => $cpdetails->most_recent_quarter
    );
    $form['number_of_rigs'] = array(
        '#type' => 'textarea',
        '#title' => t('Number of Rigs'),   
        '#value' => $cpdetails->number_of_rigs
    );
    $form['well_spacing'] = array(
        '#type' => 'textarea',
        '#title' => t('Well Spacing'),  
        '#value' => $cpdetails->well_spacing
    );
    $form['inventory'] = array(
        '#type' => 'textarea',
        '#title' => t('Inventory'),     
        '#value' => $cpdetails->inventory
    );
    $form['completions'] = array(
        '#type' => 'textarea',
        '#title' => t('Completions'),   
        '#value' => $cpdetails->completions
    );
    $form['ip'] = array(
        '#type' => 'textarea',
        '#title' => t('IP'),       
        '#value' => $cpdetails->ip
    );
    $form['eur'] = array(
        '#type' => 'textarea',
        '#title' => t('EUR'),           
        '#value' => $cpdetails->eur
    );
    $form['total_prod_wells'] = array(
        '#type' => 'textarea',
        '#title' => t('Total Prod Wells'),    
        '#value' => $cpdetails->total_prod_wells
    );
    $form['reserves'] = array(
        '#type' => 'textarea',
        '#title' => t('Reserves'),      
        '#value' => $cpdetails->reserves
    );
    $form['resource_potential'] = array(
        '#type' => 'textarea',
        '#title' => t('Resource Potential'),                
        '#value' => $cpdetails->resource_potential
    );
    $form['comment'] = array(
        '#type' => 'textarea',
        '#title' => t('Comment'),               
        '#value' => $cpdetails->comment
    );
    $form['cpd_id'] = array(
        '#type' => 'hidden',
        '#value' => $cpd_id
    );
    $form['submit'] = array(
        '#type' => 'submit',
        '#value' => t('Submit')
    );
//    $form['cancel'] = array(
//        '#type' => 'button',
//        '#value' => t('Cancel'),
//        '#prefix' => '&nbsp; &nbsp; &nbsp;',
//        '#attributes' => array('onClick' => 'history.go(-1); return true;'),
//        '#post_render' => array('change_button_type'),
//    );
    return $form;
}

function edit_region_form_submit($form, &$form_state) { 
    $cpd_id = $form_state['input']['cpd_id']; 
    $company_id = $form_state['input']['company_id']; 
    $play_id = $form_state['input']['play_id']; 
    $location = $form_state['input']['location']; 
    $project_field = $form_state['input']['project_field']; 
    $entered_play = $form_state['input']['entered_play']; 
    $depth = $form_state['input']['depth']; 
    $acres_gross_net = $form_state['input']['acres_gross_net']; 
    $jvs = $form_state['input']['jvs']; 
    $well_cost = $form_state['input']['well_cost']; 
    $most_recent_quarter = $form_state['input']['most_recent_quarter']; 
    $number_of_rigs = $form_state['input']['number_of_rigs']; 
    $well_spacing = $form_state['input']['well_spacing']; 
    $inventory = $form_state['input']['inventory']; 
    $completions = $form_state['input']['completions']; 
    $ip = $form_state['input']['ip']; 
    $eur = $form_state['input']['eur']; 
    $total_prod_wells = $form_state['input']['total_prod_wells']; 
    $reserves = $form_state['input']['reserves']; 
    $resource_potential = $form_state['input']['resource_potential'];
    $comment = $form_state['input']['comment'];    
    
    $company = get_company_by_id($company_id);
    $play = get_play_by_id($play_id);
    
//    $cpd = getCompanyPlayDetails($company->company_name, $play->play_name, $location, $project_field);
//    if(!$cpd){  // Add
//        
//    }else{  // Update
        $cpd_updated = db_update('oa_company_play_details')
                ->fields(array(             
                        'location' => $location, 'project_field' => $project_field, 
                        'entered_play' => $entered_play, 'depth' => $depth, 
                        'acres_gross_net' => $acres_gross_net, 'jvs'=> $jvs, 'well_cost'=> $well_cost,'most_recent_quarter' => $most_recent_quarter,
                        'number_of_rigs'=> $number_of_rigs,'well_spacing'=> $well_spacing, 'inventory'=> $inventory,'completions'=> $completions,        
                        'ip'=> $ip, 'eur'=> $eur,'total_prod_wells'=> $total_prod_wells,'reserves'=> $reserves,'resource_potential'=> $resource_potential,
                        'comment'=> $comment
                ))->condition('cpd_id', $cpd_id, '=')
                ->execute();
    //}   
    
    
    drupal_set_message(t('Region details updated.'));
}


function edit_comp_annual_report_form($form, &$form_state, $annual_report_id){
    $car = get_comp_annual_report_by_arid($annual_report_id);
    
    $yearlist = array();
    $start_year = date('Y')-10;
    $cur_year = date('Y');
    for($i=$start_year; $i<=$cur_year; $i++){
        $yearlist[$i] = $i;
    }   
    
    $form['year'] = array(
        '#type' => 'select',
        '#title' => t('Year'),
        '#options' => $yearlist,
        '#default_value' => $car->year                
    );
    $form['report_url'] = array(
        '#type' => 'textfield',
        '#title' => t('Report Url'),  
        '#value' => $car->report_url
    );
    $form['annual_report_id'] = array(
        '#type' => 'hidden',
        '#value' => $annual_report_id
    );
    $form['submit'] = array(
        '#type' => 'submit',
        '#value' => t('Submit')
    );
//    $form['cancel'] = array(
//        '#type' => 'button',
//        '#value' => t('Cancel'),
//        '#prefix' => '&nbsp; &nbsp; &nbsp;',
//        '#attributes' => array('onClick' => 'history.go(-1); return true;'),
//        '#post_render' => array('change_button_type'),
//    );
    return $form;
}

function edit_comp_annual_report_form_submit($form, &$form_state){
    $year = $form_state['input']['year']; 
    $report_url = $form_state['input']['report_url']; 
    $annual_report_id = $form_state['input']['annual_report_id']; 
    $car_updated = db_update('oa_company_annual_report')
                ->fields(array(             
                        'year' => $year, 'report_url' => $report_url
                ))->condition('annual_report_id', $annual_report_id, '=')
                ->execute();
    drupal_set_message(t('Company Annual report is updated.'));
}

function add_comp_annual_report_form($form, &$form_state, $company_id){
    $yearlist = array();
    $start_year = date('Y')-10;
    $cur_year = date('Y');
    for($i=$start_year; $i<=$cur_year; $i++){
        $yearlist[$i] = $i;
    }  
    
    $companies = get_companies();
    $compArr = array();
    foreach ($companies as $comp){
        $compArr[$comp->company_id] = $comp->company_name;
    }
    
    $form['company'] = array(
       '#type' => 'select',
       '#title' => t('Company'),
       '#options' => $compArr,
        '#default_value' => $company_id,
        '#attributes' => array('disabled' => TRUE)
   );    
    
    $form['year'] = array(
        '#type' => 'select',
        '#title' => t('Year'),
        '#options' => $yearlist                   
    );
    $form['report_url'] = array(
        '#type' => 'textfield',
        '#title' => t('Report Url')        
    );
    $form['company_id'] = array(
        '#type' => 'hidden',
        '#value' => $company_id
    );
    $form['submit'] = array(
        '#type' => 'submit',
        '#value' => t('Submit')
    );
//    $form['cancel'] = array(
//        '#type' => 'button',
//        '#value' => t('Cancel'),
//        '#prefix' => '&nbsp; &nbsp; &nbsp;',
//        '#attributes' => array('onClick' => 'history.go(-1); return true;'),
//        '#post_render' => array('change_button_type'),
//    );
    return $form;
}

function add_comp_annual_report_form_submit($form, &$form_state){
    $year = $form_state['input']['year']; 
    $report_url = $form_state['input']['report_url']; 
    $company_id = $form_state['input']['company_id'];         
    $arid = db_insert('oa_company_annual_report')
                ->fields(array(             
                        'company_id' => $company_id ,'year' => $year, 'report_url' => $report_url
                ))->execute();
    drupal_set_message(t('Company Annual report is added.'));
}

function edit_comp_quarter_report_form($form, &$form_state, $quarter_report_id){
    $cqr = get_comp_quarter_report_by_qrid($quarter_report_id);
    
    $yearlist = array();
    $start_year = date('Y')-10;
    $cur_year = date('Y');
    for($i=$start_year; $i<=$cur_year; $i++){
        $yearlist[$i] = $i;
    }  
    
    $qcres = get_quarter_codes();
    $qcodes = array();
    foreach ($qcres as $qc){
        $qcodes[$qc->quarter_code] = $qc->quarter_code;
    }
    
    $form['year'] = array(
        '#type' => 'select',
        '#title' => t('Year'),
        '#options' => $yearlist,
        '#default_value' => $cqr->year                
    );
    $form['quarter_code'] = array(
        '#type' => 'select',
        '#title' => t('Quarter'),
        '#options' => $qcodes,
        '#default_value' => $cqr->quarter_code                
    );
    $form['quarter_report_url'] = array(
        '#type' => 'textfield',
        '#title' => t('Report Url'),  
        '#value' => $cqr->quarter_report_url
    );   
    
//    $form['presentation_text'] = array(
//        '#type' => 'textfield',                
//        '#title' => t('Presentation On'),          
//        '#value' => $cqr->presentation_text        
//    );
    $form['presentation_text'] = array(
        '#type' => 'date_popup',
        '#title' => t('Presentation On'),
        '#default_value' => $cqr->presentation_text,
        '#date_type' => DATE_DATETIME,        
        '#date_format' => 'm/d/Y',
        '#date_label_position' => 'within',
        '#date_increment' => 1,
        '#date_year_range' => '-5',
    );
    $form['presentation_url'] = array(
        '#type' => 'textfield',
        '#title' => t('Presentation Url'),  
        '#value' => $cqr->presentation_url
    );
    $form['quarter_report_id'] = array(
        '#type' => 'hidden',
        '#value' => $quarter_report_id
    );
    $form['submit'] = array(
        '#type' => 'submit',
        '#value' => t('Submit')
    );
//    $form['cancel'] = array(
//        '#type' => 'button',
//        '#value' => t('Cancel'),
//        '#prefix' => '&nbsp; &nbsp; &nbsp;',
//        '#attributes' => array('onClick' => 'history.go(-1); return true;'),
//        '#post_render' => array('change_button_type'),
//    );
    return $form;
}

function edit_comp_quarter_report_form_submit($form, &$form_state){
    $year = $form_state['input']['year']; 
    $quarter_code = $form_state['input']['quarter_code']; 
    $quarter_report_url = $form_state['input']['quarter_report_url']; 
    $presentation_text = $form_state['input']['presentation_text']['date'];      
    $presentation_text = (trim($presentation_text)!='') ? date('Y-m-d',strtotime($presentation_text)) : NULL;    
    $presentation_url = $form_state['input']['presentation_url'];     
    $quarter_report_id = $form_state['input']['quarter_report_id'];
    
    $car_updated = db_update('oa_company_quarter_report')
                ->fields(array(             
                        'year' => $year, 'quarter_code' => $quarter_code,
                        'quarter_report_url' => $quarter_report_url,
                        'presentation_text' => $presentation_text,'presentation_url' => $presentation_url
                ))->condition('quarter_report_id', $quarter_report_id, '=')
                ->execute();
    drupal_set_message(t('Company Quarter report is updated.'));
}

function add_comp_quarter_report_form($form, &$form_state, $company_id){
    $yearlist = array();
    $start_year = date('Y')-10;
    $cur_year = date('Y');
    for($i=$start_year; $i<=$cur_year; $i++){
        $yearlist[$i] = $i;
    }  
    
    $qcres = get_quarter_codes();
    $qcodes = array();
    foreach ($qcres as $qc){
        $qcodes[$qc->quarter_code] = $qc->quarter_code;
    }
    
    $companies = get_companies();
    $compArr = array();
    foreach ($companies as $comp){
        $compArr[$comp->company_id] = $comp->company_name;
    }
    
    $form['company'] = array(
       '#type' => 'select',
       '#title' => t('Company'),
       '#options' => $compArr,
        '#default_value' => $company_id,
        '#attributes' => array('disabled' => TRUE)
   ); 
    
    $form['year'] = array(
        '#type' => 'select',
        '#title' => t('Year'),
        '#options' => $yearlist        
    );
    $form['quarter_code'] = array(
        '#type' => 'select',
        '#title' => t('Quarter'),
        '#options' => $qcodes        
    );
    $form['quarter_report_url'] = array(
        '#type' => 'textfield',
        '#title' => t('Report Url')        
    );   
    
//    $form['presentation_text'] = array(
//        '#type' => 'textfield',                
//        '#title' => t('Presentation On')        
//    );
    $form['presentation_text'] = array(
        '#type' => 'date_popup',
        '#title' => t('Presentation On'),        
        '#date_type' => DATE_DATETIME,        
        '#date_format' => 'm/d/Y',
        '#date_label_position' => 'within',
        '#date_increment' => 1,
        '#date_year_range' => '-5',
    );
    $form['presentation_url'] = array(
        '#type' => 'textfield',
        '#title' => t('Presentation Url')        
    );
    $form['company_id'] = array(
        '#type' => 'hidden',
        '#value' => $company_id
    );
    $form['submit'] = array(
        '#type' => 'submit',
        '#value' => t('Submit')
    );
//    $form['cancel'] = array(
//        '#type' => 'button',
//        '#value' => t('Cancel'),
//        '#prefix' => '&nbsp; &nbsp; &nbsp;',
//        '#attributes' => array('onClick' => 'history.go(-1); return true;'),
//        '#post_render' => array('change_button_type'),
//    );
    return $form;
}

function add_comp_quarter_report_form_submit($form, &$form_state){
    $year = $form_state['input']['year']; 
    $quarter_code = $form_state['input']['quarter_code']; 
    $quarter_report_url = $form_state['input']['quarter_report_url']; 
    $presentation_text = $form_state['input']['presentation_text']['date'];      
    $presentation_text = (trim($presentation_text)!='') ? date('Y-m-d',strtotime($presentation_text)) : NULL;   
    $presentation_url = $form_state['input']['presentation_url'];     
    $quarter_report_id = $form_state['input']['quarter_report_id'];
    $company_id = $form_state['input']['company_id']; 
    
    $car_updated = db_insert('oa_company_quarter_report')
                ->fields(array(      
                        'company_id'=>$company_id,
                        'year' => $year, 'quarter_code' => $quarter_code,
                        'quarter_report_url' => $quarter_report_url,
                        'presentation_text' => $presentation_text,'presentation_url' => $presentation_url
                ))->execute();
    drupal_set_message(t('Company Quarter report is added.'));
}

function edit_comp_annual_capex_form($form, &$form_state, $ca_capex_id){
    $cac = get_comp_ann_capex_by_capexid($ca_capex_id);
    
    $yearlist = array();
    $start_year = date('Y')-10;
    $cur_year = date('Y');
    for($i=$start_year; $i<=$cur_year; $i++){
        $yearlist[$i] = $i;
    }  
    
    $form['year'] = array(
        '#type' => 'select',
        '#title' => t('Year'),
        '#options' => $yearlist,
        '#default_value' => $cac->year                
    );    
    $form['capex'] = array(
        '#type' => 'textarea',
        '#title' => t('Capex'),  
        '#value' => $cac->capex
    );   
    
    $estchck = ($cac->estimated=='1') ? array('checked' => 'checked') : array();
    $form['estimated'] = array(
        '#type' => 'checkbox', 
        '#title' => t('Estimated'),
        '#attributes' => $estchck
    );    
    $form['ca_capex_id'] = array(
        '#type' => 'hidden',
        '#value' => $ca_capex_id
    );
    $form['submit'] = array(
        '#type' => 'submit',
        '#value' => t('Submit')
    );
//    $form['cancel'] = array(
//        '#type' => 'button',
//        '#value' => t('Cancel'),
//        '#prefix' => '&nbsp; &nbsp; &nbsp;',
//        '#attributes' => array('onClick' => 'history.go(-1); return true;'),
//        '#post_render' => array('change_button_type'),
//    );
    return $form;
}

function edit_comp_annual_capex_form_submit($form, &$form_state){    
    $year = $form_state['input']['year']; 
    $capex = $form_state['input']['capex']; 
    $estimated = $form_state['input']['estimated']; 
    $ca_capex_id = $form_state['input']['ca_capex_id'];     
    $estimated = ($estimated=='1') ? $estimated : 0;    
    $car_updated = db_update('oa_company_annual_capex')
                ->fields(array(             
                        'year' => $year, 'capex' => $capex,'estimated' => $estimated
                ))->condition('ca_capex_id', $ca_capex_id, '=')
                ->execute();
    drupal_set_message(t('Company Annual Capex is updated.'));
}

function add_comp_annual_capex_form($form, &$form_state, $company_id){
    $yearlist = array();
    $start_year = date('Y')-10;
    $cur_year = date('Y');
    for($i=$start_year; $i<=$cur_year; $i++){
        $yearlist[$i] = $i;
    }  
    
    $companies = get_companies();
    $compArr = array();
    foreach ($companies as $comp){
        $compArr[$comp->company_id] = $comp->company_name;
    }
    
    $form['company'] = array(
       '#type' => 'select',
       '#title' => t('Company'),
       '#options' => $compArr,
        '#default_value' => $company_id,
        '#attributes' => array('disabled' => TRUE)
   ); 
    $form['year'] = array(
        '#type' => 'select',
        '#title' => t('Year'),
        '#options' => $yearlist                    
    );    
    $form['capex'] = array(
        '#type' => 'textarea',
        '#title' => t('Capex')        
    );
    $form['estimated'] = array(
        '#type' => 'checkbox', 
        '#title' => t('Estimated')        
    );    
    $form['company_id'] = array(
        '#type' => 'hidden',
        '#value' => $company_id
    );
    $form['submit'] = array(
        '#type' => 'submit',
        '#value' => t('Submit')
    );
//    $form['cancel'] = array(
//        '#type' => 'button',
//        '#value' => t('Cancel'),
//        '#prefix' => '&nbsp; &nbsp; &nbsp;',
//        '#attributes' => array('onClick' => 'history.go(-1); return true;'),
//        '#post_render' => array('change_button_type'),
//    );
    return $form;
}

function add_comp_annual_capex_form_submit($form, &$form_state){    
    $year = $form_state['input']['year']; 
    $capex = $form_state['input']['capex']; 
    $estimated = $form_state['input']['estimated']; 
    $company_id = $form_state['input']['company_id'];     
    $estimated = ($estimated=='1') ? $estimated : 0;   
    
    $ca_capex_id = db_insert('oa_company_annual_capex')
                ->fields(array(   
                        'company_id'=>$company_id,
                        'year' => $year, 'capex' => $capex,'estimated' => $estimated
                ))->execute();
    drupal_set_message(t('Company Annual Capex is added.'));
}

// ebi
function edit_comp_annual_ebidax_form($form, &$form_state, $ca_ebidax_id){
    $cac = get_comp_ann_ebidax_by_ebidaxid($ca_ebidax_id);
    
    $yearlist = array();
    $start_year = date('Y')-10;
    $cur_year = date('Y');
    for($i=$start_year; $i<=$cur_year; $i++){
        $yearlist[$i] = $i;
    }  
    
    $form['year'] = array(
        '#type' => 'select',
        '#title' => t('Year'),
        '#options' => $yearlist,
        '#default_value' => $cac->year                
    );    
    $form['ebidax'] = array(
        '#type' => 'textarea',
        '#title' => t('Ebidax'),  
        '#value' => $cac->ebidax
    );   
    
    $estchck = ($cac->estimated=='1') ? array('checked' => 'checked') : array();
    $form['estimated'] = array(
        '#type' => 'checkbox', 
        '#title' => t('Estimated'),
        '#attributes' => $estchck
    );    
    $form['ca_ebidax_id'] = array(
        '#type' => 'hidden',
        '#value' => $ca_ebidax_id
    );
    $form['submit'] = array(
        '#type' => 'submit',
        '#value' => t('Submit')
    );
//    $form['cancel'] = array(
//        '#type' => 'button',
//        '#value' => t('Cancel'),
//        '#prefix' => '&nbsp; &nbsp; &nbsp;',
//        '#attributes' => array('onClick' => 'history.go(-1); return true;'),
//        '#post_render' => array('change_button_type'),
//    );
    return $form;
}

function edit_comp_annual_ebidax_form_submit($form, &$form_state){    
    $year = $form_state['input']['year']; 
    $ebidax = $form_state['input']['ebidax']; 
    $estimated = $form_state['input']['estimated']; 
    $ca_ebidax_id = $form_state['input']['ca_ebidax_id'];     
    $estimated = ($estimated=='1') ? $estimated : 0;    
    
    $car_updated = db_update('oa_company_annual_ebidax')
                ->fields(array(             
                        'year' => $year, 'ebidax' => $ebidax,'estimated' => $estimated
                ))->condition('ca_ebidax_id', $ca_ebidax_id, '=')
                ->execute();
    drupal_set_message(t('Company Annual Ebidax is updated.'));
}

function add_comp_annual_ebidax_form($form, &$form_state, $company_id){
    $yearlist = array();
    $start_year = date('Y')-10;
    $cur_year = date('Y');
    for($i=$start_year; $i<=$cur_year; $i++){
        $yearlist[$i] = $i;
    }  
    
    $companies = get_companies();
    $compArr = array();
    foreach ($companies as $comp){
        $compArr[$comp->company_id] = $comp->company_name;
    }
    
    $form['company'] = array(
       '#type' => 'select',
       '#title' => t('Company'),
       '#options' => $compArr,
        '#default_value' => $company_id,
        '#attributes' => array('disabled' => TRUE)
   ); 
    
    $form['year'] = array(
        '#type' => 'select',
        '#title' => t('Year'),
        '#options' => $yearlist                    
    );    
    $form['ebidax'] = array(
        '#type' => 'textarea',
        '#title' => t('Ebidax')        
    );
    $form['estimated'] = array(
        '#type' => 'checkbox', 
        '#title' => t('Estimated')        
    );    
    $form['company_id'] = array(
        '#type' => 'hidden',
        '#value' => $company_id
    );
    $form['submit'] = array(
        '#type' => 'submit',
        '#value' => t('Submit')
    );
//    $form['cancel'] = array(
//        '#type' => 'button',
//        '#value' => t('Cancel'),
//        '#prefix' => '&nbsp; &nbsp; &nbsp;',
//        '#attributes' => array('onClick' => 'history.go(-1); return true;'),
//        '#post_render' => array('change_button_type'),
//    );
    return $form;
}

function add_comp_annual_ebidax_form_submit($form, &$form_state){    
    $year = $form_state['input']['year']; 
    $ebidax = $form_state['input']['ebidax']; 
    $estimated = $form_state['input']['estimated']; 
    $company_id = $form_state['input']['company_id'];     
    $estimated = ($estimated=='1') ? $estimated : 0;   
    
    $ca_capex_id = db_insert('oa_company_annual_ebidax')
                ->fields(array( 'company_id'=>$company_id,'year' => $year, 'ebidax' => $ebidax,'estimated' => $estimated ))->execute();
    drupal_set_message(t('Company Annual Ebidax is added.'));
}
// ebi


function edit_cp_annual_capex_form($form, &$form_state, $cpa_capex_id){
    $cac = get_comp_play_ann_capex_by_capexid($cpa_capex_id);
    
    $yearlist = array();
    $start_year = date('Y')-10;
    $cur_year = date('Y');
    for($i=$start_year; $i<=$cur_year; $i++){
        $yearlist[$i] = $i;
    }  
    
    $comp_play = get_comp_play_bycpid($cac->company_play_id);
    
    $companies = get_companies();
    $compArr = array();
    foreach ($companies as $comp){
        $compArr[$comp->company_id] = $comp->company_name;
    }
    
    $form['company'] = array(
       '#type' => 'select',
       '#title' => t('Company'),
       '#options' => $compArr,
        '#default_value' => $comp_play->company_id,
        '#attributes' => array('disabled' => TRUE)
   );    
    
    $plays = get_op_plays();
    $playArr = array();
    foreach ($plays as $pl){
        $playArr[$pl->play_id] = $pl->play_name;
    }
     $form['play'] = array(
       '#type' => 'select',
       '#title' => t('Play'),
       '#options' => $playArr,
        '#default_value' => $comp_play->play_id,
        '#attributes' => array('disabled' => TRUE)
   );
     
    $form['year'] = array(
        '#type' => 'select',
        '#title' => t('Year'),
        '#options' => $yearlist,
        '#default_value' => $cac->year                
    );    
    $form['capex'] = array(
        '#type' => 'textarea',
        '#title' => t('Capex'),  
        '#value' => $cac->capex
    );   
    
    $estchck = ($cac->estimated=='1') ? array('checked' => 'checked') : array();
    $form['estimated'] = array(
        '#type' => 'checkbox', 
        '#title' => t('Estimated'),
        '#attributes' => $estchck
    );    
    $form['cpa_capex_id'] = array(
        '#type' => 'hidden',
        '#value' => $cpa_capex_id
    );
    $form['submit'] = array(
        '#type' => 'submit',
        '#value' => t('Submit')
    );
//    $form['cancel'] = array(
//        '#type' => 'button',
//        '#value' => t('Cancel'),
//        '#prefix' => '&nbsp; &nbsp; &nbsp;',
//        '#attributes' => array('onClick' => 'history.go(-1); return true;'),
//        '#post_render' => array('change_button_type'),
//    );
    return $form;
}

function edit_cp_annual_capex_form_submit($form, &$form_state){    
    $year = $form_state['input']['year']; 
    $capex = $form_state['input']['capex']; 
    $estimated = $form_state['input']['estimated']; 
    $cpa_capex_id = $form_state['input']['cpa_capex_id'];     
    $estimated = ($estimated=='1') ? $estimated : 0;   
    
    $car_updated = db_update('oa_company_play_annual_capex')
                ->fields(array(             
                        'year' => $year, 'capex' => $capex,'estimated' => $estimated
                ))->condition('cpa_capex_id', $cpa_capex_id, '=')
                ->execute();
    
    drupal_set_message(t('Company Annual Play Capex is updated.'));
}

function add_cp_annual_capex_form($form, &$form_state, $company_play_id, $cpd_id){
    $yearlist = array();
    $start_year = date('Y')-10;
    $cur_year = date('Y');
    for($i=$start_year; $i<=$cur_year; $i++){
        $yearlist[$i] = $i;
    }  
    
    
    $comp_play = get_comp_play_bycpid($company_play_id);
    
    $companies = get_companies();
    $compArr = array();
    foreach ($companies as $comp){
        $compArr[$comp->company_id] = $comp->company_name;
    }
    
    $form['company'] = array(
       '#type' => 'select',
       '#title' => t('Company'),
       '#options' => $compArr,
        '#default_value' => $comp_play->company_id,
        '#attributes' => array('disabled' => TRUE)
   );    
    
    $plays = get_op_plays();
    $playArr = array();
    foreach ($plays as $pl){
        $playArr[$pl->play_id] = $pl->play_name;
    }
     $form['play'] = array(
       '#type' => 'select',
       '#title' => t('Play'),
       '#options' => $playArr,
        '#default_value' => $comp_play->play_id,
        '#attributes' => array('disabled' => TRUE)
   );
    
    $form['year'] = array(
        '#type' => 'select',
        '#title' => t('Year'),
        '#options' => $yearlist                    
    );    
    $form['capex'] = array(
        '#type' => 'textarea',
        '#title' => t('Capex')        
    );   
    $form['estimated'] = array(
        '#type' => 'checkbox', 
        '#title' => t('Estimated')        
    );    
    $form['company_play_id'] = array(
        '#type' => 'hidden',
        '#value' => $company_play_id
    );
    $form['cpd_id'] = array(
        '#type' => 'hidden',
        '#value' => $cpd_id
    );
    $form['submit'] = array(
        '#type' => 'submit',
        '#value' => t('Submit')
    );
//    $form['cancel'] = array(
//        '#type' => 'button',
//        '#value' => t('Cancel'),
//        '#prefix' => '&nbsp; &nbsp; &nbsp;',
//        '#attributes' => array('onClick' => 'history.go(-1); return true;'),
//        '#post_render' => array('change_button_type'),
//    );
    return $form;
}

function add_cp_annual_capex_form_submit($form, &$form_state){    
    $year = $form_state['input']['year']; 
    $capex = $form_state['input']['capex']; 
    $estimated = $form_state['input']['estimated']; 
    $company_play_id = $form_state['input']['company_play_id'];     
    $cpd_id = $form_state['input']['cpd_id'];  
    $estimated = ($estimated=='1') ? $estimated : 0;    
    
    $cpa_capex_id = db_insert('oa_company_play_annual_capex')
                ->fields(array(  'company_play_id' => $company_play_id, 'cpd_id' => $cpd_id,          
                        'year' => $year, 'capex' => $capex,'estimated' => $estimated
                ))
                ->execute();
    drupal_set_message(t('Company Annual Play Capex is added.'));
}


// wells
function edit_cp_annual_well_form($form, &$form_state, $cpa_wells_id){
    $cac = get_comp_play_ann_well_by_wellsid($cpa_wells_id);
    
    $yearlist = array();
    $start_year = date('Y')-10;
    $cur_year = date('Y');
    for($i=$start_year; $i<=$cur_year; $i++){
        $yearlist[$i] = $i;
    }  
    
    $comp_play = get_comp_play_bycpid($cac->company_play_id);
    
    $companies = get_companies();
    $compArr = array();
    foreach ($companies as $comp){
        $compArr[$comp->company_id] = $comp->company_name;
    }
    
    $form['company'] = array(
       '#type' => 'select',
       '#title' => t('Company'),
       '#options' => $compArr,
        '#default_value' => $comp_play->company_id,
        '#attributes' => array('disabled' => TRUE)
   );    
    
    $plays = get_op_plays();
    $playArr = array();
    foreach ($plays as $pl){
        $playArr[$pl->play_id] = $pl->play_name;
    }
     $form['play'] = array(
       '#type' => 'select',
       '#title' => t('Play'),
       '#options' => $playArr,
        '#default_value' => $comp_play->play_id,
        '#attributes' => array('disabled' => TRUE)
   );
     
    $form['year'] = array(
        '#type' => 'select',
        '#title' => t('Year'),
        '#options' => $yearlist,
        '#default_value' => $cac->year                
    );    
    $form['well'] = array(
        '#type' => 'textarea',
        '#title' => t('Well'),  
        '#value' => $cac->well
    );   
    
    $estchck = ($cac->estimated=='1') ? array('checked' => 'checked') : array();
    $form['estimated'] = array(
        '#type' => 'checkbox', 
        '#title' => t('Estimated'),
        '#attributes' => $estchck
    );    
    $form['cpa_wells_id'] = array(
        '#type' => 'hidden',
        '#value' => $cpa_wells_id
    );
    $form['submit'] = array(
        '#type' => 'submit',
        '#value' => t('Submit')
    );
//    $form['cancel'] = array(
//        '#type' => 'button',
//        '#value' => t('Cancel'),
//        '#prefix' => '&nbsp; &nbsp; &nbsp;',
//        '#attributes' => array('onClick' => 'history.go(-1); return true;'),
//        '#post_render' => array('change_button_type'),
//    );
    return $form;
}

function edit_cp_annual_well_form_submit($form, &$form_state){    
    $year = $form_state['input']['year']; 
    $well = $form_state['input']['well']; 
    $estimated = $form_state['input']['estimated']; 
    $cpa_wells_id = $form_state['input']['cpa_wells_id'];     
    $estimated = ($estimated=='1') ? $estimated : 0;    
    $car_updated = db_update('oa_company_play_annual_wells')
                ->fields(array(             
                        'year' => $year, 'well' => $well,'estimated' => $estimated
                ))->condition('cpa_wells_id', $cpa_wells_id, '=')
                ->execute();
    drupal_set_message(t('Company Annual Play Wells is updated.'));
}

function add_cp_annual_well_form($form, &$form_state, $company_play_id, $cpd_id){
    $yearlist = array();
    $start_year = date('Y')-10;
    $cur_year = date('Y');
    for($i=$start_year; $i<=$cur_year; $i++){
        $yearlist[$i] = $i;
    }  
    
    $comp_play = get_comp_play_bycpid($company_play_id);
    
    $companies = get_companies();
    $compArr = array();
    foreach ($companies as $comp){
        $compArr[$comp->company_id] = $comp->company_name;
    }
    
    $form['company'] = array(
       '#type' => 'select',
       '#title' => t('Company'),
       '#options' => $compArr,
        '#default_value' => $comp_play->company_id,
        '#attributes' => array('disabled' => TRUE)
   );    
    
    $plays = get_op_plays();
    $playArr = array();
    foreach ($plays as $pl){
        $playArr[$pl->play_id] = $pl->play_name;
    }
     $form['play'] = array(
       '#type' => 'select',
       '#title' => t('Play'),
       '#options' => $playArr,
        '#default_value' => $comp_play->play_id,
        '#attributes' => array('disabled' => TRUE)
   );
    
    $form['year'] = array(
        '#type' => 'select',
        '#title' => t('Year'),
        '#options' => $yearlist                    
    );    
    $form['well'] = array(
        '#type' => 'textarea',
        '#title' => t('Well')        
    );   
    $form['estimated'] = array(
        '#type' => 'checkbox', 
        '#title' => t('Estimated')        
    );    
    $form['company_play_id'] = array(
        '#type' => 'hidden',
        '#value' => $company_play_id
    );
    $form['cpd_id'] = array(
        '#type' => 'hidden',
        '#value' => $cpd_id
    );
    $form['submit'] = array(
        '#type' => 'submit',
        '#value' => t('Submit')
    );
//    $form['cancel'] = array(
//        '#type' => 'button',
//        '#value' => t('Cancel'),
//        '#prefix' => '&nbsp; &nbsp; &nbsp;',
//        '#attributes' => array('onClick' => 'history.go(-1); return true;'),
//        '#post_render' => array('change_button_type'),
//    );
    return $form;
}

function add_cp_annual_well_form_submit($form, &$form_state){    
    $year = $form_state['input']['year']; 
    $well = $form_state['input']['well']; 
    $estimated = $form_state['input']['estimated']; 
    $company_play_id = $form_state['input']['company_play_id'];     
    $cpd_id = $form_state['input']['cpd_id'];  
    $estimated = ($estimated=='1') ? $estimated : 0;    
    
    $cpa_capex_id = db_insert('oa_company_play_annual_wells')
                ->fields(array(  'company_play_id' => $company_play_id, 'cpd_id' => $cpd_id,          
                        'year' => $year, 'well' => $well,'estimated' => $estimated
                ))
                ->execute();
    drupal_set_message(t('Company Annual Play Well is added.'));
}
// wells end

// production
function edit_cp_annual_production_form($form, &$form_state, $cpa_production_id){
    $cac = get_comp_play_ann_production_by_prodid($cpa_production_id);
    
    $yearlist = array();
    $start_year = date('Y')-10;
    $cur_year = date('Y');
    for($i=$start_year; $i<=$cur_year; $i++){
        $yearlist[$i] = $i;
    }  
    
    
    $comp_play = get_comp_play_bycpid($cac->company_play_id);
    
    $companies = get_companies();
    $compArr = array();
    foreach ($companies as $comp){
        $compArr[$comp->company_id] = $comp->company_name;
    }
    
    $form['company'] = array(
       '#type' => 'select',
       '#title' => t('Company'),
       '#options' => $compArr,
        '#default_value' => $comp_play->company_id,
        '#attributes' => array('disabled' => TRUE)
   );    
    
    $plays = get_op_plays();
    $playArr = array();
    foreach ($plays as $pl){
        $playArr[$pl->play_id] = $pl->play_name;
    }
     $form['play'] = array(
       '#type' => 'select',
       '#title' => t('Play'),
       '#options' => $playArr,
        '#default_value' => $comp_play->play_id,
        '#attributes' => array('disabled' => TRUE)
   );
    
    
    $form['year'] = array(
        '#type' => 'select',
        '#title' => t('Year'),
        '#options' => $yearlist,
        '#default_value' => $cac->year                
    );    
    $form['production'] = array(
        '#type' => 'textarea',
        '#title' => t('Production'),  
        '#value' => $cac->production
    );   
    
    $estchck = ($cac->estimated=='1') ? array('checked' => 'checked') : array();
    $form['estimated'] = array(
        '#type' => 'checkbox', 
        '#title' => t('Estimated'),
        '#attributes' => $estchck
    );    
    $form['cpa_production_id'] = array(
        '#type' => 'hidden',
        '#value' => $cpa_production_id
    );
    $form['submit'] = array(
        '#type' => 'submit',
        '#value' => t('Submit')
    );
//    $form['cancel'] = array(
//        '#type' => 'button',
//        '#value' => t('Cancel'),
//        '#prefix' => '&nbsp; &nbsp; &nbsp;',
//        '#attributes' => array('onClick' => 'history.go(-1); return true;'),
//        '#post_render' => array('change_button_type'),
//    );
    return $form;
}

function edit_cp_annual_production_form_submit($form, &$form_state){    
    $year = $form_state['input']['year']; 
    $production = $form_state['input']['production']; 
    $estimated = $form_state['input']['estimated']; 
    $cpa_production_id = $form_state['input']['cpa_production_id'];     
    $estimated = ($estimated=='1') ? $estimated : 0;    
    $car_updated = db_update('oa_company_play_annual_production')
                ->fields(array(             
                        'year' => $year, 'production' => $production,'estimated' => $estimated
                ))->condition('cpa_production_id', $cpa_production_id, '=')
                ->execute();
    drupal_set_message(t('Company Annual Play Production is updated.'));
}

function add_cp_annual_production_form($form, &$form_state, $company_play_id, $cpd_id){
    $yearlist = array();
    $start_year = date('Y')-10;
    $cur_year = date('Y');
    for($i=$start_year; $i<=$cur_year; $i++){
        $yearlist[$i] = $i;
    }  
    
    $comp_play = get_comp_play_bycpid($company_play_id);
    
    $companies = get_companies();
    $compArr = array();
    foreach ($companies as $comp){
        $compArr[$comp->company_id] = $comp->company_name;
    }
    
    $form['company'] = array(
       '#type' => 'select',
       '#title' => t('Company'),
       '#options' => $compArr,
        '#default_value' => $comp_play->company_id,
        '#attributes' => array('disabled' => TRUE)
   );    
    
    $plays = get_op_plays();
    $playArr = array();
    foreach ($plays as $pl){
        $playArr[$pl->play_id] = $pl->play_name;
    }
     $form['play'] = array(
       '#type' => 'select',
       '#title' => t('Play'),
       '#options' => $playArr,
        '#default_value' => $comp_play->play_id,
        '#attributes' => array('disabled' => TRUE)
   );
     
    $form['year'] = array(
        '#type' => 'select',
        '#title' => t('Year'),
        '#options' => $yearlist                    
    );    
    $form['production'] = array(
        '#type' => 'textarea',
        '#title' => t('Production')        
    );   
    $form['estimated'] = array(
        '#type' => 'checkbox', 
        '#title' => t('Estimated')        
    );    
    $form['company_play_id'] = array(
        '#type' => 'hidden',
        '#value' => $company_play_id
    );
    $form['cpd_id'] = array(
        '#type' => 'hidden',
        '#value' => $cpd_id
    );
    $form['submit'] = array(
        '#type' => 'submit',
        '#value' => t('Submit')
    );
//    $form['cancel'] = array(
//        '#type' => 'button',
//        '#value' => t('Cancel'),
//        '#prefix' => '&nbsp; &nbsp; &nbsp;',
//        '#attributes' => array('onClick' => 'history.go(-1); return true;'),
//        '#post_render' => array('change_button_type'),
//    );
    return $form;
}

function add_cp_annual_production_form_submit($form, &$form_state){    
    $year = $form_state['input']['year']; 
    $production = $form_state['input']['production']; 
    $estimated = $form_state['input']['estimated']; 
    $company_play_id = $form_state['input']['company_play_id'];     
    $cpd_id = $form_state['input']['cpd_id'];  
    $estimated = ($estimated=='1') ? $estimated : 0;    
    
    $cpa_capex_id = db_insert('oa_company_play_annual_production')
                ->fields(array(  'company_play_id' => $company_play_id, 'cpd_id' => $cpd_id,          
                        'year' => $year, 'production' => $production,'estimated' => $estimated
                ))
                ->execute();
    drupal_set_message(t('Company Annual Play Production is added.'));
}
// production ends


//Delete begins
function del_cp_annual_production($cpa_production_id){
    $deleted = db_delete('oa_company_play_annual_production')->condition('cpa_production_id', $cpa_production_id)->execute();        
    drupal_set_message(t('Company Play Annual Production is deleted.'));
    drupal_goto($_SERVER['HTTP_REFERER']);
}
function del_cp_annual_well($cpa_wells_id){
    $deleted = db_delete('oa_company_play_annual_wells')->condition('cpa_wells_id', $cpa_wells_id)->execute();        
    drupal_set_message(t('Company Play Annual Well is deleted.'));
    drupal_goto($_SERVER['HTTP_REFERER']);
}
function del_cp_annual_capex($cpa_capex_id){
    $deleted = db_delete('oa_company_play_annual_capex')->condition('cpa_capex_id', $cpa_capex_id)->execute();        
    drupal_set_message(t('Company Play Annual Capex is deleted.'));
    drupal_goto($_SERVER['HTTP_REFERER']);
}
function del_comp_annual_ebidax($ca_ebidax_id){
    $deleted = db_delete('oa_company_annual_ebidax')->condition('ca_ebidax_id', $ca_ebidax_id)->execute();        
    drupal_set_message(t('Company Annual Ebidax is deleted.'));
    drupal_goto($_SERVER['HTTP_REFERER']);
}
function del_comp_annual_capex($ca_capex_id){
    $deleted = db_delete('oa_company_annual_capex')->condition('ca_capex_id', $ca_capex_id)->execute();        
    drupal_set_message(t('Company Annual Capex is deleted.'));
    drupal_goto($_SERVER['HTTP_REFERER']);
}
function del_comp_quarter_report($quarter_report_id){
    $deleted = db_delete('oa_company_quarter_report')->condition('quarter_report_id', $quarter_report_id)->execute();        
    drupal_set_message(t('Company Quarter Report is deleted.'));
    drupal_goto($_SERVER['HTTP_REFERER']);
}
function del_comp_annual_report($annual_report_id){
    $deleted = db_delete('oa_company_annual_report')->condition('annual_report_id', $annual_report_id)->execute();        
    drupal_set_message(t('Company Annual Report is deleted.'));
    drupal_goto($_SERVER['HTTP_REFERER']);
}
//Delete ends
function get_company_plays_list(){
    if(isset($_POST['cid']) && $_POST['cid']!=''){
        $comp_plays = get_company_plays($_POST['cid']);
        
        $data='';
        if(count($comp_plays)>0){
            $data .= '<select class="form-control slt" name="p" id="play" style="">
                    <option value="">Select Play</option>';
                    
                    foreach ($comp_plays as $play) {
                        if (isset($qstring['p']) && $qstring['p'] == $play->play_id) {
                            $data .= '<option value="' . $play->play_id . '" selected="selected">' . $play->play_name . '</option>';
                        } else {
                            $data .= '<option value="' . $play->play_id . '">' . $play->play_name . '</option>';
                        }
                    }
            $data .= '</select>';
        }
        echo $data;
    }
}
// Edit/Add Ends ********************************************************************/