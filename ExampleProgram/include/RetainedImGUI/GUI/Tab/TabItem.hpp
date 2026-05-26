#pragma once

#include "GUI/Containers/ContainerMultipleGUIElements.hpp"

class TabItem : public ContainerMultipleGUIElements {
public:
    TabItem(std::string name, std::string text);
    TabItem();
    void render() override;
};
