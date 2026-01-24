// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

#include <frc/MathUtil.h>
#include <frc2/command/Commands.h>

#include "Constants.h"

RobotContainer::RobotContainer() {
  ConfigureBindings();

  m_drive.SetDefaultCommand(frc2::cmd::Run(
      [this] {
        const auto left =
            -frc::ApplyDeadband(m_driverController.GetLeftY(),
                                OIConstants::kDriveDeadband);
        const auto right =
            -frc::ApplyDeadband(m_driverController.GetRightY(),
                                OIConstants::kDriveDeadband);
        m_drive.TankDrive(left, right);
      },
      {&m_drive}));
}

void RobotContainer::ConfigureBindings() {}

frc2::CommandPtr RobotContainer::GetAutonomousCommand() {
  return frc2::cmd::Print("No autonomous command configured");
}
