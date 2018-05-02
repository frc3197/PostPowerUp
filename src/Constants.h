#include <WPILib.h>
#include <ntcore.h>

#include <Commands/AutoCommandPaths/Nothing.h>
#include <Commands/AutoCommandPaths/Scale.h>
#include <Commands/AutoCommandPaths/Switch.h>
#include <Commands/AutoCommandPaths/CrossLine.h>

enum Position {
	NoAuto, LeftPos, MiddlePos, RightPos
};
enum Side {
	Left = -1, Right = 1
};
