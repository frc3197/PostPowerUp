#include "RunClaw.h"

RunClaw::RunClaw() {
//	Requires(Robot::claw->Claw);
}

void RunClaw::Initialize() {

}

void RunClaw::Execute() {
//	double left = RobotMap::driver1.GetRawAxis(5);
//	double right = RobotMap::driver2.GetRawAxis(4);
//
//	left = (std::abs(left) > RobotMap::ControllerAxisDeadzone) ? left : 0;
//	right = (std::abs(right) > RobotMap::ControllerAxisDeadzone) ? right : 0;

}

bool RunClaw::IsFinished() {
	return false;
}

void RunClaw::End() {

}
void RunClaw::Interrupted() {

}
