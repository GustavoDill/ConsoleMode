#include "Controller.h"



XINPUT_GAMEPAD Controller::GetGameController()
{
	// Poll the game controller for input
	XINPUT_STATE state;
	DWORD result = XInputGetState(0, &state);
	if (result == RESULT_SUCCESS)
	{
		return state.Gamepad;
	}
	return XINPUT_GAMEPAD();
}
// Function to get input from the game controller
bool Controller::KeyDown(ControllerKey key) {
	XINPUT_GAMEPAD gamepad = Controller::GetGameController();
	return gamepad.wButtons & (int)key;
}

BYTE Controller::RightTrigger() {
	return GetGameController().bRightTrigger;
}
BYTE Controller::LeftTrigger() {
	return GetGameController().bLeftTrigger;
}
