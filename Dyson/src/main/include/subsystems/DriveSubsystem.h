// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc/drive/MecanumDrive.h>
#include <frc/motorcontrol/MotorControllerGroup.h>
#include <frc2/command/SubsystemBase.h>
#include <rev/SparkMax.h>
#include <rev/config/SparkMaxConfig.h>
#include <studica/AHRS.h>

class DriveSubsystem : public frc2::SubsystemBase {
 public:
  DriveSubsystem();

  void Drive(double xSpeed, double ySpeed, double zRotation);

 private:
  rev::spark::SparkMax m_leftFront;
  rev::spark::SparkMax m_leftRear;
  rev::spark::SparkMax m_rightFront;
  rev::spark::SparkMax m_rightRear;

  rev::spark::SparkMaxConfig m_leftConfig;
  rev::spark::SparkMaxConfig m_rightConfig;

  frc::MecanumDrive m_drive;
  studica::AHRS m_gyro{studica::AHRS::NavXComType::kMXP_SPI};
};
