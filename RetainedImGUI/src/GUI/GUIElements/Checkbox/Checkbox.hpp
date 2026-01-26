#pragma once

#include "GUI/GUIElement.hpp"

template<typename T>
class Checkbox : public GUIElement {
public:
    Checkbox(std::string name, std::string text, std::function<T(Checkbox&)> callback=NULL) : GUIElement(name), text(text), checked(false), callback(callback) {}
    void render() override {
        if (this->visible == GUIElementVisibility::Invisible) {
            return;
        }
        else if (this->visible == GUIElementVisibility::Disabled) {
            ImGui::BeginDisabled();
            if (ImGui::Checkbox(std::format("{}##{}", this->text, this->uuid).c_str(), &this->checked)) {
                this->callback(*this);
            }
            ImGui::EndDisabled();
            return;
        }

        if (ImGui::Checkbox(std::format("{}##{}", this->text, this->uuid).c_str(), &this->checked)) {
            this->callback(*this);
        }
    }
    bool isChecked() {
        return this->checked;
    }
private:
    std::string text;
    bool checked;
    std::function<T(Checkbox&)> callback;
};
