#pragma once
#include "include/Skeleton/Skeleton.hpp"
#include "include/Madeline/WindowManager/WindowStructs.hpp"


namespace Madeline
{
	class Window
	{
	public:
		Window( windowConfig& __IN__Config, VulkanWindowHandles* __IN__winmngrHandles);
		void mainLoop();
		void cleanupWindow();
		bool shouldWindowClose();
		void createSurface();
		void windowGraphicsSetup();
		SwapChainSupportDetails querySwapChainSupport(VkPhysicalDevice device);
		VkSurfaceKHR getSurface() { return surface; }
		GLFWwindow* getWindow() { return window; }
		windowConfig getWindowConfig() { return Config; };
	
	private:
		void createSwapChain();
		void createImageViews();
		void createRenderPass();
		void createGraphicsPipeline();

		VkExtent2D chooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities);
		static std::vector<char> readFile(const std::string& filename)
		{
			std::ifstream file(filename, std::ios::ate | std::ios::binary);

			if (!file.is_open())
			{
				throw std::runtime_error("failed to open file!");
			}

			size_t fileSize = static_cast<size_t>(file.tellg());
			std::vector<char> buffer(fileSize);

			file.seekg(0);
			file.read(buffer.data(), fileSize);

			file.close();

			return buffer;
		}
		VkShaderModule createShaderModule(const std::vector<char>& code);
		VkSurfaceFormatKHR chooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& availableFormats);
		VkPresentModeKHR chooseSwapPresentMode(const std::vector<VkPresentModeKHR>& availablePresentModes);
		
		GLFWwindow* window{};
		windowConfig Config;
		VulkanWindowHandles* winmngrHandles;
		VkSurfaceKHR surface;
		VkSwapchainKHR swapChain;
		std::vector<VkImage> swapChainImages;
		std::vector<VkImageView> swapChainImageViews;
		VkFormat swapChainImageFormat;
		VkExtent2D swapChainExtent;
		VkRenderPass renderPass;
		VkPipeline graphicsPipeline;
		VkPipelineLayout pipelineLayout;
	};
}
