#include "custom_funcs.hpp"
#ifndef __EMSCRIPTEN__
#include "../backends/imgui_impl_vulkan.h"

extern void check_vk_result(VkResult err);

uint32_t ImGui_VKH_findMemoryType(const VkPhysicalDevice& physicalDevice, const uint32_t type_filter, const VkMemoryPropertyFlags properties) noexcept
{
    VkPhysicalDeviceMemoryProperties physicalDeviceProperties;
    vkGetPhysicalDeviceMemoryProperties(physicalDevice, &physicalDeviceProperties);

    for (uint32_t i = 0; i < physicalDeviceProperties.memoryTypeCount; i++)
        if ((type_filter & (1 << i)) && (physicalDeviceProperties.memoryTypes[i].propertyFlags & properties) == properties)
            return i;

    return 0xFFFFFFFF; // Unable to find memoryType
}

void destroyMSAAImages(VkDevice device, const ImGui_ImplVulkanH_Window* wd) noexcept
{
    if (wd->samples > VK_SAMPLE_COUNT_1_BIT)
    {
        if (wd->multisampledImage != VK_NULL_HANDLE)
            vkDestroyImage(device, wd->multisampledImage, nullptr);
        if (wd->multisampledImageView != VK_NULL_HANDLE)
            vkDestroyImageView(device, wd->multisampledImageView, nullptr);
        if (wd->multisampledImageMemory != VK_NULL_HANDLE)
            vkFreeMemory(device, wd->multisampledImageMemory, nullptr);
    }
}

void createMSAAImage(VkPhysicalDevice physical_device, VkDevice device, ImGui_ImplVulkanH_Window* wd) noexcept
{
    if (wd->samples > VK_SAMPLE_COUNT_1_BIT)
    {
        const VkImageCreateInfo multisampledImageCreateInfo
        {
            .sType = VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO,
            .imageType = VK_IMAGE_TYPE_2D,
            .format = wd->SurfaceFormat.format,
            .extent =
            {
                .width = static_cast<uint32_t>(wd->Width),
                .height = static_cast<uint32_t>(wd->Height),
                .depth = 1,
            },
            .mipLevels = 1,
            .arrayLayers = 1,
            .sharingMode = VK_SHARING_MODE_EXCLUSIVE,
            .tiling = VK_IMAGE_TILING_OPTIMAL,
            .samples = wd->samples,
            .usage = VK_IMAGE_USAGE_TRANSIENT_ATTACHMENT_BIT | VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT,
            .initialLayout = VK_IMAGE_LAYOUT_UNDEFINED
        };

        VkResult err = vkCreateImage(device, &multisampledImageCreateInfo, nullptr, &wd->multisampledImage);
        check_vk_result(err);

        VkMemoryRequirements memReqs;
        vkGetImageMemoryRequirements(device, wd->multisampledImage, &memReqs);
        VkMemoryAllocateInfo allocateInfo
        {
            .sType = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO,
            .allocationSize = memReqs.size,
        };

        allocateInfo.memoryTypeIndex = ImGui_VKH_findMemoryType(physical_device, memReqs.memoryTypeBits, VK_MEMORY_PROPERTY_LAZILY_ALLOCATED_BIT);
        if (allocateInfo.memoryTypeIndex == 0xFFFFFFFF)
        {
            // If this is not available, fall back to device local memory
            allocateInfo.memoryTypeIndex = ImGui_VKH_findMemoryType(physical_device, memReqs.memoryTypeBits, VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT);
        }
        check_vk_result(vkAllocateMemory(device, &allocateInfo, nullptr, &wd->multisampledImageMemory));
        vkBindImageMemory(device, wd->multisampledImage, wd->multisampledImageMemory, 0);

        const VkImageViewCreateInfo multisampledViewCreateInfo
        {
            .sType = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO,
            .image = wd->multisampledImage,
            .viewType = VK_IMAGE_VIEW_TYPE_2D,
            .format = wd->SurfaceFormat.format,
            .components =
            {
                .r = VK_COMPONENT_SWIZZLE_R,
                .g = VK_COMPONENT_SWIZZLE_G,
                .b = VK_COMPONENT_SWIZZLE_B,
                .a = VK_COMPONENT_SWIZZLE_A,
            },
            .subresourceRange =
            {
                .aspectMask = VK_IMAGE_ASPECT_COLOR_BIT,
                .levelCount = 1,
                .layerCount = 1,
            },
        };

        check_vk_result(vkCreateImageView(device, &multisampledViewCreateInfo, nullptr, &wd->multisampledImageView));
    }
}


#endif

void ImGui::ShowDemoWindow(void* p_open)
{
    ShowDemoWindow(static_cast<bool*>(p_open));
}

void ImGui::ShowMetricsWindow(void* p_open)
{
    ShowMetricsWindow(static_cast<bool*>(p_open));
}

void ImGui::ShowDebugLogWindow(void* p_open)
{
    ShowDebugLogWindow(static_cast<bool*>(p_open));
}

void ImGui::ShowIDStackToolWindow(void* p_open)
{
    ShowIDStackToolWindow(static_cast<bool*>(p_open));
}

void ImGui::ShowAboutWindow(void* p_open)
{
    ShowAboutWindow(static_cast<bool*>(p_open));
}

void ImGui::Checkbox(const char* name, void* v)
{
    ImGui::Checkbox(name, static_cast<bool*>(v));
}

bool ImGui::CollapsingHeader(const char* label, void* p_visible, const ImGuiTreeNodeFlags flags)
{
    return ImGui::CollapsingHeader(label, static_cast<bool*>(p_visible), flags);
}

bool ImGui::Selectable(const char* label, void* p_selected, const ImGuiSelectableFlags flags, const ImVec2& size)
{
    return ImGui::Selectable(label, static_cast<bool*>(p_selected), flags, size);
}

bool ImGui::MenuItem(const char* label, const char* shortcut, void* p_selected, const bool enabled)
{
    return ImGui::MenuItem(label, shortcut, static_cast<bool*>(p_selected), enabled);
}

bool ImGui::Begin(const char* name, void* p_open, const ImGuiWindowFlags flags)
{
    return Begin(name, static_cast<bool*>(p_open), flags);
}

bool ImGui::BeginPopupModal(const char* name, void* p_open, const ImGuiWindowFlags flags)
{
    return BeginPopupModal(name, static_cast<bool*>(p_open), flags);
}

bool ImGui::BeginTabItem(const char* label, void* p_open, const ImGuiTabItemFlags flags)
{
    return BeginTabItem(label, static_cast<bool*>(p_open), flags);
}