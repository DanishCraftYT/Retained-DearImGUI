#pragma once

#include "GUI/GUIElement.hpp"

class InputField : public GUIElement {
public:
    InputField(std::string name, std::string text);
    void render() override;
    std::string getInputFieldText();
private:
    std::string text;
    std::string buffer;
};
