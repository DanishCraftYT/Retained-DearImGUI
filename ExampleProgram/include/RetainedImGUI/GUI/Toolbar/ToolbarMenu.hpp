#pragma once

#include "GUI/Containers/ContainerMultipleGUIElements.hpp"

class ToolbarMenu : public ContainerMultipleGUIElements {
public:
    ToolbarMenu(std::string name, std::string text);
    ToolbarMenu();
    void render() override;
};
