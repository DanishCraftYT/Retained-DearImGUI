#pragma once

#include "ToolbarMenu.hpp"

class GUIToolbar {
public:
    GUIToolbar(std::string name);
    GUIToolbar();
    void terminate();
    void render();
    ToolbarMenu& addToolbarMenu(std::string name, std::string text);
    std::vector<ToolbarMenu> getToolbarMenusByName(std::string name) {
        std::vector<ToolbarMenu> elements;
        for (size_t i = 0; i < this->toolbarMenus.size(); i++) {
            if (this->toolbarMenus.at(i).getName() == name) {
                elements.emplace_back(this->toolbarMenus.at(i));
            }
        }
        return elements;
    }
    ToolbarMenu& getToolbarMenuByUUID(std::string uuid) {
        for (size_t i = 0; i < this->toolbarMenus.size(); i++) {
            if (this->toolbarMenus.at(i).getUUID() == uuid) {
                return this->toolbarMenus.at(i);
            }
        }

        ToolbarMenu toolbarMenu;
        return toolbarMenu;
    }
    int removeToolbarMenuByUUID(std::string uuid);
    std::string getName();
    std::string getUUID();
    GUIElementVisibility visible;
protected:
    std::string name;
    std::string uuid;
    std::vector<ToolbarMenu> toolbarMenus;
};
