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
                this->items.at(i).render();
            }
            ImGui::EndCombo();
        }
        ImGui::EndDisabled();
        return;
    }

    if (ImGui::BeginCombo(std::format("{}##{}", this->text, this->uuid).c_str(), this->previewText.c_str())) {
        for (size_t i = 0; i < this->items.size(); i++) {
            this->items.at(i).render();
        }
        ImGui::EndCombo();
    }
}

void ComboBox::addItem(std::string name, std::string text) {
    this->items.emplace_back(name, text, [this, text](Selectable<void>& selectable) { this->currentSelected = this->getIndexFromItem(selectable); this->previewText = text; });
}

int ComboBox::getIndexFromItem(Selectable<void>& selectable) {
    for (size_t i = 0; i < this->items.size(); i++) {
        if (this->items.at(i).getUUID() == selectable.getUUID()) {
            return i;
        }
    }
    return -1;
}
