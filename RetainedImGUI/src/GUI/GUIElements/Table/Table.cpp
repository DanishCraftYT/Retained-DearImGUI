#include "Table.hpp"

Table::Table(std::string name, int columns) : ContainerGUIElement(name), columns(columns) {}

void Table::terminate() {
    for (size_t i = 0; i < this->GUIElements.size(); i++) {
        this->GUIElements.at(i)->terminate();
    }
    this->GUIElements.clear();
}

void Table::render() {
    if (this->visible == GUIElementVisibility::Invisible) {
        return;
    }
    else if (this->visible == GUIElementVisibility::Disabled) {
        ImGui::BeginDisabled();
        ImGui::BeginTable(std::format("{}##{}", this->name, this->uuid).c_str(), this->columns);
        for (size_t i = 0; i < this->GUIElements.size(); i++) {
            ImGui::TableNextColumn();
            this->GUIElements.at(i)->render();
        }
        ImGui::EndTable();
        ImGui::EndDisabled();
        return;
    }

    ImGui::BeginTable(std::format("{}##{}", this->name, this->uuid).c_str(), this->columns);
    for (size_t i = 0; i < this->GUIElements.size(); i++) {
        ImGui::TableNextColumn();
        this->GUIElements.at(i)->render();
    }
    ImGui::EndTable();
}

int Table::removeGUIElementByUUID(std::string uuid) {
    for (size_t i = 0; i < this->GUIElements.size(); i++) {
        if (this->GUIElements.at(i)->getUUID() == uuid) {
            this->GUIElements.erase(this->GUIElements.begin() + i);
            return 0;
        }
    }
    return 1;
}
