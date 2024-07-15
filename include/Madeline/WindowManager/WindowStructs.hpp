#pragma once
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <stdint.h>
#include <string>
#include <optional>
namespace Madeline
{
	struct VulkanWindowHandles
	{
		VkInstance& rInstance;
		VkPhysicalDevice& rPhysicalDevice;
		VkDebugUtilsMessengerEXT& rDebugMessenger;
		VkDevice& rDevice;
		VkQueue& rGraphicsQueue;
		VulkanWindowHandles
		(
			VkInstance __IN__Instance,
			VkPhysicalDevice __IN__PhysicalDevice,
			VkDebugUtilsMessengerEXT __IN__DebugMessenger,
			VkDevice __IN__Device,
			VkQueue __IN__GraphicsQueue
		)
		:
		rInstance{ __IN__Instance },
		rPhysicalDevice{ __IN__PhysicalDevice },
		rDebugMessenger{ __IN__DebugMessenger },
		rDevice{ __IN__Device },
		rGraphicsQueue{ __IN__GraphicsQueue }
		{}
		VulkanWindowHandles& operator=(const VulkanWindowHandles& other)
		{
			rInstance = std::move(other.rInstance);
			rPhysicalDevice = std::move(other.rPhysicalDevice);
			rDebugMessenger = std::move(other.rDebugMessenger);
			rDevice = std::move(other.rDevice);
			rGraphicsQueue = std::move(other.rGraphicsQueue);
			return *this;
		}

	};
	
	struct windowConfig
	{
		std::string NAME = "defult";
		uint32_t WIDTH = 300;
		uint32_t HEIGHT = 300;
	};
	struct QueueFamilyIndices
	{
		std::optional<uint32_t> graphicsFamily;
	
		bool isComplete()
		{
			return graphicsFamily.has_value();
		}
	};
}