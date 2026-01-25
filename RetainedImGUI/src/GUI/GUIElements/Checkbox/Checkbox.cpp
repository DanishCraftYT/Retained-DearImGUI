#include "Checkbox.hpp"

Checkbox::Checkbox(std::string name, std::string text) : GUIElement(name), text(text), checked(false) {}

void Checkbox::render() {
    if (this->visible == GUIElementVisibility::Invisible) {
        return;
    }
    else if (this->visible == GUIElementVisibility::Disabled) {
        ImGui::BeginDisabled();
        ImGui::Checkbox(std::format("{}##{}", this->text, this->uuid).c_str(), &this->checked);
        ImGui::EndDisabled();
        return;
    }

    ImGui::Checkbox(std::format("{}##{}", this->text, this->uuid).c_str(), &this->checked);
}

bool Checkbox::isChecked() {
    return this->checked;
}
