#pragma once

#include <Commands/Command.h>

class RunClaw : public frc::Command {
public:
	RunClaw();
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;
};

