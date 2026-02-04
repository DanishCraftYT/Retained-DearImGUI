#pragma once

#include "Text.hpp"

class BulletText : public Text {
public:
    BulletText(std::string name, std::string text);
    void render() override;
};
