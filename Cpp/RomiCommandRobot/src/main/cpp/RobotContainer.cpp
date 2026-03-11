#include "RobotContainer.h"
#include "commands/TelescopicCommand.h"

RobotContainer::RobotContainer() {
  ConfigureBindings();
}

void RobotContainer::ConfigureBindings() {
  // PS5 Cross (Çarpı) tuşuna basılı tutulduğunda teleskopik kolu uzat (status: true)
  m_driverController.Cross().WhileTrue(
      TelescopicCommand(&m_telescopicSubsystem, true).ToPtr());

  // PS5 Circle (Yuvarlak) tuşuna basılı tutulduğunda teleskopik kolu kısalt (status: false)
  m_driverController.Circle().WhileTrue(
      TelescopicCommand(&m_telescopicSubsystem, false).ToPtr());
}