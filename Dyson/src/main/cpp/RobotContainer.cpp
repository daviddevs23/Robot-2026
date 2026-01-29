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
        const auto throttle =
            -frc::ApplyDeadband(m_driverController.GetLeftY(),
                                OIConstants::kDriveDeadband);
        const auto turn =
            -frc::ApplyDeadband(m_driverController.GetLeftX(),
                                OIConstants::kDriveDeadband);

        m_drive.TankDrive(throttle * 0.5, turn * 0.5);
      },
      {&m_drive}));
}

void RobotContainer::ConfigureBindings() {
  m_driverController.LeftTrigger()
  .WhileTrue(
    frc2::cmd::RunEnd(
      [this] {
        double speed = m_driverController.GetLeftTriggerAxis();
        m_shooter.Pickup(speed);
      },
      [this] {
        m_shooter.Pickup(0);
      },
      {&m_shooter}
    )
  );


   m_driverController.RightTrigger()
  .WhileTrue(
    frc2::cmd::RunEnd(
      [this] {
        double speed = 1.0;
        m_shooter.Shoot(speed);
      },
      [this] {
        m_shooter.Shoot(0);
      },
      {&m_shooter}
    )
  );

  m_driverController.RightBumper()
  .WhileTrue(
    frc2::cmd::RunEnd(
      [this] {
        double speed = 0.8;
        m_shooter.Feed(speed);
        speed = 1.0;
        m_shooter.Shoot(speed);
      },
      [this] {
        m_shooter.Feed(0);
        m_shooter.Shoot(0);
      },
      {&m_shooter}
    )
  );
}

frc2::CommandPtr RobotContainer::GetAutonomousCommand() {
  return frc2::cmd::Print("No autonomous command configured");
}
