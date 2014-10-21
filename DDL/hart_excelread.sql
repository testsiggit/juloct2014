-- phpMyAdmin SQL Dump
-- version 4.1.12
-- http://www.phpmyadmin.net
--
-- Host: 127.0.0.1
-- Generation Time: Oct 16, 2014 at 12:16 PM
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
-- Table structure for table `oa_company`
--

CREATE TABLE IF NOT EXISTS `oa_company` (
  `company_id` int(11) NOT NULL AUTO_INCREMENT,
  `company_name` varchar(500) DEFAULT NULL,
  `ticker` varchar(1000) DEFAULT NULL,
  `exchange` varchar(100) DEFAULT NULL,
  `production` varchar(2000) DEFAULT NULL,
  `acreage` varchar(2000) DEFAULT NULL,
  `reserves` varchar(2000) DEFAULT NULL,
  `wells_drilled` varchar(2000) DEFAULT NULL,
  `other_comments` longtext CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci,
  `website_text` varchar(100) DEFAULT NULL,
  `website_url` varchar(2090) DEFAULT NULL,
  `latest_presentation_text` varchar(100) DEFAULT NULL,
  `latest_presentaion_url` varchar(2090) DEFAULT NULL,
  `updated_on` date DEFAULT NULL,
  PRIMARY KEY (`company_id`),
  UNIQUE KEY `company_name_UNIQUE` (`company_name`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COMMENT='Company Table' AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `oa_company_annual_capex`
--

CREATE TABLE IF NOT EXISTS `oa_company_annual_capex` (
  `ca_capex_id` int(11) NOT NULL AUTO_INCREMENT,
  `company_id` int(11) DEFAULT NULL,
  `year` varchar(4) DEFAULT NULL,
  `capex` varchar(2000) DEFAULT NULL,
  `estimated` tinyint(1) DEFAULT '0',
  PRIMARY KEY (`ca_capex_id`),
  KEY `ca capex cid_idx` (`company_id`),
  KEY `year` (`year`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `oa_company_annual_ebidax`
--

CREATE TABLE IF NOT EXISTS `oa_company_annual_ebidax` (
  `ca_ebidax_id` int(11) NOT NULL AUTO_INCREMENT,
  `company_id` int(11) DEFAULT NULL,
  `year` varchar(4) DEFAULT NULL,
  `ebidax` varchar(2000) DEFAULT NULL,
  `estimated` tinyint(1) DEFAULT '0',
  PRIMARY KEY (`ca_ebidax_id`),
  KEY `ca ebidax cid_idx` (`company_id`),
  KEY `year` (`year`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `oa_company_annual_report`
--

CREATE TABLE IF NOT EXISTS `oa_company_annual_report` (
  `annual_report_id` int(11) NOT NULL AUTO_INCREMENT,
  `company_id` int(11) DEFAULT NULL,
  `year` varchar(4) DEFAULT NULL,
  `report_url` varchar(2090) DEFAULT NULL,
  PRIMARY KEY (`annual_report_id`),
  KEY `annual report comp id_idx` (`company_id`),
  KEY `year` (`year`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `oa_company_play`
--

CREATE TABLE IF NOT EXISTS `oa_company_play` (
  `company_play_id` int(11) NOT NULL AUTO_INCREMENT,
  `company_id` int(11) DEFAULT NULL,
  `play_id` int(11) DEFAULT NULL,
  PRIMARY KEY (`company_play_id`),
  KEY `cp cid_idx` (`company_id`),
  KEY `cp pid_idx` (`play_id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `oa_company_play_annual_capex`
--

CREATE TABLE IF NOT EXISTS `oa_company_play_annual_capex` (
  `cpa_capex_id` int(11) NOT NULL AUTO_INCREMENT,
  `company_play_id` int(11) DEFAULT NULL,
  `cpd_id` int(11) NOT NULL COMMENT 'This is FK of Company Play details',
  `year` varchar(4) DEFAULT NULL,
  `capex` varchar(2000) DEFAULT NULL,
  `estimated` tinyint(1) DEFAULT '0',
  PRIMARY KEY (`cpa_capex_id`),
  KEY `cpa capex cid_idx` (`company_play_id`),
  KEY `cpd_id` (`cpd_id`),
  KEY `year` (`year`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `oa_company_play_annual_production`
--

CREATE TABLE IF NOT EXISTS `oa_company_play_annual_production` (
  `cpa_production_id` int(11) NOT NULL AUTO_INCREMENT,
  `company_play_id` int(11) DEFAULT NULL,
  `cpd_id` int(11) NOT NULL COMMENT 'This is FK of Company Play details',
  `year` varchar(4) DEFAULT NULL,
  `production` varchar(2000) DEFAULT NULL,
  `estimated` tinyint(1) DEFAULT '0',
  PRIMARY KEY (`cpa_production_id`),
  KEY `cpa production cid_idx` (`company_play_id`),
  KEY `cpd_id` (`cpd_id`),
  KEY `year` (`year`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `oa_company_play_annual_wells`
--

CREATE TABLE IF NOT EXISTS `oa_company_play_annual_wells` (
  `cpa_wells_id` int(11) NOT NULL AUTO_INCREMENT,
  `company_play_id` int(11) DEFAULT NULL,
  `cpd_id` int(11) NOT NULL COMMENT 'This is FK of Company Play details',
  `year` varchar(4) DEFAULT NULL,
  `well` varchar(2000) DEFAULT NULL,
  `estimated` tinyint(1) DEFAULT '0',
  PRIMARY KEY (`cpa_wells_id`),
  KEY `cpa wells cid_idx` (`company_play_id`),
  KEY `cpd_id` (`cpd_id`),
  KEY `year` (`year`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `oa_company_play_details`
--

CREATE TABLE IF NOT EXISTS `oa_company_play_details` (
  `cpd_id` int(11) NOT NULL AUTO_INCREMENT,
  `company_play_id` int(11) DEFAULT NULL,
  `location` varchar(2000) DEFAULT NULL,
  `project_field` varchar(2000) DEFAULT NULL,
  `entered_play` varchar(2000) DEFAULT NULL,
  `depth` varchar(2000) DEFAULT NULL,
  `acres_gross_net` varchar(2000) DEFAULT NULL,
  `jvs` varchar(2000) DEFAULT NULL,
  `well_cost` varchar(2000) DEFAULT NULL,
  `most_recent_quarter` varchar(2000) DEFAULT NULL,
  `number_of_rigs` varchar(2000) DEFAULT NULL,
  `well_spacing` varchar(2000) DEFAULT NULL,
  `inventory` varchar(2000) DEFAULT NULL,
  `completions` varchar(2000) DEFAULT NULL,
  `ip` varchar(2000) DEFAULT NULL,
  `eur` varchar(2000) DEFAULT NULL,
  `total_prod_wells` varchar(2000) DEFAULT NULL,
  `reserves` varchar(2000) DEFAULT NULL,
  `resource_potential` varchar(2000) DEFAULT NULL,
  `comment` longtext CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci,
  PRIMARY KEY (`cpd_id`),
  KEY `Company Id_idx` (`company_play_id`),
  KEY `location` (`location`(767)),
  KEY `project_field` (`project_field`(767))
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COMMENT='Company Play details' AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `oa_company_quarter_report`
--

CREATE TABLE IF NOT EXISTS `oa_company_quarter_report` (
  `quarter_report_id` int(11) NOT NULL AUTO_INCREMENT,
  `company_id` int(11) DEFAULT NULL,
  `quarter_code` char(2) DEFAULT NULL,
  `year` varchar(4) DEFAULT NULL,
  `quarter_report_url` varchar(2090) DEFAULT NULL,
  `presentation_text` varchar(100) DEFAULT NULL,
  `presentation_url` varchar(2090) DEFAULT NULL,
  PRIMARY KEY (`quarter_report_id`),
  KEY `cqr comp id_idx` (`company_id`),
  KEY `quarter id_idx` (`quarter_code`),
  KEY `year` (`year`),
  KEY `quarter_code` (`quarter_code`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `oa_log_table`
--

CREATE TABLE IF NOT EXISTS `oa_log_table` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `fid` int(11) DEFAULT NULL,
  `sheet_title` varchar(250) DEFAULT NULL,
  `sheet_column` varchar(5) DEFAULT NULL,
  `sheet_row` varchar(5) DEFAULT NULL,
  `message` longtext,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `oa_play`
--

CREATE TABLE IF NOT EXISTS `oa_play` (
  `play_id` int(11) NOT NULL AUTO_INCREMENT,
  `play_name` varchar(500) DEFAULT NULL,
  `play_comment` varchar(2000) DEFAULT NULL,
  PRIMARY KEY (`play_id`),
  UNIQUE KEY `play_name_UNIQUE` (`play_name`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COMMENT='Play table' AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `oa_processed_files`
--

CREATE TABLE IF NOT EXISTS `oa_processed_files` (
  `fid` int(11) NOT NULL AUTO_INCREMENT,
  `filename` varchar(500) DEFAULT NULL,
  `modtime` datetime DEFAULT NULL,
  `processtime` datetime DEFAULT NULL,
  `process_end_time` datetime DEFAULT NULL,
  PRIMARY KEY (`fid`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `oa_quarter`
--

CREATE TABLE IF NOT EXISTS `oa_quarter` (
  `quarter_code` char(2) NOT NULL,
  `start_date` varchar(6) DEFAULT NULL,
  `end_date` varchar(6) DEFAULT NULL,
  PRIMARY KEY (`quarter_code`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `oa_quarter`
--

INSERT INTO `oa_quarter` (`quarter_code`, `start_date`, `end_date`) VALUES
('1Q', NULL, NULL),
('2Q', NULL, NULL),
('3Q', NULL, NULL),
('4Q', NULL, NULL);

--
-- Constraints for dumped tables
--

--
-- Constraints for table `oa_company_annual_capex`
--
ALTER TABLE `oa_company_annual_capex`
  ADD CONSTRAINT `ca capex cid` FOREIGN KEY (`company_id`) REFERENCES `oa_company` (`company_id`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Constraints for table `oa_company_annual_ebidax`
--
ALTER TABLE `oa_company_annual_ebidax`
  ADD CONSTRAINT `ca ebidax cid` FOREIGN KEY (`company_id`) REFERENCES `oa_company` (`company_id`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Constraints for table `oa_company_annual_report`
--
ALTER TABLE `oa_company_annual_report`
  ADD CONSTRAINT `car cid` FOREIGN KEY (`company_id`) REFERENCES `oa_company` (`company_id`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Constraints for table `oa_company_play`
--
ALTER TABLE `oa_company_play`
  ADD CONSTRAINT `cp cid` FOREIGN KEY (`company_id`) REFERENCES `oa_company` (`company_id`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `cp pid` FOREIGN KEY (`play_id`) REFERENCES `oa_play` (`play_id`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Constraints for table `oa_company_play_annual_capex`
--
ALTER TABLE `oa_company_play_annual_capex`
  ADD CONSTRAINT `cpac cpid` FOREIGN KEY (`company_play_id`) REFERENCES `oa_company_play` (`company_play_id`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Constraints for table `oa_company_play_annual_production`
--
ALTER TABLE `oa_company_play_annual_production`
  ADD CONSTRAINT `cpap cpid` FOREIGN KEY (`company_play_id`) REFERENCES `oa_company_play` (`company_play_id`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Constraints for table `oa_company_play_annual_wells`
--
ALTER TABLE `oa_company_play_annual_wells`
  ADD CONSTRAINT `cpaw cpid` FOREIGN KEY (`company_play_id`) REFERENCES `oa_company_play` (`company_play_id`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Constraints for table `oa_company_play_details`
--
ALTER TABLE `oa_company_play_details`
  ADD CONSTRAINT `cpd cpid` FOREIGN KEY (`company_play_id`) REFERENCES `oa_company_play` (`company_play_id`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Constraints for table `oa_company_quarter_report`
--
ALTER TABLE `oa_company_quarter_report`
  ADD CONSTRAINT `cqr cid` FOREIGN KEY (`company_id`) REFERENCES `oa_company` (`company_id`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `cqr qcode` FOREIGN KEY (`quarter_code`) REFERENCES `oa_quarter` (`quarter_code`) ON DELETE NO ACTION ON UPDATE NO ACTION;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
