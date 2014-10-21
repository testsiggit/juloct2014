-- phpMyAdmin SQL Dump
-- version 4.1.12
-- http://www.phpmyadmin.net
--
-- Host: 127.0.0.1
-- Generation Time: Oct 16, 2014 at 12:20 PM
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
-- Table structure for table `dp_county`
--

CREATE TABLE IF NOT EXISTS `dp_county` (
  `county_code` char(3) NOT NULL,
  `county_name` varchar(45) NOT NULL,
  PRIMARY KEY (`county_code`),
  KEY `county_name` (`county_name`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `dp_county`
--

INSERT INTO `dp_county` (`county_code`, `county_name`) VALUES
('001', 'ANDERSON'),
('003', 'ANDREWS'),
('005', 'ANGELINA'),
('007', 'ARANSAS'),
('009', 'ARCHER'),
('011', 'ARMSTRONG'),
('013', 'ATASCOSA'),
('015', 'AUSTIN'),
('017', 'BAILEY'),
('019', 'BANDERA'),
('021', 'BASTROP'),
('023', 'BAYLOR'),
('025', 'BEE'),
('027', 'BELL'),
('029', 'BEXAR'),
('031', 'BLANCO'),
('033', 'BORDEN'),
('035', 'BOSQUE'),
('037', 'BOWIE'),
('039', 'BRAZORIA'),
('041', 'BRAZOS'),
('704', 'BRAZOS-LB'),
('705', 'BRAZOS-S'),
('604', 'BRAZOS-SB'),
('043', 'BREWSTER'),
('045', 'BRISCOE'),
('047', 'BROOKS'),
('049', 'BROWN'),
('051', 'BURLESON'),
('053', 'BURNET'),
('055', 'CALDWELL'),
('057', 'CALHOUN'),
('059', 'CALLAHAN'),
('061', 'CAMERON'),
('063', 'CAMP'),
('065', 'CARSON'),
('067', 'CASS'),
('069', 'CASTRO'),
('071', 'CHAMBERS'),
('073', 'CHEROKEE'),
('075', 'CHILDRESS'),
('077', 'CLAY'),
('079', 'COCHRAN'),
('081', 'COKE'),
('083', 'COLEMAN'),
('085', 'COLLIN'),
('087', 'COLLINGSWORTH'),
('089', 'COLORADO'),
('091', 'COMAL'),
('093', 'COMANCHE'),
('095', 'CONCHO'),
('097', 'COOKE'),
('099', 'CORYELL'),
('101', 'COTTLE'),
('103', 'CRANE'),
('105', 'CROCKETT'),
('107', 'CROSBY'),
('109', 'CULBERSON'),
('111', 'DALLAM'),
('113', 'DALLAS'),
('115', 'DAWSON'),
('123', 'DE WITT'),
('117', 'DEAF SMITH'),
('119', 'DELTA'),
('121', 'DENTON'),
('125', 'DICKENS'),
('127', 'DIMMIT'),
('129', 'DONLEY'),
('131', 'DUVAL'),
('133', 'EASTLAND'),
('135', 'ECTOR'),
('137', 'EDWARDS'),
('141', 'EL PASO'),
('139', 'ELLIS'),
('143', 'ERATH'),
('145', 'FALLS'),
('147', 'FANNIN'),
('149', 'FAYETTE'),
('151', 'FISHER'),
('153', 'FLOYD'),
('155', 'FOARD'),
('157', 'FORT BEND'),
('159', 'FRANKLIN'),
('161', 'FREESTONE'),
('163', 'FRIO'),
('165', 'GAINES'),
('167', 'GALVESTON'),
('706', 'GALVESTON-LB'),
('707', 'GALVESTON-S'),
('605', 'GALVESTON-SB'),
('169', 'GARZA'),
('171', 'GILLESPIE'),
('173', 'GLASSCOCK'),
('175', 'GOLIAD'),
('177', 'GONZALES'),
('179', 'GRAY'),
('181', 'GRAYSON'),
('183', 'GREGG'),
('185', 'GRIMES'),
('187', 'GUADALUPE'),
('189', 'HALE'),
('191', 'HALL'),
('193', 'HAMILTON'),
('195', 'HANSFORD'),
('197', 'HARDEMAN'),
('199', 'HARDIN'),
('201', 'HARRIS'),
('203', 'HARRISON'),
('205', 'HARTLEY'),
('207', 'HASKELL'),
('209', 'HAYS'),
('211', 'HEMPHILL'),
('213', 'HENDERSON'),
('215', 'HIDALGO'),
('710', 'HIGH IS-E'),
('711', 'HIGH IS-E,S'),
('708', 'HIGH IS-LB'),
('709', 'HIGH IS-S'),
('606', 'HIGH IS-SB'),
('217', 'HILL'),
('219', 'HOCKELY'),
('221', 'HOOD'),
('223', 'HOPKINS'),
('225', 'HOUSTON'),
('227', 'HOWARD'),
('229', 'HUDSPETH'),
('231', 'HUNT'),
('233', 'HUTCHINSON'),
('235', 'IRION'),
('237', 'JACK'),
('239', 'JACKSON'),
('241', 'JASPER'),
('243', 'JEFF DAVIS'),
('245', 'JEFFERSON'),
('247', 'JIM HOGG'),
('249', 'JIM WELLS'),
('251', 'JOHNSON'),
('253', 'JONES'),
('255', 'KARNES'),
('257', 'KAUFMAN'),
('259', 'KENDALL'),
('261', 'KENEDY'),
('263', 'KENT'),
('265', 'KERR'),
('267', 'KIMBLE'),
('269', 'KING'),
('271', 'KINNEY'),
('273', 'KLEBERG'),
('275', 'KNOX'),
('283', 'LA SALLE'),
('277', 'LAMAR'),
('279', 'LAMB'),
('281', 'LAMPASAS'),
('285', 'LAVACA'),
('287', 'LEE'),
('289', 'LEON'),
('291', 'LIBERTY'),
('293', 'LIMESTONE'),
('295', 'LIPSCOMB'),
('297', 'LIVE OAK'),
('299', 'LLANO'),
('301', 'LOVING'),
('303', 'LUBBOCK'),
('305', 'LYNN'),
('313', 'MADISON'),
('315', 'MARION'),
('317', 'MARTIN'),
('319', 'MASON'),
('321', 'MATAGORDA'),
('703', 'MATGRDA IS-LB'),
('603', 'MATGRDA IS-SB'),
('323', 'MAVERICK'),
('307', 'MCCULLOCH'),
('309', 'MCLENNAN'),
('311', 'MCMULLEN'),
('325', 'MEDINA'),
('327', 'MENARD'),
('329', 'MIDLAND'),
('331', 'MILAM'),
('333', 'MILLS'),
('335', 'MITCHELL'),
('337', 'MONTAGUE'),
('339', 'MONTGOMERY'),
('341', 'MOORE'),
('343', 'MORRIS'),
('345', 'MOTLEY'),
('712', 'MUSTANG IS-E'),
('702', 'MUSTANG IS-LB'),
('602', 'MUSTANG IS-SB'),
('713', 'N PADRE IS-E'),
('701', 'N PADRE IS-LB'),
('601', 'N PADRE IS-SB'),
('347', 'NACOGDOCHES'),
('349', 'NAVARRO'),
('351', 'NEWTON'),
('353', 'NOLAN'),
('355', 'NUECES'),
('357', 'OCHILTREE'),
('359', 'OLDHAM'),
('361', 'ORANGE'),
('363', 'PALO PINTO'),
('365', 'PANOLA'),
('367', 'PARKER'),
('369', 'PARMER'),
('371', 'PECOS'),
('373', 'POLK'),
('375', 'POTTER'),
('377', 'PRESIDIO'),
('379', 'RAINS'),
('381', 'RANDALL'),
('383', 'REAGAN'),
('385', 'REAL'),
('387', 'RED RIVER'),
('389', 'REEVES'),
('391', 'REFUGIO'),
('393', 'ROBERTS'),
('395', 'ROBERTSON'),
('397', 'ROCKWALL'),
('399', 'RUNNELS'),
('401', 'RUSK'),
('714', 'S PADRE IS-E'),
('700', 'S PADRE IS-LB'),
('600', 'S PADRE IS-SB'),
('403', 'SABINE'),
('715', 'SABINE PASS'),
('405', 'SAN AUGUSTINE'),
('407', 'SAN JACINTO'),
('409', 'SAN PATRICIO'),
('411', 'SAN SABA'),
('413', 'SCHLEICHER'),
('415', 'SCURRY'),
('417', 'SHACKELFORD'),
('419', 'SHELBY'),
('421', 'SHERMAN'),
('423', 'SMITH'),
('425', 'SOMERVELL'),
('427', 'STARR'),
('429', 'STEPHENS'),
('431', 'STERLING'),
('433', 'STONEWALL'),
('435', 'SUTTON'),
('437', 'SWISHER'),
('439', 'TARRANT'),
('441', 'TAYLOR'),
('443', 'TERRELL'),
('445', 'TERRY'),
('447', 'THROCKMORTON'),
('449', 'TITUS'),
('451', 'TOM GREEN'),
('453', 'TRAVIS'),
('455', 'TRINITY'),
('457', 'TYLER'),
('459', 'UPSHUR'),
('461', 'UPTON'),
('463', 'UVALDE'),
('465', 'VAL VERDE'),
('467', 'VAN ZANDT'),
('469', 'VICTORIA'),
('471', 'WALKER'),
('473', 'WALLER'),
('475', 'WARD'),
('477', 'WASHINGTON'),
('479', 'WEBB'),
('481', 'WHARTON'),
('483', 'WHEELER'),
('485', 'WICHITA'),
('487', 'WILBARGER'),
('489', 'WILLACY'),
('491', 'WILLIAMSON'),
('493', 'WILSON'),
('495', 'WINKLER'),
('497', 'WISE'),
('499', 'WOOD'),
('501', 'YOAKUM'),
('503', 'YOUNG'),
('505', 'ZAPATA'),
('507', 'ZAVALA');

-- --------------------------------------------------------

--
-- Table structure for table `dp_district`
--

CREATE TABLE IF NOT EXISTS `dp_district` (
  `district_code` char(2) NOT NULL,
  `district_name` varchar(45) DEFAULT NULL,
  PRIMARY KEY (`district_code`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COMMENT='TWO-DIGIT NUMBER DESIGNATES THE RRC DISTRICT IN WHICH THE DRILLING OPERATION IS TO TAKE PLACE';

--
-- Dumping data for table `dp_district`
--

INSERT INTO `dp_district` (`district_code`, `district_name`) VALUES
('01', 'DISTRICT 01'),
('02', 'DISTRICT 02'),
('03', 'DISTRICT 03'),
('04', 'DISTRICT 04'),
('05', 'DISTRICT 05'),
('06', 'DISTRICT 06'),
('07', 'DISTRICT 6E'),
('08', 'DISTRICT 7B'),
('09', 'DISTRICT 7C'),
('10', 'DISTRICT 08'),
('11', 'DISTRICT 8A'),
('13', 'DISTRICT 09'),
('14', 'DISTRICT 10');

-- --------------------------------------------------------

--
-- Table structure for table `dp_filling_purpose`
--

CREATE TABLE IF NOT EXISTS `dp_filling_purpose` (
  `code` char(2) NOT NULL,
  `description` varchar(45) DEFAULT NULL,
  PRIMARY KEY (`code`),
  KEY `code` (`code`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COMMENT='A TWO-DIGIT CODE DEFINING THE TYPE OF\r\nW-1 APPLICATION APPROVED';

--
-- Dumping data for table `dp_filling_purpose`
--

INSERT INTO `dp_filling_purpose` (`code`, `description`) VALUES
('01', 'New Drill'),
('07', 'Reenter'),
('09', 'Field Transfer'),
('14', 'Recompletion'),
('15', 'Reclass');

-- --------------------------------------------------------

--
-- Table structure for table `dp_play`
--

CREATE TABLE IF NOT EXISTS `dp_play` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `play` varchar(22) NOT NULL,
  `county_code` varchar(22) NOT NULL,
  `district_code` varchar(22) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=86 ;

--
-- Dumping data for table `dp_play`
--

INSERT INTO `dp_play` (`id`, `play`, `county_code`, `district_code`) VALUES
(1, 'Barnett', '097', '13'),
(2, 'Barnett', '113', '05'),
(3, 'Barnett', '121', '13'),
(4, 'Barnett', '139', '05'),
(5, 'Barnett', '143', '08'),
(6, 'Barnett', '217', '05'),
(7, 'Barnett', '221', '08'),
(8, 'Barnett', '237', '13'),
(9, 'Barnett', '251', '05'),
(10, 'Barnett', '337', '13'),
(11, 'Barnett', '363', '08'),
(12, 'Barnett', '367', '08'),
(13, 'Barnett', '425', '08'),
(14, 'Barnett', '439', '05'),
(15, 'Barnett', '497', '13'),
(17, 'Eagle Ford', '013', '01'),
(18, 'Eagle Ford', '015', '03'),
(19, 'Eagle Ford', '021', '01'),
(20, 'Eagle Ford', '025', '02'),
(21, 'Eagle Ford', '041', '03'),
(22, 'Eagle Ford', '051', '03'),
(23, 'Eagle Ford', '089', '03'),
(24, 'Eagle Ford', '123', '02'),
(25, 'Eagle Ford', '127', '01'),
(26, 'Eagle Ford', '131', '04'),
(27, 'Eagle Ford', '149', '03'),
(28, 'Eagle Ford', '163', '01'),
(29, 'Eagle Ford', '157', '02'),
(30, 'Eagle Ford', '177', '01'),
(31, 'Eagle Ford', '185', '03'),
(32, 'Eagle Ford', '255', '02'),
(33, 'Eagle Ford', '283', '01'),
(34, 'Eagle Ford', '285', '02'),
(35, 'Eagle Ford', '287', '03'),
(36, 'Eagle Ford', '289', '05'),
(37, 'Eagle Ford', '297', '02'),
(38, 'Eagle Ford', '313', '03'),
(39, 'Eagle Ford', '323', '01'),
(40, 'Eagle Ford', '311', '01'),
(41, 'Eagle Ford', '331', '01'),
(42, 'Eagle Ford', '395', '05'),
(43, 'Eagle Ford', '477', '03'),
(44, 'Eagle Ford', '479', '04'),
(45, 'Eagle Ford', '493', '01'),
(46, 'Eagle Ford', '507', '01'),
(47, 'Granite Wash', '179', '14'),
(48, 'Granite Wash', '211', '14'),
(49, 'Granite Wash', '393', '14'),
(50, 'Granite Wash', '483', '14'),
(51, 'Haynesville', '201', '06'),
(52, 'Haynesville', '315', '06'),
(53, 'Haynesville', '347', '06'),
(54, 'Haynesville', '365', '06'),
(55, 'Haynesville', '401', '06'),
(56, 'Haynesville', '403', '06'),
(57, 'Haynesville', '405', '06'),
(58, 'Haynesville', '419', '06'),
(59, 'Permian', '003', '10'),
(60, 'Permian', '033', '11'),
(61, 'Permian', '043', '10'),
(62, 'Permian', '103', '10'),
(63, 'Permian', '105', '09'),
(64, 'Permian', '109', '10'),
(65, 'Permian', '115', '11'),
(66, 'Permian', '135', '10'),
(67, 'Permian', '165', '11'),
(68, 'Permian', '137', '10'),
(69, 'Permian', '227', '10'),
(70, 'Permian', '243', '10'),
(71, 'Permian', '301', '10'),
(72, 'Permian', '317', '10'),
(73, 'Permian', '329', '10'),
(74, 'Permian', '335', '10'),
(75, 'Permian', '371', '10'),
(76, 'Permian', '377', '10'),
(77, 'Permian', '383', '09'),
(78, 'Permian', '389', '10'),
(79, 'Permian', '415', '11'),
(80, 'Permian', '431', '10'),
(81, 'Permian', '443', '09'),
(82, 'Permian', '461', '09'),
(83, 'Permian', '475', '10'),
(84, 'Permian', '495', '10'),
(85, 'Permian', '501', '11');

-- --------------------------------------------------------

--
-- Table structure for table `dp_source_fileinfo`
--

CREATE TABLE IF NOT EXISTS `dp_source_fileinfo` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `filename` varchar(45) DEFAULT NULL,
  `filesize` varchar(45) DEFAULT NULL,
  `file_last_accessed_on` datetime DEFAULT NULL,
  `file_last_modified_on` datetime DEFAULT NULL,
  `file_read_on` datetime DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=10 ;

--
-- Dumping data for table `dp_source_fileinfo`
--

INSERT INTO `dp_source_fileinfo` (`id`, `filename`, `filesize`, `file_last_accessed_on`, `file_last_modified_on`, `file_read_on`) VALUES
(1, 'daf420.txt', '226709', '2014-08-07 15:49:48', '2014-08-07 15:37:21', '2014-08-11 15:17:47'),
(2, 'daf420.txt', '226709', '2014-08-07 15:49:48', '2014-08-07 15:37:21', '2014-08-11 15:19:55'),
(3, 'daf420_07Jul2014.txt', '833304', '2014-08-07 15:49:48', '2014-08-07 15:43:16', '2014-08-11 15:30:44'),
(4, 'daf420_17Jul2014.txt', '3302393', '2014-08-07 15:49:48', '2014-08-08 11:42:29', '2014-08-11 15:40:51'),
(5, 'daf420_17Jul2014.txt', '3302393', '2014-08-07 15:49:48', '2014-08-08 11:42:29', '2014-08-11 16:14:54'),
(6, 'daf420.txt', '226709', '2014-08-07 15:49:48', '2014-08-07 15:37:21', '2014-08-14 12:44:37'),
(7, 'daf420.txt', '226709', '2014-08-07 15:49:48', '2014-08-07 15:37:21', '2014-08-14 12:47:33'),
(8, 'daf420_07Jul2014.txt', '833304', '2014-08-07 15:49:48', '2014-08-07 15:43:16', '2014-08-14 12:50:35'),
(9, 'daf420_17Jul2014.txt', '3302393', '2014-08-07 15:49:48', '2014-08-08 11:42:29', '2014-08-14 12:55:04');

-- --------------------------------------------------------

--
-- Table structure for table `dp_status_of_app_flag`
--

CREATE TABLE IF NOT EXISTS `dp_status_of_app_flag` (
  `status_code` char(1) NOT NULL,
  `status_name` varchar(45) NOT NULL,
  PRIMARY KEY (`status_code`),
  KEY `status_name` (`status_name`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `dp_status_of_app_flag`
--

INSERT INTO `dp_status_of_app_flag` (`status_code`, `status_name`) VALUES
('A', 'APPROVED'),
('Z', 'CANCELLED'),
('C', 'CLOSED'),
('X', 'DELETED'),
('E', 'DENIED'),
('D', 'DISMISSED'),
('O', 'OTHER'),
('P', 'PENDING-APPROVAL'),
('W', 'WITHDRAWN');

-- --------------------------------------------------------

--
-- Table structure for table `dp_type_well_codes`
--

CREATE TABLE IF NOT EXISTS `dp_type_well_codes` (
  `code` char(1) NOT NULL,
  `description` varchar(100) DEFAULT NULL,
  PRIMARY KEY (`code`),
  KEY `code` (`code`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COMMENT='Well Status Codes (To Be Used as Spud-in and Reserved Dates)';

--
-- Dumping data for table `dp_type_well_codes`
--

INSERT INTO `dp_type_well_codes` (`code`, `description`) VALUES
('B', 'Oil & Gas'),
('C', 'Cathodic Protection'),
('G', 'Gas'),
('I', 'Injection'),
('O', 'Oil'),
('R', 'Storage'),
('S', 'Service'),
('T', 'Exploratory Test'),
('V', 'Water Supply');

-- --------------------------------------------------------

--
-- Table structure for table `dp_wellbore_profile`
--

CREATE TABLE IF NOT EXISTS `dp_wellbore_profile` (
  `wp_code` char(3) NOT NULL,
  `wp_name` varchar(45) NOT NULL,
  `directional_well_flag` varchar(1) DEFAULT NULL,
  `sidetrack_well_flag` varchar(1) DEFAULT NULL,
  `horizontal_well_flag` varchar(1) DEFAULT NULL,
  PRIMARY KEY (`wp_code`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `dp_wellbore_profile`
--

INSERT INTO `dp_wellbore_profile` (`wp_code`, `wp_name`, `directional_well_flag`, `sidetrack_well_flag`, `horizontal_well_flag`) VALUES
('DR', 'Directional', 'Y', 'N', 'N'),
('DS', 'Directional Sidetrack', 'Y', 'Y', 'N'),
('HR', 'Horizontal', 'N', 'N', 'Y'),
('HS', 'Horizontal Sidetrack', 'N', 'Y', 'Y'),
('VR', 'Vertical', 'N', 'N', 'N'),
('VS', 'Vertical Sidetrack', 'N', 'Y', 'N');

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
