#pragma once

#include "GUI/GUIElement.hpp"

class Checkbox : public GUIElement {
public:
    Checkbox(std::string name, std::string text);
    void render() override;
    bool isChecked();
private:
    std::string text;
    bool checked;
};
