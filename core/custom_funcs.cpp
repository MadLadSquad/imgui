#include "custom_funcs.hpp"

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