// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

package frc.robot.subsystems;

import edu.wpi.first.math.controller.PIDController;
import edu.wpi.first.wpilibj2.command.SubsystemBase;
import com.revrobotics.spark.SparkMax;
import com.revrobotics.spark.config.SparkMaxConfig;
import com.revrobotics.PersistMode;
import com.revrobotics.ResetMode;
import com.revrobotics.spark.SparkLowLevel.MotorType;
import frc.robot.RobotID;

public class TelescopicSubsystem extends SubsystemBase {
    /** Creates a new TelescopicSubsystem. */

    private final SparkMax telescopicMotor;

    public TelescopicSubsystem() {

        telescopicMotor = new SparkMax(RobotID.TelescopicID, MotorType.kBrushless);

        SparkMaxConfig telescopicConfig = new SparkMaxConfig();
        telescopicConfig.inverted(false);

        // telescopicConfig.idleMode();

        telescopicMotor.configure(
            telescopicConfig,
            ResetMode.kResetSafeParameters,
            PersistMode.kNoPersistParameters
        );
    
    }

    public void extendTelescopic(double power) {
        telescopicMotor.set(power);
    }

    public void shortenTelescopic(double power) {
        telescopicMotor.set(-power);
    }

    public void stop() {
        telescopicMotor.stopMotor();
    }
    @Override
    public void periodic() {
        // This method will be called once per scheduler run
    }
}
