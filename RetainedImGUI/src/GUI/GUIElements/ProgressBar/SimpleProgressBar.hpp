#pragma once

#include "GUI/GUIElement.hpp"

enum ProgressDirection {
    BACKWARD = -1,
    FORWARD = 1
};

class SimpleProgressBar : public GUIElement {
public:
    SimpleProgressBar(std::string name, float minProgress, float maxProgress, float progressAmount, ProgressDirection direction, ImVec2 size);
    void render() override;
    float getProgress();
    bool hasFinished();
private:
    float minProgress;
    float maxProgress;
    float progressAmount;
    float progress;
    ProgressDirection direction;
    ImVec2 size;
};
