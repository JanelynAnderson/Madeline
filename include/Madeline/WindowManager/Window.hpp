#pragma once
#include "include/Skeleton/Skeleton.hpp"
#include "include/Madeline/WindowManager/WindowStructs.hpp"


namespace Madeline
{
	class Window
	{
	public:
		Window( windowConfig& __IN__Config, VulkanWindowHandles* __IN__winmngrHandles);
		void initWindow();
		void mainLoop();
		void cleanupWindow();
		bool shouldWindowClose();
		void setSurface(VkSurfaceKHR& surface);
		void setSwapChainImageFormat(VkFormat swapChainImageFormat) { this->swapChainImageFormat = swapChainImageFormat; };
		void setSwapChainImageExtent(VkExtent2D swapChainExtent) { this->swapChainExtent = swapChainExtent; };
		VkSurfaceKHR getSurface(){ return surface; }
		GLFWwindow* getWindow() { return window; }
		VkSwapchainKHR* getSwapchain() { return &swapChain; }
		std::vector<VkImage>* getSwapChainImages() { return &swapChainImages; }
		windowConfig getWindowConfig() { return Config; };
		VkExtent2D chooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities);
		void createImageViews();
	private:
		GLFWwindow* window = nullptr;
		windowConfig Config;
		VulkanWindowHandles* winmngrHandles;
		VkSurfaceKHR surface;
		VkSwapchainKHR swapChain;
		std::vector<VkImage> swapChainImages;
		std::vector<VkImageView> swapChainImageViews;
		VkFormat swapChainImageFormat;
		VkExtent2D swapChainExtent;
	};
}
