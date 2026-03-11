#pragma once

#include <frc/TimedRobot.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc/PS5Controller.h>
#include <string>

#include "TelescopicSubsystem.h"

class Robot : public frc::TimedRobot {
public:
    Robot();
    void RobotPeriodic() override;
    void AutonomousInit() override;
    void AutonomousPeriodic() override;
    void TeleopInit() override;
    void TeleopPeriodic() override;
    void DisabledInit() override;
    void DisabledPeriodic() override;
    void TestInit() override;
    void TestPeriodic() override;
    void SimulationInit() override;
    void SimulationPeriodic() override;

private:
    frc::SendableChooser<std::string> m_chooser;
    const std::string kAutoNameDefault = "Default";
    const std::string kAutoNameCustom = "My Auto";
    std::string m_autoSelected;

    // Alt sistem ve kontrolcü tanımlamaları
    TelescopicSubsystem m_telescopicSubsystem;
    frc::PS5Controller m_operator{0};
};