#pragma once

#include "GUI/Containers/ContainerBoxGUIElement.hpp"

class ComboBox : public ContainerBoxGUIElement<std::string> {
public:
    ComboBox(std::string name, std::string text, std::string previewText);
    void render() override;
private:
    std::string text;
    std::string previewText;
};
