#pragma once
#include "include/Skeleton/Skeleton.hpp"

namespace Madeline
{
	struct VulkanWindowHandles
	{
		VkInstance* rInstance;
		VkPhysicalDevice* rPhysicalDevice;
		VkDebugUtilsMessengerEXT* rDebugMessenger;
		VkDevice* rDevice;
		VkQueue* rGraphicsQueue;
		VkQueue* rPresentQueue;
		VulkanWindowHandles
		(
			VkInstance* __IN__Instance,
			VkPhysicalDevice* __IN__PhysicalDevice,
			VkDebugUtilsMessengerEXT* __IN__DebugMessenger,
			VkDevice* __IN__Device,
			VkQueue* __IN__GraphicsQueue,
			VkQueue* __IN__PresentQueue
		)
		:
		rInstance{ __IN__Instance },
		rPhysicalDevice{ __IN__PhysicalDevice },
		rDebugMessenger{ __IN__DebugMessenger },
		rDevice{ __IN__Device },
		rGraphicsQueue{ __IN__GraphicsQueue },
		rPresentQueue{ __IN__PresentQueue }
		{}
		VulkanWindowHandles& operator=(const VulkanWindowHandles& other)
		{
			rInstance = other.rInstance;
			rPhysicalDevice = other.rPhysicalDevice;
			rDebugMessenger = other.rDebugMessenger;
			rDevice = other.rDevice;
			rGraphicsQueue = other.rGraphicsQueue;
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
		std::optional<uint32_t> presentFamily;
		bool isComplete()
		{
			return graphicsFamily.has_value() && presentFamily.has_value();
		}
	};
	struct SwapChainSupportDetails
	{
		VkSurfaceCapabilitiesKHR capabilities;
		std::vector<VkSurfaceFormatKHR> format;
		std::vector<VkPresentModeKHR> presentModes;
	};
}