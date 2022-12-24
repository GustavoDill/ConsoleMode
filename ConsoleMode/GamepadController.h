#pragma once
#include <Windows.h>
#include <Xinput.h>
#include <tuple>

#define RESULT_SUCCESS                    0L

typedef unsigned char	BYTE;
enum ControllerKey {
	NONE = 0,
	DPAD_UP = XINPUT_GAMEPAD_DPAD_UP,
	DPAD_DOWN = XINPUT_GAMEPAD_DPAD_DOWN,
	DPAD_LEFT = XINPUT_GAMEPAD_DPAD_LEFT,
	DPAD_RIGHT = XINPUT_GAMEPAD_DPAD_RIGHT,
	START = XINPUT_GAMEPAD_START,
	SELECT = XINPUT_GAMEPAD_BACK,
	A = XINPUT_GAMEPAD_A,
	B = XINPUT_GAMEPAD_B,
	X = XINPUT_GAMEPAD_X,
	Y = XINPUT_GAMEPAD_Y,
	LB = XINPUT_GAMEPAD_LEFT_SHOULDER,
	RB = XINPUT_GAMEPAD_RIGHT_SHOULDER,

};

class GamepadController
{

public:

	static XINPUT_GAMEPAD GetGameController();
	static bool KeyDown(ControllerKey key);
	static std::tuple<bool, ControllerKey> GetInput();
	static BYTE RightTrigger();
	static BYTE LeftTrigger();

};

