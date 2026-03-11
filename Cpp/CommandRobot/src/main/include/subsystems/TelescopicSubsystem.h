#pragma once

#include <frc2/command/SubsystemBase.h>
#include <rev/spark/SparkMax.h>

class TelescopicSubsystem : public frc2::SubsystemBase {
 public:
  TelescopicSubsystem();

  void ExtendTelescopic(double power);
  void ShortenTelescopic(double power);
  void Periodic() override;

 private:
  rev::spark::SparkMax m_telescopicMotor;
};