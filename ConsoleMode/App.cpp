#include "App.h"
#include "MainFrame.h"
#include <wx/wx.h>
#include <Xinput.h>
#include <thread>
#include <functional>
#include "GamepadController.h"


MainFrame* frame;


void CheckControllerInput() {
	while (true) {
		// Get input from the game controller

		if (GamepadController::KeyDown(ControllerKey::RB))
		{
			frame->ShowFullScreen(true);
			Sleep(50);
		}

		Sleep(20);
	}

}
 
//std::thread thread;
bool App::OnInit() {

	frame = new MainFrame("App");
	frame->SetClientSize(1024, 800);
	frame->Center();
	frame->Show();

	std::thread thread(std::bind(CheckControllerInput));
	thread.detach();

	//thread.join();

	return true;

}

wxIMPLEMENT_APP(App);