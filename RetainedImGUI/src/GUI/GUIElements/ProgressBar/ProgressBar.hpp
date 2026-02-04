#pragma once

#include "SimpleProgressBar.hpp"

class ProgressBar : public SimpleProgressBar {
public:
    ProgressBar(std::string name, float minProgress, float maxProgress, float progressAmount, ProgressDirection direction, ImVec2 size);
    void render() override;
    void update(bool useDeltaTime=false);
};
