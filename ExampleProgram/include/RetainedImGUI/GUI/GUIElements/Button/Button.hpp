#pragma once

#include "GUI/GUIElement.hpp"

class Button : public GUIElement {
public:
    Button(std::string name, std::string text, ImVec2 size);
    void render() override;
private:
    std::string text;
    ImVec2 size;
};
