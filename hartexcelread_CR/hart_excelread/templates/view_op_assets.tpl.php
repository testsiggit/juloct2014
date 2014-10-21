<style>
.rowhead{font-weight: bold;}
</style>
<script>
<?php global $base_url; ?>
jQuery(document).ready(function($) {        
    $('#comp').on('change',  function(){            
        if($('#play').length>0){
            $('#play').val('');
            
            var request = $.ajax({
                url: "<?php print $base_url ?>/get-comp-plays/",
                type: "POST",
                data: { cid : $(this).val() }                
            });
            request.done(function( msg ) {
                $('#playdiv').html(msg);
            });
            request.fail(function( jqXHR, textStatus ) {
                console.log( "Request failed: " + textStatus );
            });          
            
        }
    });
});
</script>
<div class="row">
    <?php if(is_array($companies) && count($companies)>0){ ?>  
    <form id="oaview" method="get">
        
        <div class="col-sm-6">           
            <div class="plc"><label>Company</label> <?php print l('Add New Company','add-new-company',array('attributes' => array('target' => '_blank'))); ?></div>
            <div>
                <select class="form-control slt" name="c" id="comp" style="">
                    <option value="">Select Company</option>
                    <?php
                    foreach ($companies as $comp) {
                        if (isset($qstring['c']) && $qstring['c'] == $comp->company_id) {
                            echo '<option value="' . $comp->company_id . '" selected="selected">' . $comp->company_name . '</option>';
                        } else {
                            echo '<option value="' . $comp->company_id . '">' . $comp->company_name . '</option>';
                        }
                    }
                    ?>   
                </select>
            </div>
        </div>        
        
        <div class="col-sm-6">            
            <div class="plc"><label>Play</label> <?php print l('Add New Play','add-new-play',array('attributes' => array('target' => '_blank'))); ?></div>
            <?php if(count($comp_plays)>0){ ?>
            <div id="playdiv">
                <select class="form-control slt" name="p" id="play" style="">
                    <option value="">Select Play</option>
                    <?php
                    foreach ($comp_plays as $play) {
                        if (isset($qstring['p']) && $qstring['p'] == $play->play_id) {
                            echo '<option value="' . $play->play_id . '" selected="selected">' . $play->play_name . '</option>';
                        } else {
                            echo '<option value="' . $play->play_id . '">' . $play->play_name . '</option>';
                        }
                    }
                    ?>   
                </select>
            </div>
            <?php } ?>
        </div>
        
        <div class="col-sm-12 plc">
            <input type="submit" name="submit" value="Submit" class="btn btn-primary"/>            
        </div>
        
    </form>
    <?php }else{ ?>
    <div>No Result. <?php print l('Click here','oa-upload'); ?> to upload operator assets data.</div>
    <div>OR</div>
    <div>
        <ul>
            <li><?php print l('Add New Company','add-new-company',array('attributes' => array('target' => '_blank'))); ?></li>
            <li><?php print l('Add New Play','add-new-play',array('attributes' => array('target' => '_blank'))); ?></li>
        </ul>
    </div>
    <?php } ?>
        
        <?php if(count($comp_details)>0){ 
            
//            print_r($comp_details);
            
            $compdet = $comp_details;
            
            ?>
        <div class="col-md-12">
            <div class="plc"><label>Company Details</label> <?php print l('Edit','edit-company/'.$compdet->company_id,array('attributes' => array('target' => '_blank'))) ?> | <?php print l('Add Company Annual Report','add-company-annual-report/'.$compdet->company_id,array('attributes' => array('target' => '_blank'))); ?> | <?php print l('Add Company Quarter Report','add-company-quarter-report/'.$compdet->company_id,array('attributes' => array('target' => '_blank'))); ?> | <?php print l('Add Company Annual Capex','add-company-annual-capex/'.$compdet->company_id,array('attributes' => array('target' => '_blank'))) ?> | <?php print l('Add Company Annual Ebidax','add-company-annual-ebidax/'.$compdet->company_id,array('attributes' => array('target' => '_blank'))) ?></div>
            <div class="table-responsive">
                <table class="table table-bordered table-striped dplist">
                        <thead>
                            <tr>
                                <td class="rowhead" style="width:90px;">Ticker</td>
                                <td class="rowhead" style="width:60px;">Exchange</td>
                                <td class="rowhead" style="width:90px;">Production</td>
                                <td class="rowhead" style="width:70px;">Acreage</td>
                                <td class="rowhead" style="width:110px;">Reserves</td>
                                <td class="rowhead" style="width:80px;">Wells Drilled</td>
                                <td class="rowhead" style="width:150px;">Other</td>
                                <td class="rowhead" style="width:80px;">Updated On</td>  
                            </tr>
                    </thead>
                    <tbody>
                    <tr>
                        <td class="rowbtm" style="width:90px;"><?php print $compdet->ticker; ?></td>
                        <td class="rowbtm" style="width:60px;"><?php print $compdet->exchange ?></td>
                        <td class="rowbtm" style="width:90px;"><?php print $compdet->production ?></td>
                        <td class="rowbtm" style="width:70px;"><?php print $compdet->acreage ?></td>
                        <td class="rowbtm" style="width:110px;"><?php print $compdet->reserves ?></td>
                        <td class="rowbtm" style="width:80px;"><?php print $compdet->wells_drilled ?></td>                        
                        <td class="rowbtm" style="width:80px;"><?php print $compdet->other_comments ?></td>                        
                        <td class="rowbtm" style="width:100px;"><?php echo ($compdet->updated_on!='') ? date('m/d/Y',strtotime($compdet->updated_on)) : ''; ?></td>
                    </tr>
                </tbody>
		
            </table>
            </div>    
        </div>    
        <?php } ?>
        
        
        <?php if(count($comp_ann_rep)>0){ //print_r($comp_ann_rep); ?>
        <div class="col-md-12">
            <div class="plc"><label>Company Annual Report</label></div>
            <div class="table-responsive">
                <table class="table table-bordered table-striped dplist">
                        <thead>
                            <tr>
                                <td class="rowhead">Year</td>
                                <td class="rowhead">Report Url</td> 
                                <td class="rowhead">Action</td> 
                            </tr>
                    </thead>
                    <tbody>               
                    <?php
                        foreach($comp_ann_rep as $car){
                            $repurl = ($car->report_url!='') ? l($car->report_url,$car->report_url,array('attributes'=>array('target'=>'_blank'))) : '';
                            echo '<tr>
                                    <td class="rowbtm">'.$car->year.'</td>
                                    <td class="rowbtm">'.$repurl.'</td>   
                                    <td class="rowbtm">'.l('Edit','edit-company-annual-report/'.$car->annual_report_id,array('attributes' => array('target' => '_blank'))).' | '.l('Delete','del-company-annual-report/'.$car->annual_report_id,array('attributes' => array('onclick' => 'return confirm("Are you sure?")'))).'</td>       
                                </tr>';
                        }
                        ?>
                      </tbody>
            </table>
            </div>    
        </div>       
        <?php } ?>                
                        
                        
        <?php if(count($comp_quar_rep)>0){ //print_r($comp_quar_rep); ?>
        <div class="col-md-12">
            <div class="plc"><label>Company Quarter Report</label></div>
            <div class="table-responsive">
                <table class="table table-bordered table-striped dplist">
                        <thead>
                            <tr>
                                <td class="rowhead">Quarter</td>
                                <td class="rowhead">Year</td>
                                <td class="rowhead">Quarter Report Url</td>     
                                <td class="rowhead">Presentation</td>
                                <td class="rowhead">Presentation Url</td>
                                <td class="rowhead">Action</td> 
                            </tr>
                    </thead>
                    <tbody>               
                    <?php
                        foreach($comp_quar_rep as $cqr){                            
                            $qrepurl = ($cqr->quarter_report_url!='') ? l($cqr->quarter_report_url,$cqr->quarter_report_url,array('attributes'=>array('target'=>'_blank'))) : '';
                            $ptext = ($cqr->presentation_text!='') ? date('m/d/Y',strtotime($cqr->presentation_text)) : '';
                            $purl = ($cqr->presentation_url!='') ? l($cqr->presentation_url,$cqr->presentation_url,array('attributes'=>array('target'=>'_blank'))) : '';
                            echo '<tr>
                                    <td class="rowbtm">'.$cqr->quarter_code.'</td>
                                    <td class="rowbtm">'.$cqr->year.'</td>                        
                                    <td class="rowbtm">'.$qrepurl.'</td>                                           
                                    <td class="rowbtm">'.$ptext.'</td>   
                                    <td class="rowbtm">'.$purl.'</td>      
                                    <td class="rowbtm">'.l('Edit','edit-company-quarter-report/'.$cqr->quarter_report_id,array('attributes' => array('target' => '_blank'))).' | '.l('Delete','del-company-quarter-report/'.$cqr->quarter_report_id,array('attributes' => array('onclick' => 'return confirm("Are you sure?")'))).'</td>     
                                </tr>';
                        }
                        ?>
                      </tbody>
            </table>
            </div>    
        </div>       
        <?php } ?>                
                        
                        
        <?php if(count($comp_ann_capex)>0){ //print_r($comp_ann_capex); ?>
        <div class="col-md-12">
            <div class="plc"><label>Company Annual Capex</label></div>
            <div class="table-responsive">
                <table class="table table-bordered table-striped dplist">
                        <thead>
                            <tr>
                                <td class="rowhead">Year</td>
                                <td class="rowhead">Capex</td>                                                             
                                <td class="rowhead">Estimated</td>   
                                <td class="rowhead">Action</td>   
                            </tr>
                    </thead>
                    <tbody>               
                    <?php
                        foreach($comp_ann_capex as $cac){
                            $estimated = ($cac->estimated=='1') ? 'Yes' : 'No';
                            echo '<tr>
                                    <td class="rowbtm">'.$cac->year.'</td>
                                    <td class="rowbtm">'.$cac->capex.'</td>       
                                    <td class="rowbtm">'.$estimated.'</td>       
                                    <td class="rowbtm">'.l('Edit','edit-company-annual-capex/'.$cac->ca_capex_id,array('attributes' => array('target' => '_blank'))).' | '.l('Delete','del-company-annual-capex/'.$cac->ca_capex_id,array('attributes' => array('onclick' => 'return confirm("Are you sure?")'))).'</td>    
                                </tr>';
                        }
                        ?>
                      </tbody>
            </table>
            </div>    
        </div>       
        <?php } ?>    
    
    
    
        <?php if(count($comp_ann_ebidax)>0){ //print_r($comp_ann_ebidax); ?>
        <div class="col-md-12">
            <div class="plc"><label>Company Annual Ebidax</label></div>
            <div class="table-responsive">
                <table class="table table-bordered table-striped dplist">
                        <thead>
                            <tr>
                                <td class="rowhead">Year</td>
                                <td class="rowhead">Ebidax</td>                                                             
                                <td class="rowhead">Estimated</td>   
                                <td class="rowhead">Action</td>   
                            </tr>
                    </thead>
                    <tbody>               
                    <?php
                        foreach($comp_ann_ebidax as $cae){
                            $estimated = ($cae->estimated=='1') ? 'Yes' : 'No';
                            echo '<tr>
                                    <td class="rowbtm">'.$cae->year.'</td>
                                    <td class="rowbtm">'.$cae->ebidax.'</td>       
                                    <td class="rowbtm">'.$estimated.'</td>  
                                    <td class="rowbtm">'.l('Edit','edit-company-annual-ebidax/'.$cae->ca_ebidax_id,array('attributes' => array('target' => '_blank'))).' | '.l('Delete','del-company-annual-ebidax/'.$cae->ca_ebidax_id,array('attributes' => array('onclick' => 'return confirm("Are you sure?")'))).'</td>    
                                </tr>';
                        }
                        ?>
                      </tbody>
            </table>
            </div>    
        </div>       
        <?php } ?> 
    
    
    
        <?php if( (is_array($companies) && count($companies)>0) && is_array($plays) && count($plays)>0 ){ ?>  
        <div class="col-md-12 plc"><label>Region Details</label> <?php print l('Add New Region','add-new-region',array('attributes' => array('target' => '_blank'))); ?></div>
        <?php } ?>
        
        <?php if(count($comp_play_details)>0){  //print_r($comp_play_details); exit; 
            
            $multiple_cp = (count($comp_play_details)>1) ? true : false;
        ?>
        <div class="col-md-12">
            
            <div class="table-responsive">                
                <?php 
                    
                    $cp_loop = 1;
                    
                    foreach($comp_play_details as $cpd){ 
                ?>  
                <div class="plc"><label>Company Play Details <?php echo ($multiple_cp) ? $cp_loop : ''; ?></label> <?php print l('Edit','edit-region/'.$cpd->cpd_id,array('attributes' => array('target' => '_blank'))); ?> | <?php print l('Add Company Play Capex','add-cp-annual-capex/'.$cpd->company_play_id.'/'.$cpd->cpd_id,array('attributes' => array('target' => '_blank'))) ?> | <?php print l('Add Company Play Well','add-cp-annual-well/'.$cpd->company_play_id.'/'.$cpd->cpd_id,array('attributes' => array('target' => '_blank'))) ?> | <?php print l('Add Company Play Production','add-cp-annual-production/'.$cpd->company_play_id.'/'.$cpd->cpd_id,array('attributes' => array('target' => '_blank'))) ?></div>
                <table class="table table-bordered table-striped dplist">                        
                    <tbody>
                        <tr>
                            <td class="rowhead">Location</td><td class="rowbtm"><?php print $cpd->location; ?></td>
                        </tr>    
                        <tr><td class="rowhead">Project Field</td><td class="rowbtm"><?php print $cpd->project_field; ?></td></tr>
                            <tr><td class="rowhead">Entered Play</td><td class="rowbtm"><?php print $cpd->entered_play; ?></td></tr>
                            <tr><td class="rowhead">Depth</td><td class="rowbtm"><?php print $cpd->depth; ?></td></tr>
                            <tr><td class="rowhead">Acres Gross Net</td><td class="rowbtm"><?php print $cpd->acres_gross_net; ?></td></tr>
                            <tr><td class="rowhead">JVs</td><td class="rowbtm"><?php print $cpd->jvs; ?></td></tr>
                            <tr><td class="rowhead">Well Cost</td><td class="rowbtm"><?php print $cpd->well_cost; ?></td></tr>
                            <tr><td class="rowhead">Most Recent Quarter</td> <td class="rowbtm"><?php print $cpd->most_recent_quarter; ?></td></tr>
                            <tr><td class="rowhead">Number of Rigs</td><td class="rowbtm"><?php print $cpd->number_of_rigs; ?></td></tr>
                            <tr><td class="rowhead">Well Spacing</td><td class="rowbtm"><?php print $cpd->well_spacing; ?></td></tr>
                            <tr><td class="rowhead">Inventory</td><td class="rowbtm"><?php print $cpd->inventory; ?></td></tr>
                            <tr><td class="rowhead">Completions</td><td class="rowbtm"><?php print $cpd->completions; ?></td></tr>
                            <tr><td class="rowhead">IP</td><td class="rowbtm"><?php print $cpd->ip; ?></td></tr>
                            <tr><td class="rowhead">EUR</td><td class="rowbtm"><?php print $cpd->eur; ?></td></tr>
                            <tr><td class="rowhead">Total Prod Wells</td><td class="rowbtm"><?php print $cpd->total_prod_wells; ?></td></tr>
                            <tr><td class="rowhead">Reserves</td><td class="rowbtm"><?php print $cpd->reserves; ?></td></tr>
                            <tr><td class="rowhead">Resource Potential</td><td class="rowbtm"><?php print $cpd->resource_potential; ?></td></tr>
                            <tr><td class="rowhead">Comment</td><td class="rowbtm comment"><?php print $cpd->comment; ?></td></tr>   
                            </tbody>		
                </table>
                
                
                <?php     
                // company play capex begins
                $cpcapex = get_comp_play_ann_capex($cpd->cpd_id,$cpd->company_play_id);
                if($cpcapex && is_array($cpcapex) && count($cpcapex)>0){
                ?>
                <div class="plc"><label>Company Play Annual Capex <?php echo ($multiple_cp) ? $cp_loop : ''; ?></label></div>
                <table class="table table-bordered table-striped dplist">  
                    <thead>
                            <tr>
                                <td class="rowhead">Year</td>
                                <td class="rowhead">Capex</td>                                                             
                                <td class="rowhead">Estimated</td>   
                                <td class="rowhead">Action</td>   
                            </tr>
                    </thead>
                    <tbody>
                <?php
                    foreach ($cpcapex as $cpc){
                        $cpc_estimated = ($cpc->estimated=='1') ? 'Yes' : 'No';
                            echo '<tr>
                                    <td class="rowbtm">'.$cpc->year.'</td>
                                    <td class="rowbtm">'.$cpc->capex.'</td>       
                                    <td class="rowbtm">'.$cpc_estimated.'</td>  
                                    <td class="rowbtm">'.l('Edit','edit-cp-annual-capex/'.$cpc->cpa_capex_id,array('attributes' => array('target' => '_blank'))).' | '.l('Delete','del-cp-annual-capex/'.$cpc->cpa_capex_id,array('attributes' => array('onclick' => 'return confirm("Are you sure?")'))).'</td>    
                                </tr>';
                    }
                ?>
                        </tbody>
                </table>
                <?php
                }
                // company play capex ends
                ?>
                
                
                <?php     
                // company play wells begins
                $cpwells = get_comp_play_ann_wells($cpd->cpd_id,$cpd->company_play_id);
                if($cpwells && is_array($cpwells) && count($cpwells)>0){
                ?>
                <div class="plc"><label>Company Play Annual Well <?php echo ($multiple_cp) ? $cp_loop : ''; ?></label></div>
                <table class="table table-bordered table-striped dplist">  
                    <thead>
                            <tr>
                                <td class="rowhead">Year</td>
                                <td class="rowhead">Wells</td>                                                             
                                <td class="rowhead">Estimated</td>   
                                <td class="rowhead">Action</td>   
                            </tr>
                    </thead>
                    <tbody>
                <?php
                    foreach ($cpwells as $cpw){
                        $cpw_estimated = ($cpw->estimated=='1') ? 'Yes' : 'No';
                            echo '<tr>
                                    <td class="rowbtm">'.$cpw->year.'</td>
                                    <td class="rowbtm">'.$cpw->well.'</td>       
                                    <td class="rowbtm">'.$cpw_estimated.'</td>    
                                    <td class="rowbtm">'.l('Edit','edit-cp-annual-well/'.$cpw->cpa_wells_id,array('attributes' => array('target' => '_blank'))).' | '.l('Delete','del-cp-annual-well/'.$cpw->cpa_wells_id,array('attributes' => array('onclick' => 'return confirm("Are you sure?")'))).'</td>      
                                </tr>';
                    }
                ?>
                        </tbody>
                </table>
                <?php
                }
                // company play wells ends
                ?>
                
                <?php     
                // company play production begins
                $cpproduction = get_comp_play_ann_production($cpd->cpd_id,$cpd->company_play_id);
                if($cpproduction && is_array($cpproduction) && count($cpproduction)>0){
                ?>
                <div class="plc"><label>Company Play Annual Production <?php echo ($multiple_cp) ? $cp_loop : ''; ?></label></div>
                <table class="table table-bordered table-striped dplist">  
                    <thead>
                            <tr>
                                <td class="rowhead">Year</td>
                                <td class="rowhead">Production</td>                                                             
                                <td class="rowhead">Estimated</td>   
                                <td class="rowhead">Action</td>   
                            </tr>
                    </thead>
                    <tbody>
                <?php
                    foreach ($cpproduction as $cpp){
                        $cpp_estimated = ($cpp->estimated=='1') ? 'Yes' : 'No';
                            echo '<tr>
                                    <td class="rowbtm">'.$cpp->year.'</td>
                                    <td class="rowbtm">'.$cpp->production.'</td>       
                                    <td class="rowbtm">'.$cpp_estimated.'</td>   
                                    <td class="rowbtm">'.l('Edit','edit-cp-annual-production/'.$cpp->cpa_production_id,array('attributes' => array('target' => '_blank'))).' | '.l('Delete','del-cp-annual-production/'.$cpp->cpa_production_id,array('attributes' => array('onclick' => 'return confirm("Are you sure?")'))).'</td>          
                                </tr>';
                    }
                ?>
                        </tbody>
                </table>
                <?php
                }
                // company play production ends
                ?>
                
                
                <?php
                    
                        $cp_loop++;
                
                    }                
               ?>   
            </div>    
        </div>    
            <?php }  ?>
        
    
        
</div>