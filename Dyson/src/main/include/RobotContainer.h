// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc/XboxController.h>
#include <frc2/command/CommandPtr.h>

#include "Constants.h"
#include "subsystems/DriveSubsystem.h"

class RobotContainer {
 public:
  RobotContainer();

 frc2::CommandPtr GetAutonomousCommand();

 private:
  void ConfigureBindings();

  DriveSubsystem m_drive;
  frc::XboxController m_driverController{OIConstants::kDriverControllerPort};
};
