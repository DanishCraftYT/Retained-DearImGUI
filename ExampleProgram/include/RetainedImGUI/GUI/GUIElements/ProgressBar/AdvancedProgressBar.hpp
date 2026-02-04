#pragma once

#include "GUI/GUIElement.hpp"

class AdvancedProgressBar : public GUIElement {
public:
    AdvancedProgressBar(std::string name, float& progress, ImVec2 size);
    void render() override;
private:
    float& progress;
    ImVec2 size;
};
