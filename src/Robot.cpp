#include <Robot.h>

void Robot::RobotInit() {
//	nt::NetworkTableInstance;
	prefs = NetworkTable::GetTable("Preferences");
	initPosition.AddDefault("Nothing", NoAuto);
	initPosition.AddObject("Left", LeftPos);
	initPosition.AddObject("Middle", MiddlePos);
	initPosition.AddObject("Right", RightPos);
}

void Robot::DisabledInit() {
}

void Robot::AutonomousInit() {
	std::string gameData =
			DriverStation::GetInstance().GetGameSpecificMessage();
	Side switchSide = (gameData.substr(0, 1).compare("R") == 0) ? Right : Left;
	Side scaleSide = (gameData.substr(1, 1).compare("R") == 0) ? Right : Left;

	bool doOpp = prefs->GetEntry("Do Opposite Scale").GetBoolean(false);

	switch (initPosition.GetSelected()) {
	case LeftPos: {
		bool isOpp = scaleSide == Right;
		if (isOpp && !doOpp)
			selected = new CrossLine();
		else
			selected = new Scale(Left, isOpp);
		break;
	}
	case MiddlePos: {
		selected = new Switch(switchSide);
		break;
	}
	case RightPos: {
		bool isOpp = scaleSide == Left;
		if (isOpp && !doOpp)
			selected = new CrossLine();
		else
			selected = new Scale(Right, isOpp);
		break;
	}
	default: {
		selected = new Nothing();
		break;
	}
	}
	selected->Start();
}

void Robot::TeleopInit() {
	selected->Cancel();
}

void Robot::TestInit() {
}

void Robot::RobotPeriodic() {
}

void Robot::DisabledPeriodic() {
}

void Robot::AutonomousPeriodic() {
	frc::Scheduler::GetInstance()->Run();
}

void Robot::TeleopPeriodic() {

}

void Robot::TestPeriodic() {

}

START_ROBOT_CLASS(Robot)
