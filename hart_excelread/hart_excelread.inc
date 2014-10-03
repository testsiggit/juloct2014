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