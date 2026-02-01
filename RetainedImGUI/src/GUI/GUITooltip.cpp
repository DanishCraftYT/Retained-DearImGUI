#include "GUITooltip.hpp"

GUITooltip::GUITooltip(std::string name, std::string text) : name(name), text(text), uuid(UUIDGenerator::generateUUID()) {}

GUITooltip::GUITooltip() : name(""), text(""), uuid(UUIDGenerator::generateUUID()) {}

void GUITooltip::render() {
    if (this->visible == GUIElementVisibility::Invisible) {
        return;
    }
    else if (this->visible == GUIElementVisibility::Disabled) {
        ImGui::BeginDisabled();
        ImGui::BeginTooltip();
        ImGui::Text(std::format("{}##{}", this->text, this->uuid).c_str());
        ImGui::EndTooltip();
        ImGui::EndDisabled();
        return;
    }

    ImGui::BeginTooltip();
    ImGui::Text(std::format("{}##{}", this->text, this->uuid).c_str());
    ImGui::EndTooltip();
}
