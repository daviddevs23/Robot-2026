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
        const double xSpeed = -frc::ApplyDeadband(m_driverController.GetLeftY(), OIConstants::kDriveDeadband);
        const double ySpeed = frc::ApplyDeadband(m_driverController.GetRightX(), OIConstants::kDriveDeadband); 
        const double zRotation = frc::ApplyDeadband(m_driverController.GetLeftX(), OIConstants::kDriveDeadband);

        double scale = 0.35;

        m_drive.Drive(xSpeed * scale, ySpeed * scale, zRotation * scale);
      },
      {&m_drive}));
}

void RobotContainer::ConfigureBindings() {
  m_driverController.A().ToggleOnTrue(
    frc2::cmd::StartEnd(
      [&] {m_ballIntake.EnableIntake(); },
      [&] {m_ballIntake.DisableIntake(); },
      {&m_ballIntake}
    )
  );

  m_driverController.X().ToggleOnTrue(
    frc2::cmd::StartEnd(
      [&] {m_shooterFeeder.EnableShooterFeeder(); },
      [&] {m_shooterFeeder.DisableShooterFeeder(); },
      {&m_shooterFeeder}
    )
  );

  m_driverController.B().ToggleOnTrue(
    frc2::cmd::StartEnd(
      [&] {m_shooter.EnableShooter(); },
      [&] {m_shooter.DisableShooter(); },
      {&m_shooter}
    )
  );
}

frc2::CommandPtr RobotContainer::GetAutonomousCommand() {
  return frc2::cmd::Print("No autonomous command configured");
}
