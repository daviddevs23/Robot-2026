// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/ShooterSubsystem.h"
#include "Constants.h"

ShooterSubsystem::ShooterSubsystem()
    : m_LeftShooterMotor(ShooterConstants::kLeftShooterId,
                  rev::spark::SparkMax::MotorType::kBrushless),
      m_RightShooterMotor(ShooterConstants::kRightShooterId,
                 rev::spark::SparkMax::MotorType::kBrushless) {

  m_LeftShooterConfig
    .SetIdleMode(rev::spark::SparkMaxConfig::IdleMode::kCoast);

  m_RightShooterConfig
    .SetIdleMode(rev::spark::SparkMaxConfig::IdleMode::kCoast)
    .Inverted(true);

  m_LeftShooterMotor.Configure(m_LeftShooterConfig, rev::spark::SparkMax::ResetMode::kResetSafeParameters, rev::spark::SparkMax::PersistMode::kPersistParameters);
  m_RightShooterMotor.Configure(m_RightShooterConfig, rev::spark::SparkMax::ResetMode::kResetSafeParameters, rev::spark::SparkMax::PersistMode::kPersistParameters);
}

void ShooterSubsystem::EnableShooter() {
    double velocity = 0.55;
    m_LeftShooterMotor.Set(velocity);
    m_RightShooterMotor.Set(velocity);
}
void ShooterSubsystem::DisableShooter() {
    double velocity = 0.0;
    m_LeftShooterMotor.Set(velocity);
    m_RightShooterMotor.Set(velocity);
}