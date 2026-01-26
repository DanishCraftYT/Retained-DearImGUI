#include "Separator.hpp"

Separator::Separator(std::string name, std::string text) : GUIElement(name), text(text) {}

Separator::Separator() : GUIElement(""), text("") {}

void Separator::render() {
    if (this->visible == GUIElementVisibility::Invisible) {
        return;
    }
    else if (this->visible == GUIElementVisibility::Disabled) {
        ImGui::BeginDisabled();
        if (this->text == "") {
            ImGui::Separator();
        }
        else {
            ImGui::SeparatorText(std::format("{}##{}", this->text, this->uuid).c_str());
        }
        ImGui::EndDisabled();
        return;
    }

    if (this->text == "") {
        ImGui::Separator();
    }
    else {
        ImGui::SeparatorText(std::format("{}##{}", this->text, this->uuid).c_str());
    }
}
