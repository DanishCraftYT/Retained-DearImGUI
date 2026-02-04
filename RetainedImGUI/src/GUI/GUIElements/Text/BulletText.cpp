#include "BulletText.hpp"

BulletText::BulletText(std::string name, std::string text) : Text(name, text) {}

void BulletText::render() {
    if (this->visible == GUIElementVisibility::Invisible) {
        return;
    }
    else if (this->visible == GUIElementVisibility::Disabled) {
        ImGui::BeginDisabled();
        ImGui::BulletText(this->text.c_str());
        ImGui::EndDisabled();
        return;
    }

    ImGui::BulletText(this->text.c_str());
}
