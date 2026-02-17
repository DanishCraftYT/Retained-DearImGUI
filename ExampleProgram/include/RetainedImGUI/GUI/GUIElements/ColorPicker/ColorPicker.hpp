#pragma once

#include "GUI/GUIElement.hpp"

enum ColorFormat {
    RGB=1048576,
    HSV=2097152
};

enum ColorAlpha {
    ALPHA=0,
    NO_ALPHA=2
};

class ColorPicker : public GUIElement {
public:
    ColorPicker(std::string name, std::string text, ColorFormat colorFormat, ColorAlpha alpha=ColorAlpha::NO_ALPHA);
    void render() override;
    ColorFormat getColorFormat();
    ColorAlpha getAlpha();
    ImVec4 getColor();
private:
    std::string text;
    ColorFormat colorFormat;
    ColorAlpha alpha;
    ImVec4 color;
};
