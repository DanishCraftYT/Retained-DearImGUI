#include "GUI.hpp"

GUI::GUI(std::string name) : visible(GUIElementVisibility::Visible), toolbar(std::format("{}Toolbar", name)), name(name) {
    toolbar.visible = GUIElementVisibility::Invisible;
}

GUI::GUI() : visible(GUIElementVisibility::Visible), toolbar("Toolbar"), name("") {
    toolbar.visible = GUIElementVisibility::Invisible;
}

void GUI::terminate() {
    for (size_t i = 0; i < this->GUIWindows.size(); i++) {
        this->GUIWindows.at(i).terminate();
    }
    this->GUIWindows.clear();
}

void GUI::renderAllWindows() {
    if (this->visible == GUIElementVisibility::Invisible) {
        return;
    }
    else if (this->visible == GUIElementVisibility::Disabled) {
        ImGui::BeginDisabled();
        this->toolbar.render();
        for (size_t i = 0; i < this->GUIWindows.size(); i++) {
            this->GUIWindows.at(i).render();
        }
        ImGui::EndDisabled();
        return;
    }

    this->toolbar.render();
    for (size_t i = 0; i < this->GUIWindows.size(); i++) {
        this->GUIWindows.at(i).render();
    }
}

GUIWindow& GUI::createWindow(std::string name, std::string text, ImVec2 position, ImVec2 size) {
    this->GUIWindows.emplace_back(name, text, position, size);
    return this->GUIWindows.back();
}

GUIWindow& GUI::getWindowByUUID(std::string uuid) {
    for (size_t i = 0; i < this->GUIWindows.size(); i++) {
        if (this->GUIWindows.at(i).getUUID() == uuid) {
            return this->GUIWindows.at(i);
        }
    }

    GUIWindow window;
    return window;
}

int GUI::removeWindowByUUID(std::string uuid) {
    for (size_t i = 0; i < this->GUIWindows.size(); i++) {
        if (this->GUIWindows.at(i).getUUID() == uuid) {
            this->GUIWindows.erase(this->GUIWindows.begin() + i);
            return 0;
        }
    }
    return 1;
}

std::string GUI::getName() {
    return this->name;
}

std::string GUI::getUUID() {
    return this->uuid;
}
