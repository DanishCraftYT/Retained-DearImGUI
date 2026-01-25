#pragma once

#include <string>
#include <functional>
#include <format>

#include "ImGUI/imgui.h"
#include "ImGUI/imgui_impl_glfw.h"
#include "ImGUI/imgui_impl_opengl3.h"
#include "ImGUI/imgui_stdlib.h"

#include "UUIDGenerator/UUIDGenerator.hpp"

enum GUIElementVisibility {
    Visible, // visible = true, disabled = false.
    Invisible, // visible = false, disabled = false.
    Disabled // visible = true, disabled = true.
};

class GUIElement {
public:
    GUIElement(std::string name);
    GUIElement();
    virtual void render();
    std::string getName();
    std::string getUUID();
    GUIElementVisibility visible;
protected:
    std::string name;
    std::string uuid;
};
