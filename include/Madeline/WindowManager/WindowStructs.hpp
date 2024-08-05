#pragma once
#include "include/Skeleton/Skeleton.hpp"

namespace Madeline
{
	struct QueueFamilyIndices
	{
		std::optional<uint32_t> graphicsFamily;
		std::optional<uint32_t> presentFamily;
		bool isComplete()
		{
			return graphicsFamily.has_value() && presentFamily.has_value();
		}
	};
	struct VulkanWindowHandles
	{
		VkInstance* pInstance;
		VkPhysicalDevice* pPhysicalDevice;
		VkDebugUtilsMessengerEXT* pDebugMessenger;
		VkDevice* pDevice;
		VkQueue* pGraphicsQueue;
		VkQueue* pPresentQueue;
		QueueFamilyIndices* pQueueIndicies;
		VulkanWindowHandles
		(
			VkInstance* __IN__Instance,
			VkPhysicalDevice* __IN__PhysicalDevice,
			VkDebugUtilsMessengerEXT* __IN__DebugMessenger,
			VkDevice* __IN__Device,
			VkQueue* __IN__GraphicsQueue,
			VkQueue* __IN__PresentQueue,
			QueueFamilyIndices* __IN__QueueIndicies
		)
		:
		pInstance{ __IN__Instance },
		pPhysicalDevice{ __IN__PhysicalDevice },
		pDebugMessenger{ __IN__DebugMessenger },
		pDevice{ __IN__Device },
		pGraphicsQueue{ __IN__GraphicsQueue },
		pPresentQueue{ __IN__PresentQueue },
		pQueueIndicies{ __IN__QueueIndicies }
		{}
		VulkanWindowHandles& operator=(const VulkanWindowHandles& other)
		{
			pInstance = other.pInstance;
			pPhysicalDevice = other.pPhysicalDevice;
			pDebugMessenger = other.pDebugMessenger;
			pDevice = other.pDevice;
			pGraphicsQueue = other.pGraphicsQueue;
			pQueueIndicies = other.pQueueIndicies;
			return *this;
		}

	};
	
	struct windowConfig
	{
		std::string NAME = "defult";
		uint32_t WIDTH = 300;
		uint32_t HEIGHT = 300;
	};
	struct SwapChainSupportDetails
	{
		VkSurfaceCapabilitiesKHR capabilities;
		std::vector<VkSurfaceFormatKHR> format;
		std::vector<VkPresentModeKHR> presentModes;
	};
}