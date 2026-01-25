#pragma once

#include "GUI/Containers/ContainerBoxGUIElement.hpp"

class ListBox : public ContainerBoxGUIElement<std::string> {
public:
    ListBox(std::string name, std::string text, ImVec2 size);
    void render() override;
private:
    std::string text;
    ImVec2 size;
};
