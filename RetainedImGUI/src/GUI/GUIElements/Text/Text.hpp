#pragma once

#include "GUI/GUIElement.hpp"

class Text : public GUIElement {
public:
    Text(std::string name, std::string text);
    void render() override;
protected:
    std::string text;
};
