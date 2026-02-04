#include "AdvancedProgressBar.hpp"

AdvancedProgressBar::AdvancedProgressBar(std::string name, float& progress, ImVec2 size) : GUIElement(name), progress(progress), size(size) {}

void AdvancedProgressBar::render() {
    if (this->visible == GUIElementVisibility::Invisible) {
        return;
    }
    else if (this->visible == GUIElementVisibility::Disabled) {
        ImGui::BeginDisabled();
        ImGui::ProgressBar(this->progress, this->size);
        ImGui::EndDisabled();
        return;
    }

    ImGui::ProgressBar(this->progress, this->size);
}
