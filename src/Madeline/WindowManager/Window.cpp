#include <include/Madeline/WindowManager/Window.hpp>

namespace Madeline
{
	Window::Window(windowConfig& __IN__Config, VulkanWindowHandles __IN__winmngrHandles) :
	Config{ __IN__Config },
	winmngrHandles{__IN__winmngrHandles}
	{
		initWindow();
	}

	Window& Window::operator=(const Window& other)
	{
		winmngrHandles = std::move(other.winmngrHandles);
		return *this;
	}

	void Window::initWindow()
	{
		glfwWindowHint( GLFW_CLIENT_API, GLFW_NO_API );
		glfwWindowHint( GLFW_RESIZABLE, GLFW_FALSE );
		window = glfwCreateWindow( Config.WIDTH, Config.HEIGHT, (Config.NAME).c_str(), nullptr, nullptr);
		if (!window)
		{
			fprintf( stderr, "Failed to open GLFW window\n" );
			glfwTerminate();
			exit( EXIT_FAILURE );
		}
	}

	void Window::mainLoop()
	{
		glfwSwapBuffers( Window::window );
		glfwPollEvents();
	}

	void Window::cleanupWindow()
	{
		glfwDestroyWindow( Window::window );
	}

	bool Window::shouldWindowClose()
	{
		return glfwWindowShouldClose( window );
	}
}
