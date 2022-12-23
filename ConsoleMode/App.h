#pragma once
#include <wx/wx.h>
#include <thread>

class App : public wxApp
{
private:

public:
	bool exited = false;
	std::thread* controller_thread;
	void Exit();
	void StartController();
	bool OnInit();
};

