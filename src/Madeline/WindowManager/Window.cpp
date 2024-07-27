#include <include/Madeline/WindowManager/Window.hpp>

namespace Madeline
{
	Window::Window(windowConfig& __IN__Config, VulkanWindowHandles* __IN__winmngrHandles) :
	Config{ __IN__Config },
	winmngrHandles{__IN__winmngrHandles}
	{
		initWindow();
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
		for ( auto imageView : swapChainImageViews )
		{
			vkDestroyImageView( *winmngrHandles->rDevice, imageView, nullptr );
		}
		vkDestroySwapchainKHR( *winmngrHandles->rDevice, swapChain, nullptr );
		vkDestroySurfaceKHR( *winmngrHandles->rInstance, surface, nullptr );
		glfwDestroyWindow( window );
		#if !NDEBUG
		std::cout << "The window \"" << Config.NAME << "\" has been destroyed" << std::endl;
		#endif
	}

	bool Window::shouldWindowClose()
	{
		return glfwWindowShouldClose( window );
	}

	void Window::setSurface(VkSurfaceKHR& surface)
	{
		this->surface = surface;
	}
	
	VkExtent2D Window::chooseSwapExtent( const VkSurfaceCapabilitiesKHR& capabilities ) {
#undef max
		if (capabilities.currentExtent.width != std::numeric_limits<uint32_t>::max())
		{
			return capabilities.currentExtent;
		}
		else
		{
			int width, height;
			glfwGetFramebufferSize(window, &width, &height);

			VkExtent2D actualExtent = {
				static_cast<uint32_t>(width),
				static_cast<uint32_t>(height)
			};

			actualExtent.width = std::clamp(actualExtent.width, capabilities.minImageExtent.width, capabilities.maxImageExtent.width);
			actualExtent.height = std::clamp(actualExtent.height, capabilities.minImageExtent.height, capabilities.maxImageExtent.height);

			return actualExtent;
		}
	}

	void Window::createImageViews()
	{
		swapChainImageViews.resize(swapChainImages.size());

		for (size_t i = 0; i < swapChainImages.size(); i++)
		{
			VkImageViewCreateInfo createInfo{};

			createInfo.sType = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO;
			createInfo.image = swapChainImages.at(i);

			createInfo.viewType = VK_IMAGE_VIEW_TYPE_2D;
			createInfo.format = swapChainImageFormat;

			createInfo.components.r = VK_COMPONENT_SWIZZLE_IDENTITY;
			createInfo.components.b = VK_COMPONENT_SWIZZLE_IDENTITY;
			createInfo.components.g = VK_COMPONENT_SWIZZLE_IDENTITY;
			createInfo.components.a = VK_COMPONENT_SWIZZLE_IDENTITY;

			createInfo.subresourceRange.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
			createInfo.subresourceRange.baseMipLevel = 0;
			createInfo.subresourceRange.levelCount = 1;
			createInfo.subresourceRange.baseArrayLayer = 0;
			createInfo.subresourceRange.layerCount = 1;

			if (vkCreateImageView(*winmngrHandles->rDevice, &createInfo, nullptr, &swapChainImageViews[i]) != VK_SUCCESS)
			{
				throw std::runtime_error("failed to create image views!");
			}
		}
	}
}
