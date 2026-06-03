#include "Group.hpp"

Group::Group(std::string name) : ContainerGUIElement(name) {}

void Group::terminate() {
    for (size_t i = 0; i < this->GUIElements.size(); i++) {
        this->GUIElements.at(i)->terminate();
    }
    this->GUIElements.clear();
}

void Group::render() {
    if (this->visible == GUIElementVisibility::Invisible) {
        return;
    }
    else if (this->visible == GUIElementVisibility::Disabled) {
        ImGui::BeginDisabled();
        ImGui::BeginGroup();
        for (size_t i = 0; i < this->GUIElements.size(); i++) {
            this->GUIElements.at(i)->render();
        }
        ImGui::EndGroup();
        ImGui::EndDisabled();
        return;
    }

    ImGui::BeginGroup();
    for (size_t i = 0; i < this->GUIElements.size(); i++) {
        this->GUIElements.at(i)->render();
    }
    ImGui::EndGroup();
}

int Group::removeGUIElementByUUID(std::string uuid) {
    for (size_t i = 0; i < this->GUIElements.size(); i++) {
        if (this->GUIElements.at(i)->getUUID() == uuid) {
            this->GUIElements.erase(this->GUIElements.begin() + i);
            return 0;
        }
    }
    return 1;
}
