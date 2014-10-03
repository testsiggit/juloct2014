<?php
//ini_set('display_errors',1); 
//error_reporting(E_ALL);

//function he_clean_string($text){
//    $text = preg_replace('/[^A-Za-z0-9\-\(\)&#%\',\/:`\. ]/', '', $text); 
//    $text = htmlspecialchars($text, ENT_QUOTES, 'UTF-8');
//    return $text;
//}

function he_utf_conversion($dataArr){
    if(is_array($dataArr) && count($dataArr)>0){
        foreach( $dataArr as $field => $value ){
            $dataArr[$field] = mb_check_encoding($dataArr[$field], 'UTF-8') ? $dataArr[$field] : utf8_encode($dataArr[$field]);
        }
    }
    return $dataArr;
}

// 01
function DAROOT($str) {
    $data = array();
    if ($str != '') {
        $data['rrc_tape_record_id'] = substr($str, 0, 2);
        $data['status_number'] = substr($str, 2, 7);
        $data['status_sequence_number'] = substr($str, 9, 2);
        $data['county_code'] = substr($str, 11, 3);
        $data['lease_name'] = substr($str, 14, 32);
        $data['district'] = substr($str, 46, 2);
        $data['operator_number'] = substr($str, 48, 6);
        $data['converted_date'] = substr($str, 54, 8);
        $data['da_app_rcvd_century'] = substr($str, 58, 2);
        $data['da_app_rcvd_year'] = substr($str, 60, 2);
        $data['da_app_rcvd_month'] = substr($str, 62, 2);
        $data['da_app_rcvd_day'] = substr($str, 64, 2);
        $data['operator_name'] = substr($str, 66, 32);
        $data['filler'] = substr($str, 98, 1);
        $data['hb1407_problem_flag'] = substr($str, 99, 1);
        $data['status_of_app_flag'] = substr($str, 100, 1);
        $data['not_enough_money_flag'] = substr($str, 101, 1);
        $data['too_much_money_flag'] = substr($str, 102, 1);
        $data['p5_problem_flag'] = substr($str, 103, 1);
        $data['p12_problem_flag'] = substr($str, 104, 1);
        $data['plat_problem_flag'] = substr($str, 105, 1);
        $data['w1a_problem_flag'] = substr($str, 106, 1);
        $data['other_problem_flag'] = substr($str, 107, 1);
        $data['rule37_problem_flag'] = substr($str, 108, 1);
        $data['rule38_problem_flag'] = substr($str, 109, 1);
        $data['rule39_problem_flag'] = substr($str, 110, 1);
        $data['no_money_flag'] = substr($str, 111, 1);
        $data['permit'] = substr($str, 112, 7);
        $data['da_issue_century'] = substr($str, 119, 2);
        $data['da_issue_year'] = substr($str, 121, 2);
        $data['da_issue_month'] = substr($str, 123, 2);
        $data['da_issue_day'] = substr($str, 125, 2);
        $data['da_withdrawn_century'] = substr($str, 127, 2);
        $data['da_withdrawn_year'] = substr($str, 129, 2);
        $data['da_withdrawn_month'] = substr($str, 131, 2);
        $data['da_withdrawn_day'] = substr($str, 133, 2);
        $data['walkthrough_flag'] = substr($str, 135, 2);
        $data['other_problem_text'] = substr($str, 136, 20);
        $data['well_number'] = substr($str, 156, 6);
        $data['built_from_old_master_flag'] = substr($str, 162, 1);
        $data['status_renumbered_to'] = substr($str, 163, 9);
        $data['status_renumbered_from'] = substr($str, 172, 9);
        $data['application_returned_flag'] = substr($str, 181, 1);
        $data['problem_flag_filler'] = substr($str, 182, 1);
        $data['rrc_tape_filler'] = substr($str, 183, 29);
    }
    return $data;
}

//02 
function DAPERMIT($str) {    
    $data = array();
    $da_pmt_amended_date = NULL;
    $da_pmt_issued_date = NULL;
    
    if ($str != '') {
        $data['rrc_tape_record_id'] = substr($str, 0, 2);
        $data['permit_number'] = substr($str, 2, 7);
        $data['permit_sequence_number'] = substr($str, 9, 2);
        $data['permit_county_code'] = substr($str, 11, 3);
        $data['permit_lease_name'] = substr($str, 14, 32);
        $data['permit_district'] = substr($str, 46, 2);
        $data['permit_well_number'] = substr($str, 48, 6);
        $data['permit_total_depth'] = substr($str, 54, 5);
        $data['permit_operator_number'] = substr($str, 59, 6);
        $data['type_application'] = substr($str, 65, 2);
        $data['other_explanation'] = substr($str, 67, 30);
        $data['address_unique_number'] = substr($str, 97, 6);
        $data['zip_code_prefix'] = substr($str, 103, 5);
        $data['zip_code_suffix'] = substr($str, 108, 4);
        $data['fiche_set_number'] = substr($str, 112, 6);
        $data['onshore_county'] = substr($str, 118, 3);
        $data['da_received_century'] = substr($str, 121, 2);
        $data['da_received_year'] = substr($str, 123, 2);
        $data['da_received_month'] = substr($str, 125, 2);
        $data['da_received_day'] = substr($str, 127, 2);
        $data['da_pmt_issued_century'] = substr($str, 129, 2);
        $data['da_pmt_issued_year'] = substr($str, 131, 2);
        $data['da_pmt_issued_month'] = substr($str, 133, 2);
        $data['da_pmt_issued_day'] = substr($str, 135, 2);
        $data['da_pmt_amended_century'] = substr($str, 137, 2);
        $data['da_pmt_amended_year'] = substr($str, 139, 2);
        $data['da_pmt_amended_month'] = substr($str, 141, 2);
        $data['da_pmt_amended_day'] = substr($str, 143, 2);
        $data['da_pmt_extented_century'] = substr($str, 145, 2);
        $data['da_pmt_extented_year'] = substr($str, 147, 2);
        $data['da_pmt_extented_month'] = substr($str, 149, 2);
        $data['da_pmt_extented_day'] = substr($str, 151, 2);
        $data['da_pmt_spud_century'] = substr($str, 153, 2);
        $data['da_pmt_spud_year'] = substr($str, 155, 2);
        $data['da_pmt_spud_month'] = substr($str, 157, 2);
        $data['da_pmt_spud_day'] = substr($str, 159, 2);
        $data['da_pmt_surface_casting_century'] = substr($str, 161, 2);
        $data['da_pmt_surface_casting_year'] = substr($str, 163, 2);
        $data['da_pmt_surface_casting_month'] = substr($str, 165, 2);
        $data['da_pmt_surface_casting_day'] = substr($str, 167, 2);        
        $data['well_staus'] = substr($str, 169, 1);
        $data['da_pmt_well_status_century'] = substr($str, 170, 2);
        $data['da_pmt_well_status_year'] = substr($str, 172, 2);
        $data['da_pmt_well_status_month'] = substr($str, 174, 2);
        $data['da_pmt_well_status_day'] = substr($str, 176, 2);
        $data['da_pmt_expired_century'] = substr($str, 178, 2);
        $data['da_pmt_expired_year'] = substr($str, 180, 2);
        $data['da_pmt_expired_month'] = substr($str, 182, 2);
        $data['da_pmt_expired_day'] = substr($str, 184, 2);
        $data['da_pmt_cancelled_century'] = substr($str, 186, 2);
        $data['da_pmt_cancelled_year'] = substr($str, 188, 2);
        $data['da_pmt_cancelled_month'] = substr($str, 190, 2);
        $data['da_pmt_cancelled_day'] = substr($str, 192, 2);
        $data['cancellation_reason'] = substr($str, 194, 30);
        $data['p12_filed_flag'] = substr($str, 224, 1);
        $data['substandard_acreage_flag'] = substr($str, 225, 1);
        $data['rule_36_flag'] = substr($str, 226, 1);
        $data['h9_flag'] = substr($str, 227, 1);
        $data['rule_37_case_number'] = substr($str, 228, 7);
        $data['rule_38_docket_number'] = substr($str, 235, 7);
        $data['location_formation_flag'] = substr($str, 242, 1);
        $data['old_surface_location'] = substr($str, 243, 52);
        $data['old_surface_filler'] = substr($str, 295, 30);
        $data['new_surface_section'] = substr($str, 243, 8);
        $data['new_surface_block'] = substr($str, 251, 10);
        $data['new_surface_survey'] = substr($str, 261, 55);
        $data['new_surface_abstract'] = substr($str, 316, 6);
        $data['new_surface_filler'] = substr($str, 322, 3);
        $data['surface_acres'] = substr($str, 325, 8);
        $data['surface_miles_from_city'] = substr($str, 333, 6);
        $data['surface_direction_from_city'] = substr($str, 339, 6);
        $data['surface_nearest_city'] = substr($str, 345, 13);
        $data['surface_lease_feet_1'] = substr($str, 358, 8);
        $data['surface_lease_direction_1'] = substr($str, 366, 13);
        $data['surface_lease_feet_2'] = substr($str, 379, 8);
        $data['surface_lease_direction_2'] = substr($str, 387, 13);
        $data['surface_survey_feet_1'] = substr($str, 400, 8);
        $data['surface_survey_direction_1'] = substr($str, 408, 13);
        $data['surface_survey_feet_2'] = substr($str, 421, 8);
        $data['surface_survey_dierction_2'] = substr($str, 429, 13);
        $data['nearest_well'] = substr($str, 442, 28);
        $data['nearest_well_format_flag'] = substr($str, 470, 1);
        $data['final_update'] = substr($str, 471, 8);
        $data['cancelled_flag'] = substr($str, 479, 1);
        $data['spud_in_flag'] = substr($str, 480, 1);
        $data['directional_well_flag'] = substr($str, 481, 1);
        $data['sidetrack_well_flag'] = substr($str, 482, 1);
        $data['moved_indicator'] = substr($str, 483, 1);
        $data['permit_conv_issued_date'] = substr($str, 484, 8);
        $data['rule_37_granted_code'] = substr($str, 492, 1);
        $data['horizontal_well_flag'] = substr($str, 493, 1);
        $data['duplicate_permit_flag'] = substr($str, 494, 1);
        $data['nearest_lease_line'] = substr($str, 495, 7);
        $data['api_number'] = substr($str, 502, 8);
        $data['rrc_tape_filler'] = substr($str, 510, 45);
        
        if( $data['da_pmt_amended_month'] != "00" && $data['da_pmt_amended_day']!="00" && $data['da_pmt_amended_century']!="00" && $data['da_pmt_amended_year']!="00" ){
            $da_pmt_amended_date = date('Y-m-d', strtotime( $data['da_pmt_amended_month'].'/'.$data['da_pmt_amended_day'].'/'.$data['da_pmt_amended_century'].$data['da_pmt_amended_year']));
        }
        if( $data['da_pmt_issued_month'] != "00" && $data['da_pmt_issued_day']!="00" && $data['da_pmt_issued_century']!="00" && $data['da_pmt_issued_year']!="00" ){
            $da_pmt_issued_date = date('Y-m-d', strtotime( $data['da_pmt_issued_month'].'/'.$data['da_pmt_issued_day'].'/'.$data['da_pmt_issued_century'].$data['da_pmt_issued_year']));
        }
        $data['final_approved_date'] = (!is_null($da_pmt_amended_date)) ? $da_pmt_amended_date : $da_pmt_issued_date;         
        
        //print_r($data);
    }
    
    
    return $data;
}

//03
function DAFIELD($str) {
    $data = array();
    if ($str != '') {
        $data['rrc_tape_record_id'] = substr($str, 0, 2);
        $data['field_number'] = substr($str, 2, 8);         // UNIQUE
        $data['field_application_well_code'] = substr($str, 10, 1);
        $data['field_completion_well_code'] = substr($str, 11, 1);
        $data['field_completion_code'] = substr($str, 12, 1);
        $data['field_transfer_code'] = substr($str, 13, 1);
        $data['field_validation_date'] = substr($str, 14, 8);
        $data['field_completion_date'] = substr($str, 22, 8);
        $data['field_rule37_flag'] = substr($str, 30, 1);
        $data['field_rule38_flag'] = substr($str, 31, 1);
        $data['filler'] = substr($str, 32, 18);
        $data['rrc_tape_filler'] = substr($str, 32, 45);
    }
    return $data;    
}

//04
function DAFLDSPC($str) {
    $data = array();
    if ($str != '') {
        $data['rrc_tape_record_id'] = substr($str, 0, 2);
        $data['field_district'] = substr($str, 2, 2);
        $data['field_lease_name'] = substr($str, 4, 32);
        $data['field_total_depth'] = substr($str, 36, 5);
        $data['field_well_number'] = substr($str, 41, 6);
        $data['field_acres'] = substr($str, 47, 8);
        $data['filler'] = substr($str, 55, 17);
        $data['rrc_tape_filler'] = substr($str, 72, 45);
    }
    return $data;
}

//05
function DAFLDBHL($str) {
    $data = array();
    if ($str != '') {
        $data['rrc_tape_record_id'] = substr($str, 0, 2);
        $data['fld_bhl_section'] = substr($str, 2, 8);
        $data['fld_bhl_block'] = substr($str, 10, 10);
        $data['fld_bhl_abstract'] = substr($str, 20, 6);
        $data['fld_bhl_survey'] = substr($str, 26, 55);
        $data['fld_bhl_acres'] = substr($str, 81, 8);
        $data['fld_bhl_nearest_well'] = substr($str, 89, 28);
        $data['fld_bhl_lease_feet_1'] = substr($str, 117, 8);
        $data['fld_bhl_lease_direction_1'] = substr($str, 125, 13);
        $data['fld_bhl_lease_feet_2'] = substr($str, 138, 8);
        $data['fld_bhl_lease_direction_2'] = substr($str, 146, 13);
        $data['fld_bhl_survey_feet_1'] = substr($str, 159, 8);
        $data['fld_bhl_survey_direction_1'] = substr($str, 167, 13);
        $data['fld_bhl_survey_feet_2'] = substr($str, 180, 8);
        $data['fld_bhl_survey_direction_2'] = substr($str, 188, 13);
        $data['fld_bhl_county'] = substr($str, 201, 13);
        $data['fld_bhl_pntrt_dist_1'] = substr($str, 214, 8);
        $data['fld_bhl_pntrt_dir_1'] = substr($str, 222, 13);
        $data['fld_bhl_pntrt_dist_2'] = substr($str, 235, 8);
        $data['fld_bhl_pntrt_dir_2'] = substr($str, 243, 13);
        $data['filler'] = substr($str, 256, 6);
        $data['rrc_tape_filler'] = substr($str, 262, 45);
    }
    //exit;
    return $data;
}

//06
function DACANRES($str) {
    $data = array();
    if ($str != '') {
        $data['rrc_tape_record_id'] = substr($str, 0, 2);
        $data['can_restr_key'] = substr($str, 2, 2);
        $data['can_restr_type'] = substr($str, 4, 2);
        $data['can_restr_remark'] = substr($str, 6, 35);
    }
    return $data;
}

//07
function DACANFLD($str) {
    $data = array();
    if ($str != '') {
        $data['rrc_tape_record_id'] = substr($str, 0, 2);
        $data['can_restr_field_number'] = substr($str, 2, 8);
        $data['filler'] = substr($str, 10, 5);
    }
    return $data;    
}

//08
function DAFRERES($str) {
    $data = array();
    if ($str != '') {
        $data['rrc_tape_record_id'] = substr($str, 0, 2);
        $data['free_restr_key'] = substr($str, 2, 2);
        $data['free_restr_type'] = substr($str, 4, 2);
        $data['free_restr_remark'] = substr($str, 6, 70);
        $data['free_restr_flag'] = substr($str, 76, 1);
        $data['filler'] = substr($str, 77, 10);
        $data['rrc_tape_filler'] = substr($str, 87, 45);
    }
    return $data;
}

//09
function DAFREFLD($str) {
    $data = array();
    if ($str != '') {
        $data['rrc_tape_record_id'] = substr($str, 0, 2);
        $data['free_restr_fld_number'] = substr($str, 2, 8);
        $data['filler'] = substr($str, 10, 5);
        $data['rrc_tape_filler'] = substr($str, 15, 60);
    }
    return $data;
}

//10
function DAPMTBHL($str) {
    $data = array();
    if ($str != '') {
        $data['rrc_tape_record_id'] = substr($str, 0, 2);
        $data['pmt_bhl_section'] = substr($str, 2, 8);
        $data['pmt_bhl_block'] = substr($str, 10, 10);
        $data['pmt_bhl_abstract'] = substr($str, 20, 6);
        $data['pmt_bhl_survey'] = substr($str, 26, 55);
        $data['pmt_bhl_acres'] = substr($str, 81, 8);
        $data['pmt_bhl_nearest_well'] = substr($str, 89, 28);
        $data['pmt_bhl_lease_feet_1'] = substr($str, 117, 8);
        $data['pmt_bhl_lease_direction_1'] = substr($str, 125, 13);
        $data['pmt_bhl_lease_feet_2'] = substr($str, 138, 8);
        $data['pmt_bhl_lease_directon_2'] = substr($str, 146, 13);
        $data['pmt_bhl_survey_feet_1'] = substr($str, 159, 8);
        $data['pmt_bhl_survey_direction_1'] = substr($str, 167, 13);
        $data['pmt_bhl_survey_feet_2'] = substr($str, 180, 8);
        $data['pmt_bhl_survey_direction_2'] = substr($str, 188, 13);
        $data['pmt_bhl_county'] = substr($str, 201, 13);
        $data['pmt_bhl_pntrt_dist_1'] = substr($str, 214, 8);
        $data['pmt_bhl_pntrt_dir_1'] = substr($str, 222, 13);
        $data['pmt_bhl_pntrt_dist_2'] = substr($str, 235, 8);
        $data['pmt_bhl_pntrt_dir_2'] = substr($str, 243, 13);
        $data['filler'] = substr($str, 256, 6);
        $data['rrc_tape_filler'] = substr($str, 262, 45);
    }
    return $data;    
}

//11
function DAALTADD($str) {
    $data = array();
    if ($str != '') {
        $data['rrc_tape_record_id'] = substr($str, 0, 2);
        $data['alt_address_key'] = substr($str, 2, 2);
        $data['alt_address_line_1'] = substr($str, 4, 33);
        $data['alternate_address_2'] = substr($str, 4, 35);
        $data['rrc_tape_filler'] = substr($str, 39, 45);
    }
    return $data;    
    
}

//12
function DAREMARK($str) {
    $data = array();
    if ($str != '') {
        $data['rrc_tape_record_id'] = substr($str, 0, 2);
        $data['remark_sequence_number'] = substr($str, 2, 3);
        $data['remark_file_date'] = substr($str, 5, 8);
        $data['remark_line'] = substr($str, 13, 70);
        $data['filler'] = substr($str, 83, 10);
        $data['rrc_tape_filler'] = substr($str, 93, 45);
    }
    return $data;        
}

//13
function DACHECK($str) {
    $data = array();
    if ($str != '') {
        $data['rrc_tape_record_id'] = substr($str, 0, 2);
        $data['check_register_date'] = substr($str, 2, 8);
        $data['da_check_register_number'] = substr($str, 10, 8);
        $data['filler'] = substr($str, 18, 10);
        $data['rrc_tape_filler'] = substr($str, 28, 45);
    }
    return $data;        
}

//14
function DAW999A1($str) {
    $data = array();
    if ($str != '') {
        $data['surf_loc_longitude'] = substr($str, 2, 13);
        $data['surf_loc_lattitude'] = substr($str, 14, 26);
    }
    return $data;   
    
}

function DAW999B1($str) {
    $data = array();
    if ($str != '') {
        $data['bottom_hole_longitude'] = substr($str, 2, 13);
        $data['bottom_hole_lattitude'] = substr($str, 14, 26);
    }

//    echo 'root_id'.$root_id;
//    print_r($data);
    return $data;       
}




// Add ASCII Data ////////////////////////////////////////////// BEGINS
function permit_root_add($data){     
    try{
        $data = he_utf_conversion($data);
        //print_r($data);   
        $da_app_rcvd_date = NULL;
        $da_issue_date = NULL;
        $da_withdrawn_date = NULL;

        if( $data['da_app_rcvd_month'] != "00" && $data['da_app_rcvd_day']!="00" && $data['da_app_rcvd_century']!="00" && $data['da_app_rcvd_year']!="00" ){
            $da_app_rcvd_date = date('Y-m-d', strtotime( $data['da_app_rcvd_month'].'/'.$data['da_app_rcvd_day'].'/'.$data['da_app_rcvd_century'].$data['da_app_rcvd_year']));
        }
        if( $data['da_issue_month'] != "00" && $data['da_issue_day']!="00" && $data['da_issue_century']!="00" && $data['da_issue_year']!="00" ){
            $da_issue_date = date('Y-m-d', strtotime( $data['da_issue_month'].'/'.$data['da_issue_day'].'/'.$data['da_issue_century'].$data['da_issue_year']));
        }
        if( $data['da_withdrawn_month'] != "00" && $data['da_withdrawn_day']!="00" && $data['da_withdrawn_century']!="00" && $data['da_withdrawn_year']!="00" ){
            $da_withdrawn_date = date('Y-m-d', strtotime( $data['da_withdrawn_month'].'/'.$data['da_withdrawn_day'].'/'.$data['da_withdrawn_century'].$data['da_withdrawn_year']));
        }

        //echo 'ttt:'.$da_withdrawn_date; exit;        
        
        $root_id = db_insert('da_root') 
            ->fields(array(
                'rrc_tape_record_id' => $data['rrc_tape_record_id'],
                'status_number' => $data['status_number'],
                'status_sequence_number' => $data['status_sequence_number'],
                'county_code' => $data['county_code'],
                'lease_name' => $data['lease_name'],
                'district' => $data['district'],
                'operator_number' => $data['operator_number'],
                'converted_date' => $data['converted_date'],
                'da_app_rcvd_century' => $data['da_app_rcvd_century'],
                'da_app_rcvd_year' => $data['da_app_rcvd_year'],
                'da_app_rcvd_month' => $data['da_app_rcvd_month'],
                'da_app_rcvd_day' => $data['da_app_rcvd_day'],
                'da_app_rcvd_date' => $da_app_rcvd_date,
                'operator_name' => $data['operator_name'],
                'filler' => $data['filler'],
                'hb1407_problem_flag' => $data['hb1407_problem_flag'],
                'status_of_app_flag' => $data['status_of_app_flag'],
                'not_enough_money_flag' => $data['not_enough_money_flag'],
                'too_much_money_flag' => $data['too_much_money_flag'],
                'p5_problem_flag' => $data['p5_problem_flag'],
                'p12_problem_flag' => $data['p12_problem_flag'],
                'plat_problem_flag' => $data['plat_problem_flag'],
                'w1a_problem_flag' => $data['w1a_problem_flag'],
                'other_problem_flag' => $data['other_problem_flag'],
                'rule37_problem_flag' => $data['rule37_problem_flag'],
                'rule38_problem_flag' => $data['rule38_problem_flag'],
                'rule39_problem_flag' => $data['rule39_problem_flag'],
                'no_money_flag' => $data['no_money_flag'],
                'permit' => $data['permit'],
                'da_issue_century' => $data['da_issue_century'],
                'da_issue_year' => $data['da_issue_year'],
                'da_issue_month' => $data['da_issue_month'],
                'da_issue_day' => $data['da_issue_day'],
                'da_issue_date' => $da_issue_date,
                'da_withdrawn_century' => $data['da_withdrawn_century'],
                'da_withdrawn_year' => $data['da_withdrawn_year'],
                'da_withdrawn_month' => $data['da_withdrawn_month'],
                'da_withdrawn_day' => $data['da_withdrawn_day'],
                'da_withdrawn_date' => $da_withdrawn_date,
                'walkthrough_flag' => $data['walkthrough_flag'],
                'other_problem_text' => $data['other_problem_text'],
                'well_number' => $data['well_number'],
                'built_from_old_master_flag' => $data['built_from_old_master_flag'],
                'status_renumbered_to' => $data['status_renumbered_to'],
                'status_renumbered_from' => $data['status_renumbered_from'],
                'application_returned_flag' => $data['application_returned_flag'],
                'problem_flag_filler' => $data['problem_flag_filler'],
                'rrc_tape_filler' => $data['rrc_tape_filler'],
            ))
            ->execute();
            return $root_id;       
    }catch (Exception $e){        
        $errordata=array('fun_name'=>__FUNCTION__, 'message'=>$e->getMessage());
        adderrorlog($errordata);
    }
     
}

function permit_master_add($data,$root_id){    // 02 
    try{  
        $data = he_utf_conversion($data);

        $da_received_date = NULL;
        $da_pmt_issued_date = NULL;
        $da_pmt_amended_date = NULL; 
        $da_pmt_extented_date = NULL;   
        $da_pmt_spud_date = NULL;
        $da_pmt_surface_casting_date = NULL;
        $da_received_date = NULL;
        $da_pmt_cancelled_date = NULL;
        $da_pmt_well_status_date = NULL;
        $final_approved_date = NULL;
        if( $data['da_received_month'] != "00" && $data['da_received_day']!="00" && $data['da_received_century']!="00" && $data['da_received_year']!="00" ){
           $da_received_date = date('Y-m-d', strtotime( $data['da_received_month'].'/'.$data['da_received_day'].'/'.$data['da_received_century'].$data['da_received_year'])); 
        }
        if( $data['da_pmt_issued_month'] != "00" && $data['da_pmt_issued_day']!="00" && $data['da_pmt_issued_century']!="00" && $data['da_pmt_issued_year']!="00" ){
            $da_pmt_issued_date = date('Y-m-d', strtotime( $data['da_pmt_issued_month'].'/'.$data['da_pmt_issued_day'].'/'.$data['da_pmt_issued_century'].$data['da_pmt_issued_year']));
        }
        if( $data['da_pmt_amended_month'] != "00" && $data['da_pmt_amended_day']!="00" && $data['da_pmt_amended_century']!="00" && $data['da_pmt_amended_year']!="00" ){
            $da_pmt_amended_date = date('Y-m-d', strtotime( $data['da_pmt_amended_month'].'/'.$data['da_pmt_amended_day'].'/'.$data['da_pmt_amended_century'].$data['da_pmt_amended_year']));
        }
        if( $data['da_pmt_extented_month'] != "00" && $data['da_pmt_extented_day']!="00" && $data['da_pmt_extented_century']!="00" && $data['da_pmt_extented_year']!="00" ){
            $da_pmt_extented_date = date('Y-m-d', strtotime( $data['da_pmt_extented_month'].'/'.$data['da_pmt_extented_day'].'/'.$data['da_pmt_extented_century'].$data['da_pmt_extented_year']));
        }
        if( $data['da_pmt_spud_month'] != "00" && $data['da_pmt_spud_day']!="00" && $data['da_pmt_spud_century']!="00" && $data['da_pmt_spud_year']!="00" ){
            $da_pmt_spud_date = date('Y-m-d', strtotime( $data['da_pmt_spud_month'].'/'.$data['da_pmt_spud_day'].'/'.$data['da_pmt_spud_century'].$data['da_pmt_spud_year']));
        }
        if( $data['da_pmt_surface_casting_month'] != "00" && $data['da_pmt_surface_casting_day']!="00" && $data['da_pmt_surface_casting_century']!="00" && $data['da_pmt_surface_casting_year']!="00" ){
            $da_pmt_surface_casting_date = date('Y-m-d', strtotime( $data['da_pmt_surface_casting_month'].'/'.$data['da_pmt_surface_casting_day'].'/'.$data['da_pmt_surface_casting_century'].$data['da_pmt_surface_casting_year']));
        }
        if( $data['da_pmt_expired_month'] != "00" && $data['da_pmt_expired_day']!="00" && $data['da_pmt_expired_century']!="00" && $data['da_pmt_expired_year']!="00" ){
            $da_pmt_expired_date = date('Y-m-d', strtotime( $data['da_pmt_expired_month'].'/'.$data['da_pmt_expired_day'].'/'.$data['da_pmt_expired_century'].$data['da_pmt_expired_year']));
        }
        if( $data['da_pmt_cancelled_month'] != "00" && $data['da_pmt_cancelled_day']!="00" && $data['da_pmt_cancelled_century']!="00" && $data['da_pmt_cancelled_year']!="00" ){
            $da_pmt_cancelled_date = date('Y-m-d', strtotime( $data['da_pmt_cancelled_month'].'/'.$data['da_pmt_cancelled_day'].'/'.$data['da_pmt_cancelled_century'].$data['da_pmt_cancelled_year']));
        }
        if( $data['da_pmt_well_status_month'] != "00" && $data['da_pmt_well_status_day']!="00" && $data['da_pmt_well_status_century']!="00" && $data['da_pmt_well_status_year']!="00" ){
            $da_pmt_cancelled_date = date('Y-m-d', strtotime( $data['da_pmt_well_status_month'].'/'.$data['da_pmt_well_status_day'].'/'.$data['da_pmt_well_status_century'].$data['da_pmt_well_status_year']));
        }    

        $final_approved_date = (!is_null($da_pmt_amended_date)) ? $da_pmt_amended_date : $da_pmt_issued_date;    
     
        $permit_master_id = db_insert('da_permit_master') 
            ->fields(array(
                'root_id' => $root_id,
                'rrc_tape_record_id' => $data['rrc_tape_record_id'],
                'permit_number' => $data['permit_number'],
                'permit_sequence_number' => $data['permit_sequence_number'],
                'permit_county_code' => $data['permit_county_code'],
                'permit_lease_name' => $data['permit_lease_name'],
                'permit_district' => $data['permit_district'],
                'permit_well_number' => $data['permit_well_number'],
                'permit_total_depth' => $data['permit_total_depth'],
                'permit_operator_number' => $data['permit_operator_number'],
                'type_application' => $data['type_application'],
                'other_explanation' => $data['other_explanation'],
                'address_unique_number' => $data['address_unique_number'],
                'zip_code_prefix' => $data['zip_code_prefix'],
                'zip_code_suffix' => $data['zip_code_suffix'],
                'fiche_set_number' => $data['fiche_set_number'],
                'onshore_county' => $data['onshore_county'],
                'da_received_century' => $data['da_received_century'],
                'da_received_year' => $data['da_received_year'],
                'da_received_month' => $data['da_received_month'],
                'da_received_day' => $data['da_received_day'],
                'da_received_date' => $da_received_date,
                'da_pmt_issued_century' => $data['da_pmt_issued_century'],
                'da_pmt_issued_year' => $data['da_pmt_issued_year'],
                'da_pmt_issued_month' => $data['da_pmt_issued_month'],
                'da_pmt_issued_day' => $data['da_pmt_issued_day'],
                'da_pmt_issued_date' => $da_pmt_issued_date,
                'da_pmt_amended_century' => $data['da_pmt_amended_century'],
                'da_pmt_amended_year' => $data['da_pmt_amended_year'],
                'da_pmt_amended_month' => $data['da_pmt_amended_month'],
                'da_pmt_amended_day' => $data['da_pmt_amended_day'],
                'da_pmt_amended_date' => $da_pmt_amended_date,
                'final_approved_date' => $final_approved_date,
                'da_pmt_extented_century' => $data['da_pmt_extented_century'],
                'da_pmt_extented_year' => $data['da_pmt_extented_year'],
                'da_pmt_extented_month' => $data['da_pmt_extented_month'],
                'da_pmt_extented_day' => $data['da_pmt_extented_day'],
                'da_pmt_extented_date' => $da_pmt_extented_date,
                'da_pmt_spud_century' => $data['da_pmt_spud_century'],
                'da_pmt_spud_year' => $data['da_pmt_spud_year'],
                'da_pmt_spud_month' => $data['da_pmt_spud_month'],
                'da_pmt_spud_day' => $data['da_pmt_spud_day'],
                'da_pmt_spud_date' => $da_pmt_spud_date,
                'da_pmt_surface_casting_century' => $data['da_pmt_surface_casting_century'],
                'da_pmt_surface_casting_year' => $data['da_pmt_surface_casting_year'],
                'da_pmt_surface_casting_month' => $data['da_pmt_surface_casting_month'],
                'da_pmt_surface_casting_day' => $data['da_pmt_surface_casting_day'],
                'da_pmt_surface_casting_date' => $da_pmt_surface_casting_date,
                'well_staus' => $data['well_staus'],
                'da_pmt_well_status_century' => $data['da_pmt_well_status_century'],
                'da_pmt_well_status_year' => $data['da_pmt_well_status_year'],
                'da_pmt_well_status_month' => $data['da_pmt_well_status_month'],
                'da_pmt_well_status_day' => $data['da_pmt_well_status_day'],
                'da_pmt_well_status_date' => $da_pmt_well_status_date,
                'da_pmt_expired_century' => $data['da_pmt_expired_century'],
                'da_pmt_expired_year' => $data['da_pmt_expired_year'],
                'da_pmt_expired_month' => $data['da_pmt_expired_month'],
                'da_pmt_expired_day' => $data['da_pmt_expired_day'],
                'da_pmt_expired_date' => $da_pmt_expired_date,
                'da_pmt_cancelled_century' => $data['da_pmt_cancelled_century'],
                'da_pmt_cancelled_year' => $data['da_pmt_cancelled_year'],
                'da_pmt_cancelled_month' => $data['da_pmt_cancelled_month'],
                'da_pmt_cancelled_day' => $data['da_pmt_cancelled_day'],
                'da_pmt_cancelled_date' => $da_pmt_cancelled_date,
                'cancellation_reason' => $data['cancellation_reason'],                
                'p12_filed_flag' => $data['p12_filed_flag'],
                'substandard_acreage_flag' => $data['substandard_acreage_flag'],
                'rule_36_flag' => $data['rule_36_flag'],
                'h9_flag' => $data['h9_flag'],
                'rule_37_case_number' => $data['rule_37_case_number'],
                'rule_38_docket_number' => $data['rule_38_docket_number'],
                'location_formation_flag' => $data['location_formation_flag'],
                'old_surface_location' => $data['old_surface_location'],
                'old_surface_filler' => $data['old_surface_filler'],
                'new_surface_section' => $data['new_surface_section'],
                'new_surface_block' => $data['new_surface_block'],
                'new_surface_survey' => $data['new_surface_survey'],
                'new_surface_abstract' => $data['new_surface_abstract'],
                'new_surface_filler' => $data['new_surface_filler'],
                'surface_acres' => $data['surface_acres'],
                'surface_miles_from_city' => $data['surface_miles_from_city'],
                'surface_direction_from_city' => $data['surface_direction_from_city'],
                'surface_miles_from_city' => $data['surface_miles_from_city'],
                'surface_direction_from_city' => $data['surface_direction_from_city'],
                'surface_nearest_city' => $data['surface_nearest_city'],
                'surface_lease_feet_1' => $data['surface_lease_feet_1'],
                'surface_lease_direction_1' => $data['surface_lease_direction_1'],
                'surface_lease_feet_2' => $data['surface_lease_feet_2'],
                'surface_lease_direction_2' => $data['surface_lease_direction_2'],
                'surface_survey_feet_1' => $data['surface_survey_feet_1'],
                'surface_survey_direction_1' => $data['surface_survey_direction_1'],
                'surface_survey_feet_2' => $data['surface_survey_feet_2'],
                'surface_survey_dierction_2' => $data['surface_survey_dierction_2'],
                'nearest_well' => $data['nearest_well'],
                'nearest_well_format_flag' => $data['nearest_well_format_flag'],
                'final_update' => $data['final_update'],
                'cancelled_flag' => $data['cancelled_flag'],
                'spud_in_flag' => $data['spud_in_flag'],
                'directional_well_flag' => $data['directional_well_flag'],
                'sidetrack_well_flag' => $data['sidetrack_well_flag'],
                'moved_indicator' => $data['moved_indicator'],
                'permit_conv_issued_date' => $data['permit_conv_issued_date'],
                'rule_37_granted_code' => $data['rule_37_granted_code'],
                'horizontal_well_flag' => $data['horizontal_well_flag'],
                'duplicate_permit_flag' => $data['duplicate_permit_flag'],
                'nearest_lease_line' => $data['nearest_lease_line'],
                'api_number' => $data['api_number'],
                'rrc_tape_filler' => $data['rrc_tape_filler']
            ))
            ->execute();
  
        return $permit_master_id;
    
     }catch (Exception $e){        
        $errordata=array('fun_name'=>__FUNCTION__, 'message'=>$e->getMessage());
        adderrorlog($errordata);
    }
    
}
function field_add($data,$permit_master_id){
    try{
        $data = he_utf_conversion($data);
        $field_id = db_insert('da_field') 
                ->fields(array(
                    'permit_master_id' => $permit_master_id,
                    'rrc_tape_record_id' => $data['rrc_tape_record_id'],
                    'field_number' => $data['field_number'],
                    'field_application_well_code' => $data['field_application_well_code'],
                    'field_completion_well_code' => $data['field_completion_well_code'],
                    'field_completion_code' => $data['field_completion_code'],
                    'field_transfer_code' => $data['field_transfer_code'],
                    'field_validation_date' => $data['field_validation_date'],
                    'field_completion_date' => $data['field_completion_date'],
                    'field_rule37_flag' => $data['field_rule37_flag'],
                    'field_rule38_flag' => $data['field_rule38_flag'],
                    'filler' => $data['filler'],
                    'rrc_tape_filler' => $data['rrc_tape_filler'],
                ))
                ->execute();
        return $field_id;
    }catch(Exception $e){
        $errordata=array('fun_name'=>__FUNCTION__, 'message'=>$e->getMessage());
        adderrorlog($errordata);
    }
}

function field_specific_data_add($data,$field_id){     
    try{
        $data = he_utf_conversion($data);
        //echo 'field_id:'.$field_id.'\n';
        $nid = db_insert('da_field_specific_data') 
            ->fields(array(
                'field_id' => $field_id,
                'rrc_tape_record_id' => $data['rrc_tape_record_id'],
                'field_district' => $data['field_district'],
                'field_lease_name' => $data['field_lease_name'],
                'field_total_depth' => $data['field_total_depth'],
                'field_well_number' => $data['field_well_number'],
                'field_acres' => $data['field_acres'],
                'filler' => $data['filler'],
                'rrc_tape_filler' => $data['rrc_tape_filler'],
            ))
            ->execute();
    }catch(Exception $e){
        $errordata=array('fun_name'=>__FUNCTION__, 'message'=>$e->getMessage());
        adderrorlog($errordata);
    }
}
function field_bhl_add($data,$field_id){
    try{
        $data = he_utf_conversion($data);
        $nid = db_insert('da_field_bottom_hole_location') 
            ->fields(array(
                'field_id' => $field_id,
                'rrc_tape_record_id' => $data['rrc_tape_record_id'],
                'fld_bhl_section' => $data['fld_bhl_section'],
                'fld_bhl_block' => $data['fld_bhl_block'],
                'fld_bhl_abstract' => $data['fld_bhl_abstract'],
                'fld_bhl_survey' => $data['fld_bhl_survey'],
                'fld_bhl_acres' => $data['fld_bhl_acres'],
                'fld_bhl_nearest_well' => $data['fld_bhl_nearest_well'],
                'fld_bhl_lease_feet_1' => $data['fld_bhl_lease_feet_1'],
                'fld_bhl_lease_direction_1' => $data['fld_bhl_lease_direction_1'],
                'fld_bhl_lease_feet_2' => $data['fld_bhl_lease_feet_2'],
                'fld_bhl_lease_direction_2' => $data['fld_bhl_lease_direction_2'],
                'fld_bhl_survey_feet_1' => $data['fld_bhl_survey_feet_1'],
                'fld_bhl_survey_direction_1' => $data['fld_bhl_survey_direction_1'],
                'fld_bhl_survey_feet_2' => $data['fld_bhl_survey_feet_2'],
                'fld_bhl_survey_direction_2' => $data['fld_bhl_survey_direction_2'],
                'fld_bhl_county'=> $data['fld_bhl_county'],
                'fld_bhl_pntrt_dist_1' => $data['fld_bhl_pntrt_dist_1'],
                'fld_bhl_pntrt_dir_1' => $data['fld_bhl_pntrt_dir_1'],
                'fld_bhl_pntrt_dist_2' => $data['fld_bhl_pntrt_dist_2'],
                'fld_bhl_pntrt_dir_2' => $data['fld_bhl_pntrt_dir_2'],
                'filler' => $data['filler'],
                'rrc_tape_filler' => $data['rrc_tape_filler'],
            ))
            ->execute();
    }catch(Exception $e){
        $errordata=array('fun_name'=>__FUNCTION__, 'message'=>$e->getMessage());
        adderrorlog($errordata);
    }
}

function canned_restrictions_add($data,$permit_master_id){      // 06
    try{
        $data = he_utf_conversion($data);
        $canned_restrictions_id = db_insert('da_canned_restrictions') 
                ->fields(array(
                    'permit_master_id' => $permit_master_id,
                    'rrc_tape_record_id' => $data['rrc_tape_record_id'],
                    'can_restr_key' => $data['can_restr_key'],
                    'can_restr_type' => $data['can_restr_type'],
                    'can_restr_remark' => $data['can_restr_remark'],
                ))
                ->execute();
        return $canned_restrictions_id;
    }catch(Exception $e){
        $errordata=array('fun_name'=>__FUNCTION__, 'message'=>$e->getMessage());
        adderrorlog($errordata);
    }
}

function canned_restriction_fields_add($data,$canned_restrictions_id){
    try{
        $data = he_utf_conversion($data);
        $nid = db_insert('da_canned_restriction_fields') 
            ->fields(array(
                'canned_restrictions_id' => $canned_restrictions_id,
                'rrc_tape_record_id' => $data['rrc_tape_record_id'],
                'can_restr_field_number' => $data['can_restr_field_number'],
                'filler' => $data['filler'],
            ))
            ->execute();
    }catch(Exception $e){
        $errordata=array('fun_name'=>__FUNCTION__, 'message'=>$e->getMessage());
        adderrorlog($errordata);
    }
}

function bhl_add($data,$permit_master_id){
    try{
        $data = he_utf_conversion($data);
        $nid = db_insert('da_bottom_hole_location') 
            ->fields(array(
                'permit_master_id' => $permit_master_id,
                'rrc_tape_record_id' => $data['rrc_tape_record_id'],
                'pmt_bhl_section' => $data['pmt_bhl_section'],
                'pmt_bhl_block' => $data['pmt_bhl_block'],
                'pmt_bhl_abstract' => $data['pmt_bhl_abstract'],
                'pmt_bhl_survey' => $data['pmt_bhl_survey'],
                'pmt_bhl_acres' => $data['pmt_bhl_acres'],
                'pmt_bhl_nearest_well' => $data['pmt_bhl_nearest_well'],
                'pmt_bhl_lease_feet_1' => $data['pmt_bhl_lease_feet_1'],
                'pmt_bhl_lease_direction_1' => $data['pmt_bhl_lease_direction_1'],
                'pmt_bhl_lease_feet_2' => $data['pmt_bhl_lease_feet_2'],
                'pmt_bhl_lease_directon_2' => $data['pmt_bhl_lease_directon_2'],
                'pmt_bhl_survey_feet_1' => $data['pmt_bhl_survey_feet_1'],
                'pmt_bhl_survey_direction_1' => $data['pmt_bhl_survey_direction_1'],
                'pmt_bhl_survey_feet_2' => $data['pmt_bhl_survey_feet_2'],
                'pmt_bhl_survey_direction_2' => $data['pmt_bhl_survey_direction_2'],
                'pmt_bhl_county' => $data['pmt_bhl_county'],
                'pmt_bhl_pntrt_dist_1' => $data['pmt_bhl_pntrt_dist_1'],
                'pmt_bhl_pntrt_dir_1' => $data['pmt_bhl_pntrt_dir_1'],
                'pmt_bhl_pntrt_dist_2' => $data['pmt_bhl_pntrt_dist_2'],
                'pmt_bhl_pntrt_dir_2' => $data['pmt_bhl_pntrt_dir_2'],
                'filler' => $data['filler'],
                'rrc_tape_filler' => $data['rrc_tape_filler'],
            ))
            ->execute();
    }catch(Exception $e){
        $errordata=array('fun_name'=>__FUNCTION__, 'message'=>$e->getMessage());
        adderrorlog($errordata);
    }    
}

function free_form_restriction_fields_add($data,$bottom_hole_location_id){      // 09
    try{
        $data = he_utf_conversion($data);
        $nid = db_insert('da_free_form_restriction_fields') 
            ->fields(array(
                'free_form_restrictions_id' => $bottom_hole_location_id,
                'rrc_tape_record_id' => $data['rrc_tape_record_id'],
                'free_restr_fld_number' => $data['free_restr_fld_number'],
                'filler' => $data['filler'],
                'rrc_tape_filler' => $data['rrc_tape_filler'],
            ))
            ->execute();
    }catch(Exception $e){
        $errordata=array('fun_name'=>__FUNCTION__, 'message'=>$e->getMessage());
        adderrorlog($errordata);
    }
}

function alternate_address_add($data,$permit_master_id){    // 11
    try{
        $data = he_utf_conversion($data);
        $nid = db_insert('da_alternate_address') 
            ->fields(array(
                'permit_master_id' => $permit_master_id,
                'rrc_tape_record_id' => $data['rrc_tape_record_id'],
                'alt_address_key' => $data['alt_address_key'],
                'alt_address_line_1' => $data['alt_address_line_1'],
                'alternate_address_2' => $data['alternate_address_2'],
                'rrc_tape_filler' => $data['rrc_tape_filler'],
            ))
            ->execute();
    }catch(Exception $e){
        $errordata=array('fun_name'=>__FUNCTION__, 'message'=>$e->getMessage());
        adderrorlog($errordata);
    }
}
function permit_remarks_add($data,$root_id){    // 12
    try{
        $data = he_utf_conversion($data);
        $nid = db_insert('da_permit_remarks') 
            ->fields(array(
                'root_id' => $root_id,
                'rrc_tape_record_id' => $data['rrc_tape_record_id'],
                'remark_sequence_number' => $data['remark_sequence_number'],
                'remark_file_date' => $data['remark_file_date'],
                'remark_line' => $data['remark_line'],
                'filler' => $data['filler'],
                'rrc_tape_filler' => $data['rrc_tape_filler'],
            ))
            ->execute();
    }catch(Exception $e){
        $errordata=array('fun_name'=>__FUNCTION__, 'message'=>$e->getMessage());
        adderrorlog($errordata);
    }    
}

function check_register_add($data,$root_id){    // 13
    try{
        $data = he_utf_conversion($data);
        $nid = db_insert('da_check_register') 
            ->fields(array(
                'root_id' => $root_id,
                'rrc_tape_record_id' => $data['rrc_tape_record_id'],
                'check_register_date' => $data['check_register_date'],
                'da_check_register_number' => $data['da_check_register_number'],
                'filler' => $data['filler'],
                'rrc_tape_filler' => $data['rrc_tape_filler'],
            ))
            ->execute();
    }catch(Exception $e){
        $errordata=array('fun_name'=>__FUNCTION__, 'message'=>$e->getMessage());
        adderrorlog($errordata);
    }
}
function gis_surface_location_add($data,$root_id){  //  14
    try{
        $data = he_utf_conversion($data);
        $nid = db_insert('da_gis_surface_location_coordinates') 
            ->fields(array(
                'root_id' => $root_id,
                'surf_loc_longitude' => $data['surf_loc_longitude'],
                'surf_loc_lattitude' => $data['surf_loc_lattitude'],
            ))
            ->execute();
    }catch(Exception $e){
        $errordata=array('fun_name'=>__FUNCTION__, 'message'=>$e->getMessage());
        adderrorlog($errordata);
    }
}

function gis_bhl_add($data,$root_id){       // 15
    try {
        $data = he_utf_conversion($data);
        if(isset($data['bottom_hole_longitude']) && isset($data['bottom_hole_lattitude'])){
            $nid = db_insert('da_gis_bottom_hole_location_coordinates') 
                ->fields(array(
                    'root_id' => $root_id,
                    'bottom_hole_longitude' => $data['bottom_hole_longitude'],
                    'bottom_hole_lattitude' => $data['bottom_hole_lattitude'],
                ))
                ->execute();
        }
    }catch (Exception $e) {
        $errordata=array('fun_name'=>__FUNCTION__, 'message'=>$e->getMessage());
        adderrorlog($errordata);
    }
}
// Add ASCII Data ////////////////////////////////////////////// ENDS


// Update ASCII Data //////////////////////////////////////////// BEGINS
function permit_root_update($data,$root_id){
    try{
            $data = he_utf_conversion($data);
            
            $da_app_rcvd_date = NULL;
            $da_issue_date = NULL;
            $da_withdrawn_date =NULL;   

            if( $data['da_app_rcvd_month'] != "00" && $data['da_app_rcvd_day']!="00" && $data['da_app_rcvd_century']!="00" && $data['da_app_rcvd_year']!="00" ){
                $da_app_rcvd_date = date('Y-m-d', strtotime( $data['da_app_rcvd_month'].'/'.$data['da_app_rcvd_day'].'/'.$data['da_app_rcvd_century'].$data['da_app_rcvd_year']));
            }    
            if( $data['da_issue_month'] != "00" && $data['da_issue_day']!="00" && $data['da_issue_century']!="00" && $data['da_issue_year']!="00" ){
                $da_issue_date = date('Y-m-d', strtotime( $data['da_issue_month'].'/'.$data['da_issue_day'].'/'.$data['da_issue_century'].$data['da_issue_year']));
            }
            if( $data['da_withdrawn_month'] != "00" && $data['da_withdrawn_day']!="00" && $data['da_withdrawn_century']!="00" && $data['da_withdrawn_year']!="00" ){
                $da_withdrawn_date = date('Y-m-d', strtotime( $data['da_withdrawn_month'].'/'.$data['da_withdrawn_day'].'/'.$data['da_withdrawn_century'].$data['da_withdrawn_year']));
            }    
    
            $root_updated = db_update('da_root') 
            ->fields(array(
                'rrc_tape_record_id' => $data['rrc_tape_record_id'],
                'status_number' => $data['status_number'],
                'status_sequence_number' => $data['status_sequence_number'],
                'county_code' => $data['county_code'],
                'lease_name' => $data['lease_name'],
                'district' => $data['district'],
                'operator_number' => $data['operator_number'],
                'converted_date' => $data['converted_date'],
                'da_app_rcvd_century' => $data['da_app_rcvd_century'],
                'da_app_rcvd_year' => $data['da_app_rcvd_year'],
                'da_app_rcvd_month' => $data['da_app_rcvd_month'],
                'da_app_rcvd_day' => $data['da_app_rcvd_day'],
                'da_app_rcvd_date' => $da_app_rcvd_date,
                'operator_name' => $data['operator_name'],
                'filler' => $data['filler'],
                'hb1407_problem_flag' => $data['hb1407_problem_flag'],
                'status_of_app_flag' => $data['status_of_app_flag'],
                'not_enough_money_flag' => $data['not_enough_money_flag'],
                'too_much_money_flag' => $data['too_much_money_flag'],
                'p5_problem_flag' => $data['p5_problem_flag'],
                'p12_problem_flag' => $data['p12_problem_flag'],
                'plat_problem_flag' => $data['plat_problem_flag'],
                'w1a_problem_flag' => $data['w1a_problem_flag'],
                'other_problem_flag' => $data['other_problem_flag'],
                'rule37_problem_flag' => $data['rule37_problem_flag'],
                'rule38_problem_flag' => $data['rule38_problem_flag'],
                'rule39_problem_flag' => $data['rule39_problem_flag'],
                'no_money_flag' => $data['no_money_flag'],
                'permit' => $data['permit'],
                'da_issue_century' => $data['da_issue_century'],
                'da_issue_year' => $data['da_issue_year'],
                'da_issue_month' => $data['da_issue_month'],
                'da_issue_day' => $data['da_issue_day'],
                'da_issue_date' => $da_issue_date,
                'da_withdrawn_century' => $data['da_withdrawn_century'],
                'da_withdrawn_year' => $data['da_withdrawn_year'],
                'da_withdrawn_month' => $data['da_withdrawn_month'],
                'da_withdrawn_day' => $data['da_withdrawn_day'],
                'da_withdrawn_date' => $da_withdrawn_date,
                'walkthrough_flag' => $data['walkthrough_flag'],
                'other_problem_text' => $data['other_problem_text'],
                'well_number' => $data['well_number'],
                'built_from_old_master_flag' => $data['built_from_old_master_flag'],
                'status_renumbered_to' => $data['status_renumbered_to'],
                'status_renumbered_from' => $data['status_renumbered_from'],
                'application_returned_flag' => $data['application_returned_flag'],
                'problem_flag_filler' => $data['problem_flag_filler'],
                'rrc_tape_filler' => $data['rrc_tape_filler']
            ))->condition('root_id', $root_id , '=')
            ->execute();              
    }catch (Exception $e){        
        $errordata=array('fun_name'=>__FUNCTION__, 'message'=>$e->getMessage());
        adderrorlog($errordata);
    }
}

function permit_master_update($data,$root_id){     // 02
    try{
        
        $data = he_utf_conversion($data);
        $da_received_date = NULL;
        $da_pmt_issued_date = NULL;
        $da_pmt_amended_date = NULL;    
        $da_pmt_spud_date = NULL;
        $da_pmt_surface_casting_date = NULL;
        $da_received_date = NULL;
        $da_pmt_cancelled_date = NULL;
        $da_pmt_cancelled_date=NULL;
        $final_approved_date=NULL;
        $da_pmt_extented_date = NULL;
        $da_pmt_well_status_date = NULL;
        if( $data['da_received_month'] != "00" && $data['da_received_day']!="00" && $data['da_received_century']!="00" && $data['da_received_year']!="00" ){
           $da_received_date = date('Y-m-d', strtotime( $data['da_received_month'].'/'.$data['da_received_day'].'/'.$data['da_received_century'].$data['da_received_year'])); 
        }
        if( $data['da_pmt_issued_month'] != "00" && $data['da_pmt_issued_day']!="00" && $data['da_pmt_issued_century']!="00" && $data['da_pmt_issued_year']!="00" ){
        $da_pmt_issued_date = date('Y-m-d', strtotime( $data['da_pmt_issued_month'].'/'.$data['da_pmt_issued_day'].'/'.$data['da_pmt_issued_century'].$data['da_pmt_issued_year']));
        }
        if( $data['da_pmt_amended_month'] != "00" && $data['da_pmt_amended_day']!="00" && $data['da_pmt_amended_century']!="00" && $data['da_pmt_amended_year']!="00" ){
        $da_pmt_amended_date = date('Y-m-d', strtotime( $data['da_pmt_amended_month'].'/'.$data['da_pmt_amended_day'].'/'.$data['da_pmt_amended_century'].$data['da_pmt_amended_year']));
        }
        if( $data['da_pmt_extented_month'] != "00" && $data['da_pmt_extented_day']!="00" && $data['da_pmt_extented_century']!="00" && $data['da_pmt_extented_year']!="00" ){
        $da_pmt_extented_date = date('Y-m-d', strtotime( $data['da_pmt_extented_month'].'/'.$data['da_pmt_extented_day'].'/'.$data['da_pmt_extented_century'].$data['da_pmt_extented_year']));
        }
        if( $data['da_pmt_spud_month'] != "00" && $data['da_pmt_spud_day']!="00" && $data['da_pmt_spud_century']!="00" && $data['da_pmt_spud_year']!="00" ){
        $da_pmt_spud_date = date('Y-m-d', strtotime( $data['da_pmt_spud_month'].'/'.$data['da_pmt_spud_day'].'/'.$data['da_pmt_spud_century'].$data['da_pmt_spud_year']));
        }
        if( $data['da_pmt_surface_casting_month'] != "00" && $data['da_pmt_surface_casting_day']!="00" && $data['da_pmt_surface_casting_century']!="00" && $data['da_pmt_surface_casting_year']!="00" ){
        $da_pmt_surface_casting_date = date('Y-m-d', strtotime( $data['da_pmt_surface_casting_month'].'/'.$data['da_pmt_surface_casting_day'].'/'.$data['da_pmt_surface_casting_century'].$data['da_pmt_surface_casting_year']));
        }
        if( $data['da_pmt_expired_month'] != "00" && $data['da_pmt_expired_day']!="00" && $data['da_pmt_expired_century']!="00" && $data['da_pmt_expired_year']!="00" ){
        $da_pmt_expired_date = date('Y-m-d', strtotime( $data['da_pmt_expired_month'].'/'.$data['da_pmt_expired_day'].'/'.$data['da_pmt_expired_century'].$data['da_pmt_expired_year']));
        }
        if( $data['da_pmt_cancelled_month'] != "00" && $data['da_pmt_cancelled_day']!="00" && $data['da_pmt_cancelled_century']!="00" && $data['da_pmt_cancelled_year']!="00" ){
        $da_pmt_cancelled_date = date('Y-m-d', strtotime( $data['da_pmt_cancelled_month'].'/'.$data['da_pmt_cancelled_day'].'/'.$data['da_pmt_cancelled_century'].$data['da_pmt_cancelled_year']));
        }
        if( $data['da_pmt_well_status_month'] != "00" && $data['da_pmt_well_status_day']!="00" && $data['da_pmt_well_status_century']!="00" && $data['da_pmt_well_status_year']!="00" ){
            $da_pmt_cancelled_date = date('Y-m-d', strtotime( $data['da_pmt_well_status_month'].'/'.$data['da_pmt_well_status_day'].'/'.$data['da_pmt_well_status_century'].$data['da_pmt_well_status_year']));
        }
        $final_approved_date = (!is_null($da_pmt_amended_date)) ? $da_pmt_amended_date : $da_pmt_issued_date;
    
    
        $pm_updated = db_update('da_permit_master') 
          ->fields(array(                
              'rrc_tape_record_id' => $data['rrc_tape_record_id'],
              'permit_number' => $data['permit_number'],
              'permit_sequence_number' => $data['permit_sequence_number'],
              'permit_county_code' => $data['permit_county_code'],
              'permit_lease_name' => $data['permit_lease_name'],
              'permit_district' => $data['permit_district'],
              'permit_well_number' => $data['permit_well_number'],
              'permit_total_depth' => $data['permit_total_depth'],
              'permit_operator_number' => $data['permit_operator_number'],
              'type_application' => $data['type_application'],
              'other_explanation' => $data['other_explanation'],
              'address_unique_number' => $data['address_unique_number'],
              'zip_code_prefix' => $data['zip_code_prefix'],
              'zip_code_suffix' => $data['zip_code_suffix'],
              'fiche_set_number' => $data['fiche_set_number'],
              'onshore_county' => $data['onshore_county'],
              'da_received_century' => $data['da_received_century'],
              'da_received_year' => $data['da_received_year'],
              'da_received_month' => $data['da_received_month'],
              'da_received_day' => $data['da_received_day'],
              'da_received_date' => $da_received_date,
              'da_pmt_issued_century' => $data['da_pmt_issued_century'],
              'da_pmt_issued_year' => $data['da_pmt_issued_year'],
              'da_pmt_issued_month' => $data['da_pmt_issued_month'],
              'da_pmt_issued_day' => $data['da_pmt_issued_day'],
              'da_pmt_issued_date' => $da_pmt_issued_date,
              'da_pmt_amended_century' => $data['da_pmt_amended_century'],
              'da_pmt_amended_year' => $data['da_pmt_amended_year'],
              'da_pmt_amended_month' => $data['da_pmt_amended_month'],
              'da_pmt_amended_day' => $data['da_pmt_amended_day'],
              'da_pmt_amended_date' => $da_pmt_amended_date,
              'final_approved_date' => $final_approved_date,
              'da_pmt_extented_century' => $data['da_pmt_extented_century'],
              'da_pmt_extented_year' => $data['da_pmt_extented_year'],
              'da_pmt_extented_month' => $data['da_pmt_extented_month'],
              'da_pmt_extented_day' => $data['da_pmt_extented_day'],
              'da_pmt_extented_date' => $da_pmt_extented_date,
              'da_pmt_spud_century' => $data['da_pmt_spud_century'],
              'da_pmt_spud_year' => $data['da_pmt_spud_year'],
              'da_pmt_spud_month' => $data['da_pmt_spud_month'],
              'da_pmt_spud_day' => $data['da_pmt_spud_day'],
              'da_pmt_spud_date' => $da_pmt_spud_date,
              'da_pmt_surface_casting_century' => $data['da_pmt_surface_casting_century'],
              'da_pmt_surface_casting_year' => $data['da_pmt_surface_casting_year'],
              'da_pmt_surface_casting_month' => $data['da_pmt_surface_casting_month'],
              'da_pmt_surface_casting_day' => $data['da_pmt_surface_casting_day'],
              'da_pmt_surface_casting_date' => $da_pmt_surface_casting_date,
              'well_staus' => $data['well_staus'],
              'da_pmt_well_status_century' => $data['da_pmt_well_status_century'],
              'da_pmt_well_status_year' => $data['da_pmt_well_status_year'],
              'da_pmt_well_status_month' => $data['da_pmt_well_status_month'],
              'da_pmt_well_status_day' => $data['da_pmt_well_status_day'],
              'da_pmt_well_status_date' => $da_pmt_well_status_date,
              'da_pmt_expired_century' => $data['da_pmt_expired_century'],
              'da_pmt_expired_year' => $data['da_pmt_expired_year'],
              'da_pmt_expired_month' => $data['da_pmt_expired_month'],
              'da_pmt_expired_day' => $data['da_pmt_expired_day'],
              'da_pmt_expired_date' => $da_pmt_expired_date,
              'da_pmt_cancelled_century' => $data['da_pmt_cancelled_century'],
              'da_pmt_cancelled_year' => $data['da_pmt_cancelled_year'],
              'da_pmt_cancelled_month' => $data['da_pmt_cancelled_month'],
              'da_pmt_cancelled_day' => $data['da_pmt_cancelled_day'],
              'da_pmt_cancelled_date' => $da_pmt_cancelled_date,
              'cancellation_reason' => $data['cancellation_reason'],                
              'p12_filed_flag' => $data['p12_filed_flag'],
              'substandard_acreage_flag' => $data['substandard_acreage_flag'],
              'rule_36_flag' => $data['rule_36_flag'],
              'h9_flag' => $data['h9_flag'],
              'rule_37_case_number' => $data['rule_37_case_number'],
              'rule_38_docket_number' => $data['rule_38_docket_number'],
              'location_formation_flag' => $data['location_formation_flag'],
              'old_surface_location' => $data['old_surface_location'],
              'old_surface_filler' => $data['old_surface_filler'],
              'new_surface_section' => $data['new_surface_section'],
              'new_surface_block' => $data['new_surface_block'],
              'new_surface_survey' => $data['new_surface_survey'],
              'new_surface_abstract' => $data['new_surface_abstract'],
              'new_surface_filler' => $data['new_surface_filler'],
              'surface_acres' => $data['surface_acres'],
              'surface_miles_from_city' => $data['surface_miles_from_city'],
              'surface_direction_from_city' => $data['surface_direction_from_city'],
              'surface_miles_from_city' => $data['surface_miles_from_city'],
              'surface_direction_from_city' => $data['surface_direction_from_city'],
              'surface_nearest_city' => $data['surface_nearest_city'],
              'surface_lease_feet_1' => $data['surface_lease_feet_1'],
              'surface_lease_direction_1' => $data['surface_lease_direction_1'],
              'surface_lease_feet_2' => $data['surface_lease_feet_2'],
              'surface_lease_direction_2' => $data['surface_lease_direction_2'],
              'surface_survey_feet_1' => $data['surface_survey_feet_1'],
              'surface_survey_direction_1' => $data['surface_survey_direction_1'],
              'surface_survey_feet_2' => $data['surface_survey_feet_2'],
              'surface_survey_dierction_2' => $data['surface_survey_dierction_2'],
              'nearest_well' => $data['nearest_well'],
              'nearest_well_format_flag' => $data['nearest_well_format_flag'],
              'final_update' => $data['final_update'],
              'cancelled_flag' => $data['cancelled_flag'],
              'spud_in_flag' => $data['spud_in_flag'],
              'directional_well_flag' => $data['directional_well_flag'],
              'sidetrack_well_flag' => $data['sidetrack_well_flag'],
              'moved_indicator' => $data['moved_indicator'],
              'permit_conv_issued_date' => $data['permit_conv_issued_date'],
              'rule_37_granted_code' => $data['rule_37_granted_code'],
              'horizontal_well_flag' => $data['horizontal_well_flag'],
              'duplicate_permit_flag' => $data['duplicate_permit_flag'],
              'nearest_lease_line' => $data['nearest_lease_line'],
              'api_number' => $data['api_number'],
              'rrc_tape_filler' => $data['rrc_tape_filler']
          ))->condition('root_id', $root_id , '=')
          ->execute();        
    }catch (Exception $e){        
        $errordata=array('fun_name'=>__FUNCTION__, 'message'=>$e->getMessage());
        adderrorlog($errordata);
    }
}

function field_update($data,$permit_master_id,$field_id){    // 03     
    try{
        $data = he_utf_conversion($data);
        $field_updated = db_update('da_field') 
            ->fields(array(                
                'rrc_tape_record_id' => $data['rrc_tape_record_id'],
                'field_number' => $data['field_number'],
                'field_application_well_code' => $data['field_application_well_code'],
                'field_completion_well_code' => $data['field_completion_well_code'],
                'field_completion_code' => $data['field_completion_code'],
                'field_transfer_code' => $data['field_transfer_code'],
                'field_validation_date' => $data['field_validation_date'],
                'field_completion_date' => $data['field_completion_date'],
                'field_rule37_flag' => $data['field_rule37_flag'],
                'field_rule38_flag' => $data['field_rule38_flag'],
                'filler' => $data['filler'],
                'rrc_tape_filler' => $data['rrc_tape_filler'],
            ))->condition('permit_master_id', $permit_master_id , '=')
            ->condition('field_id', $field_id , '=')
            ->execute();
    }catch(Exception $e){
        $errordata=array('fun_name'=>__FUNCTION__, 'message'=>$e->getMessage());
        adderrorlog($errordata);
    }
}

function canned_restrictions_update($data,$permit_master_id,$canned_restrictions_id){      // 06     
    try{
        $data = he_utf_conversion($data);
        $cr_updated = db_update('da_canned_restrictions') 
            ->fields(array(                
                'rrc_tape_record_id' => $data['rrc_tape_record_id'],
                'can_restr_key' => $data['can_restr_key'],
                'can_restr_type' => $data['can_restr_type'],
                'can_restr_remark' => $data['can_restr_remark'],
            ))->condition('permit_master_id', $permit_master_id , '=')
            ->condition('canned_restrictions_id', $canned_restrictions_id , '=')
            ->execute();
    }catch(Exception $e){
        $errordata=array('fun_name'=>__FUNCTION__, 'message'=>$e->getMessage());
        adderrorlog($errordata);
    }
}

function free_form_restrictions_update($data,$permit_master_id){         
    try{
        $data = he_utf_conversion($data);        
        $ffr_updated = db_update('da_free_form_restrictions')
                ->fields(array(                                                
                    'free_restr_type' => $data['free_restr_type'],
                    'free_restr_remark' => $data['free_restr_remark'],
                    'free_restr_flag' => $data['free_restr_flag'],
                    'filler' => $data['filler'],
                    'rrc_tape_filler' => '' 
                ))
                ->execute();        
    }catch(Exception $e){
        $errordata=array('fun_name'=>__FUNCTION__, 'message'=>$e->getMessage());
        adderrorlog($errordata);
    }
}

function alternate_address_update($data,$permit_master_id){    // 11    
    try{
        $data = he_utf_conversion($data);
        $aa_updated = db_update('da_alternate_address')
            ->fields(array(                
                'rrc_tape_record_id' => $data['rrc_tape_record_id'],
                'alt_address_key' => $data['alt_address_key'],
                'alt_address_line_1' => $data['alt_address_line_1'],
                'alternate_address_2' => $data['alternate_address_2'],
                'rrc_tape_filler' => $data['rrc_tape_filler'],
            ))->condition('permit_master_id', $permit_master_id , '=')
            ->execute();
    }catch(Exception $e){
        $errordata=array('fun_name'=>__FUNCTION__, 'message'=>$e->getMessage());
        adderrorlog($errordata);
    }
}
function permit_remarks_update($data,$root_id){    // 12     
    try{
        $data = he_utf_conversion($data);
        $pr_updated = db_update('da_permit_remarks') 
            ->fields(array(                
                'rrc_tape_record_id' => $data['rrc_tape_record_id'],
                'remark_sequence_number' => $data['remark_sequence_number'],
                'remark_file_date' => $data['remark_file_date'],
                'remark_line' => $data['remark_line'],
                'filler' => $data['filler'],
                'rrc_tape_filler' => $data['rrc_tape_filler'],
            ))->condition('root_id', $root_id , '=')
            ->execute();
    }catch(Exception $e){
        $errordata=array('fun_name'=>__FUNCTION__, 'message'=>$e->getMessage());
        adderrorlog($errordata);
    }
}

function check_register_update($data,$root_id){    // 13     
    try{
        $data = he_utf_conversion($data);
        $cr_updated = db_update('da_check_register') 
            ->fields(array(                
                'rrc_tape_record_id' => $data['rrc_tape_record_id'],
                'check_register_date' => $data['check_register_date'],
                'da_check_register_number' => $data['da_check_register_number'],
                'filler' => $data['filler'],
                'rrc_tape_filler' => $data['rrc_tape_filler'],
            ))->condition('root_id', $root_id , '=')
            ->execute();
    }catch(Exception $e){
        $errordata=array('fun_name'=>__FUNCTION__, 'message'=>$e->getMessage());
        adderrorlog($errordata);
    }
}
function gis_surface_location_update($data,$root_id){  //  14     
    try{
        $data = he_utf_conversion($data);
        $gis_slc_updated = db_update('da_gis_surface_location_coordinates') 
            ->fields(array(                
                'surf_loc_longitude' => $data['surf_loc_longitude'],
                'surf_loc_lattitude' => $data['surf_loc_lattitude'],
            ))->condition('root_id', $root_id , '=')
            ->execute();
    }catch(Exception $e){
        $errordata=array('fun_name'=>__FUNCTION__, 'message'=>$e->getMessage());
        adderrorlog($errordata);
    }
}

function gis_bhl_update($data,$root_id){       // 15     
    try{
        $data = he_utf_conversion($data);
        $gis_bhlc_updated = db_update('da_gis_bottom_hole_location_coordinates') 
            ->fields(array(                
                'bottom_hole_longitude' => $data['bottom_hole_longitude'],
                'bottom_hole_lattitude' => $data['bottom_hole_lattitude'],
            ))->condition('root_id', $root_id , '=')
            ->execute();
    }catch(Exception $e){
        $errordata=array('fun_name'=>__FUNCTION__, 'message'=>$e->getMessage());
        adderrorlog($errordata);
    }
}
// Update ASCII Data //////////////////////////////////////////// ENDS




function get_field_data_by_pmid($permit_master_id ){
    $query = db_select('da_field', 'f');    
    $query->leftJoin('da_field_specific_data', 'fs', 'f.field_id = fs.field_id');
    $query->leftJoin('da_field_bottom_hole_location', 'fbhl', 'f.field_id = fbhl.field_id');
    $query->condition('f.permit_master_id', $permit_master_id, '=');
    $query->fields('f',array('field_id','field_number'));
    $query->fields('fs',array('field_specific_data_id'));
    $query->fields('fbhl',array('field_bottom_hole_location_id'));
    $query->orderBy('f.field_id');
    $result = $query->execute()->fetchAll();
    return $result;
}

function get_canned_data_by_pmid($permit_master_id ){
    $query = db_select('da_canned_restrictions', 'cr');    
    $query->leftJoin('da_canned_restriction_fields', 'crf', 'cr.canned_restrictions_id = crf.canned_restrictions_id');    
    $query->condition('cr.permit_master_id', $permit_master_id, '=');
    $query->fields('cr',array('canned_restrictions_id','can_restr_key'));
    $query->fields('crf',array('canned_restriction_fields_id'));    
    $query->orderBy('cr.canned_restrictions_id');
    $result = $query->execute()->fetchAll();
    return $result;
}


// Delete
function field_and_child_delete($field_id){    // 05 and 04 and 03
    try{
        $field_bhl_deleted = db_delete('da_field_bottom_hole_location')
                        ->condition('field_id', $field_id)
                        ->execute();

        $field_specific_deleted = db_delete('da_field_specific_data')
                        ->condition('field_id', $field_id)
                        ->execute();

        $field_deleted = db_delete('da_field')
                        ->condition('field_id', $field_id)
                        ->execute();
        return $field_deleted;
    }catch(Exception $e){
        $errordata=array('fun_name'=>__FUNCTION__, 'message'=>$e->getMessage());
        adderrorlog($errordata);
    }
}

function field_specific_data_delete($field_id){
    try{
        $field_specific_deleted = db_delete('da_field_specific_data')
                    ->condition('field_id', $field_id)
                    ->execute();    
    }catch(Exception $e){
        $errordata=array('fun_name'=>__FUNCTION__, 'message'=>$e->getMessage());
        adderrorlog($errordata);
    }
}

function field_bhl_delete($field_id){
    try{
        $field_bhl_deleted = db_delete('da_field_bottom_hole_location')
                    ->condition('field_id', $field_id)
                    ->execute();    
    }catch(Exception $e){
        $errordata=array('fun_name'=>__FUNCTION__, 'message'=>$e->getMessage());
        adderrorlog($errordata);
    }
}


function canned_and_child_delete($canned_restrictions_id){    // 07 and 06
    try{
        $crf_deleted = db_delete('da_canned_restriction_fields')
                        ->condition('canned_restrictions_id', $canned_restrictions_id)
                        ->execute();

        $cr_deleted = db_delete('da_canned_restrictions')
                        ->condition('canned_restrictions_id', $canned_restrictions_id)
                        ->execute();

        return $cr_deleted;
    }catch(Exception $e){
        $errordata=array('fun_name'=>__FUNCTION__, 'message'=>$e->getMessage());
        adderrorlog($errordata);
    }
}

function canned_restriction_fields_delete($canned_restrictions_id){
    //print_r($canned_restrictions_id);
    try{
        $crf_deleted = db_delete('da_canned_restriction_fields')
                    ->condition('canned_restrictions_id', $canned_restrictions_id)
                    ->execute();
        return $crf_deleted;
    }catch(Exception $e){
        $errordata=array('fun_name'=>__FUNCTION__, 'message'=>$e->getMessage());
        adderrorlog($errordata);
    }
}

function bhl_delete($permit_master_id){
    try{
        $bhl_deleted = db_delete('da_bottom_hole_location')
                        ->condition('permit_master_id', $permit_master_id)
                        ->execute();
        return $bhl_deleted;
    }catch(Exception $e){
        $errordata=array('fun_name'=>__FUNCTION__, 'message'=>$e->getMessage());
        adderrorlog($errordata);
    }
}

function adderrorlog($data) {
    try{
        $file_id = (isset($GLOBALS['da_proc_file_id']) && $GLOBALS['da_proc_file_id']!='') ? $GLOBALS['da_proc_file_id'] : 0;
        $api_no =  (isset($GLOBALS['da_api_no']) && $GLOBALS['da_api_no']!='') ? $GLOBALS['da_api_no'] : '';
        $id = db_insert('da_error_log')
            ->fields(array(
                'file_id' => $file_id,
                'api_no' => $api_no,
                'fun_name' => $data['fun_name'],
                'message' => $data['message'],
                'updated_on' => date('Y-m-d H:i:s')
            ))
            ->execute();
        return $id;
    } catch (Exception $e){        
        error_log( date('Y-m-d H:i').' : '.$e->getMessage().PHP_EOL , 3 , drupal_get_path('module','ascii_import')."/logs/logtableerr.log");
        $errordata=array('fun_name'=>__FUNCTION__, 'message'=>$e->getMessage());
        adderrorlog($errordata);
    }    
}