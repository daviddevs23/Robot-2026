#include "subsystems/AutonSubsystem.h"
#include <frc2/command/Commands.h>
#include <frc2/command/CommandHelper.h>
#include <frc2/command/RunCommand.h>
#include <units/time.h>


DriveForwardCommand::DriveForwardCommand(DriveSubsystem* drive, ShooterSubsystem* shooter, ShooterFeederSubsystem* shooterFeeder)
    : m_drive(drive), m_shooter(shooter), m_shooterFeeder(shooterFeeder) {
  AddRequirements(m_drive);
  AddRequirements(m_shooter);
  AddRequirements(m_shooterFeeder);
}

void DriveForwardCommand::Initialize() {
  m_timer.Reset();
  m_timer.Start();
}

void DriveForwardCommand::Execute() {
  if (m_timer.HasElapsed(9_s))
  {
    m_shooterFeeder->DisableShooterFeeder();
    m_shooter->DisableShooter();
  }
  else if (m_timer.HasElapsed(3_s)) {
    m_shooterFeeder->EnableShooterFeeder();
  }
  else if (m_timer.HasElapsed(1_s)) {
      m_shooter->EnableShooter();
  }
  else if (m_timer.HasElapsed(0.5_s))
  {
      m_drive->Drive(0, 0.0, 0.0);
  }
  else {
      m_drive->Drive(0.0, 0.0, 0.0);
  }
}

void DriveForwardCommand::End(bool interrupted) {
  // Stop robot
  m_drive->Drive(0.0, 0.0, 0.0);
}

bool DriveForwardCommand::IsFinished() {
  // Drive for 2 seconds
  return m_timer.HasElapsed(10_s);
}