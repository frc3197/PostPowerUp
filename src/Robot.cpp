//#include <IterativeRobot.h>
//#include <SmartDashboard/SendableChooser.h>
//#include <networktables/NetworkTable.h>
//#include <Commands/Scheduler.h>
//#include <DriverStation.h>
#include <WPILib.h>
#include <RobotMap.h>

class Robot: public IterativeRobot {
private:
	std::shared_ptr<nt::NetworkTable> prefs;
	frc::SendableChooser<int> initPosition;

	enum Position {
		NoAuto, LeftPos, MiddlePos, RightPos
	};

	Command* selected;
public:
	enum Side {Left, Right};

	void RobotInit() {
		prefs = NetworkTable::GetTable("Preferences");
		initPosition.AddDefault("Nothing", NoAuto);
		initPosition.AddObject("Left", LeftPos);
		initPosition.AddObject("Middle", MiddlePos);
		initPosition.AddObject("Right", RightPos);
	}

	void DisabledInit() {
	}

	void AutonomousInit() {
		std::string gameData =
				DriverStation::GetInstance().GetGameSpecificMessage();

		Side switchSide =
				(gameData.substr(0, 1).compare("R") == 0) ?
						Right : Left;
		Side scaleSide =
				(gameData.substr(1, 1).compare("R") == 0) ?
						Right : Left;

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

	void TeleopInit() {
		selected->Cancel();
	}

	void TestInit() {
	}

	void RobotPeriodic() {
	}

	void DisabledPeriodic() {
	}

	void AutonomousPeriodic() {
		Scheduler::GetInstance()->Run();
	}

	void TeleopPeriodic() {

	}

	void TestPeriodic() {

	}
};

START_ROBOT_CLASS(Robot)
