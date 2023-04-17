#pragma once
#include "imgui.h"

namespace ImGui
{
    // Modified ShowDemoWindow that uses void instead of bool for p_open
    IMGUI_API void          ShowDemoWindow(void* p_open = nullptr);
    // Modified ShowMetricsWindow that uses void instead of bool for p_open
    IMGUI_API void          ShowMetricsWindow(void* p_open = nullptr);
    // Modified ShowDebugLogWindow that uses void instead of bool for p_open
    IMGUI_API void          ShowDebugLogWindow(void* p_open = nullptr);
    // Modified ShowStackToolWindow that uses void instead of bool for p_open
    IMGUI_API void          ShowStackToolWindow(void* p_open = nullptr);
    // Modified ShowAboutWindow that uses void instead of bool for p_open
    IMGUI_API void          ShowAboutWindow(void* p_open = nullptr);

    // Modified Begin that uses void instead of bool for p_open
    IMGUI_API bool          Begin(const char* name, void* p_open = nullptr, ImGuiWindowFlags flags = 0);

    // Modified BeginPopupModal that uses void instead of bool for p_open
    IMGUI_API bool          BeginPopupModal(const char* name, void* p_open = nullptr, ImGuiWindowFlags flags = 0);

    // Modified BeginTabItem that uses void instead of bool for p_open
    IMGUI_API bool          BeginTabItem(const char* label, void* p_open = nullptr, ImGuiTabItemFlags flags = 0);
}