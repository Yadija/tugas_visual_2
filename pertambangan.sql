-- --------------------------------------------------------
-- Host:                         127.0.0.1
-- Server version:               8.0.30 - MySQL Community Server - GPL
-- Server OS:                    Win64
-- HeidiSQL Version:             12.4.0.6659
-- --------------------------------------------------------

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET NAMES utf8 */;
/*!50503 SET NAMES utf8mb4 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

-- Dumping structure for table pertambangan.cadangan
CREATE TABLE IF NOT EXISTS `cadangan` (
  `kd_cad` varchar(150) NOT NULL,
  `nm_kpl` varchar(150) NOT NULL,
  `bulan` varchar(50) NOT NULL,
  `tahun` varchar(10) NOT NULL,
  `no_iup` varchar(150) NOT NULL,
  `laut` varchar(150) NOT NULL,
  `luas` varchar(150) NOT NULL,
  `ddh` varchar(150) NOT NULL,
  `idh` varchar(150) NOT NULL,
  `tdh` varchar(150) NOT NULL,
  `pdh` double NOT NULL DEFAULT '0',
  PRIMARY KEY (`kd_cad`),
  KEY `fk_cadangan.nm_kpl_kapal.nm_kpl` (`nm_kpl`),
  KEY `fk_cadangan.no_iup_iup.no_iup` (`no_iup`),
  CONSTRAINT `fk_cadangan.nm_kpl_kapal.nm_kpl` FOREIGN KEY (`nm_kpl`) REFERENCES `kapal` (`nm_kpl`),
  CONSTRAINT `fk_cadangan.no_iup_iup.no_iup` FOREIGN KEY (`no_iup`) REFERENCES `iup` (`no_iup`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

-- Data exporting was unselected.

-- Dumping structure for table pertambangan.iup
CREATE TABLE IF NOT EXISTS `iup` (
  `no_iup` varchar(150) NOT NULL DEFAULT '',
  `lokasi` varchar(250) NOT NULL DEFAULT '',
  `no_sk` varchar(150) NOT NULL DEFAULT '',
  `tgl_berlaku` varchar(100) NOT NULL DEFAULT '',
  `no_sert` varchar(150) NOT NULL DEFAULT '',
  `ket` varchar(250) NOT NULL DEFAULT '',
  PRIMARY KEY (`no_iup`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

-- Data exporting was unselected.

-- Dumping structure for table pertambangan.kapal
CREATE TABLE IF NOT EXISTS `kapal` (
  `nm_kpl` varchar(150) NOT NULL,
  `instansi` varchar(150) NOT NULL,
  `dlm_gali` varchar(150) NOT NULL,
  PRIMARY KEY (`nm_kpl`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

-- Data exporting was unselected.

-- Dumping structure for table pertambangan.realisasi
CREATE TABLE IF NOT EXISTS `realisasi` (
  `kd_real` varchar(150) NOT NULL,
  `kd_cad` varchar(150) NOT NULL,
  `dsb` varchar(150) NOT NULL,
  `isb` varchar(150) NOT NULL,
  `tsb` varchar(150) NOT NULL,
  `psb` double NOT NULL DEFAULT '0',
  PRIMARY KEY (`kd_real`),
  KEY `fk_realisasi.kd_cad_cadangan.kd_cad` (`kd_cad`),
  CONSTRAINT `fk_realisasi.kd_cad_cadangan.kd_cad` FOREIGN KEY (`kd_cad`) REFERENCES `cadangan` (`kd_cad`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

-- Data exporting was unselected.

-- Dumping structure for table pertambangan.user
CREATE TABLE IF NOT EXISTS `user` (
  `nik` varchar(100) NOT NULL,
  `nama` varchar(150) NOT NULL,
  `email` varchar(150) NOT NULL,
  `role` varchar(20) NOT NULL,
  `password` varchar(150) NOT NULL,
  PRIMARY KEY (`nik`),
  UNIQUE KEY `email` (`email`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

-- Data exporting was unselected.

-- Dumping structure for table pertambangan.wilayah
CREATE TABLE IF NOT EXISTS `wilayah` (
  `kd_wil` varchar(150) NOT NULL,
  `nm_wil` varchar(150) NOT NULL,
  PRIMARY KEY (`kd_wil`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

-- Data exporting was unselected.

/*!40103 SET TIME_ZONE=IFNULL(@OLD_TIME_ZONE, 'system') */;
/*!40101 SET SQL_MODE=IFNULL(@OLD_SQL_MODE, '') */;
/*!40014 SET FOREIGN_KEY_CHECKS=IFNULL(@OLD_FOREIGN_KEY_CHECKS, 1) */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40111 SET SQL_NOTES=IFNULL(@OLD_SQL_NOTES, 1) */;
