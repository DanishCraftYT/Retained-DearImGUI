#include "ToolbarMenu.hpp"

ToolbarMenu::ToolbarMenu(std::string name, std::string text) : ContainerMultipleGUIElements(name, text) {}

ToolbarMenu::ToolbarMenu() : ContainerMultipleGUIElements("", "") {}

void ToolbarMenu::render() {
    if (this->visible == GUIElementVisibility::Invisible) {
        return;
    }
    else if (this->visible == GUIElementVisibility::Disabled) {
        ImGui::BeginDisabled();
        if (ImGui::BeginMenu(std::format("{}##{}", this->text, this->uuid).c_str())) {
            for (size_t i = 0; i < this->GUIElements.size(); i++) {
                this->GUIElements.at(i)->render();
            }
            ImGui::EndMenu();
        }
        ImGui::EndDisabled();
        return;
    }

    if (ImGui::BeginMenu(std::format("{}##{}", this->text, this->uuid).c_str())) {
        for (size_t i = 0; i < this->GUIElements.size(); i++) {
            this->GUIElements.at(i)->render();
        }
        ImGui::EndMenu();
    }
}
