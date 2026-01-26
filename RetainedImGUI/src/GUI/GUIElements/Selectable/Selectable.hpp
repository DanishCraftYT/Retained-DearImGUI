#pragma once

#include "GUI/GUIElement.hpp"

template <typename T>
class Selectable : public GUIElement {
public:
    Selectable(std::string name, std::string text, std::function<T(Selectable&)> callback=NULL) : GUIElement(name), text(text), callback(callback) {}
    void render() override {
        if (this->visible == GUIElementVisibility::Invisible) {
            return;
        }
        else if (this->visible == GUIElementVisibility::Disabled) {
            ImGui::BeginDisabled();
            if (ImGui::Selectable(std::format("{}##{}", this->text, this->uuid).c_str())) {
                this->callback(*this);
            }
            ImGui::EndDisabled();
            return;
        }

        if (ImGui::Selectable(std::format("{}##{}", this->text, this->uuid).c_str())) {
            this->callback(*this);
        }
    }
private:
    std::string text;
    std::function<T(Selectable&)> callback;
};
