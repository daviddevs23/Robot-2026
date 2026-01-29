// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/button/CommandXboxController.h>
#include <frc2/command/CommandPtr.h>

#include "Constants.h"
#include "subsystems/DriveSubsystem.h"
#include "subsystems/ShooterSubsystem.h"

class RobotContainer {
 public:
  RobotContainer();

 frc2::CommandPtr GetAutonomousCommand();

 private:
  void ConfigureBindings();

  DriveSubsystem m_drive;
  ShooterSubsystem m_shooter;
  frc2::CommandXboxController m_driverController{OIConstants::kDriverControllerPort};
};
