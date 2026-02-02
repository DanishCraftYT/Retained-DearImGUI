#pragma once

#include "GUI/GUITooltip.hpp"

template<typename T>
class Button : public GUIElement {
public:
    Button(std::string name, std::string text, ImVec2 size, std::function<T(Button&)> callback=NULL, std::string tooltipText="") : GUIElement(name), tooltip(std::format("{}Tooltip", name), tooltipText), text(text), size(size), callback(callback) {
        this->tooltip.visible = GUIElementVisibility::Invisible;
    }
    void render() override {
        if (this->visible == GUIElementVisibility::Invisible) {
            return;
        }
        else if (this->visible == GUIElementVisibility::Disabled) {
            ImGui::BeginDisabled();
            if (ImGui::Button(std::format("{}##{}", this->text, this->uuid).c_str(), size) && this->callback != NULL) {
                this->callback(*this);
            }
            ImGui::EndDisabled();
            return;
        }
        
        if (ImGui::Button(std::format("{}##{}", this->text, this->uuid).c_str(), size) && this->callback != NULL) {
            this->callback(*this);
        }
    }
    GUITooltip tooltip;
private:
    std::string text;
    ImVec2 size;
    std::function<T(Button&)> callback;
};
