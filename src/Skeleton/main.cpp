#include "include/Skeleton/Skeleton.hpp"

int main( int, char* [] )
{
	Madeline::Logging *Logsystem = new Madeline::Logging;
	delete Logsystem;
	boost::log::sources::logger lg;



	std::unique_ptr<Madeline::WindowManager> WinMngr(new Madeline::WindowManager);
	WinMngr->initalizeGLFW();

	//X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X
	// X X X X X X X X X Start Create Startup Window(s)  X X X X X X X X X X X
	//X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X
	
	Madeline::windowConfig Window1;
	Window1.HEIGHT = 700;
	Window1.WIDTH = 700;
	Window1.NAME = "Test Window UwU";
	WinMngr->addWindow(Window1);

	/*
	Madeline::windowConfig Window2;
	Window2.HEIGHT = 600;
	Window2.WIDTH = 600;
	Window2.NAME = "UwU 2 electric boogaloo";
	WinMngr->addWindow( Window2 );
	*/
	
	//X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X
	// X X X X X X X X X X End Create Startup Window(s)  X X X X X X X X X X X
	//X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X
	
	WinMngr->initalizeVulkan();

	
	
	while (WinMngr->areActiveWindows())
	{
		WinMngr->allMainLoops();

		WinMngr->checkWindowsForCloseRequest();
	}
	WinMngr->cleanup();
	WinMngr.release();

	bool deconstructed = true;
	
	deconstructed = deconstructed ? WinMngr == nullptr : false;
	
	return !deconstructed;
}