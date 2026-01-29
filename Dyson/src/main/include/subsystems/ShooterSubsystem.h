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

  void Shoot(double speed);
  void Feed(double speed);
  void Pickup(double speed);

 private:
  rev::spark::SparkMax m_LaunchMotor;
  rev::spark::SparkMax m_FeedMotor;

  rev::spark::SparkMaxConfig m_shooterConfig;
};
