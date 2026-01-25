#include "InputField.hpp"

InputField::InputField(std::string name, std::string text) : GUIElement(name), text(text) {}

void InputField::render() {
    if (this->visible == GUIElementVisibility::Invisible) {
        return;
    }
    else if (this->visible == GUIElementVisibility::Disabled) {
        ImGui::BeginDisabled();
        ImGui::InputText(std::format("{}##{}", this->text, this->uuid).c_str(), &this->buffer);
        ImGui::EndDisabled();
        return;
    }
    
    ImGui::InputText(std::format("{}##{}", this->text, this->uuid).c_str(), &this->buffer);
}

std::string InputField::getInputFieldText() {
    return this->buffer;
}
