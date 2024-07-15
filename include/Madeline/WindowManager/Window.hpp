#pragma once
#include "include/Madeline/WindowManager/WindowStructs.hpp"
#include <stdint.h>
#include <string>
#include <utility>
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

namespace Madeline
{
	class Window
	{
	public:
		Window( windowConfig& __IN__Config, VulkanWindowHandles __IN__winmngrHandles);
		Window& operator=(const Window& other);
		void initWindow();
		void mainLoop();
		void cleanupWindow();
		bool shouldWindowClose();
	private:
		GLFWwindow* window = nullptr;
		windowConfig Config;
		VulkanWindowHandles& winmngrHandles;
	};
}
