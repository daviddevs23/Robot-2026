// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"

#include <frc/smartdashboard/SmartDashboard.h>
#include <wpi/print.h>


/*Old code in Notepad goes here*/

#include <frc/TimedRobot.h>
#include <frc/XboxController.h>
#include <frc/drive/MecanumDrive.h>
#include <frc/motorcontrol/MotorControllerGroup.h>

class Robot : public frc::TimedRobot {
public:
    void RobotInit() override {
        // Initialize Spark Max controllers via CAN
        m_frontLeft.SetInverted(false);
        m_rearLeft.SetInverted(false);
        m_frontRight.SetInverted(true); // Usually need to invert right side
        m_rearRight.SetInverted(true);  // Usually need to invert right side
    }

    void TeleopPeriodic() override {
        // Use Xbox Left Stick X for Strafe, Left Stick Y for Forward/Back,
        // and Right Stick X for Rotation.
        // Cartesian drive takes (Forward/Back, Strafe, Rotation)
        // NWU convention: Forward is +X, Left is +Y, CCW is +Rot
        m_robotDrive.DriveCartesian(
            -m_driverController.GetLeftY(),  // Forward/Back (Inverted)
             m_driverController.GetLeftX(),  // Strafe
             m_driverController.GetRightX()  // Rotation
        );
    }

private:
    // CAN IDs must match your Spark Max configuration
    rev::CANSparkMax m_frontLeft{44, rev::CANSparkMax::MotorType::kBrushless};
    rev::CANSparkMax m_rearLeft{42, rev::CANSparkMax::MotorType::kBrushless};
    rev::CANSparkMax m_frontRight{41, rev::CANSparkMax::MotorType::kBrushless};
    rev::CANSparkMax m_rearRight{43, rev::CANSparkMax::MotorType::kBrushless};

    // Instantiate MecanumDrive class
    frc::MecanumDrive m_robotDrive{m_frontLeft, m_rearLeft, m_frontRight, m_rearRight};

    // Driver Controller
    frc::XboxController m_driverController{0};
};

#ifndef RUNNING_FRC_TESTS
int main() {
    return frc::StartRobot<Robot>();
}
#endif