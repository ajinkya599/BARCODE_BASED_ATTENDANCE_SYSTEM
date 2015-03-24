CREATE DATABASE  IF NOT EXISTS `bba` /*!40100 DEFAULT CHARACTER SET utf8 */;
USE `bba`;
-- MySQL dump 10.13  Distrib 5.6.17, for Win32 (x86)
--
-- Host: localhost    Database: bba
-- ------------------------------------------------------
-- Server version	5.6.23-log

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `2_1`
--

DROP TABLE IF EXISTS `2_1`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `2_1` (
  `serial` int(11) unsigned NOT NULL AUTO_INCREMENT,
  `Roll` int(11) NOT NULL,
  `2/14/2015` int(11) DEFAULT NULL,
  `2/15/2015` int(11) DEFAULT NULL,
  `2/16/2015` int(11) DEFAULT NULL,
  `2/17/2015` int(11) DEFAULT NULL,
  `2/18/2015` int(11) DEFAULT NULL,
  `2/19/2015` int(11) DEFAULT NULL,
  `2/20/2015` int(11) DEFAULT NULL,
  `Total` int(11) DEFAULT NULL,
  PRIMARY KEY (`serial`,`Roll`),
  UNIQUE KEY `serial_UNIQUE` (`serial`)
) ENGINE=InnoDB AUTO_INCREMENT=11 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `2_1`
--

LOCK TABLES `2_1` WRITE;
/*!40000 ALTER TABLE `2_1` DISABLE KEYS */;
INSERT INTO `2_1` VALUES (1,1,1,0,1,0,0,1,1,4),(2,23,0,0,0,0,0,0,0,0),(3,130101002,1,0,1,0,0,0,0,2),(4,130101004,1,0,1,0,0,0,0,2),(5,130101048,1,0,0,0,0,1,0,2),(6,130101055,0,0,0,0,0,0,0,0),(7,130101056,0,0,0,0,0,1,1,2),(8,130101077,0,0,0,0,0,0,1,1),(9,130101084,0,0,0,0,0,0,0,0),(10,130101059,0,0,0,0,0,0,0,0);
/*!40000 ALTER TABLE `2_1` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `2_2`
--

DROP TABLE IF EXISTS `2_2`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `2_2` (
  `serial` int(11) NOT NULL AUTO_INCREMENT,
  `Roll` int(11) NOT NULL,
  `2/14/2015` int(11) DEFAULT NULL,
  `2/15/2015` int(11) DEFAULT NULL,
  `2/16/2015` int(11) DEFAULT NULL,
  `2/17/2015` int(11) DEFAULT NULL,
  `2/18/2015` int(11) DEFAULT NULL,
  `2/19/2015` int(11) DEFAULT NULL,
  `2/20/2015` int(11) DEFAULT NULL,
  `Total` int(11) DEFAULT NULL,
  PRIMARY KEY (`serial`,`Roll`),
  UNIQUE KEY `serial_UNIQUE` (`serial`)
) ENGINE=InnoDB AUTO_INCREMENT=10 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `2_2`
--

LOCK TABLES `2_2` WRITE;
/*!40000 ALTER TABLE `2_2` DISABLE KEYS */;
INSERT INTO `2_2` VALUES (1,1,0,1,1,0,0,0,0,2),(2,130101002,0,0,0,0,0,0,0,0),(3,130101004,0,0,0,0,0,0,0,0),(4,130101048,0,0,1,0,0,0,0,1),(5,130101055,0,0,0,0,0,0,0,0),(6,130101056,0,1,1,0,0,0,0,2),(7,130101059,0,0,0,0,0,0,0,0),(8,130101077,0,0,1,0,0,0,0,1),(9,130101084,0,0,0,0,0,0,0,0);
/*!40000 ALTER TABLE `2_2` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `2_3`
--

DROP TABLE IF EXISTS `2_3`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `2_3` (
  `serial` int(11) NOT NULL AUTO_INCREMENT,
  `Roll` int(11) NOT NULL,
  `2/14/2015` int(11) DEFAULT NULL,
  `2/15/2015` int(11) DEFAULT NULL,
  `2/16/2015` int(11) DEFAULT NULL,
  `2/17/2015` int(11) DEFAULT NULL,
  `2/18/2015` int(11) DEFAULT NULL,
  `2/19/2015` int(11) DEFAULT NULL,
  `2/20/2015` int(11) DEFAULT NULL,
  `Total` int(11) DEFAULT NULL,
  PRIMARY KEY (`serial`,`Roll`)
) ENGINE=InnoDB AUTO_INCREMENT=10 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `2_3`
--

LOCK TABLES `2_3` WRITE;
/*!40000 ALTER TABLE `2_3` DISABLE KEYS */;
INSERT INTO `2_3` VALUES (1,1,0,0,0,1,1,0,0,2),(2,23,0,0,0,0,0,0,0,0),(3,130101002,0,0,0,0,0,0,0,0),(4,130101004,0,0,0,0,0,0,0,0),(5,130101048,0,0,0,0,0,0,0,0),(6,130101055,0,0,0,0,1,0,0,1),(7,130101056,0,0,0,1,0,0,0,1),(8,130101077,0,0,0,0,0,0,0,0),(9,130101084,0,0,0,0,0,0,0,0);
/*!40000 ALTER TABLE `2_3` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `2_4`
--

DROP TABLE IF EXISTS `2_4`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `2_4` (
  `serial` int(11) NOT NULL AUTO_INCREMENT,
  `Roll` int(11) NOT NULL,
  `2/14/2015` int(11) DEFAULT NULL,
  `2/15/2015` int(11) DEFAULT NULL,
  `2/16/2015` int(11) DEFAULT NULL,
  `2/17/2015` int(11) DEFAULT NULL,
  `2/18/2015` int(11) DEFAULT NULL,
  `2/19/2015` int(11) DEFAULT NULL,
  `2/20/2015` int(11) DEFAULT NULL,
  `Total` int(11) DEFAULT NULL,
  PRIMARY KEY (`serial`,`Roll`)
) ENGINE=InnoDB AUTO_INCREMENT=9 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `2_4`
--

LOCK TABLES `2_4` WRITE;
/*!40000 ALTER TABLE `2_4` DISABLE KEYS */;
INSERT INTO `2_4` VALUES (1,1,1,0,0,1,1,0,0,3),(2,130101002,1,0,0,0,0,0,0,1),(3,130101004,1,0,0,0,0,0,0,1),(4,130101048,1,0,0,0,0,0,0,1),(5,130101055,0,0,0,0,0,0,0,0),(6,130101056,1,0,0,1,0,0,0,2),(7,130101077,0,0,0,0,0,0,0,0),(8,130101084,1,0,0,0,1,0,0,2);
/*!40000 ALTER TABLE `2_4` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `2_5`
--

DROP TABLE IF EXISTS `2_5`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `2_5` (
  `serial` int(11) NOT NULL AUTO_INCREMENT,
  `Roll` int(11) NOT NULL,
  `2/14/2015` int(11) DEFAULT NULL,
  `2/15/2015` int(11) DEFAULT NULL,
  `2/16/2015` int(11) DEFAULT NULL,
  `2/17/2015` int(11) DEFAULT NULL,
  `2/18/2015` int(11) DEFAULT NULL,
  `2/19/2015` int(11) DEFAULT NULL,
  `2/20/2015` int(11) DEFAULT NULL,
  `Total` int(11) DEFAULT NULL,
  PRIMARY KEY (`serial`,`Roll`)
) ENGINE=InnoDB AUTO_INCREMENT=9 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `2_5`
--

LOCK TABLES `2_5` WRITE;
/*!40000 ALTER TABLE `2_5` DISABLE KEYS */;
INSERT INTO `2_5` VALUES (1,1,1,1,0,0,0,0,0,2),(2,130101002,0,0,0,0,0,0,0,0),(3,130101004,1,0,0,0,0,0,0,1),(4,130101048,0,1,0,0,0,0,0,1),(5,130101055,0,0,0,0,0,0,0,0),(6,130101056,1,1,0,0,0,0,0,2),(7,130101077,0,0,0,0,0,0,0,0),(8,130101084,0,0,0,0,0,0,0,0);
/*!40000 ALTER TABLE `2_5` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `csett`
--

DROP TABLE IF EXISTS `csett`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `csett` (
  `Number` int(11) NOT NULL,
  `Date` varchar(45) DEFAULT NULL,
  `9` varchar(45) DEFAULT NULL,
  `10` varchar(45) DEFAULT NULL,
  `11` varchar(45) DEFAULT NULL,
  PRIMARY KEY (`Number`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `csett`
--

LOCK TABLES `csett` WRITE;
/*!40000 ALTER TABLE `csett` DISABLE KEYS */;
INSERT INTO `csett` VALUES (1,'2/14/2015','2_1','2_5','2_4'),(2,'2/15/2015','2_2','2_1','2_5'),(3,'2/16/2015','2_3','2_2','2_1'),(4,'2/17/2015','2_4','2_3','2_2'),(5,'2/18/2015','2_5','2_4','2_3'),(6,'2/19/2015','2_1','2_5','2_4'),(7,'2/20/2015','2_2','2_1','2_5');
/*!40000 ALTER TABLE `csett` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `login`
--

DROP TABLE IF EXISTS `login`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `login` (
  `Roll` varchar(45) NOT NULL,
  `User Type` varchar(45) DEFAULT NULL,
  `User Id` varchar(45) DEFAULT NULL,
  `Password` varchar(45) DEFAULT NULL,
  PRIMARY KEY (`Roll`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `login`
--

LOCK TABLES `login` WRITE;
/*!40000 ALTER TABLE `login` DISABLE KEYS */;
INSERT INTO `login` VALUES ('1','Admin','nikit','nikit'),('130101055','Student','Pulkit','verma'),('130101056','Student','piyush','piyush'),('130101059','Student','parteek','abey'),('23','Student','af','af'),('3','Professor','ajinkya','ajinkya');
/*!40000 ALTER TABLE `login` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `sizes`
--

DROP TABLE IF EXISTS `sizes`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `sizes` (
  `serial` int(11) NOT NULL AUTO_INCREMENT,
  `2_1` varchar(45) DEFAULT NULL,
  `2_2` varchar(45) DEFAULT NULL,
  `2_3` varchar(45) DEFAULT NULL,
  `2_4` varchar(45) DEFAULT NULL,
  `2_5` varchar(45) DEFAULT NULL,
  PRIMARY KEY (`serial`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `sizes`
--

LOCK TABLES `sizes` WRITE;
/*!40000 ALTER TABLE `sizes` DISABLE KEYS */;
INSERT INTO `sizes` VALUES (1,'10','9','9','8','8');
/*!40000 ALTER TABLE `sizes` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2015-03-10 12:57:32
