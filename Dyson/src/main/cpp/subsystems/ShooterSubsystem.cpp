// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/ShooterSubsystem.h"

#include "Constants.h"

ShooterSubsystem::ShooterSubsystem()
    : m_LaunchMotor(ShooterConstants::kLaunchMotor,
                  rev::spark::SparkMax::MotorType::kBrushed),
      m_FeedMotor(ShooterConstants::kFeedMotor,
                 rev::spark::SparkMax::MotorType::kBrushed) {

  m_shooterConfig
    .SetIdleMode(rev::spark::SparkMaxConfig::IdleMode::kCoast);

  m_LaunchMotor.Configure(m_shooterConfig, rev::spark::SparkMax::ResetMode::kResetSafeParameters, rev::spark::SparkMax::PersistMode::kPersistParameters);
  m_FeedMotor.Configure(m_shooterConfig, rev::spark::SparkMax::ResetMode::kResetSafeParameters, rev::spark::SparkMax::PersistMode::kPersistParameters);
}

void ShooterSubsystem::Shoot(double speed) {
  m_LaunchMotor.Set(-speed);
}

void ShooterSubsystem::Feed(double speed) {
  m_FeedMotor.Set(speed);
}

void ShooterSubsystem::Pickup(double speed) {
  m_LaunchMotor.Set(-speed);
  m_FeedMotor.Set(-speed);
}