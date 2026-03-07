// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <rev/SparkMax.h>
#include <rev/config/SparkMaxConfig.h>

class BallIntakeSubsystem : public frc2::SubsystemBase {
 public:
  BallIntakeSubsystem();

  void EnableIntake();
  void DisableIntake();

 private:
  rev::spark::SparkMax m_LeftIntakeMotor;
  rev::spark::SparkMax m_RightIntakeMotor;

  rev::spark::SparkMaxConfig m_LeftIntakeConfig;
  rev::spark::SparkMaxConfig m_RightIntakeConfig;
};
