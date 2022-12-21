#pragma once
#include <Xinput.h>

#define RESULT_SUCCESS                    0L

typedef unsigned char	BYTE;
enum ControllerKey {
	D_PAD_UP = 0x0001,
	D_PAD_DOWN = 0x0002,
	D_PAD_LEFT = 0x0004,
	D_PAD_RIGHT = 0x0008,
	START = 0x0010,
	SELECT = 0x0020,
	A = 0x1000,
	B = 0x2000,
	X = 0x4000,
	Y = 0x8000,
	LB = 0x0040,
	RB = 0x0080,
	LT = 0x0100,
	RT = 0x0200

};

class Controller
{
public:
	 XINPUT_GAMEPAD GetGameController();
	 bool KeyDown(ControllerKey key);
	 BYTE RightTrigger();
	BYTE LeftTrigger();

};

