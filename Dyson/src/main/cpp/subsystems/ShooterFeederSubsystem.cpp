// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/ShooterFeederSubsystem.h"
#include "Constants.h"

ShooterFeederSubsystem::ShooterFeederSubsystem()
    : m_LeftShooterFeederMotor(ShooterFeederConstants::kLeftShooterFeederId,
                  rev::spark::SparkMax::MotorType::kBrushless),
      m_RightShooterFeederMotor(ShooterFeederConstants::kRightShooterFeederId,
                 rev::spark::SparkMax::MotorType::kBrushless) {

  m_LeftShooterFeederConfig
    .SetIdleMode(rev::spark::SparkMaxConfig::IdleMode::kCoast);

  m_RightShooterFeederConfig
    .SetIdleMode(rev::spark::SparkMaxConfig::IdleMode::kCoast)
    .Inverted(true);

  m_LeftShooterFeederMotor.Configure(m_LeftShooterFeederConfig, rev::spark::SparkMax::ResetMode::kResetSafeParameters, rev::spark::SparkMax::PersistMode::kPersistParameters);
  m_RightShooterFeederMotor.Configure(m_RightShooterFeederConfig, rev::spark::SparkMax::ResetMode::kResetSafeParameters, rev::spark::SparkMax::PersistMode::kPersistParameters);
}

void ShooterFeederSubsystem::EnableShooterFeeder() {
    double velocity = 1.0;
    m_LeftShooterFeederMotor.Set(velocity);
    m_RightShooterFeederMotor.Set(velocity);
}
void ShooterFeederSubsystem::DisableShooterFeeder() {
    double velocity = 0.0;
    m_LeftShooterFeederMotor.Set(velocity);
    m_RightShooterFeederMotor.Set(velocity);
}