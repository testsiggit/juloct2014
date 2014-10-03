-- phpMyAdmin SQL Dump
-- version 4.1.12
-- http://www.phpmyadmin.net
--
-- Host: 127.0.0.1
-- Generation Time: Sep 05, 2014 at 08:34 PM
-- Server version: 5.6.16
-- PHP Version: 5.5.11

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Database: `hartdrupal_aug19`
--

-- --------------------------------------------------------

--
-- Table structure for table `da_alternate_address`
--

CREATE TABLE IF NOT EXISTS `da_alternate_address` (
  `alternate_address_id` int(11) NOT NULL AUTO_INCREMENT,
  `permit_master_id` int(11) DEFAULT NULL,
  `rrc_tape_record_id` varchar(2) DEFAULT NULL,
  `alt_address_key` varchar(2) DEFAULT NULL,
  `alt_address_line_1` varchar(33) DEFAULT NULL,
  `alternate_address_2` varchar(35) DEFAULT NULL,
  `rrc_tape_filler` varchar(45) DEFAULT NULL,
  PRIMARY KEY (`alternate_address_id`),
  KEY `alternate address FK_idx` (`permit_master_id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COMMENT='11  - DAALTADD -  DA ALTERNATE ADDRESS SEGMENT' AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `da_bottom_hole_location`
--

CREATE TABLE IF NOT EXISTS `da_bottom_hole_location` (
  `bottom_hole_location_id` int(11) NOT NULL AUTO_INCREMENT,
  `permit_master_id` int(11) NOT NULL,
  `rrc_tape_record_id` varchar(2) DEFAULT NULL,
  `pmt_bhl_section` varchar(8) DEFAULT NULL,
  `pmt_bhl_block` varchar(10) DEFAULT NULL,
  `pmt_bhl_abstract` varchar(6) DEFAULT NULL,
  `pmt_bhl_survey` varchar(55) DEFAULT NULL,
  `pmt_bhl_acres` decimal(8,2) DEFAULT NULL,
  `pmt_bhl_nearest_well` varchar(28) DEFAULT NULL,
  `pmt_bhl_lease_feet_1` varchar(30) DEFAULT NULL,
  `pmt_bhl_lease_direction_1` varchar(13) DEFAULT NULL,
  `pmt_bhl_lease_feet_2` decimal(8,2) DEFAULT NULL,
  `pmt_bhl_lease_directon_2` varchar(13) DEFAULT NULL,
  `pmt_bhl_survey_feet_1` decimal(8,2) DEFAULT NULL,
  `pmt_bhl_survey_direction_1` varchar(13) DEFAULT NULL,
  `pmt_bhl_survey_feet_2` decimal(8,2) DEFAULT NULL,
  `pmt_bhl_survey_direction_2` varchar(13) DEFAULT NULL,
  `pmt_bhl_county` varchar(13) DEFAULT NULL,
  `pmt_bhl_pntrt_dist_1` decimal(8,2) DEFAULT NULL,
  `pmt_bhl_pntrt_dir_1` varchar(213) DEFAULT NULL,
  `pmt_bhl_pntrt_dist_2` decimal(8,2) DEFAULT NULL,
  `pmt_bhl_pntrt_dir_2` varchar(213) DEFAULT NULL,
  `pmt_bhl_surface_lease_feet_1` decimal(8,2) DEFAULT NULL,
  `pmt_bhl_surface_lease_direction_1` varchar(13) DEFAULT NULL,
  `pmt_bhl_surface_lease_feet_2` decimal(8,2) DEFAULT NULL,
  `pmt_bhl_surface_lease_direction_2` varchar(13) DEFAULT NULL,
  `pmt_bhl_surface_lease_total_acres` decimal(8,2) DEFAULT NULL,
  `filler` varchar(6) DEFAULT NULL,
  `rrc_tape_filler` varchar(45) DEFAULT NULL,
  PRIMARY KEY (`bottom_hole_location_id`),
  KEY `bot hole FK_idx` (`permit_master_id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COMMENT='10  - DAPMTBHL  - DA BOTTOM-HOLE LOCATION SEGMENT' AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `da_canned_restrictions`
--

CREATE TABLE IF NOT EXISTS `da_canned_restrictions` (
  `canned_restrictions_id` int(11) NOT NULL AUTO_INCREMENT,
  `permit_master_id` int(11) DEFAULT NULL,
  `rrc_tape_record_id` varchar(2) NOT NULL,
  `can_restr_key` varchar(2) DEFAULT NULL,
  `can_restr_type` varchar(2) DEFAULT NULL,
  `can_restr_remark` varchar(35) DEFAULT NULL,
  PRIMARY KEY (`canned_restrictions_id`),
  KEY `can rest FK_idx` (`permit_master_id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COMMENT='06 - DACANRES - DA CANNED RESTRICTIONS' AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `da_canned_restriction_fields`
--

CREATE TABLE IF NOT EXISTS `da_canned_restriction_fields` (
  `canned_restriction_fields_id` int(11) NOT NULL AUTO_INCREMENT,
  `canned_restrictions_id` int(11) DEFAULT NULL,
  `rrc_tape_record_id` varchar(2) DEFAULT NULL,
  `can_restr_field_number` varchar(8) DEFAULT NULL,
  `filler` varchar(5) DEFAULT NULL,
  PRIMARY KEY (`canned_restriction_fields_id`),
  KEY `can rest fields FK_idx` (`canned_restrictions_id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COMMENT='07 - DACANFLD - DA CANNED RESTRICTION FIELDS' AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `da_check_register`
--

CREATE TABLE IF NOT EXISTS `da_check_register` (
  `check_register_id` int(11) NOT NULL AUTO_INCREMENT,
  `root_id` int(11) NOT NULL,
  `rrc_tape_record_id` varchar(2) DEFAULT NULL,
  `check_register_date` varchar(20) DEFAULT NULL,
  `da_check_register_number` int(20) NOT NULL,
  `filler` varchar(10) DEFAULT NULL,
  `rrc_tape_filler` varchar(45) DEFAULT NULL,
  PRIMARY KEY (`check_register_id`),
  KEY `check register root_id FK_idx` (`root_id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COMMENT='13  - DACHECK  - DA CHECK REGISTER SEGMENT' AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `da_error_log`
--

CREATE TABLE IF NOT EXISTS `da_error_log` (
  `id` int(12) NOT NULL AUTO_INCREMENT,
  `linenumber` int(11) DEFAULT NULL,
  `message` varchar(1000) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `da_field`
--

CREATE TABLE IF NOT EXISTS `da_field` (
  `field_id` int(11) NOT NULL AUTO_INCREMENT,
  `permit_master_id` int(11) DEFAULT NULL,
  `rrc_tape_record_id` varchar(2) DEFAULT NULL,
  `field_number` varchar(8) DEFAULT NULL,
  `field_application_well_code` varchar(1) DEFAULT NULL,
  `field_completion_well_code` varchar(1) DEFAULT NULL,
  `field_completion_code` varchar(1) DEFAULT NULL,
  `field_transfer_code` varchar(1) DEFAULT NULL,
  `field_validation_date` varchar(20) DEFAULT NULL,
  `field_completion_date` varchar(20) DEFAULT NULL,
  `field_rule37_flag` varchar(1) DEFAULT NULL,
  `field_rule38_flag` varchar(1) DEFAULT NULL,
  `filler` varchar(18) DEFAULT NULL,
  `rrc_tape_filler` varchar(45) DEFAULT NULL,
  PRIMARY KEY (`field_id`),
  KEY `field segment FK_idx` (`permit_master_id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COMMENT='03 -  DAFIELD -  DA FIELD SEGMENT' AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `da_field_bottom_hole_location`
--

CREATE TABLE IF NOT EXISTS `da_field_bottom_hole_location` (
  `field_bottom_hole_location_id` int(11) NOT NULL AUTO_INCREMENT,
  `field_id` int(11) DEFAULT NULL,
  `rrc_tape_record_id` varchar(2) DEFAULT NULL,
  `fld_bhl_section` varchar(8) DEFAULT NULL,
  `fld_bhl_block` varchar(10) DEFAULT NULL,
  `fld_bhl_abstract` varchar(6) DEFAULT NULL,
  `fld_bhl_survey` varchar(55) DEFAULT NULL,
  `fld_bhl_acres` decimal(18,2) DEFAULT NULL,
  `fld_bhl_nearest_well` varchar(28) DEFAULT NULL,
  `fld_bhl_lease_feet_1` decimal(18,2) DEFAULT NULL,
  `fld_bhl_lease_direction_1` varchar(13) DEFAULT NULL,
  `fld_bhl_lease_feet_2` decimal(18,2) DEFAULT NULL,
  `fld_bhl_lease_direction_2` varchar(13) DEFAULT NULL,
  `fld_bhl_survey_feet_1` decimal(18,2) DEFAULT NULL,
  `fld_bhl_survey_direction_1` varchar(13) DEFAULT NULL,
  `fld_bhl_survey_feet_2` decimal(18,2) DEFAULT NULL,
  `fld_bhl_survey_direction_2` varchar(13) DEFAULT NULL,
  `fld_bhl_county` varchar(13) DEFAULT NULL,
  `fld_bhl_pntrt_dist_1` decimal(18,2) DEFAULT NULL,
  `fld_bhl_pntrt_dir_1` varchar(13) DEFAULT NULL,
  `fld_bhl_pntrt_dist_2` decimal(18,2) DEFAULT NULL,
  `fld_bhl_pntrt_dir_2` varchar(13) DEFAULT NULL,
  `filler` varchar(6) DEFAULT NULL,
  `rrc_tape_filler` varchar(45) DEFAULT NULL,
  PRIMARY KEY (`field_bottom_hole_location_id`),
  KEY `fbhl FK_idx` (`field_id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COMMENT='05  - DAFLDBHL - DA FIELD BOTTOM-HOLE LOCATION SEGMENT' AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `da_field_specific_data`
--

CREATE TABLE IF NOT EXISTS `da_field_specific_data` (
  `field_specific_data_id` int(11) NOT NULL AUTO_INCREMENT,
  `field_id` int(11) DEFAULT NULL,
  `rrc_tape_record_id` varchar(2) DEFAULT NULL,
  `field_district` varchar(2) DEFAULT NULL,
  `field_lease_name` varchar(32) DEFAULT NULL,
  `field_total_depth` varchar(5) DEFAULT NULL,
  `field_well_number` varchar(6) DEFAULT NULL,
  `field_acres` decimal(18,2) DEFAULT NULL,
  `filler` varchar(17) DEFAULT NULL,
  `rrc_tape_filler` varchar(45) DEFAULT NULL,
  PRIMARY KEY (`field_specific_data_id`),
  KEY `field segment FK_idx` (`field_id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COMMENT='04 - DAFLDSPC -  DA FIELD SPECIFIC DATA SEGMENT' AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `da_free_form_restrictions`
--

CREATE TABLE IF NOT EXISTS `da_free_form_restrictions` (
  `free_form_restrictions_id` int(11) NOT NULL AUTO_INCREMENT,
  `permit_master_id` int(11) DEFAULT NULL,
  `rrc_tape_record_id` varchar(2) DEFAULT NULL,
  `free_restr_key` varchar(2) DEFAULT NULL,
  `free_restr_type` varchar(2) DEFAULT NULL,
  `free_restr_remark` varchar(2000) DEFAULT NULL,
  `free_restr_flag` varchar(1) DEFAULT NULL,
  `filler` varchar(10) DEFAULT NULL,
  `rrc_tape_filler` varchar(45) DEFAULT NULL,
  PRIMARY KEY (`free_form_restrictions_id`),
  KEY `free form rest FK_idx` (`permit_master_id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COMMENT='08 - DAFRERES - DA FREE-FORM RESTRICTIONS' AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `da_free_form_restriction_fields`
--

CREATE TABLE IF NOT EXISTS `da_free_form_restriction_fields` (
  `free_form_restriction_fields_id` int(11) NOT NULL AUTO_INCREMENT,
  `free_form_restrictions_id` int(11) DEFAULT NULL,
  `rrc_tape_record_id` varchar(2) DEFAULT NULL,
  `free_restr_fld_number` varchar(8) DEFAULT NULL,
  `filler` varchar(5) DEFAULT NULL,
  `rrc_tape_filler` varchar(45) DEFAULT NULL,
  PRIMARY KEY (`free_form_restriction_fields_id`),
  KEY `ff rest fields FK_idx` (`free_form_restrictions_id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COMMENT='09 - DAFREFLD - DA FREE-FORM RESTRICTION FIELDS' AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `da_gis_bottom_hole_location_coordinates`
--

CREATE TABLE IF NOT EXISTS `da_gis_bottom_hole_location_coordinates` (
  `gis_bot_hole_loc_coord_id` int(11) NOT NULL AUTO_INCREMENT,
  `root_id` int(11) DEFAULT NULL,
  `bottom_hole_longitude` varchar(45) DEFAULT NULL,
  `bottom_hole_lattitude` varchar(45) DEFAULT NULL,
  PRIMARY KEY (`gis_bot_hole_loc_coord_id`),
  KEY `root_id_idx` (`root_id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COMMENT='15  - DAW999B1  - DA GIS BOTTOM HOLE LOCATION COORDINATES' AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `da_gis_surface_location_coordinates`
--

CREATE TABLE IF NOT EXISTS `da_gis_surface_location_coordinates` (
  `gis_surf_loc_coord_id` int(11) NOT NULL AUTO_INCREMENT,
  `root_id` int(11) DEFAULT NULL,
  `surf_loc_longitude` varchar(45) DEFAULT NULL,
  `surf_loc_lattitude` varchar(45) DEFAULT NULL,
  PRIMARY KEY (`gis_surf_loc_coord_id`),
  KEY `root_id_idx` (`root_id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COMMENT='14  - DAW999A1  - DA GIS SURFACE LOCATION COORDINATES' AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `da_permit_master`
--

CREATE TABLE IF NOT EXISTS `da_permit_master` (
  `permit_master_id` int(11) NOT NULL AUTO_INCREMENT,
  `root_id` int(11) DEFAULT NULL,
  `rrc_tape_record_id` varchar(2) DEFAULT NULL,
  `permit_number` varchar(7) DEFAULT NULL,
  `permit_sequence_number` varchar(2) DEFAULT NULL,
  `permit_county_code` varchar(3) DEFAULT NULL,
  `permit_lease_name` varchar(32) DEFAULT NULL,
  `permit_district` varchar(2) DEFAULT NULL,
  `permit_well_number` varchar(6) DEFAULT NULL,
  `permit_total_depth` decimal(5,0) DEFAULT NULL,
  `permit_operator_number` varchar(6) DEFAULT NULL,
  `type_application` varchar(2) DEFAULT NULL,
  `other_explanation` varchar(30) DEFAULT NULL,
  `address_unique_number` varchar(6) DEFAULT NULL,
  `zip_code_prefix` varchar(5) DEFAULT NULL,
  `zip_code_suffix` varchar(4) DEFAULT NULL,
  `fiche_set_number` varchar(6) DEFAULT NULL,
  `onshore_county` varchar(3) DEFAULT NULL,
  `da_received_century` int(20) DEFAULT NULL,
  `da_received_year` int(10) NOT NULL,
  `da_received_month` int(10) NOT NULL,
  `da_received_day` int(10) NOT NULL,
  `da_received_date` date DEFAULT NULL,
  `da_pmt_issued_century` int(20) DEFAULT NULL,
  `da_pmt_issued_year` int(10) NOT NULL,
  `da_pmt_issued_month` int(10) NOT NULL,
  `da_pmt_issued_day` int(10) NOT NULL,
  `da_pmt_issued_date` date DEFAULT NULL,
  `da_pmt_amended_century` int(20) DEFAULT NULL,
  `da_pmt_amended_year` int(10) NOT NULL,
  `da_pmt_amended_month` int(10) NOT NULL,
  `da_pmt_amended_day` int(10) NOT NULL,
  `da_pmt_amended_date` date DEFAULT NULL,
  `da_pmt_extented_century` varchar(20) DEFAULT NULL,
  `da_pmt_extented_year` int(10) NOT NULL,
  `da_pmt_extented_month` int(10) NOT NULL,
  `da_pmt_extented_day` int(10) NOT NULL,
  `da_pmt_extented_date` date DEFAULT NULL,
  `da_pmt_spud_century` varchar(20) DEFAULT NULL,
  `da_pmt_spud_year` int(10) NOT NULL,
  `da_pmt_spud_month` int(10) NOT NULL,
  `da_pmt_spud_day` int(10) NOT NULL,
  `da_pmt_spud_date` date DEFAULT NULL,
  `da_pmt_surface_casting_century` varchar(20) DEFAULT NULL,
  `da_pmt_surface_casting_year` int(10) NOT NULL,
  `da_pmt_surface_casting_month` int(10) NOT NULL,
  `da_pmt_surface_casting_day` int(10) NOT NULL,
  `da_pmt_surface_casting_date` date DEFAULT NULL,
  `well_staus` varchar(1) DEFAULT NULL,
  `da_pmt_well_status_century` varchar(20) DEFAULT NULL,
  `da_pmt_well_status_year` int(10) NOT NULL,
  `da_pmt_well_status_month` int(10) NOT NULL,
  `da_pmt_well_status_day` int(10) DEFAULT NULL,
  `da_pmt_well_status_date` date DEFAULT NULL,
  `da_pmt_expired_century` varchar(20) DEFAULT NULL,
  `da_pmt_expired_year` int(10) NOT NULL,
  `da_pmt_expired_month` int(10) NOT NULL,
  `da_pmt_expired_day` int(10) NOT NULL,
  `da_pmt_expired_date` date DEFAULT NULL,
  `da_pmt_cancelled_century` varchar(20) DEFAULT NULL,
  `da_pmt_cancelled_year` int(10) NOT NULL,
  `da_pmt_cancelled_month` int(10) NOT NULL,
  `da_pmt_cancelled_day` int(10) NOT NULL,
  `da_pmt_cancelled_date` date DEFAULT NULL,
  `cancellation_reason` varchar(45) DEFAULT NULL,
  `p12_filed_flag` varchar(1) DEFAULT NULL,
  `substandard_acreage_flag` varchar(1) DEFAULT NULL,
  `rule_36_flag` varchar(1) DEFAULT NULL,
  `h9_flag` varchar(1) DEFAULT NULL,
  `rule_37_case_number` varchar(7) DEFAULT NULL,
  `rule_38_docket_number` varchar(7) DEFAULT NULL,
  `location_formation_flag` varchar(1) DEFAULT NULL,
  `old_surface_location` varchar(52) DEFAULT NULL,
  `old_surface_filler` varchar(30) DEFAULT NULL,
  `new_surface_section` varchar(8) DEFAULT NULL,
  `new_surface_block` varchar(10) DEFAULT NULL,
  `new_surface_survey` varchar(55) DEFAULT NULL,
  `new_surface_abstract` varchar(6) DEFAULT NULL,
  `new_surface_filler` varchar(3) DEFAULT NULL,
  `surface_acres` varchar(8) DEFAULT NULL,
  `surface_miles_from_city` varchar(6) DEFAULT NULL,
  `surface_direction_from_city` varchar(6) DEFAULT NULL,
  `surface_nearest_city` varchar(13) DEFAULT NULL,
  `surface_lease_feet_1` varchar(8) DEFAULT NULL,
  `surface_lease_direction_1` varchar(13) DEFAULT NULL,
  `surface_lease_feet_2` varchar(8) DEFAULT NULL,
  `surface_lease_direction_2` varchar(13) DEFAULT NULL,
  `surface_survey_feet_1` varchar(8) DEFAULT NULL,
  `surface_survey_direction_1` varchar(13) DEFAULT NULL,
  `surface_survey_feet_2` varchar(8) DEFAULT NULL,
  `surface_survey_dierction_2` varchar(13) DEFAULT NULL,
  `nearest_well` varchar(28) DEFAULT NULL,
  `nearest_well_format_flag` varchar(1) DEFAULT NULL,
  `final_update` varchar(20) DEFAULT NULL,
  `cancelled_flag` varchar(1) DEFAULT NULL,
  `spud_in_flag` varchar(1) DEFAULT NULL,
  `directional_well_flag` varchar(1) DEFAULT NULL,
  `sidetrack_well_flag` varchar(1) DEFAULT NULL,
  `moved_indicator` varchar(1) DEFAULT NULL,
  `permit_conv_issued_date` int(20) DEFAULT NULL,
  `rule_37_granted_code` varchar(1) DEFAULT NULL,
  `horizontal_well_flag` varchar(1) DEFAULT NULL,
  `duplicate_permit_flag` varchar(1) DEFAULT NULL,
  `nearest_lease_line` varchar(7) DEFAULT NULL,
  `api_number` varchar(8) DEFAULT NULL,
  `rrc_tape_filler` varchar(45) DEFAULT NULL,
  PRIMARY KEY (`permit_master_id`),
  KEY `permit table root id foreign key_idx` (`root_id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COMMENT='02 -  DAPERMIT - DA PERMIT MASTER SEGMENT' AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `da_permit_remarks`
--

CREATE TABLE IF NOT EXISTS `da_permit_remarks` (
  `permit_remarks_id` int(11) NOT NULL,
  `root_id` int(11) DEFAULT NULL,
  `rrc_tape_record_id` varchar(2) DEFAULT NULL,
  `remark_sequence_number` varchar(3) DEFAULT NULL,
  `remark_file_date` varchar(20) DEFAULT NULL,
  `remark_line` varchar(70) DEFAULT NULL,
  `filler` varchar(10) DEFAULT NULL,
  `rrc_tape_filler` varchar(45) DEFAULT NULL,
  PRIMARY KEY (`permit_remarks_id`),
  KEY `permit remarks root_id FK_idx` (`root_id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COMMENT='12  - DAREMARK -  DA PERMIT REMARKS';

-- --------------------------------------------------------

--
-- Table structure for table `da_processed_files`
--

CREATE TABLE IF NOT EXISTS `da_processed_files` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `filename` varchar(25) NOT NULL,
  `modified_time` datetime NOT NULL,
  `processed_time` datetime NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `da_root`
--

CREATE TABLE IF NOT EXISTS `da_root` (
  `root_id` int(11) NOT NULL AUTO_INCREMENT,
  `rrc_tape_record_id` varchar(2) DEFAULT NULL,
  `status_number` varchar(7) NOT NULL,
  `status_sequence_number` varchar(2) NOT NULL,
  `county_code` varchar(3) DEFAULT NULL,
  `lease_name` varchar(32) DEFAULT NULL,
  `district` varchar(2) DEFAULT NULL,
  `operator_number` varchar(6) DEFAULT NULL,
  `converted_date` int(11) DEFAULT NULL,
  `da_app_rcvd_century` int(20) DEFAULT NULL,
  `da_app_rcvd_year` int(10) NOT NULL,
  `da_app_rcvd_month` int(15) NOT NULL,
  `da_app_rcvd_day` int(15) NOT NULL,
  `da_app_rcvd_date` date DEFAULT NULL,
  `operator_name` varchar(32) DEFAULT NULL,
  `filler` varchar(1) DEFAULT NULL,
  `hb1407_problem_flag` varchar(1) DEFAULT NULL,
  `status_of_app_flag` varchar(1) DEFAULT NULL,
  `not_enough_money_flag` varchar(1) DEFAULT NULL,
  `too_much_money_flag` varchar(1) DEFAULT NULL,
  `p5_problem_flag` varchar(1) DEFAULT NULL,
  `p12_problem_flag` varchar(1) DEFAULT NULL,
  `plat_problem_flag` varchar(1) DEFAULT NULL,
  `w1a_problem_flag` varchar(1) DEFAULT NULL,
  `other_problem_flag` varchar(1) DEFAULT NULL,
  `rule37_problem_flag` varchar(1) DEFAULT NULL,
  `rule38_problem_flag` varchar(1) DEFAULT NULL,
  `rule39_problem_flag` varchar(1) DEFAULT NULL,
  `no_money_flag` varchar(1) DEFAULT NULL,
  `permit` varchar(7) DEFAULT NULL,
  `da_issue_century` int(20) DEFAULT NULL,
  `da_issue_year` int(20) NOT NULL,
  `da_issue_month` int(20) NOT NULL,
  `da_issue_day` int(20) NOT NULL,
  `da_issue_date` date DEFAULT NULL,
  `da_withdrawn_century` int(20) DEFAULT NULL,
  `da_withdrawn_year` int(20) NOT NULL,
  `da_withdrawn_month` int(20) NOT NULL,
  `da_withdrawn_day` int(20) NOT NULL,
  `da_withdrawn_date` date DEFAULT NULL,
  `walkthrough_flag` varchar(1) DEFAULT NULL,
  `other_problem_text` varchar(20) DEFAULT NULL,
  `well_number` varchar(6) DEFAULT NULL,
  `built_from_old_master_flag` varchar(1) DEFAULT NULL,
  `status_renumbered_to` varchar(9) DEFAULT NULL,
  `status_renumbered_from` varchar(9) DEFAULT NULL,
  `application_returned_flag` varchar(1) DEFAULT NULL,
  `problem_flag_filler` varchar(29) DEFAULT NULL,
  `rrc_tape_filler` varchar(45) DEFAULT NULL,
  PRIMARY KEY (`root_id`),
  KEY `ROOT SRCH IND` (`da_issue_century`),
  KEY `ROOT SRCH IND2` (`permit`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 AUTO_INCREMENT=1 ;

--
-- Constraints for dumped tables
--

--
-- Constraints for table `da_alternate_address`
--
ALTER TABLE `da_alternate_address`
  ADD CONSTRAINT `alternate address FK` FOREIGN KEY (`permit_master_id`) REFERENCES `da_permit_master` (`permit_master_id`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Constraints for table `da_bottom_hole_location`
--
ALTER TABLE `da_bottom_hole_location`
  ADD CONSTRAINT `bot hole FK` FOREIGN KEY (`permit_master_id`) REFERENCES `da_permit_master` (`permit_master_id`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Constraints for table `da_canned_restrictions`
--
ALTER TABLE `da_canned_restrictions`
  ADD CONSTRAINT `can rest FK` FOREIGN KEY (`permit_master_id`) REFERENCES `da_permit_master` (`permit_master_id`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Constraints for table `da_canned_restriction_fields`
--
ALTER TABLE `da_canned_restriction_fields`
  ADD CONSTRAINT `can rest fields FK` FOREIGN KEY (`canned_restrictions_id`) REFERENCES `da_canned_restrictions` (`canned_restrictions_id`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Constraints for table `da_check_register`
--
ALTER TABLE `da_check_register`
  ADD CONSTRAINT `check register root_id FK` FOREIGN KEY (`root_id`) REFERENCES `da_root` (`root_id`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Constraints for table `da_field`
--
ALTER TABLE `da_field`
  ADD CONSTRAINT `field segment FK` FOREIGN KEY (`permit_master_id`) REFERENCES `da_permit_master` (`permit_master_id`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Constraints for table `da_field_bottom_hole_location`
--
ALTER TABLE `da_field_bottom_hole_location`
  ADD CONSTRAINT `fbhl FK` FOREIGN KEY (`field_id`) REFERENCES `da_field` (`field_id`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Constraints for table `da_field_specific_data`
--
ALTER TABLE `da_field_specific_data`
  ADD CONSTRAINT `fsd FK` FOREIGN KEY (`field_id`) REFERENCES `da_field` (`field_id`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Constraints for table `da_free_form_restrictions`
--
ALTER TABLE `da_free_form_restrictions`
  ADD CONSTRAINT `free form rest FK` FOREIGN KEY (`permit_master_id`) REFERENCES `da_permit_master` (`permit_master_id`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Constraints for table `da_free_form_restriction_fields`
--
ALTER TABLE `da_free_form_restriction_fields`
  ADD CONSTRAINT `ff rest fields FK` FOREIGN KEY (`free_form_restrictions_id`) REFERENCES `da_free_form_restrictions` (`free_form_restrictions_id`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Constraints for table `da_gis_bottom_hole_location_coordinates`
--
ALTER TABLE `da_gis_bottom_hole_location_coordinates`
  ADD CONSTRAINT `root id 2` FOREIGN KEY (`root_id`) REFERENCES `da_root` (`root_id`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Constraints for table `da_gis_surface_location_coordinates`
--
ALTER TABLE `da_gis_surface_location_coordinates`
  ADD CONSTRAINT `root id` FOREIGN KEY (`root_id`) REFERENCES `da_root` (`root_id`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Constraints for table `da_permit_master`
--
ALTER TABLE `da_permit_master`
  ADD CONSTRAINT `permit table root id foreign key` FOREIGN KEY (`root_id`) REFERENCES `da_root` (`root_id`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Constraints for table `da_permit_remarks`
--
ALTER TABLE `da_permit_remarks`
  ADD CONSTRAINT `permit remarks root_id FK` FOREIGN KEY (`root_id`) REFERENCES `da_root` (`root_id`) ON DELETE NO ACTION ON UPDATE NO ACTION;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
