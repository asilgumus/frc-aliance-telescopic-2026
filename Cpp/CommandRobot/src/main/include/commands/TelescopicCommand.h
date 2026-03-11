#pragma once

#include <frc2/command/Command.h>
#include <frc2/command/CommandHelper.h>
#include "subsystems/TelescopicSubsystem.h"

class TelescopicCommand : public frc2::CommandHelper<frc2::Command, TelescopicCommand> {
 public:
  explicit TelescopicCommand(TelescopicSubsystem* telescopicSubsystem, bool status);

  void Initialize() override;
  void Execute() override;
  void End(bool interrupted) override;
  bool IsFinished() override;

 private:
  TelescopicSubsystem* m_telescopicSubsystem;
  bool m_status;
};