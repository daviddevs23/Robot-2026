// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/DriveSubsystem.h"

#include "Constants.h"

DriveSubsystem::DriveSubsystem()
    : m_leftFront(DriveConstants::kLeftFrontId,
                  rev::spark::SparkMax::MotorType::kBrushless),
      m_leftRear(DriveConstants::kLeftRearId,
                 rev::spark::SparkMax::MotorType::kBrushless),
      m_rightFront(DriveConstants::kRightFrontId,
                   rev::spark::SparkMax::MotorType::kBrushless),
      m_rightRear(DriveConstants::kRightRearId,
                  rev::spark::SparkMax::MotorType::kBrushless),
      m_leftGroup(m_leftFront, m_leftRear),
      m_rightGroup(m_rightFront, m_rightRear),
      m_drive(m_leftGroup, m_rightGroup) {

  m_leftConfig
    .SetIdleMode(rev::spark::SparkMaxConfig::IdleMode::kBrake);
  
  m_rightConfig
    .SetIdleMode(rev::spark::SparkMaxConfig::IdleMode::kBrake)
    .Inverted(true);

  m_leftFront.Configure(m_leftConfig, rev::spark::SparkMax::ResetMode::kResetSafeParameters, rev::spark::SparkMax::PersistMode::kPersistParameters);
  m_leftRear.Configure(m_leftConfig, rev::spark::SparkMax::ResetMode::kResetSafeParameters, rev::spark::SparkMax::PersistMode::kPersistParameters);
  m_rightFront.Configure(m_rightConfig, rev::spark::SparkMax::ResetMode::kResetSafeParameters, rev::spark::SparkMax::PersistMode::kPersistParameters);
  m_rightRear.Configure(m_rightConfig, rev::spark::SparkMax::ResetMode::kResetSafeParameters, rev::spark::SparkMax::PersistMode::kPersistParameters);

  // m_rightGroup.SetInverted(true);
}

void DriveSubsystem::TankDrive(double leftSpeed, double rightSpeed) {
  m_drive.TankDrive(leftSpeed, rightSpeed);
}
