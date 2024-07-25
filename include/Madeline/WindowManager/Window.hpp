#pragma once
#include "include/Skeleton/Skeleton.hpp"
#include "include/Madeline/WindowManager/WindowStructs.hpp"


namespace Madeline
{
	class Window
	{
	public:
		Window( windowConfig& __IN__Config, VulkanWindowHandles* __IN__winmngrHandles);
		Window& operator=(const Window& other);
		void initWindow();
		void mainLoop();
		void cleanupWindow();
		bool shouldWindowClose();
		void setSurface(VkSurfaceKHR& surface);
		VkSurfaceKHR getSurface(){ return surface; }
		GLFWwindow* getWindow() { return window; }
		VkExtent2D chooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities);
		VkSwapchainKHR* getSwapchain() {return &swapChain;}
	private:
		GLFWwindow* window = nullptr;
		windowConfig Config;
		VulkanWindowHandles* winmngrHandles;
		VkSurfaceKHR surface;
		VkSwapchainKHR swapChain;
	};
}
