#pragma once

#include "UUIDGenerator/UUIDGenerator.hpp"
#include "GUI/GUIElement.hpp"

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
