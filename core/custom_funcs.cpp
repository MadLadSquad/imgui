#include "custom_funcs.hpp"

void ImGui::ShowDemoWindow(void* p_open)
{
    ShowDemoWindow((bool*)p_open);
}

void ImGui::ShowMetricsWindow(void* p_open)
{
    ShowMetricsWindow((bool*)p_open);
}

void ImGui::ShowDebugLogWindow(void* p_open)
{
    ShowDebugLogWindow((bool*)p_open);
}

void ImGui::ShowStackToolWindow(void* p_open)
{
    ShowStackToolWindow((bool*)p_open);
}

void ImGui::ShowAboutWindow(void* p_open)
{
    ShowAboutWindow((bool*)p_open);
}

bool ImGui::Begin(const char* name, void* p_open, ImGuiWindowFlags flags)
{
    return Begin(name, (bool*)p_open, flags);
}

bool ImGui::BeginPopupModal(const char* name, void* p_open, ImGuiWindowFlags flags)
{
    return BeginPopupModal(name, (bool*)p_open, flags);
}

bool ImGui::BeginTabItem(const char* label, void* p_open, ImGuiTabItemFlags flags)
{
    return BeginTabItem(label, (bool*)p_open, flags);
}
