// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc/drive/DifferentialDrive.h>
#include <frc/motorcontrol/MotorControllerGroup.h>
#include <frc2/command/SubsystemBase.h>
#include <rev/SparkMax.h>
#include <rev/config/SparkMaxConfig.h>

class DriveSubsystem : public frc2::SubsystemBase {
 public:
  DriveSubsystem();

  void TankDrive(double leftSpeed, double rightSpeed);

 private:
  rev::spark::SparkMax m_leftFront;
  rev::spark::SparkMax m_leftRear;
  rev::spark::SparkMax m_rightFront;
  rev::spark::SparkMax m_rightRear;

  rev::spark::SparkMaxConfig m_leftConfig;
  rev::spark::SparkMaxConfig m_rightConfig;

  frc::MotorControllerGroup m_leftGroup;
  frc::MotorControllerGroup m_rightGroup;
  frc::DifferentialDrive m_drive;
};
