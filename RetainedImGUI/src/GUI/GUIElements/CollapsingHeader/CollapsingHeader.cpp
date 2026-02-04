#include "CollapsingHeader.hpp"

CollapsingHeader::CollapsingHeader(std::string name) : ContainerGUIElement(name) {}

void CollapsingHeader::terminate() {
    for (size_t i = 0; i < this->GUIElements.size(); i++) {
        this->GUIElements.at(i)->terminate();
    }
    this->GUIElements.clear();
}

void CollapsingHeader::render() {
    if (this->visible == GUIElementVisibility::Invisible) {
        return;
    }
    else if (this->visible == GUIElementVisibility::Disabled) {
        ImGui::BeginDisabled();
        if (ImGui::CollapsingHeader(std::format("{}##{}", this->name, this->uuid).c_str())) {
            for (size_t i = 0; i < this->GUIElements.size(); i++) {
                this->GUIElements.at(i)->render();
            }
        }
        ImGui::EndDisabled();
        return;
    }

    if (ImGui::CollapsingHeader(std::format("{}##{}", this->name, this->uuid).c_str())) {
        for (size_t i = 0; i < this->GUIElements.size(); i++) {
            this->GUIElements.at(i)->render();
        }
    }
}

int CollapsingHeader::removeGUIElementByUUID(std::string uuid) {
    for (size_t i = 0; i < this->GUIElements.size(); i++) {
        if (this->GUIElements.at(i)->getUUID() == uuid) {
            this->GUIElements.erase(this->GUIElements.begin() + i);
            return 0;
        }
    }
    return 1;
}
