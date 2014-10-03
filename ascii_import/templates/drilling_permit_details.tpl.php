<style>    
    /* Drilling Permit Details Page */
 
     body{
        font-family:open sans;
          font-size:14px;
    }
    #page-wrap {
        margin: 50px;
    }
    p {
        margin: 20px 0; 
    }

    /* 
    Generic Styling, for Desktops/Laptops 
    */
    table { 
        width: 100%; 
        border-collapse: collapse; 
    }
    /* Zebra striping */
    tr:nth-of-type(odd) { 
        background: #eee; 
    }
    th { 
        background: #333; 
        color: white; 
        font-weight: bold; 
    }
    td, th { 
        padding: 6px; 
        border: 1px solid #ccc; 
        text-align: left; 
    }
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
        #dpdetails1 td:nth-of-type(1):before { content: "Filling Purpose"; }
        #dpdetails1 td:nth-of-type(2):before { content: "Wellbore Profiles"; }
        #dpdetails1 td:nth-of-type(3):before { content: "Lease Name"; }
        #dpdetails1 td:nth-of-type(4):before { content: "Well Number"; }
        #dpdetails1 td:nth-of-type(5):before { content: "Well #"; }
        #dpdetails1 td:nth-of-type(6):before { content: "SWR"; }
        #dpdetails1 td:nth-of-type(7):before { content: "Total Depth"; }
        #dpdetails1 td:nth-of-type(8):before { content: "Horizontal Wellbore"; }
        #dpdetails1 td:nth-of-type(9):before { content: "Wellbore Profiles"; }
        #dpdetails1 td:nth-of-type(10):before { content: "Stacked Lateral Status #"; }

        #dpdetails2 td:nth-of-type(1):before { content: "API #"; }
        #dpdetails2 td:nth-of-type(2):before { content: "Distance from Nearest Town"; }
        #dpdetails2 td:nth-of-type(3):before { content: "Direction from Nearest Town"; }
        #dpdetails2 td:nth-of-type(4):before { content: "Nearest Town"; }
        #dpdetails2 td:nth-of-type(5):before { content: "Surface Location Type"; }

        #dpdetails3 td:nth-of-type(1):before { content: "Section"; }
        #dpdetails3 td:nth-of-type(2):before { content: "Block"; }
        #dpdetails3 td:nth-of-type(3):before { content: "Survey"; }
        #dpdetails3 td:nth-of-type(4):before { content: "Abstract#"; }
        #dpdetails3 td:nth-of-type(5):before { content: "County"; }

        #dpdetails4 td:nth-of-type(1):before { content: "Perpendiculars"; }
        #dpdetails4 td:nth-of-type(2):before { content: "Distance"; }
        #dpdetails4 td:nth-of-type(3):before { content: "Direction"; }
        #dpdetails4 td:nth-of-type(4):before { content: "Distance"; }
        #dpdetails4 td:nth-of-type(5):before { content: "Direction"; } 

        #dpdetails5 td:nth-of-type(1):before { content: "Code"; }
        #dpdetails5 td:nth-of-type(2):before { content: "Descriptions"; } 


    }
    .rowhead {
        background: none repeat scroll 0 0 #638498;
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


/*********** sujan ****************/



</style>
<?php

function wellbore_text2($directional, $sidetrack, $horizontal) {
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
?>
<div id="map" style="height:500px; width:100%;"></div>
<?php
$js_locs = '';
$langitude = '';
$latitude = '';
foreach ($listdetails as $row) {

    $test = $row;
    if ($row->horizontal_well_flag == 'N') {
        $horizontal_well_flag = 'Vertical';
    } else {
        $horizontal_well_flag = 'Horizontal';
    }

    $wellbore = '';
    $wellbore = wellbore_text2($row->directional_well_flag, $row->sidetrack_well_flag, $row->horizontal_well_flag);
    
    $submitted = date('m/d/Y', strtotime($row->da_received_date));
//    if($row->da_pmt_amended_date!=''){
//        $approved = date('m/d/Y', strtotime($row->da_pmt_amended_date));
//    }else{
//        $approved = date('m/d/Y', strtotime($row->da_pmt_issued_date));
//    }
    $approved = date('m/d/Y', strtotime($row->final_approved_date));
    
    ?>
    <div class="operatorhead"><h4><?php echo $row->operator_name . '-' . $approved ?></h4></div>
    <div class="operatorleasehead"><p><b>Lease Summary</b></p></div>
    <div class="wrapperField">
        <div><label>API Number</label> : <?php echo $row->api_number ?></div>
        <div><label>Oil Lease No/Gas Well IDNo</label> : </div>
        <div><label>Well No</label> : <?php echo $row->well_number ?></div>
        <div><label>Field Number</label> : <?php echo $row->api_number ?></div>
        <div><label>Current Operator Number</label> : <?php echo $row->operator_number ?></div>
        <div><label>Operator Status</label> : <?php echo $row->status_name ?></div>
    </div>

    <div class="wrapperescondField">
        <div><label>District</label> : <?php echo $row->district_name ?></div>
        <div><label>Lease Name</label> : <?php echo $row->lease_name ?></div>
        <div><label>Well Type</label> : <?php echo $row->description ?></div>
        <div><label>Field Name</label> : </div>
        <div><label>Current Operator Name</label> : <?php echo $row->operator_name ?></div>   
    </div>

    <div style="clear:both;"></div>

    <div id="dpdetails">    
        <table class="table table-bordered table-striped table-responsive" id="dpdetails1">
            <h3 class="block-title">General/Location Information</h3>
            <p class="topwarphead">Surface Basic Information:</p>
            <thead>
                <tr>
                    <th>Filling Purpose</th>
                    <th>Wellbore Profiles</th>
                    <th>Lease Name</th>
                    <th>Well #</th>
                    <th>SWR</th>
                    <th>Total Depth</th>
                    <th>Horizontal Wellbore</th>
                    <th>Stacked Lateral Status #</th>
                </tr>
            </thead>
            <tbody>
                <tr>
                    <td><?php echo $row->fp_description ?></td>
                    <td><?php echo $wellbore ?></td>
                    <td><?php echo $row->lease_name ?></td>
                    <td><?php echo $row->well_number ?></td>
                    <td> </td>
                    <td><?php echo $row->permit_total_depth ?></td>
                    <td></td>
                    <td></td>
                </tr>
            </tbody>
        </table>
        <table class="table table-bordered table-striped table-responsive" border="1" id="dpdetails2"><p class="topwarphead">Surface Location Information:</p>
            <thead>
                <tr>
                    <th>API #</th>
                    <th>Distance from Nearest Town</th>
                    <th>Direction from Nearest Town</th>
                    <th>Nearest Town</th>
                    <th>Surface Location Type</th>
                </tr>
            </thead>
            <tbody>
                <tr>
                    <td><?php echo $row->api_number ?></td>
                    <td><?php echo $row->surface_miles_from_city ?></td>
                    <td><?php echo $row->surface_direction_from_city ?></td>
                    <td><?php echo $row->surface_nearest_city ?></td>
                    <td></td>
                </tr>
            </tbody>
        </table>
        <table class="table table-bordered table-striped table-responsive" border="1" id="dpdetails3"><p class="topwarphead">Survey/Legal Location Information:</p>
            <thead>
                <tr>
                    <th>Section</th>
                    <th>Block</th>
                    <th>Survey</th>
                    <th>Abstract#</th>
                    <th>County</th>
                </tr>
            </thead>
            <tbody>
                <tr>
                    <td><?php echo $row->new_surface_section ?></td>
                    <td><?php echo $row->new_surface_block ?></td>
                    <td><?php echo $row->new_surface_survey ?></td>
                    <td><?php echo $row->new_surface_abstract ?></td>
                    <td><?php echo $row->county_name ?></td>
                </tr>
            </tbody>
        </table>
        <table class="table table-bordered table-striped table-responsive" border="1" id="dpdetails4"><p class="topwarphead">Perpendicular Surface location from two nearest designated Lines:</p>
            <thead>
                <tr>

                    <th>Perpendiculars</th>
                    <th>Distance</th>
                    <th>Direction</th>
                    <th>Distance</th>
                    <th>Direction</th>
                </tr>
            </thead>
            <tbody>
                <tr>
                    <td>Survey Perpendiculars</td>
                    <td><?php echo $row->surface_survey_feet_1 ?></td>
                    <td><?php echo $row->surface_survey_direction_1 ?></td>
                    <td><?php echo $row->surface_survey_feet_2 ?></td>
                    <td><?php echo $row->surface_survey_dierction_2 ?></td>
                </tr>
            </tbody>
        </table>
    </table>
    <table class="table table-bordered table-striped table-responsive" border="1" id="dpdetails5"><p class="topwarphead">Permit Restrictions:</p>
        <thead
            <tr>
                <th>Code</th>
                <th>Descriptions</th>
            </tr>
        </thead>
        <tbody
            <tr>
                <td><?php echo $row->free_restr_type ?></td>
                <td><?php echo $row->free_restr_remark ?></td>
            </tr>
        </tbody>
    </table>
    </div>
    
    
    <div style="margin-top:20px; "><a href="<?php echo $_SERVER['HTTP_REFERER'] ?>">Back</a></div>
    
    
    <?php
    $js_locs .= '["' . trim($row->operator_name) . '",' . trim($row->surf_loc_lattitude) . ',' . trim($row->surf_loc_longitude) . '],';

    //$latitude = trim($row->surf_loc_lattitude);
    //$langitude= trim($row->surf_loc_longitude);
}
?>
<script type="text/javascript">
    function initialize() {
        var locations = [
<?php echo $js_locs; ?>
        ];

        window.map = new google.maps.Map(document.getElementById('map'), {
            mapTypeId: google.maps.MapTypeId.ROADMAP
        });

        var infowindow = new google.maps.InfoWindow();

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

        var listener = google.maps.event.addListener(map, "idle", function() {
            map.setZoom(7);
            google.maps.event.removeListener(listener);
        });
    }

    function loadScript() {
        var script = document.createElement('script');
        script.type = 'text/javascript';
        script.src = 'https://maps.googleapis.com/maps/api/js?v=3.exp&sensor=false&' + 'callback=initialize';
        document.body.appendChild(script);
    }

    window.onload = loadScript;
</script>