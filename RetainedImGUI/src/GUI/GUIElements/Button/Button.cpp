#include "Button.hpp"

Button::Button(std::string name, std::string text, ImVec2 size) : GUIElement(name), text(text), size(size) {}

void Button::render() {
    if (this->visible == GUIElementVisibility::Invisible) {
        return;
    }
    else if (this->visible == GUIElementVisibility::Disabled) {
        ImGui::BeginDisabled();
        ImGui::Button(std::format("{}##{}", this->text, this->uuid).c_str(), size);
        ImGui::EndDisabled();
        return;
    }
    
    ImGui::Button(std::format("{}##{}", this->text, this->uuid).c_str(), size);
}
