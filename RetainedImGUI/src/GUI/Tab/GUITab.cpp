#include "GUITab.hpp"
#include "GUI/Tab/TabItem.hpp"
#include <memory>

GUITab::GUITab(std::string name, std::string text) : visible(GUIElementVisibility::Visible), name(name), uuid(UUIDGenerator::generateUUID()) {}

GUITab::GUITab() : visible(GUIElementVisibility::Visible), name(""), uuid(UUIDGenerator::generateUUID()) {}

void GUITab::terminate() {
    for (size_t i = 0; i < this->tabItems.size(); i++) {
        this->tabItems.at(i)->terminate();
    }
    this->tabItems.clear();
}

void GUITab::render() {
    if (this->visible == GUIElementVisibility::Invisible) {
        return;
    }
    else if (this->visible == GUIElementVisibility::Disabled) {
        ImGui::BeginDisabled();
        if (ImGui::BeginMainMenuBar()) {
            for (size_t i = 0; i < this->tabItems.size(); i++) {
                this->tabItems.at(i)->render();
            }
            ImGui::EndMainMenuBar();
        }
        ImGui::EndDisabled();
        return;
    }

    if (ImGui::BeginMainMenuBar()) {
        for (size_t i = 0; i < this->tabItems.size(); i++) {
            this->tabItems.at(i)->render();
        }
        ImGui::EndMainMenuBar();
    }
}

std::shared_ptr<TabItem> GUITab::addTabItem(std::string name, std::string text) {
    this->tabItems.emplace_back(std::make_shared<TabItem>(name, text));
    return this->tabItems.back();
}

int GUITab::removeTabItemByUUID(std::string uuid) {
    for (size_t i = 0; i < this->tabItems.size(); i++) {
        if (this->tabItems.at(i)->getUUID() == uuid) {
            this->tabItems.erase(this->tabItems.begin() + i);
            return 1;
        }
    }
    return 0;
}

std::string GUITab::getName() {
    return this->name;
}

std::string GUITab::getUUID() {
    return this->uuid;
}
