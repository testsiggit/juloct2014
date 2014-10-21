-- phpMyAdmin SQL Dump
-- version 4.1.12
-- http://www.phpmyadmin.net
--
-- Host: 127.0.0.1
-- Generation Time: Oct 19, 2014 at 09:47 AM
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
-- Table structure for table `ea_alert_config`
--

CREATE TABLE IF NOT EXISTS `ea_alert_config` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `alert_id` int(11) DEFAULT NULL,
  `condition_id` int(11) DEFAULT NULL,
  `condition_value` varchar(100) DEFAULT NULL,
  `additional_notes` varchar(100) DEFAULT NULL,
  PRIMARY KEY (`id`),
  KEY `ea conditon id_idx` (`condition_id`),
  KEY `ea alert id_idx` (`alert_id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `ea_condition`
--

CREATE TABLE IF NOT EXISTS `ea_condition` (
  `condition_id` int(11) NOT NULL AUTO_INCREMENT,
  `table_field` varchar(100) NOT NULL,
  `form_field` varchar(100) NOT NULL,
  `label_text` varchar(50) NOT NULL,
  `comments` text NOT NULL,
  PRIMARY KEY (`condition_id`),
  UNIQUE KEY `form_field` (`form_field`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=8 ;

--
-- Dumping data for table `ea_condition`
--

INSERT INTO `ea_condition` (`condition_id`, `table_field`, `form_field`, `label_text`, `comments`) VALUES
(1, 'da_root.status_of_app_flag', 'status_of_app_flag', 'Status', ''),
(2, 'da_field.field_application_well_code', 'field_application_well_code', 'Well Type', ''),
(3, 'da_root.county_code', 'county_code', 'County', ''),
(4, 'da_root.operator_name', 'operator_name', 'Company / Operator ', ''),
(5, 'da_permit_master.permit_total_depth', 'permit_total_depth', 'Total Depth', ''),
(6, 'dp_wellbore_profile.wp_code', 'wp_code', 'Wellbore Profiles', ''),
(7, 'dp_play.play', 'play', 'Play', 'dp_play.county_code==da_root.county_code AND dp.district_code=da_root.district');

-- --------------------------------------------------------

--
-- Table structure for table `ea_email_matching_apis`
--

CREATE TABLE IF NOT EXISTS `ea_email_matching_apis` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `sent_email_id` int(11) DEFAULT NULL COMMENT '''id'' from ''ea_saving_sent_emails'' table',
  `api_number` varchar(8) DEFAULT NULL,
  `status_number` varchar(7) DEFAULT NULL,
  `sequence_number` varchar(2) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `ea_saving_sent_emails`
--

CREATE TABLE IF NOT EXISTS `ea_saving_sent_emails` (
  `id` int(100) NOT NULL AUTO_INCREMENT,
  `uid` int(11) DEFAULT NULL COMMENT '''uid'' from ''users'' table',
  `file_id` int(11) DEFAULT NULL COMMENT '''id'' from ''da_processed_files'' table',
  `alert_id` int(50) DEFAULT NULL COMMENT '''alert_id'' from ''ea_user_alerts'' table',
  `subject` varchar(500) DEFAULT NULL,
  `sent_on` datetime DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `ea_user_alerts`
--

CREATE TABLE IF NOT EXISTS `ea_user_alerts` (
  `alert_id` int(11) NOT NULL AUTO_INCREMENT,
  `uid` int(11) DEFAULT NULL,
  `alert_name` varchar(100) DEFAULT NULL,
  `alert_description` text,
  `status` tinyint(1) NOT NULL DEFAULT '0',
  PRIMARY KEY (`alert_id`),
  KEY `user alert uid_idx` (`uid`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 AUTO_INCREMENT=1 ;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
