#pragma once

#include "GUI/GUITooltip.hpp"

template<typename T>
class Checkbox : public GUIElement {
public:
    Checkbox(std::string name, std::string text, std::function<T(Checkbox&)> callback=NULL, std::string tooltipText="") : GUIElement(name), tooltip(std::format("{}Tooltip", name), tooltipText), text(text), checked(false), callback(callback) {
        this->tooltip.visible = GUIElementVisibility::Invisible;
    }
    void render() override {
        if (this->visible == GUIElementVisibility::Invisible) {
            return;
        }
        else if (this->visible == GUIElementVisibility::Disabled) {
            ImGui::BeginDisabled();
            if (ImGui::Checkbox(std::format("{}##{}", this->text, this->uuid).c_str(), &this->checked) && this->callback != NULL) {
                this->callback(*this);
            }
            ImGui::EndDisabled();
            return;
        }

        if (ImGui::Checkbox(std::format("{}##{}", this->text, this->uuid).c_str(), &this->checked) && this->callback != NULL) {
            this->callback(*this);
        }
    }
    bool isChecked() {
        return this->checked;
    }
    GUITooltip tooltip;
private:
    std::string text;
    bool checked;
    std::function<T(Checkbox&)> callback;
};
