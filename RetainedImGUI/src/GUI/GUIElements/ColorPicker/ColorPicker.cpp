#include "ColorPicker.hpp"

ColorPicker::ColorPicker(std::string name, std::string text, ColorFormat colorFormat, ColorAlpha alpha) : GUIElement(name), text(text), colorFormat(colorFormat), alpha(alpha) {}

void ColorPicker::render() {
    if (this->visible == GUIElementVisibility::Invisible) {
        return;
    }
    else if (this->visible == GUIElementVisibility::Disabled) {
        ImGui::BeginDisabled();
        ImGui::ColorEdit4(std::format("{}##{}", this->text, this->uuid).c_str(), (float*)&this->color, this->colorFormat | this->alpha);
        ImGui::EndDisabled();
        return;
    }
    ImGui::ColorEdit4(std::format("{}##{}", this->text, this->uuid).c_str(), (float*)&this->color, this->colorFormat | this->alpha);
}

ColorFormat ColorPicker::getColorFormat() {
    return this->colorFormat;
}

ColorAlpha ColorPicker::getAlpha() {
    return this->alpha;
}

ImVec4 ColorPicker::getColor() {
    return this->color;
}
