#pragma once

#include "ImGUI/imgui.h"
#include "ImGUI/imgui_impl_glfw.h"
#include "ImGUI/imgui_impl_opengl3.h"

#include "UUIDGenerator/UUIDGenerator.hpp"
#include "GUIElement.hpp"

class GUITooltip {
public:
    GUITooltip(std::string name, std::string text);
    GUITooltip();
    void render();
    GUIElementVisibility visible;
private:
    std::string name;
    std::string text;
    std::string uuid;
};
