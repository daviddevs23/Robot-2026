// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

#include <frc/MathUtil.h>
#include <frc2/command/Commands.h>

#include "Constants.h"
#include "subsystems/AutonSubsystem.h"

RobotContainer::RobotContainer() {

  ConfigureBindings();

  m_drive.SetDefaultCommand(frc2::cmd::Run(
      [this] {
        const double xSpeed = -frc::ApplyDeadband(m_driverController.GetLeftY(), OIConstants::kDriveDeadband);
        const double ySpeed = frc::ApplyDeadband(m_driverController.GetRightX(), OIConstants::kDriveDeadband); 
        const double zRotation = frc::ApplyDeadband(m_driverController.GetLeftX(), OIConstants::kDriveDeadband);

        double scale = 0.65;

        m_drive.Drive(xSpeed * scale, ySpeed * scale, zRotation * scale);
      },
      {&m_drive}));
}

void RobotContainer::ConfigureBindings() {
  m_driverController.RightBumper().WhileTrue(
    frc2::cmd::StartEnd(
      [&] { m_ballIntake.EnableIntake(); },
      [&] { m_ballIntake.DisableIntake(); },
      { &m_ballIntake }
    )
  );

  m_driverController.Y().WhileTrue(
    frc2::cmd::RunEnd(
      [&] {
        m_shooter.EnableShooter();
        if (m_shooter.SpunUp()) {
          m_shooterFeeder.EnableShooterFeeder();
        } else {
          m_shooterFeeder.DisableShooterFeeder();
        }
      },
      [&] {
        m_shooter.DisableShooter();
        m_shooterFeeder.DisableShooterFeeder();
      },
      {&m_shooter, &m_shooterFeeder}
    )
  );
}

frc2::CommandPtr RobotContainer::GetAutonomousCommand() {
    return frc2::CommandPtr(std::make_unique<DriveForwardCommand>(&m_drive, &m_shooter, &m_shooterFeeder));
}

