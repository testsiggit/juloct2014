-- phpMyAdmin SQL Dump
-- version 4.1.12
-- http://www.phpmyadmin.net
--
-- Host: 127.0.0.1
-- Generation Time: Sep 11, 2014 at 05:32 PM
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
-- Table structure for table `da_processed_files`
--

CREATE TABLE IF NOT EXISTS `da_processed_files` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `original_filename` varchar(250) DEFAULT NULL,
  `processing_filename` varchar(250) DEFAULT NULL,
  `proc_file_mod_time` datetime DEFAULT NULL,
  `process_start_time` datetime DEFAULT NULL,
  `process_end_time` datetime DEFAULT NULL,
  `process_status` varchar(25) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 AUTO_INCREMENT=1 ;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
