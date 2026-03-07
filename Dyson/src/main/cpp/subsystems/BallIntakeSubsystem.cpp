// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/BallIntakeSubsystem.h"
#include "Constants.h"

BallIntakeSubsystem::BallIntakeSubsystem()
    : m_LeftIntakeMotor(BallIntakeConstants::kLeftIntakeMotor,
                  rev::spark::SparkMax::MotorType::kBrushless),
      m_RightIntakeMotor(BallIntakeConstants::kRightIntakeMotor,
                 rev::spark::SparkMax::MotorType::kBrushless) {

  m_LeftIntakeConfig
    .SetIdleMode(rev::spark::SparkMaxConfig::IdleMode::kCoast);

  m_RightIntakeConfig
    .SetIdleMode(rev::spark::SparkMaxConfig::IdleMode::kCoast)
    .Inverted(true);

  m_LeftIntakeMotor.Configure(m_LeftIntakeConfig, rev::spark::SparkMax::ResetMode::kResetSafeParameters, rev::spark::SparkMax::PersistMode::kPersistParameters);
  m_RightIntakeMotor.Configure(m_RightIntakeConfig, rev::spark::SparkMax::ResetMode::kResetSafeParameters, rev::spark::SparkMax::PersistMode::kPersistParameters);
}

void BallIntakeSubsystem::ToggleIntake() {
  feeding = !feeding;
  // if (feeding) {
  //   m_LeftIntakeMotor.Set(0.1);
  // } else {
  //   m_LeftIntakeMotor.Set(0.0);
  // }
    double velocity = -1.0;
    m_LeftIntakeMotor.Set(velocity);
    m_RightIntakeMotor.Set(velocity);
}