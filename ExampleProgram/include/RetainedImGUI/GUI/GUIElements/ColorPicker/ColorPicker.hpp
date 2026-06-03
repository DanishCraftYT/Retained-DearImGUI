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

template <typename T>
class ColorPicker : public GUIElement {
public:
    ColorPicker(std::string name, std::string text, ColorFormat colorFormat, ColorAlpha alpha=ColorAlpha::NO_ALPHA, std::function<T(ColorPicker&)> callback=NULL) : GUIElement(name), text(text), colorFormat(colorFormat), alpha(alpha), callback(callback) {}
    void render() override {
        if (this->visible == GUIElementVisibility::Invisible) {
            return;
        }
        else if (this->visible == GUIElementVisibility::Disabled) {
            ImGui::BeginDisabled();
            if (ImGui::ColorEdit4(std::format("{}##{}", this->text, this->uuid).c_str(), (float*)&this->color, this->colorFormat | this->alpha) && this->callback != NULL) {
                this->callback(*this);
            }
            ImGui::EndDisabled();
            return;
        }
        if (ImGui::ColorEdit4(std::format("{}##{}", this->text, this->uuid).c_str(), (float*)&this->color, this->colorFormat | this->alpha) && this->callback != NULL) {
            this->callback(*this);
        }
    }
    ColorFormat getColorFormat() {
        return this->colorFormat;
    }
    ColorAlpha getAlpha() {
        return this->alpha;
    }
    void setColor(ImVec4 color, bool normalize=true) {
	// determines if the color needs to be normalized (ImGUI expects the colors to be between 0.0f - 1.0f).
	if (normalize) {
	    color.x = color.x/255.0f;
	    color.y = color.y/255.0f;
	    color.z = color.z/255.0f;
	    color.w = color.w/255.0f;
	}
	this->color = color;
    }
    ImVec4 getColor() {
        return this->color;
    }
private:
    std::string text;
    ColorFormat colorFormat;
    ColorAlpha alpha;
    ImVec4 color;
    std::function<T(ColorPicker&)> callback;
};
