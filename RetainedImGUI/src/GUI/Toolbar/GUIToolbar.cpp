#include "GUIToolbar.hpp"

GUIToolbar::GUIToolbar(std::string name) : visible(GUIElementVisibility::Visible), name(name), uuid(UUIDGenerator::generateUUID()) {}

GUIToolbar::GUIToolbar() : visible(GUIElementVisibility::Visible), name(""), uuid(UUIDGenerator::generateUUID()) {}

void GUIToolbar::terminate() {
    for (size_t i = 0; i < this->toolbarMenus.size(); i++) {
        this->toolbarMenus.at(i).terminate();
    }
    this->toolbarMenus.clear();
}

void GUIToolbar::render() {
    if (this->visible == GUIElementVisibility::Invisible) {
        return;
    }
    else if (this->visible == GUIElementVisibility::Disabled) {
        ImGui::BeginDisabled();
        if (ImGui::BeginMainMenuBar()) {
            for (size_t i = 0; i < this->toolbarMenus.size(); i++) {
                this->toolbarMenus.at(i).render();
            }
            ImGui::EndMainMenuBar();
        }
        ImGui::EndDisabled();
        return;
    }

    if (ImGui::BeginMainMenuBar()) {
        for (size_t i = 0; i < this->toolbarMenus.size(); i++) {
            this->toolbarMenus.at(i).render();
        }
        ImGui::EndMainMenuBar();
    }
}

ToolbarMenu& GUIToolbar::addToolbarMenu(std::string name, std::string text) {
    this->toolbarMenus.emplace_back(name, text);
    return this->toolbarMenus.back();
}

int GUIToolbar::removeToolbarMenuByUUID(std::string uuid) {
    for (size_t i = 0; i < this->toolbarMenus.size(); i++) {
        if (this->toolbarMenus.at(i).getUUID() == uuid) {
            this->toolbarMenus.erase(this->toolbarMenus.begin() + i);
            return 0;
        }
    }
    return 1;
}

std::string GUIToolbar::getName() {
    return this->name;
}

std::string GUIToolbar::getUUID() {
    return this->uuid;
}
