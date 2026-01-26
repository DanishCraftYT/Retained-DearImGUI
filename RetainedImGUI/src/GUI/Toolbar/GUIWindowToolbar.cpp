#include "GUIWindowToolbar.hpp"

GUIWindowToolbar::GUIWindowToolbar(std::string name) : visible(GUIElementVisibility::Visible), name(name), uuid(UUIDGenerator::generateUUID()) {}

GUIWindowToolbar::GUIWindowToolbar() : visible(GUIElementVisibility::Visible), name(""), uuid(UUIDGenerator::generateUUID()) {}

void GUIWindowToolbar::terminate() {
    for (size_t i = 0; i < this->toolbarMenus.size(); i++) {
        this->toolbarMenus.at(i).terminate();
    }
    this->toolbarMenus.clear();
}

void GUIWindowToolbar::render() {
    if (this->visible == GUIElementVisibility::Invisible) {
        return;
    }
    else if (this->visible == GUIElementVisibility::Disabled) {
        ImGui::BeginDisabled();
        if (ImGui::BeginMenuBar()) {
            for (size_t i = 0; i < this->toolbarMenus.size(); i++) {
                this->toolbarMenus.at(i).render();
            }
            ImGui::EndMenuBar();
        }
        ImGui::EndDisabled();
        return;
    }

    if (ImGui::BeginMenuBar()) {
        for (size_t i = 0; i < this->toolbarMenus.size(); i++) {
            this->toolbarMenus.at(i).render();
        }
        ImGui::EndMenuBar();
    }
}

ToolbarMenu& GUIWindowToolbar::addToolbarMenu(std::string name, std::string text) {
    this->toolbarMenus.emplace_back(name, text);
    return this->toolbarMenus.back();
}

int GUIWindowToolbar::removeToolbarMenuByUUID(std::string uuid) {
    for (size_t i = 0; i < this->toolbarMenus.size(); i++) {
        if (this->toolbarMenus.at(i).getUUID() == uuid) {
            this->toolbarMenus.erase(this->toolbarMenus.begin() + i);
            return 0;
        }
    }
    return 1;
}

std::string GUIWindowToolbar::getName() {
    return this->name;
}

std::string GUIWindowToolbar::getUUID() {
    return this->uuid;
}
