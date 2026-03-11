#include "TelescopicSubsystem.h"
#include "Constants.h"
#include <rev/d/SparkMaxConfig.h>

TelescopicSubsystem::TelescopicSubsystem()
    : m_telescopicMotor{Constants::Telescopic::kMotorID, rev::spark::SparkLowLevel::MotorType::kBrushless} {

    rev::spark::SparkMaxConfig telescopicConfig{};
    telescopicConfig.Inverted(false);

    m_telescopicMotor.Configure(
        telescopicConfig,
        rev::spark::SparkBase::ResetMode::kResetSafeParameters,
        rev::spark::SparkBase::PersistMode::kNoPersistParameters
    );
}

void TelescopicSubsystem::ExtendTelescopic(double power) {
    m_telescopicMotor.Set(power);
}

void TelescopicSubsystem::ShortenTelescopic(double power) {
    m_telescopicMotor.Set(-power);
}

void TelescopicSubsystem::Stop() {
    m_telescopicMotor.StopMotor();
}

void TelescopicSubsystem::Periodic() {
    // Bu metod her zamanlayıcı (scheduler) döngüsünde bir kez çağrılır
}