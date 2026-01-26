#pragma once

#include "GUI/GUIElement.hpp"

class Separator : public GUIElement {
public:
    Separator(std::string name, std::string text="");
    Separator();
    void render() override;
private:
    std::string text;
};
