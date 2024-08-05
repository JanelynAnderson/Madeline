#pragma once
#include "include/Madeline/WindowManager/WindowStructs.hpp"
#include "include/Madeline/WindowManager/Window.hpp"
#include "include/Skeleton/Skeleton.hpp"

namespace Madeline
{
	using pWindowMemberFunction = void (Window::*)();
	class WindowManager
	{
	public:
		
		void initalize_GLFW_Vulkan_Debug();

		void finalizeInitalization();

		void cleanup();

		void allMainLoops();
		
		void addWindow( Madeline::windowConfig& Config );
		
		bool areActiveWindows();
		
		void initalizeGLFW();
		
		void createVulkanInstance();
		
		void checkWindowsForCloseRequest();
		
		void terminateVulkanInstance();
		
		void pickPhysicalDevice();
		
		bool isDeviceSuitable( VkPhysicalDevice device );
		
		bool checkValidationLayerSupport();
		
		std::vector<const char*> getRequiredExtensions();
		
		void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);

		static VKAPI_ATTR uint32_t VKAPI_CALL debugCallback
		(
			VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
			VkDebugUtilsMessageTypeFlagsEXT messageType,
			const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
			void* pUserData
		);

		void setupDebugMessenger();

		VkResult CreateDebugUtilsMessengerEXT
		(
			VkInstance instance, 
			const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo,
			const VkAllocationCallbacks* pAllocator, 
			VkDebugUtilsMessengerEXT* pDebugMessenger
		);
		
		void DestroyDebugUtilsMessengerEXT
		(
			VkInstance instance,
			VkDebugUtilsMessengerEXT debugMessenger,
			const VkAllocationCallbacks* pAllocator
		);

		QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);
		
		void createLogicalDevice();
		bool checkDeviceExtensionSupport(VkPhysicalDevice device);
		void applyFunctionToAllWindows(pWindowMemberFunction func);
	private:
		std::string boolToString(bool value) {return value ? "TRUE" : "FALSE";}
		std::vector<Madeline::Window> windowStack;
		const std::vector<const char*> validationLayers = {
			"VK_LAYER_KHRONOS_validation"
		};
		const std::vector<const char*> deviceExtensions = {
			VK_KHR_SWAPCHAIN_EXTENSION_NAME
		};
		#ifdef NDEBUG
			const bool enableValidationLayers = false;
		#else
			const bool enableValidationLayers = true;
		#endif
		VkInstance instance						{ VK_NULL_HANDLE };
		VkPhysicalDevice physicalDevice			{ VK_NULL_HANDLE };
		VkDebugUtilsMessengerEXT debugMessenger { VK_NULL_HANDLE };
		VkDevice device							{ VK_NULL_HANDLE };
		VkQueue graphicsQueue					{ VK_NULL_HANDLE };
		VkQueue presentQueue					{ VK_NULL_HANDLE };
		QueueFamilyIndices queueIndices;
		VulkanWindowHandles windowHandles
		{
			&instance,
			&physicalDevice,
			&debugMessenger,
			&device,
			&graphicsQueue,
			&presentQueue,
			&queueIndices
		};
	};
}

