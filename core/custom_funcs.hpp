#pragma once
#include "imgui.h"

namespace ImGui
{
    // Modified ShowDemoWindow that uses void instead of bool for p_open
    IMGUI_API void          ShowDemoWindow(void* p_open);
    // Modified ShowMetricsWindow that uses void instead of bool for p_open
    IMGUI_API void          ShowMetricsWindow(void* p_open);
    // Modified ShowDebugLogWindow that uses void instead of bool for p_open
    IMGUI_API void          ShowDebugLogWindow(void* p_open);
    // Modified ShowStackToolWindow that uses void instead of bool for p_open
    IMGUI_API void          ShowStackToolWindow(void* p_open);
    // Modified ShowAboutWindow that uses void instead of bool for p_open
    IMGUI_API void          ShowAboutWindow(void* p_open);

    // Modified Checkbox that uses void instead of bool for v
    IMGUI_API void          Checkbox(const char* name, void* v);

    // Modified CollapsingHeader that uses void instead of bool for p_visible
    IMGUI_API bool          CollapsingHeader(const char* label, void* p_visible, ImGuiTreeNodeFlags flags = 0);

    // Modified Selectable that uses void instead of bool for p_selected
    IMGUI_API bool          Selectable(const char* label, void* p_selected, ImGuiSelectableFlags flags = 0, const ImVec2& size = ImVec2(0, 0));

    // Modified MenuItem that uses void instead of bool for p_selected
    IMGUI_API bool          MenuItem(const char* label, const char* shortcut, void* p_selected, bool enabled = true);

    // Modified Begin that uses void instead of bool for p_open
    IMGUI_API bool          Begin(const char* name, void* p_open, ImGuiWindowFlags flags = 0);

    // Modified BeginPopupModal that uses void instead of bool for p_open
    IMGUI_API bool          BeginPopupModal(const char* name, void* p_open, ImGuiWindowFlags flags = 0);

    // Modified BeginTabItem that uses void instead of bool for p_open
    IMGUI_API bool          BeginTabItem(const char* label, void* p_open, ImGuiTabItemFlags flags = 0);
}
