<?php

function wellbore_text($directional, $sidetrack, $horizontal) {
    $string = '';
    if ($horizontal == 'N' && $sidetrack == 'N' && $directional == 'Y') {
        $string = 'Directional';
    } else if ($horizontal == 'N' && $sidetrack == 'Y' && $directional == 'Y') {
        $string = 'Directional Sidetrack';
    } else if ($horizontal == 'Y' && $sidetrack == 'N' && $directional == 'N') {
        $string = 'Horizontal';
    } else if ($horizontal == 'Y' && $sidetrack == 'Y' && $directional == 'N') {
        $string = 'Horizontal Sidetrack';
    } else if ($horizontal == 'N' && $sidetrack == 'N' && $directional == 'N') {
        $string = 'Vertical';
    } else if ($horizontal == 'N' && $sidetrack == 'Y' && $directional == 'N') {
        $string = 'Vertical Sidetrack';
    }
    return $string;
}

$show_days = array('3' => 'Last 3 Days', '7' => 'Last 7 Days', '30' => 'Last 30 Days', '100' => 'Last 100 Days', '300' => 'Last 300 Days');
$qstring['show'] = (!isset($qstring['show'])) ? 7 : $qstring['show'];
?>
<script>
    jQuery(document).ready(function($) {
        $('#advsrch_btn').click(function() {
            if ($('#advsrch_div').is(':visible')) {
                $('#advsrch_div').hide();
            } else {
                $('#advsrch_div').show();
                $('#as').val(1);
            }
        });

<?php
if (isset($qstring['as']) && $qstring['as'] == 1) {
    ?>
            $('#advsrch_div').show();
    <?php
}
?>

        $(function() {
            $("#date_start").datepicker({
                defaultDate: "+1w",
                changeMonth: true,
                changeYear: true,
                dateFormat: "mm/dd/yy",
                minDate: new Date(2000, 0, 1),
                maxDate: new Date,
                onClose: function(selectedDate) {
                    $("#date_end").datepicker("option", "minDate", selectedDate);
                }
            });
            $("#date_end").datepicker({
                defaultDate: "+1w",
                changeMonth: true,
                changeYear: true,
                dateFormat: "mm/dd/yy",
                maxDate: new Date,
                onClose: function(selectedDate) {
                    $("#date_end").datepicker("option", "maxDate", selectedDate);
                }
            });
        });


        $(".resetBtn").click(function() {
            $(this).closest('form').find("input[type=text], select").val("");
        });
        
        $('#date_start,#date_end').on('change',  function(){            
            $('#show').val("");
        });
        
        $('#show').on('change', function() {
            $('#date_start,#date_end').val("");             
        });

    });
</script>
<style>

	/* 
	Max width before this PARTICULAR table gets nasty
	This query will take effect for any screen smaller than 760px
	and also iPads specifically.
	*/
	@media 
	only screen and (max-width: 1000px),
	(min-device-width: 1000px) and (max-device-width: 1024px)  {
	
		/* Force table to not be like tables anymore */
		table, thead, tbody, th, td, tr { 
			display: block; 
		}
		
		/* Hide table headers (but not display: none;, for accessibility) */
		thead tr { 
			position: absolute;
			top: -9999px;
			left: -9999px;
		}
		
		tr { border: 1px solid #ccc; }
		
		td { 
			/* Behave  like a "row" */
			border: none;
			border-bottom: 1px solid #eee; 
			position: relative;
			padding-left: 50%; 
		}
		
		td:before { 
			/* Now like a table header */
			position: absolute;
			/* Top/left values mimic padding */
			top: 6px;
			left: 6px;
			width: 45%; 
			padding-right: 10px; 
			white-space: nowrap;
		}
		
		/*
		Label the data
		*/
		td:nth-of-type(1):before { content: "API No."; }
		td:nth-of-type(2):before { content: "District"; }
		td:nth-of-type(3):before { content: "Lease"; }
		td:nth-of-type(4):before { content: "Well Number"; }
		td:nth-of-type(5):before { content: "Permitted Operator"; }
		td:nth-of-type(6):before { content: "County"; }
		td:nth-of-type(7):before { content: "Status Date"; }
		td:nth-of-type(8):before { content: "Status Number"; }
		td:nth-of-type(9):before { content: "Wellbore Profiles"; }
		td:nth-of-type(10):before { content: "Filling Purpose"; }
                td:nth-of-type(11):before { content: "Amend"; }
		td:nth-of-type(12):before { content: "Total Depth"; }
		td:nth-of-type(13):before { content: "Status"; }
               
	}


	/* Smartphones (portrait and landscape) ----------- */
	@media only screen
	and (min-device-width : 320px)
	and (max-device-width : 480px) {
		body { 
			padding: 0; 
			margin: 0; 
			width: 320px; }
		}
	
	/* iPads (portrait and landscape) ----------- */
	@media only screen and (min-device-width: 768px) and (max-device-width: 1024px) {
		body { 
			width: 495px; 
		}
	}
	
    
    

</style>
<script>
function isNumberKey(evt){
    var charCode = (evt.which) ? evt.which : event.keyCode
    if (charCode > 31 && (charCode < 48 || charCode > 57))
        return false;
    return true;
}   
</script>
<div id="manage-alerts"><a href="email-alert-config" class="btn btn-primary"><i class="fa fa-bell"></i> Manage Alerts</a></div>
<?php
if(isset($_GET['easrch'])){
    $sent_email_id = base64_decode($_GET['easrch']);
    $email_alert_qry = "SELECT ua.alert_name, count(ema.id) AS matching_api FROM `ea_saving_sent_emails` sse join ea_user_alerts ua on sse.alert_id=ua.alert_id "
            . "join ea_email_matching_apis ema on sse.id=ema.sent_email_id WHERE sse.id = :SENT_EMAIL_ID group by ema.sent_email_id ";
    $alres = db_query($email_alert_qry, array(':SENT_EMAIL_ID' => $sent_email_id));
    $alinfo = $alres->fetch();
    
    if($alinfo){
        echo '<div style="margin:15px 0;font-weight:bold;">There were '.$alinfo->matching_api.' permits release that matched your alert "'.$alinfo->alert_name.'".</div>';
    }    
}
?>   
<div id="map" style="height:500px;width:100%;"></div>
<div id="pageWrapper">    
    <div id="contentWrapper">
        <div id="content">

            <form method="GET" action="">
                <input type="hidden" name="as" id="as" value="<?php echo (isset($qstring['as']) && $qstring['as'] != '') ? $qstring['as'] : 0 ?>" />    
                <div class="subSection">
                    <table bordercolor="#FF0000" cellpadding="2">
                        <tr>
                        <div class="form_box_sec">
                        	<div class="row">
                            <div class="form-group col-sm-3">
                                <label>Play</label>
                               <select class="form-control" name="play">
                                        <option value="">Select Play</option>
                                         <?php
                                        foreach ($play_list as $plays) {
                                            if (isset($qstring['play']) && $qstring['play'] == $plays->play) {
                                                echo '<option value="' . $plays->play . '" selected="selected">' . $plays->play . '</option>';
                                            } else {
                                                echo '<option value="' . $plays->play . '">' . $plays->play . '</option>';
                                            }
                                        }
                                        ?>   
                                    </select> 
                            </div>   
                            <div class="form-group col-sm-3">
                                <label>County</label>
                                <select class="form-control" name="cty" id="county">
                                        <option value="">Select County</option>
                                        <?php
                                        foreach ($counties as $county) {
                                            if (isset($qstring['cty']) && $qstring['cty'] == $county->county_code) {
                                                echo '<option value="' . $county->county_code . '" selected="selected">' . $county->county_name . '</option>';
                                            } else {
                                                echo '<option value="' . $county->county_code . '">' . $county->county_name . '</option>';
                                            }
                                        }
                                        ?>                                        
                                    </select> 
                            </div>   
                            <div class="form-group col-sm-3">
                                <label>Wellbore Profile</label>
                                <select class="form-control" name="wt1">
                                        <option value="">Select Wellbore Profile</option>
                                        <?php
                                        foreach ($well_type_flag as $wtflag => $wtdesc) {
                                            if (isset($qstring['wt1']) && $qstring['wt1'] == $wtflag) {
                                                echo '<option value="' . $wtflag . '" selected="selected">' . $wtdesc . '</option>';
                                            } else {
                                                echo '<option value="' . $wtflag . '">' . $wtdesc . '</option>';
                                            }
                                        }
                                        ?> 
                                    </select>
                            </div>   
                            <div class="form-group col-sm-3">
                                <label>Operator</label>
                                <input type="text" class="form-control" name="op" value="<?php echo (isset($qstring['op']) && $qstring['op'] != '') ? $qstring['op'] : '' ?>" />
                            </div>
                        	</div>
                        	<div class="row"> 
                            <div class="form-group col-sm-3">
                                <label>API #</label>
                              <input type="text" class="form-control" name="api" value="<?php echo (isset($qstring['api']) && $qstring['api'] != '') ? $qstring['api'] : '' ?>" maxlength="8"/> 
                            </div> 
                            <div class="form-group col-sm-6 col-lg-3">
                                <label>Approved Date</label>
                                	<div class="row">
                                		<div class="col-sm-6">
                                <input class="resizedDatebox form-control" type="text" name="fd" id="date_start" value="<?php echo (isset($qstring['fd']) && $qstring['fd'] != '') ? $qstring['fd'] : '' ?>" placeholder="From" autocomplete="off" maxlength="10"/></div>
                                <div class="col-sm-6"><input class="resizedDatebox form-control" type="text" name="td" id="date_end" value="<?php echo (isset($qstring['td']) && $qstring['td'] != '') ? $qstring['td'] : '' ?>" placeholder="To" autocomplete="off" maxlength="10"/> </div>
                                	</div>
                            </div> 
                            <div class="form-group col-sm-3">
                                <label>Show</label>
                                <select class="form-control" name="show" id="show">   
                                        <option value="">Show All</option>
                                        <?php
                                        foreach ($show_days as $d => $dtext) {
                                            if (isset($qstring['show']) && $qstring['show'] == $d) {
                                                echo '<option value="' . $d . '" selected="selected">' . $dtext . '</option>';
                                            } else {
                                                echo '<option value="' . $d . '">' . $dtext . '</option>';
                                            }
                                        }
                                        ?> 
                                    </select>
                            </div> 
                        	</div>

                            <div class="hr"></div>
                            <div class="adv_for">
                                <div style="float: right">                                    
                                    <a href="javascript:void(0)" id="advsrch_btn" class="adv_btn">Advanced Search </a>                                    
                                </div>
                                <div style="clear:both;"></div>

                                <div id="advsrch_div" name="police_response1" style="display:none; ">
                                	<div class="row">
	                                    <div class="form-group col-sm-6 col-lg-3">
                                        <label>Total Depth</label>
                                        	<div class="row">
                                        		<div class="col-sm-6">
													<input type="text" class="form-control" name="minr" value="<?php echo (isset($qstring['minr']) && $qstring['minr'] != '') ? $qstring['minr'] : '' ?>" maxlength="5" class="resizedTextbox" placeholder="Min" onkeypress="return isNumberKey(event)" />
                                        		</div>
                                        		<div class="col-sm-6">
													<input type="text" class="form-control" name="maxr" value="<?php echo (isset($qstring['maxr']) && $qstring['maxr'] != '') ? $qstring['maxr'] : '' ?>" maxlength="5" class="resizedTextbox" placeholder="Max" onkeypress="return isNumberKey(event)" />
                                        		</div>
                                        	</div>
                                    </div>                                        
	                                    <div class="form-group col-sm-3">
                                        <label> Filling Purpose</label>
                                        <select class="form-control" name="fp">
                                                <option value="">Select Filling Purpose</option>
                                                <?php
                                                foreach ($fillingpurposes as $fp) {
                                                    if (isset($qstring['fp']) && $qstring['fp'] == $fp->code) {
                                                        echo '<option value="' . $fp->code . '" selected="selected">' . $fp->description . '</option>';
                                                    } else {
                                                        echo '<option value="' . $fp->code . '">' . $fp->description . '</option>';
                                                    }
                                                }
                                                ?>  
                                            </select>  
                                    </div>   
	                                    <div class="form-group col-sm-3">
                                        <label> Well Type</label>
                                        <select class="form-control" name="wt2" id="well_type">
                                                <option value="">Select Well type</option>
                                                <?php
                                                foreach ($welltypes as $wt) {
                                                    if (isset($qstring['wt2']) && $qstring['wt2'] == $wt->code) {
                                                        echo '<option value="' . $wt->code . '" selected="selected">' . $wt->description . '</option>';
                                                    } else {
                                                        echo '<option value="' . $wt->code . '">' . $wt->description . '</option>';
                                                    }
                                                }
                                                ?>  
                                            </select> 
                                    </div> 
	                                    <div class="form-group col-sm-3">
                                        <label>District</label>
                                        <select class="form-control" name="dis" id="district">
                                                <option value="">Select District</option>
                                                <?php
                                                foreach ($districts as $dist) {
                                                    if (isset($qstring['dis']) && $qstring['dis'] == $dist->district_code) {
                                                        echo '<option value="' . $dist->district_code . '" selected="selected">' . $dist->district_name . '</option>';
                                                    } else {
                                                        echo '<option value="' . $dist->district_code . '">' . $dist->district_name . '</option>';
                                                    }
                                                }
                                                ?>                                        
                                            </select> 
                                    </div>
	                                    <div class="form-group col-sm-3">
                                        <label>Section</label>
                                        <input type="text" class="form-control" name="sec" value="<?php echo (isset($qstring['sec']) && $qstring['sec'] != '') ? $qstring['sec'] : '' ?>" />
                                    </div>    
                                	</div>                                
                                </div> 
                                <div><div class="form-group">
                                        <button type="submit" class="btn btn-primary" value="Submit">Submit</button>&nbsp;<button type="rest" class="resetBtn btn btn-default" value="Reset" style="cursor:pointer;">Reset</button>
                                    </div></div>
                            </div>
                        </div>
                        </tr>
                    </table>                    
                </div>
            </form>    

        </div> 
        
        <div id="permit-list">
            <?php
            $play_res = array();
            if (isset($qstring['play']) && $qstring['play'] != '') {
                $q2 = db_select('dp_play','p');
                $q2->fields('p');
                $q2->condition('p.play', trim($qstring['play']), '=');
                $play_res = $q2->execute()->fetchAll();
            }
            ?>
            <?php
            $query = db_select('da_root', 't1');
            $query->join("da_permit_master", "t2", "t1.root_id = t2.root_id");
            $query->join("da_field", "t3", "t2.permit_master_id = t3.permit_master_id");
            $query->leftJoin("da_field_bottom_hole_location", "t5", "t3.field_id = t5.field_id");
            $query->leftJoin("da_free_form_restrictions", "t8", "t2.permit_master_id = t8.permit_master_id");
            $query->join("da_gis_surface_location_coordinates", "t14", "t1.root_id = t14.root_id");
            $query->join("da_gis_bottom_hole_location_coordinates", "t15", "t1.root_id = t15.root_id");
            $query->leftJoin("dp_district", "district", "t1.district = district.district_code");
            $query->leftJoin("dp_county", "county", "t1.county_code = county.county_code");
            $query->leftJoin("dp_status_of_app_flag", "appstatus", "t1.status_of_app_flag = appstatus.status_code");
            $query->leftJoin("dp_filling_purpose", "fp", "t2.type_application = fp.code");            
            $query->fields('t1', array('root_id', 'lease_name', 'operator_name', 'well_number', 'status_number','da_app_rcvd_date','da_issue_date'))
                    ->fields('t2', array('permit_master_id', 'da_received_date', 'da_pmt_issued_date','da_pmt_amended_date','final_approved_date',
                        'api_number', 'permit_total_depth', 'type_application', 'directional_well_flag', 'sidetrack_well_flag', 'horizontal_well_flag'))
                    ->fields('t8', array('free_form_restrictions_id', 'free_restr_remark'))
                    ->fields('t14', array('surf_loc_longitude', 'surf_loc_lattitude'))
                    ->fields('t15', array('bottom_hole_longitude', 'bottom_hole_lattitude'))
                    ->fields('district', array('district_name'))
                    ->fields('county', array('county_name'))
                    ->fields('appstatus', array('status_name'))
                    ->fields('fp', array('description'));
            
            if (isset($qstring['easrch']) && $qstring['easrch'] != '' ) { 
                $sent_email_id = base64_decode($qstring['easrch']);
                //$sent_email_id = $qstring['easrch'];
                $query->join("ea_email_matching_apis", "ema", "(t1.status_number=ema.status_number AND t1.status_sequence_number=ema.sequence_number AND t2.api_number = ema.api_number )");
                $query->where('ema.sent_email_id = '.$sent_email_id);     
            }
            
            if (isset($qstring['play']) && $qstring['play'] != '' && count($play_res)>0 ) { 
                $play_county = array();
                $play_district = array();
                
                foreach($play_res as $prow){       
                    $play_county[] = $prow->county_code;
                    $play_district[] = $prow->district_code;                                         
                }   
                
                $query->condition('t1.county_code', $play_county , 'IN');
                $query->condition('t1.district', $play_district , 'IN');                    
            } 
            
            if ($qstring['show'] != '') {
                if ( (isset($qstring['fd']) && $qstring['fd'] == '' && isset($qstring['td']) && $qstring['td'] == '') || !isset($qstring['easrch']) ) {
                    $query->where('t2.final_approved_date >= DATE_SUB(NOW(), INTERVAL ' . $qstring['show'] . ' DAY)');                        
                }                
            }
            if (isset($qstring['cty']) && $qstring['cty'] != '') {
                $query->condition('t1.county_code', trim($qstring['cty']), '=');
            }
            if (isset($qstring['op']) && $qstring['op'] != '') {
                $query->condition('t1.operator_name', trim($qstring['op'] . '%'), 'LIKE');
            }
            if (isset($qstring['dis']) && $qstring['dis'] != '') {
                $query->condition('t1.district', trim($qstring['dis']), '=');
            }
            if (isset($qstring['wt1']) && $qstring['wt1'] != '') {
                $query->condition('t2.horizontal_well_flag', trim($qstring['wt1']), '=');
            }
            if (isset($qstring['api']) && $qstring['api'] != '') {
                $query->condition('t2.api_number', trim($qstring['api']), '=');
            }

            if (isset($qstring['fd']) && $qstring['fd'] != '' && isset($qstring['td']) && $qstring['td'] != '') {
                $from_date = date('Y-m-d', strtotime($qstring['fd']));
                $to_date = date('Y-m-d', strtotime($qstring['td']));
                $query->condition('t2.final_approved_date', array($from_date, $to_date), 'BETWEEN');
            }
            if (isset($qstring['minr']) && $qstring['minr'] != '' && isset($qstring['maxr']) && $qstring['maxr'] != '') {
                $query->condition('t2.permit_total_depth', array($qstring['minr'], $qstring['maxr']), 'BETWEEN');
            }
            if (isset($qstring['fp']) && $qstring['fp'] != '') {
                $query->condition('t2.type_application', trim($qstring['fp']), '=');
            }
            if (isset($qstring['wt2']) && $qstring['wt2'] != '') {
                $query->condition('t3.field_application_well_code', trim($qstring['wt2']), '=');
            }
            if (isset($qstring['sec']) && $qstring['sec'] != '') {
                $query->condition('t5.fld_bhl_section', trim($qstring['sec']), '=');
            }
            $query->orderBy('t2.final_approved_date', 'DESC');
            $query->groupBy('t1.root_id');

//print_r($query->__toString()); echo '\n-------------\n'; print_r($query->arguments()); 

            $result = $query->extend('PagerDefault')->element(0)->limit(20)->execute();

            $number_of_rows = $result->rowCount();


            $args = array('parameters' => array('ps' => 'da_permit_master', 'pv' => 0), 'element' => 0);



            $js_locs = '';
            if ($number_of_rows > 0) {

                /*if (count($qstring) > 0) {

                    $qs = http_build_query($qstring);
                    //echo $qs;
                    $test = str_replace('q=drilling_permit', '', $qs);
                    // echo $test;
                    echo '<div><a href="drilling_permit_download?' . $test . '">Download</a></div>';
                } else {
                    echo '<div><a href="drilling_permit_download">Download</a></div>';
                }*/

                foreach ($result as $row) {
                    $test = $row;

                    echo '<div>';

                    $submitted = date('m/d/Y', strtotime($row->da_received_date));
//                    if($row->da_pmt_amended_date!=''){
//                        $approved = date('m/d/Y', strtotime($row->da_pmt_amended_date));
//                    }else{
//                        $approved = date('m/d/Y', strtotime($row->da_pmt_issued_date));
//                    }
                    $approved = date('m/d/Y', strtotime($row->final_approved_date));
                    

                    $wellbore = '';
                    $wellbore = wellbore_text($row->directional_well_flag, $row->sidetrack_well_flag, $row->horizontal_well_flag);
                    ?>
                    <h4><a href="dpdetails/<?php echo $row->api_number ?>/<?php echo $row->status_number ?>"><?php echo $row->operator_name ?></a>-<span class="submitdate"><?php echo $approved ?></span></h4>
                    <div>
                
                <table class="table table-responsive table-striped dplist">
                        <thead>
                            <tr>
                                <th class="rowhead" style="width:90px;">API No.</th>
                                <th class="rowhead" style="width:60px;">District</th>
                                <th class="rowhead" style="width:90px;">Lease</th>
                                <th class="rowhead" style="width:70px;">Well Number</th>
                                <th class="rowhead" style="width:110px;">Permitted Operator</th>
                                <th class="rowhead" style="width:80px;">County</th>
                                <th class="rowhead" style="width:150px;">Status Date</th>
                                <th class="rowhead" style="width:80px;">Status Number</th>
                                <th class="rowhead" style="width:75px;">Wellbore Profiles</th>
                                <th class="rowhead" style="width:70px;">Filling Purpose</th>
                                <th class="rowhead" style="width:65px;">Amend</th>
                                <th class="rowhead" style="width:75px;">Total Depth</th>
                                <th class="rowhead" style="width:100px;">Status</th>
                            </tr>
                    </thead>
		<tbody>
                    <tr>
                        <td class="rowbtm" style="width:90px;"><?php print $row->api_number; ?></td>
                        <td class="rowbtm" style="width:60px;"><?php print $row->district_name ?></td>
                                <td class="rowbtm" style="width:90px;"><?php print $row->lease_name ?></td>
                                <td class="rowbtm" style="width:70px;"><?php print $row->well_number ?></td><td class="rowbtm" style="width:110px;"><?php print $row->operator_name ?></td>
                                <td class="rowbtm" style="width:80px;"><?php print $row->county_name ?></td>
                                <td class="rowbtm" style="width:150px;"><?php echo nl2br("Submitted:$submitted\nApproved:$approved"); ?></td>
                                <td class="rowbtm" style="width:80px;"><?php print $row->status_number ?></td>
                                <td class="rowbtm" style="width:75px;"><?php print $wellbore ?></td><td class="rowbtm" style="width:70px;"><?php print $row->description ?></td>
                                <td class="rowbtm" style="width:65px;"><?php echo ($row->type_application == '06') ? 'Y' : 'N'; ?></td><td class="rowbtm" style="width:75px;"><?php print $row->permit_total_depth ?></td>
                                <td class="rowbtm" style="width:100px;"><?php print $row->status_name ?></td>

                    </tr>
                </tbody>
            </table>
                    </div>            
                    <?php
                    $marker_tooltip = '<div>' . trim($row->operator_name) . '</div>';
                    //<div><strong>API:</strong>'.trim($row->api_number).'</div><div><strong>Status:</strong>'.trim($row->status_number).'</div>';

                    $js_locs .= '["' . $marker_tooltip . '",' . $row->surf_loc_lattitude . ',' . $row->surf_loc_longitude . '],';

                    echo '</div>';
                }
            } else {
                echo '<div>No Results</div>';
            }

            print theme('pager', $args);

            //echo $js_locs;
            ?>
        </div>
        <script type="text/javascript">
            function initialize() {
                var locations = [<?php echo $js_locs; ?>];

                window.map = new google.maps.Map(document.getElementById('map'), {
                    mapTypeId: google.maps.MapTypeId.ROADMAP
                });

                var infowindow = new google.maps.InfoWindow({
                    maxWidth: 300
                });

                var bounds = new google.maps.LatLngBounds();

                for (i = 0; i < locations.length; i++) {
                    marker = new google.maps.Marker({
                        position: new google.maps.LatLng(locations[i][1], locations[i][2]),
                        map: map
                    });

                    bounds.extend(marker.position);

                    google.maps.event.addListener(marker, 'click', (function(marker, i) {
                        return function() {
                            infowindow.setContent(locations[i][0]);
                            infowindow.open(map, marker);
                        }
                    })(marker, i));
                }

                map.fitBounds(bounds);


//                var listener = google.maps.event.addListener(map, "idle", function () {
//                    map.setZoom(4);
//                    google.maps.event.removeListener(listener);
//                });


            }

            function loadScript() {
                var script = document.createElement('script');
                script.type = 'text/javascript';
                script.src = 'https://maps.googleapis.com/maps/api/js?v=3.exp&sensor=false&' + 'callback=initialize';
                document.body.appendChild(script);
            }

            window.onload = loadScript;
        </script>
    </div>
</div>
