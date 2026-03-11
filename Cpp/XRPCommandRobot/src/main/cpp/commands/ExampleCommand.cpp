#include "commands/TelescopicCommand.h"

// Eksik olan atama (constructor) bölümü burada düzeltildi kanka
TelescopicCommand::TelescopicCommand(TelescopicSubsystem* telescopicSubsystem, bool status)
    : m_telescopicSubsystem{telescopicSubsystem}, m_status{status} {
  AddRequirements(m_telescopicSubsystem);
}

void TelescopicCommand::Initialize() {}

void TelescopicCommand::Execute() {
  if (m_status) {
    m_telescopicSubsystem->ExtendTelescopic(0.3);
  } else {
    m_telescopicSubsystem->ShortenTelescopic(0.3);
  }
}

void TelescopicCommand::End(bool interrupted) {
  // Tuşu bıraktığında komut sonlanır, motorun dönmeye devam etmemesi için 0 veriyoruz.
  m_telescopicSubsystem->ExtendTelescopic(0.0);
}

bool TelescopicCommand::IsFinished() {
  return false;
}