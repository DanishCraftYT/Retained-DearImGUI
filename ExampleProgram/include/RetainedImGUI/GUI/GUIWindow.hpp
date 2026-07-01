#pragma once

#include "Containers/ContainerMultipleGUIElements.hpp"
#include "Toolbar/GUIWindowToolbar.hpp"
#include "Tab/GUITab.hpp"

class GUIWindow : public ContainerMultipleGUIElements {
public:
    GUIWindow(std::string name, std::string text, ImVec2 position, ImVec2 size, bool resizable=true, bool movable=true);
    GUIWindow();
    void terminate() override;
    void render() override;
    GUIWindowToolbar toolbar;
    GUITab tab;
private:
    ImVec2 position;
    ImVec2 size;
    int resizable;
    int movable;
};
