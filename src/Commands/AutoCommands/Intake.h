#pragma once

#include <Commands/Command.h>

class Intake : public frc::Command {
public:
	Intake();
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;
};

