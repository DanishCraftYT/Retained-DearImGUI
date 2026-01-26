#include "SameLine.hpp"

SameLine::SameLine(std::string name) : GUIElement(name) {}

SameLine::SameLine() : GUIElement("") {}

void SameLine::render() {
    if (this->visible == GUIElementVisibility::Invisible) {
        return;
    }
    else if (this->visible == GUIElementVisibility::Disabled) {
        ImGui::BeginDisabled();
        ImGui::SameLine();
        ImGui::EndDisabled();
        return;
    }

    ImGui::SameLine();
}
