#include "subsystems/TelescopicSubsystem.h"
#include "RobotID.h" // Constants.h yerine yeni dosyamızı ekledik

TelescopicSubsystem::TelescopicSubsystem()
    : m_telescopicMotor(RobotID::TELESCOPIC_ID, rev::spark::SparkLowLevel::MotorType::kBrushless) {}

void TelescopicSubsystem::ExtendTelescopic(double power) {
  m_telescopicMotor.Set(power);
}

void TelescopicSubsystem::ShortenTelescopic(double power) {
  m_telescopicMotor.Set(-power);
}

void TelescopicSubsystem::Periodic() {
  // Bu metod scheduler her çalıştığında bir kez çağrılır
}