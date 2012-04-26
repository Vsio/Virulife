-- phpMyAdmin SQL Dump
-- version 3.3.9
-- http://www.phpmyadmin.net
--
-- Host: localhost
-- Generation Time: Apr 26, 2012 at 07:37 
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
-- Table structure for table `user`
--

CREATE TABLE IF NOT EXISTS `user` (
  `id` int(16) NOT NULL AUTO_INCREMENT COMMENT 'index of username',
  `username` varchar(256) NOT NULL COMMENT 'username of user',
  `password` varchar(256) NOT NULL COMMENT 'password of user',
  `like` varchar(256) NOT NULL COMMENT 'what user like',
  `dislike` varchar(256) NOT NULL COMMENT 'what user dislike',
  PRIMARY KEY (`id`),
  UNIQUE KEY `username` (`username`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=4 ;

--
-- Dumping data for table `user`
--

INSERT INTO `user` (`id`, `username`, `password`, `like`, `dislike`) VALUES
(1, 'user1', 'password1', 'chicken,pizza', 'nothing'),
(2, 'user2', 'password2', 'nut', 'too nut'),
(3, 'user3', 'password3', 'shoes', 'broken shoes');
