#include "App.h"
#include "MainFrame.h"
#include <wx/wx.h>
#include <Xinput.h>
#include <thread>
#include <functional>
#include "GamepadController.h"


MainFrame* frame;

void App::Exit() {
	frame->Close();
	exited = true;
}
App* instance;

void CheckControllerInput() {
	while (!instance->exited) {
		// Get input from the game controller

		if (GamepadController::KeyDown(ControllerKey::RB))
		{
			frame->menu->Show(true);
		}
		if (GamepadController::KeyDown(ControllerKey::LB))
		{
			frame->menu->Show(false);
		}

		// If Select pressed, exit application
		if (GamepadController::KeyDown(ControllerKey::SELECT))
		{
			instance->Exit();

		}

		Sleep(20);
	}

}

void App::StartController() {
	App::controller_thread = new std::thread(std::bind(CheckControllerInput));
	App::controller_thread->detach();
}
 


bool App::OnInit() {
	instance = this;
	frame = new MainFrame("App");
	frame->SetClientSize(1024, 800);
	frame->Center();
	frame->Show();

	//frame->ShowFullScreen(true);
	
	//RunController();

	return true;

}

wxIMPLEMENT_APP(App);