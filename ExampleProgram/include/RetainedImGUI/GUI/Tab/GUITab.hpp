#pragma once

#include "TabItem.hpp"
#include <memory>

class GUITab {
public:
    GUITab(std::string name, std::string text);
    GUITab();
    void terminate();
    void render();
    std::shared_ptr<TabItem> addTabItem(std::string name, std::string text);
    std::vector<std::shared_ptr<TabItem>> getTabItemsByName(std::string name) {
        std::vector<std::shared_ptr<TabItem>> elements;
        for (size_t i = 0; i < this->tabItems.size(); i++) {
            if (this->tabItems.at(i)->getName() == name) {
                elements.emplace_back(this->tabItems.at(i));
            }
        }
        return elements;
    }
    std::shared_ptr<TabItem> getTabItemByUUID(std::string uuid) {
        for (size_t i = 0; i < this->tabItems.size(); i++) {
            if (this->tabItems.at(i)->getUUID() == uuid) {
                return this->tabItems.at(i);
            }
        }
        return nullptr;
    }
    int removeTabItemByUUID(std::string uuid);
    std::string getName();
    std::string getUUID();
    GUIElementVisibility visible;
private:
    std::string name;
    std::string text;
    std::string uuid;
    std::vector<std::shared_ptr<TabItem>> tabItems;
};
