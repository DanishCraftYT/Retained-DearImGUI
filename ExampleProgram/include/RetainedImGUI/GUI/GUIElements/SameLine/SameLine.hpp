#pragma once

#include "GUI/GUIElement.hpp"

class SameLine : public GUIElement {
public:
    SameLine(std::string name);
    SameLine();
    void render() override;
};
