-- phpMyAdmin SQL Dump
-- version 3.3.9
-- http://www.phpmyadmin.net
--
-- Host: localhost
-- Generation Time: Apr 24, 2012 at 07:19 
-- Server version: 5.5.8
-- PHP Version: 5.3.5

SET SQL_MODE="NO_AUTO_VALUE_ON_ZERO";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Database: `db_virucodesoup`
--

-- --------------------------------------------------------

--
-- Table structure for table `post`
--

CREATE TABLE IF NOT EXISTS `post` (
  `id` int(16) NOT NULL AUTO_INCREMENT COMMENT 'Index of post.',
  `title` varchar(255) DEFAULT NULL COMMENT 'Title of post.',
  `tag` varchar(255) DEFAULT NULL COMMENT 'Tag of post.',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=11 ;

--
-- Dumping data for table `post`
--

INSERT INTO `post` (`id`, `title`, `tag`) VALUES
(1, 'Today is Raining', 'weather,rain,today'),
(2, 'I am hungry', 'food,hungry'),
(3, 'Pizza is hot', 'food,pizza'),
(4, 'Summer is coming!', 'sun,season,weather,hot'),
(5, 'Popcorn is Hot', 'corn,food,hot,plant'),
(6, 'Food Season!', 'food,season'),
(7, 'Free Food Today!', 'free,food,today'),
(8, 'Pizza Season!', 'season,pizza,food'),
(9, 'Peanut Summer', 'summer,season,peanut,food'),
(10, 'Winter is Coming!', 'winter,season,come');
