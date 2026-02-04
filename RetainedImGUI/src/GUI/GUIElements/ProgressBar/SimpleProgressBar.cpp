#include "SimpleProgressBar.hpp"

SimpleProgressBar::SimpleProgressBar(std::string name, float minProgress, float maxProgress, float progressAmount, ProgressDirection direction, ImVec2 size) : GUIElement(name), minProgress(minProgress), maxProgress(maxProgress), progressAmount(progressAmount), progress(minProgress), direction(direction), size(size) {}

void SimpleProgressBar::render() {
    if (this->visible == GUIElementVisibility::Invisible) {
        return;
    }
    else if (this->visible == GUIElementVisibility::Disabled) {
        ImGui::BeginDisabled();
        ImGui::ProgressBar(this->progress, this->size);
        ImGui::EndDisabled();
        return;
    }

    // checks if the Progress Bar has reached the end and renders the Progress Bar without doing any maths.
    if (this->direction == ProgressDirection::BACKWARD && this->progress == this->minProgress) {
        ImGui::ProgressBar(this->progress, this->size);
        return;
    }
    else if (this->progress == this->maxProgress) {
        ImGui::ProgressBar(this->progress, this->size);
        return;
    }

    // ADD COMMENT HERE EXPLAINING WHAT IT DOES.
    this->progress += direction * this->progressAmount * ImGui::GetIO().DeltaTime;
    if (this->progress >= this->maxProgress) {
        this->progress = this->maxProgress;
    }

    ImGui::ProgressBar(this->progress, this->size);
}

float SimpleProgressBar::getProgress() {
    return this->progress;
}

bool SimpleProgressBar::hasFinished() {
    if (direction == ProgressDirection::FORWARD) {
        return this->progress == this->maxProgress;
    }

    // handles backwards Progress Direction.
    return this->progress == this->minProgress;
}
