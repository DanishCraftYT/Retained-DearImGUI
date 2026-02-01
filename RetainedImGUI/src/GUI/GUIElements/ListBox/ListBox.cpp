#include "ListBox.hpp"

ListBox::ListBox(std::string name, std::string text, ImVec2 size) : ContainerBoxGUIElement(name), text(text), size(size) {}

void ListBox::terminate() {
    for (size_t i = 0; i < this->items.size(); i++) {
        this->items.at(i).terminate();
    }
    this->items.clear();
}

void ListBox::render() {
    if (this->visible == GUIElementVisibility::Invisible) {
        return;
    }
    else if (this->visible == GUIElementVisibility::Disabled) {
        ImGui::BeginDisabled();
        if (ImGui::BeginListBox(std::format("{}##{}", this->text, this->uuid).c_str())) {
            for (size_t i = 0; i < this->items.size(); i++) {
                this->items.at(i).render();
            }
            ImGui::EndListBox();
        }
        ImGui::EndDisabled();
        return;
    }

    if (ImGui::BeginListBox(std::format("{}##{}", this->text, this->uuid).c_str())) {
        for (size_t i = 0; i < this->items.size(); i++) {
            this->items.at(i).render();
        }
        ImGui::EndListBox();
    }
}

void ListBox::addItem(std::string name, std::string text) {
    this->items.emplace_back(name, text, [this](Selectable<void>& selectable) { this->currentSelected = this->getIndexFromItem(selectable); });
}

int ListBox::getIndexFromItem(Selectable<void>& selectable) {
    for (size_t i = 0; i < this->items.size(); i++) {
        if (this->items.at(i).getUUID() == selectable.getUUID()) {
            return i;
        }
    }
    return -1;
}
