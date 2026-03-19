// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <rev/SparkMax.h>
#include <rev/config/SparkMaxConfig.h>

class ShooterFeederSubsystem : public frc2::SubsystemBase {
 public:
  ShooterFeederSubsystem();

  void EnableShooterFeeder();
  void DisableShooterFeeder();

 private:
  rev::spark::SparkMax m_LeftShooterFeederMotor;
  rev::spark::SparkMax m_RightShooterFeederMotor;

  rev::spark::SparkMaxConfig m_LeftShooterFeederConfig;
  rev::spark::SparkMaxConfig m_RightShooterFeederConfig;
};
