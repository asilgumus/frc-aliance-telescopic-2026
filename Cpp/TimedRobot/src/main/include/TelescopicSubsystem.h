#pragma once

#include <frc2/command/SubsystemBase.h>
#include <rev/SparkMax.h>

class TelescopicSubsystem : public frc2::SubsystemBase {
public:
    TelescopicSubsystem();

    void ExtendTelescopic(double power);
    void ShortenTelescopic(double power);
    void Stop();
    void Periodic() override;

private:
    rev::spark::SparkMax m_telescopicMotor;
};