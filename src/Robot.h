#pragma once

#include <Constants.h>

class Robot: public frc::IterativeRobot {
public:
	void RobotInit() override;
	void DisabledInit() override;
	void AutonomousInit() override;
	void TeleopInit() override;
	void TestInit() override;

	void RobotPeriodic() override;
	void AutonomousPeriodic() override;
	void TeleopPeriodic() override;
	void TestPeriodic() override;
	void DisabledPeriodic() override;

private:
	std::shared_ptr<nt::NetworkTable> prefs;
	frc::SendableChooser<int> initPosition;

	Command* selected;
};
