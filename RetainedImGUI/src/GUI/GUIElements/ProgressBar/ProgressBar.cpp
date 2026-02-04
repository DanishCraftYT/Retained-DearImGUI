#include "ProgressBar.hpp"

ProgressBar::ProgressBar(std::string name, float minProgress, float maxProgress, float progressAmount, ProgressDirection direction, ImVec2 size) : SimpleProgressBar(name, minProgress, maxProgress, progressAmount, direction, size) {}

void ProgressBar::render() {
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

void ProgressBar::update(bool useDeltaTime) {
    // checks if the Progress Bar has reached the end and doesn't need to be updated.
    if (this->direction == ProgressDirection::BACKWARD) {
        if (this->progress == this->minProgress) {
            return;
        }
    }
    else if (this->progress == this->maxProgress) {
        return;
    }

    // ADD COMMENT HERE EXPLAINING WHAT IT DOES.
    if (useDeltaTime) {
        this->progress += direction * this->progressAmount * ImGui::GetIO().DeltaTime;
    }
    else {
        this->progress += direction * this->progressAmount;
    }
    if (this->progress >= this->maxProgress) {
        this->progress = this->maxProgress;
    }
}
