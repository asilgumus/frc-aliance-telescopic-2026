#pragma once

#include <frc2/command/CommandPtr.h>
#include <frc2/command/button/CommandPS5Controller.h>
#include "subsystems/TelescopicSubsystem.h"

class RobotContainer {
 public:
  RobotContainer();

 private:
  void ConfigureBindings();

  // Subsystem ve Controller tanımlamaları
  TelescopicSubsystem m_telescopicSubsystem;
  frc2::CommandPS5Controller m_driverController{0}; // Driver Station'daki port numarası: 0
};