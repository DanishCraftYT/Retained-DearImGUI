#include "ComboBox.hpp"

ComboBox::ComboBox(std::string name, std::string text, std::string previewText) : ContainerBoxGUIElement(name), text(text), previewText(previewText) {}

void ComboBox::render() {
    if (this->visible == GUIElementVisibility::Invisible) {
        return;
    }
    else if (this->visible == GUIElementVisibility::Disabled) {
        ImGui::BeginDisabled();
        if (ImGui::BeginCombo(std::format("{}##{}", this->text, this->uuid).c_str(), this->previewText.c_str())) {
            for (size_t i = 0; i < this->items.size(); i++) {
                if (ImGui::Selectable(this->items.at(i).c_str())) {
                    this->currentSelected = i;
                    this->previewText = this->getSelectedItem();
                }
            }
            ImGui::EndCombo();
        }
        ImGui::EndDisabled();
        return;
    }

    if (ImGui::BeginCombo(std::format("{}##{}", this->text, this->uuid).c_str(), this->previewText.c_str())) {
        for (size_t i = 0; i < this->items.size(); i++) {
            if (ImGui::Selectable(this->items.at(i).c_str())) {
                this->currentSelected = i;
                this->previewText = this->getSelectedItem();
            }
        }
        ImGui::EndCombo();
    }
}
