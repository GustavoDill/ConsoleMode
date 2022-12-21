#include "GamepadController.h"

XINPUT_GAMEPAD GamepadController::GetGameController()
{
	// Poll the game controller for input
	XINPUT_STATE state;
	DWORD result = XInputGetState(0, &state);
	if (result == ERROR_SUCCESS)
	{
		return state.Gamepad;
	}
	else
	{
		// The controller is not connected
		//wxLogError(_T("Controller is not connected"));
	}
	return XINPUT_GAMEPAD();
}
bool GamepadController::KeyDown(ControllerKey key) {
	return GamepadController::GetGameController().wButtons & (int)key;
}
BYTE GamepadController::LeftTrigger() {
	return GamepadController::GetGameController().bLeftTrigger;
}
BYTE GamepadController::RightTrigger() {
	return GamepadController::GetGameController().bRightTrigger;
}