#pragma once

#include "GUI/GUITooltip.hpp"

template <typename T>
class InputField : public GUIElement {
public:
    InputField(std::string name, std::string text, std::function<T(InputField&)> callback=NULL, std::string tooltipText="") : GUIElement(name), tooltip(std::format("{}Tooltip", name), tooltipText), text(text), callback(callback) {
        this->tooltip.visible = GUIElementVisibility::Invisible;
    }
    void render() override {
        if (this->visible == GUIElementVisibility::Invisible) {
            return;
        }
        else if (this->visible == GUIElementVisibility::Disabled) {
            ImGui::BeginDisabled();
            if (ImGui::InputText(std::format("{}##{}", this->text, this->uuid).c_str(), &this->buffer) && this->callback != NULL) {
                this->callback(*this);
            }
            ImGui::EndDisabled();
            return;
        }
        
        if (ImGui::InputText(std::format("{}##{}", this->text, this->uuid).c_str(), &this->buffer) && this->callback != NULL) {
            this->callback(*this);
        }
    }
    std::string getInputFieldText() {
        return this->buffer;
    }
    GUITooltip tooltip;
private:
    std::string text;
    std::string buffer;
    std::function<T(InputField&)> callback;
};
