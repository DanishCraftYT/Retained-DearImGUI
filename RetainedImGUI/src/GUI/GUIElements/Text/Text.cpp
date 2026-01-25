#include "Text.hpp"

Text::Text(std::string name, std::string text) : GUIElement(name), text(text) {}

void Text::render() {
    if (this->visible == GUIElementVisibility::Invisible) {
        return;
    }
    else if (this->visible == GUIElementVisibility::Disabled) {
        ImGui::BeginDisabled();
        ImGui::Text(this->text.c_str());
        ImGui::EndDisabled();
        return;
    }

    ImGui::Text(this->text.c_str());
}
