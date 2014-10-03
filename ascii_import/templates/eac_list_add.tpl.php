<style>

	/* 
	Max width before this PARTICULAR table gets nasty
	This query will take effect for any screen smaller than 760px
	and also iPads specifically.
	*/
	@media 
	only screen and (max-width: 760px),
	(min-device-width: 768px) and (max-device-width: 1024px)  {
	
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
		#dplist td:nth-of-type(1):before { content: "Alert Name"; }
		#dplist td:nth-of-type(2):before { content: "Edit"; }
		#dplist td:nth-of-type(3):before { content: "Delete"; }
		
              
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
        
        
        .rowhead{text-align: center;}
        .fieldstar{color:red;}
        #alertlist{height: 200px; overflow-y: auto; }
</style>
<script>
function isNumberKey(evt){
    var charCode = (evt.which) ? evt.which : event.keyCode
    if (charCode > 31 && (charCode < 48 || charCode > 57))
        return false;
    return true;
}
setTimeout(function() { document.getElementById('alert_name').focus(); }, 10);
</script>
<?php if ($no_of_rows > 0) { ?>
    <div class="col-md-12" id="alertlist" style="padding-left:0px;padding-right: 0;margin-bottom: 8px;">
        <table border="1" id="dplist">
                        <thead>
                            <tr>
                                <td class="rowhead" style="width:25%">Alert Name</td>
                                <td class="rowhead" style="width:45%">Alert Description</td>
                                <td class="rowhead" style="width:10%">Edit</td>
                                <td class="rowhead" style="width:10%">Delete</td>
                                <td class="rowhead" style="width:10%">Active</td>
                            </tr>
                    </thead>
        <?php foreach ($result as $row) { ?>
          
		<tbody>
                    <tr>
                        <td> <?php echo $row->alert_name; ?></td>
                        <td> <?php echo $row->alert_description; ?></td>
			<td style="text-align:center;"><a href="eac-edit/<?php echo $row->alert_id ?>" title='<?php echo t('Edit'); ?>'><span class="dp_edit_icon">&nbsp</span></a></td>
			<td style="text-align:center;"> <a href="eac-del/<?php echo $row->alert_id ?>" onclick="return confirm('Are you sure want to delete?')" title='<?php echo t('Delete'); ?>'>
                        <span class="dp_del_icon">&nbsp</span></a></td>
                        <td style="text-align:center;"><?php echo ($row->status==1) ? '<img src="'.  drupal_get_path('module','ascii_import').'/assets/active.jpg" />' : '<img src="'.  drupal_get_path('module','ascii_import').'/assets/inactive.jpg" />'; ?></td>    
                 	</tr>
                </tbody>
           
        <?php } ?>
                 </table>
    </div>    
<?php } ?> 

<div class="row">
<div class="col-md-8">
<div class="well">


    <form id="eacform" method="post">
    	<legend>Add New Email Alert</legend>
        <div class="form-group">
            <label>Alert Name <span class="fieldstar">*</span></label>
           <input id="alert_name" name="alert_name" class="alert_name form-control" maxlength="100" style="width:40%" value="" type="text" placeholder="Alert Name" autofocus/>
           </div>
            
        <div class="form-group">
            <label>Alert Description</label>
           <textarea id="alert_description" name="alert_description" cols="51" rows="2" placeholder="Alert Description" class="form-control"></textarea>
        </div>

       
        <div class="row">
            	<div class="form-group col-md-4">
                <label>Play</label>
            
                    <select class="form-control slt" name="play" id="play" style="">
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
				<div class="form-group col-md-4">
               <label>Status</label>
            
                    <select class="form-control slt" name="status_of_app_flag" id="status_of_app_flag">
                        <option value="">Select App Status</option>
                        <?php
                        foreach ($app_status as $st) {
                            echo '<option value="' . $st->status_code . '">' . $st->status_name . '</option>';
                        }
                        ?>  
                    </select>
            
            </div>
				<div class="form-group col-md-4">
                <label>Well Type</label>
        
                    <select class="form-control slt" name="field_application_well_code" id="field_application_well_code">
                        <option value="">Select Well type</option>
                        <?php
                        foreach ($welltypes as $wt) {
                            echo '<option value="' . $wt->code . '">' . $wt->description . '</option>';
                        }
                        ?>  
                    </select>
                
            </div>
        	</div>
       

        <div class="row">
            <div class="form-group col-md-4">
                <label>County</label>
        
                    <select class="form-control slt" name="county_code" id="county_code">
                        <option value="">Select County</option>
                        <?php
                        foreach ($counties as $county) {
                            echo '<option value="' . $county->county_code . '">' . $county->county_name . '</option>';
                        }
                        ?>  
                    </select>
                
            </div>            
            <div class="form-group col-md-4">
               <label>Company / Operator</label>
              
                <input type="text" name="operator_name" id="operator_name"  class="fnpt form-control" placeholder="Company / Operator"/>
                
            </div>
			
			<div class="form-group col-md-4">
                <label>Wellbore Profiles</label>
             
                    <select class="form-control slt" name="wp_code" id="wp_code">
                        <option value="">Select Wellbore Profile</option>
                        <?php
                        foreach ($wellbore_profiles as $wp) {
                            echo '<option value="' . $wp->wp_code . '">' . $wp->wp_name . '</option>';
                        }
                        ?>  
                    </select>
               
            </div>

        </div>

        <div class="row">            
           
              <div class="form-group col-md-8">
                <label>Total Depth</label>
                    <div class="row">
                    	<div class="col-sm-6">   
							<input type="text" name="permit_total_depth_MIN" id="permit_total_depth_MIN" class="resizedTextbox fnpt form-control" placeholder="Min" maxlength="8" onkeypress="return isNumberKey(event)"/>
                    	</div>
                    	<div class="col-sm-6">                            
							<input type="text" name="permit_total_depth_MAX" id="permit_total_depth_MAX" class="resizedTextbox fnpt form-control" placeholder="Max"  maxlength="8" onkeypress="return isNumberKey(event)"/>
                    	</div>
                    </div>
                
            </div>

           
        </div>        
         <div class="form-group">
                <div class="checkbox">
                <label>         
                <input type="checkbox" name="status" id="status" value="1"/> Active
                </label> 
                </div>
            </div>
        <div class="form-group">
         <input type="submit" name="submit" value="Save" class="submit btn btn-primary"/>            
        </div>
    </form>
</div>
</div>
</div>