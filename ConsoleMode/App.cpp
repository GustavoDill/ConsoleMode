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
		std::tuple<bool, ControllerKey> result = GamepadController::GetInput();
		bool yes;
		ControllerKey key;
		std::tie(yes, key) = result;

		if (yes) {
			frame->ControllerInput(key);
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
	frame->Shown();

	//frame->ShowFullScreen(true);
	
	StartController();

	return true;

}

wxIMPLEMENT_APP(App);