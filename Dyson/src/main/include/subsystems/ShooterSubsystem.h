// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <rev/SparkMax.h>
#include <rev/config/SparkMaxConfig.h>

class ShooterSubsystem : public frc2::SubsystemBase {
 public:
  ShooterSubsystem();

  void EnableShooter();
  void DisableShooter();

 private:
  rev::spark::SparkMax m_LeftShooterMotor;
  rev::spark::SparkMax m_RightShooterMotor;

  rev::spark::SparkMaxConfig m_LeftShooterConfig;
  rev::spark::SparkMaxConfig m_RightShooterConfig;
};
