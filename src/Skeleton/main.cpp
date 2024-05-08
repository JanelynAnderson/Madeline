#include <iostream>
#include <limits>
#include <exception>
#include <GLFW/glfw3.h>
#include "include/Madeline/Logger/Logging.hpp"
#include <windows.h>

int main( int, char* [] )
{
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	MCAD::Logger::Logging Logsystem;
	// initalize logging
	std::cout << "Log System Booting..." << std::endl;
	std::cout << "Log System ";
	try
	{
		Logsystem.init_logging();
		boost::log::core::get()->add_global_attribute("TimeStamp", boost::log::attributes::local_clock());
		boost::log::core::get()->add_global_attribute("RecordID", boost::log::attributes::counter< unsigned int >());
		
		SetConsoleTextAttribute(hConsole, 10);
		std::cout << "ONLINE";
		SetConsoleTextAttribute(hConsole, 7);
	}
	catch(std::exception& e)
	{
		SetConsoleTextAttribute(hConsole, 4);
		std::cout << "FAILED";
		SetConsoleTextAttribute(hConsole, 7);
		std::cerr << "failed to initalize log system" << std::endl;
	}
	boost::log::sources::logger lg;
	BOOST_LOG(lg) << "Test Log";
	
	GLFWwindow *window;

	if ( !glfwInit() )
	{
		fprintf( stderr, "Failed to initalize GLFW\n" );
		exit( EXIT_FAILURE );
	}

	window = glfwCreateWindow( 300, 300, "TEST WINDOW", NULL, NULL );
	if (!window)
	{
		fprintf( stderr, "Failed to open GLFW window\n" );
		glfwTerminate();
		exit( EXIT_FAILURE );
	}

	while ( !glfwWindowShouldClose( window ) )
	{
		glfwSwapBuffers( window );
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}