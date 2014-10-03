<style>
    .fieldstar{color:red;}
</style>
<script>
function isNumberKey(evt){
    var charCode = (evt.which) ? evt.which : event.keyCode
    if (charCode > 31 && (charCode < 48 || charCode > 57))
        return false;
    return true;
}
</script>

<div class="col-md-12 resultset">
<form id="eacform" method="post">
<input type='hidden' name="alert_id" value="<?php echo (isset($editdata['alert_id'])) ? $editdata['alert_id'] : '' ?>" />
<div class="col-md-12 frmdata">
    <div class="plc"><label>Alert Name <span class="fieldstar">*</span></label></div>
    <div><input id="alert_name" name="alert_name" class="alert_name" style="width:40%" placeholder="Alert Name" maxlength="100" value='<?php echo (isset($editdata['alert_name'])) ? $editdata['alert_name'] : '' ?>'/></div>
    <div class="plc"><label>Alert Description</label></div>
    <div><textarea id="alert_description" name="alert_description" cols="51" rows="2" placeholder="Alert Description"><?php echo (isset($editdata['alert_description'])) ? $editdata['alert_description'] : '' ?></textarea></div>
</div>

<div class="col-md-12">
    <div class="col-md-4" style="padding-left:0;">
        <div class="plc"><label>Play</label></div>
        <div>
            <select class="full slt" name="play" id="play">
                <option value="">Select Play</option>
                <?php
                foreach ($play_list as $plays) {
                    if(isset($editdata['play']->condition_value) && $editdata['play']->condition_value==$plays->play){
                        echo '<option value="' . $plays->play . '" selected="selected">' . $plays->play . '</option>';
                    }else{
                        echo '<option value="' . $plays->play . '">' . $plays->play . '</option>';
                    }
                }
                ?>
            </select>
        </div>
    </div>
    <div class="col-md-4">
        <div class="plc"><label>Status</label></div>
        <div>
            <select class="full slt" name="status_of_app_flag" id="status_of_app_flag">
                <option value="">Select App Status</option>
                <?php
                foreach ($app_status as $st) {
                    if(isset($editdata['status_of_app_flag']->condition_value) && $editdata['status_of_app_flag']->condition_value==$st->status_code){
                        echo '<option value="' . $st->status_code . '" selected="selected">' . $st->status_name . '</option>';
                    }else{
                        echo '<option value="' . $st->status_code . '">' . $st->status_name . '</option>';
                    }
                }
                ?>
            </select>
        </div>
    </div>
    <div class="col-md-4">
        <div class="plc"><label>Well Type</label></div>
        <div>
            <select class="full slt" name="field_application_well_code" id="field_application_well_code">
                <option value="">Select Well type</option>
                <?php
                foreach ($welltypes as $wt) {
                    if(isset($editdata['field_application_well_code']->condition_value) && $editdata['field_application_well_code']->condition_value==$wt->code){
                        echo '<option value="' . $wt->code . '" selected="selected">' . $wt->description . '</option>';
                    }else{
                        echo '<option value="' . $wt->code . '">' . $wt->description . '</option>';
                    }
                }
                ?>
            </select>
        </div>
    </div>
</div>

<div class="col-md-12">
    <div class="col-md-4" style="padding-left:0;">
        <div class="plc"><label>County</label></div>
        <div>
            <select class="full slt" name="county_code" id="county_code">
                <option value="">Select County</option>
                <?php
                foreach ($counties as $county) {
                    if(isset($editdata['county_code']->condition_value) && $editdata['county_code']->condition_value==$county->county_code){
                        echo '<option value="' . $county->county_code . '" selected="selected">' . $county->county_name . '</option>';
                    }else{
                        echo '<option value="' . $county->county_code . '">' . $county->county_name . '</option>';
                    }
                }
                ?>
            </select>
        </div>
    </div>
    <div class="col-md-4">
        <div class="plc"><label>Company / Operator</label></div>
        <div>
            <input type="text" style="width: 50%;" name="operator_name" id="operator_name" placeholder="Company / Operator" class="fnpt" value='<?php echo (isset($editdata['operator_name']->condition_value)) ? $editdata['operator_name']->condition_value : '' ?>'/>
        </div>
    </div>
    <div class="col-md-4">
        <div class="plc"><label>Total Depth</label></div>
        <div class="col-md-2" style="padding:0;">
            <input type="text" name="permit_total_depth_MIN" id="permit_total_depth_MIN" class="resizedTextbox fnpt" placeholder="Min" maxlength="8" onkeypress="return isNumberKey(event)" value="<?php echo (isset($editdata['permit_total_depth_MIN']->condition_value)) ? $editdata['permit_total_depth_MIN']->condition_value : '' ?>"/>
        </div>
        <div class="col-md-2" style="padding:0;">
            <input type="text" name="permit_total_depth_MAX" id="permit_total_depth_MAX" class="resizedTextbox fnpt" placeholder="Max" maxlength="8" onkeypress="return isNumberKey(event)" value="<?php echo (isset($editdata['permit_total_depth_MAX']->condition_value)) ? $editdata['permit_total_depth_MAX']->condition_value : '' ?>"/>
        </div>
    </div>
</div>

<div class="col-md-12">
    <div class="col-md-4"style="padding-left:0;">
        <div class="plc"><label>Wellbore Profiles</label></div>
        <div>
            <select class="full slt" name="wp_code" id="wp_code">
                <option value="">Select Wellbore Profile</option>
                <?php
                foreach ($wellbore_profiles as $wp) {
                    if(isset($editdata['wp_code']->condition_value) && $editdata['wp_code']->condition_value==$wp->wp_code){
                        echo '<option value="' . $wp->wp_code . '" selected="selected">' . $wp->wp_name . '</option>';
                    }else{
                        echo '<option value="' . $wp->wp_code . '">' . $wp->wp_name . '</option>';
                    }
                }
                ?>
            </select>
        </div>
    </div>
    <div class="col-md-4" style="padding-left:17px;">
        <div class="plc"><label>Active</label></div>
        <?php $checked = (isset($editdata['status']) && $editdata['status']==1) ? 'checked="checked"' : '' ?>
        <input type="checkbox" name="status" id="status" value="1" <?php echo $checked ?> />
    </div>
</div>


<div class="col-md-12 plc">
    <input type="submit" name="submit" value="Update" class="submit"/>
     <input id="buttonrain" class="submit" type="button" onClick="window.location.href='/email-alert-config'" value="Cancel" />
</div>
</form>
</div>
 
