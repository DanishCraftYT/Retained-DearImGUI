#include "Child.hpp"

Child::Child(std::string name, ImVec2 size, bool border) : GUIElement(name), size(size), border(border) {}

void Child::render() {
    if (this->visible == GUIElementVisibility::Invisible) {
        return;
    }
    else if (this->visible == GUIElementVisibility::Disabled) {
        ImGui::BeginDisabled();
        if (this->border) {
            ImGui::BeginChild(this->name.c_str(), this->size, ImGuiChildFlags_Borders);
        }
        else {
            ImGui::BeginChild(this->name.c_str(), this->size);
        }
        for (size_t i = 0; i < this->GUIElements.size(); i++) {
            this->GUIElements.at(i)->render();
        }
        ImGui::EndChild();
        ImGui::EndDisabled();
        return;
    }

    if (this->border) {
        ImGui::BeginChild(this->name.c_str(), this->size, ImGuiChildFlags_Borders);
    }
    else {
        ImGui::BeginChild(this->name.c_str(), this->size);
    }
    for (size_t i = 0; i < this->GUIElements.size(); i++) {
        this->GUIElements.at(i)->render();
    }
    ImGui::EndChild();
}

void Child::addGUIElement(std::shared_ptr<GUIElement> element) {
    this->GUIElements.emplace_back(element);
}

int Child::removeGUIElementByUUID(std::string uuid) {
    for (size_t i = 0; i < this->GUIElements.size(); i++) {
        if (this->GUIElements.at(i)->getUUID() == uuid) {
            this->GUIElements.erase(this->GUIElements.begin() + i);
            return 0;
        }
    }
    return 1;
}
