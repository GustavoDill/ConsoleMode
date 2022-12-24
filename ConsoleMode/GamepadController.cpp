#include "GamepadController.h"
#include <tuple>

std::tuple<bool, ControllerKey> NO_INPUT = std::make_tuple(false, ControllerKey::NONE);

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
;
std::tuple<bool, ControllerKey> GamepadController::GetInput() {
	unsigned short a = GetGameController().wButtons;
	auto key = (ControllerKey)a;

	if (a > ControllerKey::NONE)
		return std::tuple<bool, ControllerKey>(true, key);
	return NO_INPUT;
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