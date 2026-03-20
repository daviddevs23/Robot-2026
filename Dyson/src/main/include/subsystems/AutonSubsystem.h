#pragma once

#include <frc2/command/CommandHelper.h>
#include "subsystems/DriveSubsystem.h"
#include "subsystems/ShooterSubsystem.h"
#include "subsystems/ShooterFeederSubsystem.h"
#include <frc/Timer.h>
#include <frc2/command/Commands.h>
#include <frc2/command/CommandHelper.h>
#include <frc2/command/RunCommand.h>

class DriveForwardCommand
    : public frc2::CommandHelper<frc2::Command, DriveForwardCommand> {
 public:
  DriveForwardCommand(DriveSubsystem* drive, ShooterSubsystem* shooter, ShooterFeederSubsystem* shooterFeeder);

  void Initialize() override;
  void Execute() override;
  void End(bool interrupted) override;
  bool IsFinished() override;

 private:
  DriveSubsystem* m_drive;
  ShooterSubsystem* m_shooter;
  ShooterFeederSubsystem* m_shooterFeeder;
  frc::Timer m_timer;
};