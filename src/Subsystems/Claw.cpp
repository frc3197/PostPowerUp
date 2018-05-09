#include "Claw.h"

Claw::Claw() :
		Subsystem("Claw") {

}

void Claw::InitDefaultCommand() {
	SetDefaultCommand(NULL);
}

double Claw::SetClaw(double speed){
//	RobotMap::claw->Set(speed);
//	return RobotMap::claw->Get();
	return 0;
}
