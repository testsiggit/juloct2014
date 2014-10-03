<script>
jQuery(document).ready(function($) {        
    $('#comp').on('change',  function(){            
        if($('#play').length>0){
            $('#play').val('');
        }
    });
});
</script>
<div class="row">
    <form id="oaview" method="get">
        <div class="col-sm-5">           
            <div class="plc"><label>Company</label></div>
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
        
        <?php if(count($comp_plays)>0){ ?>
        <div class="col-sm-5">            
            <div class="plc"><label>Play</label></div>
            <div>
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
        </div>
        <?php } ?>
        <div class="col-sm-2 plc">
            <input type="submit" name="submit" value="Submit" class="btn btn-primary"/>            
        </div>
    </form>
    
        
        <?php if(count($comp_details)>0){ 
            
//            print_r($comp_details);
            
            $compdet = $comp_details;
            
            ?>
        <div class="col-md-12">
            <div class="plc"><label>Company Details</label></div>
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
                            </tr>
                    </thead>
                    <tbody>               
                    <?php
                        foreach($comp_ann_rep as $car){
                            $repurl = ($car->report_url!='') ? l($car->report_url,$car->report_url,array('attributes'=>array('target'=>'_blank'))) : '';
                            echo '<tr>
                                    <td class="rowbtm">'.$car->year.'</td>
                                    <td class="rowbtm">'.$repurl.'</td>                        
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
                                </tr>';
                        }
                        ?>
                      </tbody>
            </table>
            </div>    
        </div>       
        <?php } ?> 
    
    
    
        <?php if(count($comp_play_details)>0){  //print_r($comp_play_details); exit; ?>
        <div class="col-md-12">
            <div class="plc"><label>Company Play Details</label></div>
            <div class="table-responsive">
                <table class="table table-bordered table-striped dplist">
                        <thead>
                            <tr>
                                <td class="rowhead">Location</td>
                                <td class="rowhead">Project Field</td>
                                <td class="rowhead">Entered Play</td>
                                <td class="rowhead">Depth</td>
                                <td class="rowhead">Acres Gross Net</td>
                                <td class="rowhead">JVs</td>
                                <td class="rowhead">Well Cost</td>
                                <td class="rowhead">Most Recent Quarter</td>       
                                <td class="rowhead">Number of Rigs</td>
                                <td class="rowhead">Well Spacing</td>
                                <td class="rowhead">Inventory</td>
                                <td class="rowhead">Completions</td>
                                <td class="rowhead">IP</td>
                                <td class="rowhead">EUR</td>
                                <td class="rowhead">Total Prod Wells</td>
                                <td class="rowhead">Reserves</td>
                                <td class="rowhead">Resource Potential</td>
                                <td class="rowhead">Comment</td>                                
                            </tr>
                    </thead>
                    <tbody>
                    <?php   foreach($comp_play_details as $cpd){ ?>  
                    <tr>
                        <td class="rowbtm"><?php print $cpd->location; ?></td>
                        <td class="rowbtm"><?php print $cpd->project_field; ?></td>
                        <td class="rowbtm"><?php print $cpd->entered_play; ?></td>
                        <td class="rowbtm"><?php print $cpd->depth; ?></td>
                        <td class="rowbtm"><?php print $cpd->acres_gross_net; ?></td>
                        <td class="rowbtm"><?php print $cpd->jvs; ?></td>
                        <td class="rowbtm"><?php print $cpd->well_cost; ?></td>
                        <td class="rowbtm"><?php print $cpd->most_recent_quarter; ?></td>
                        <td class="rowbtm"><?php print $cpd->number_of_rigs; ?></td>
                        <td class="rowbtm"><?php print $cpd->well_spacing; ?></td>
                        <td class="rowbtm"><?php print $cpd->inventory; ?></td>
                        <td class="rowbtm"><?php print $cpd->completions; ?></td>
                        <td class="rowbtm"><?php print $cpd->ip; ?></td>
                        <td class="rowbtm"><?php print $cpd->eur; ?></td>
                        <td class="rowbtm"><?php print $cpd->total_prod_wells; ?></td>
                        <td class="rowbtm"><?php print $cpd->reserves; ?></td>
                        <td class="rowbtm"><?php print $cpd->resource_potential; ?></td>
                        <td class="rowbtm comment"><?php print $cpd->comment; ?></td>
                    </tr>
                    <?php } ?>
                </tbody>
		
            </table>
            </div>    
        </div>    
            <?php }  ?>
        
    
        
</div>