#include "ListBox.hpp"

ListBox::ListBox(std::string name, std::string text, ImVec2 size) : ContainerBoxGUIElement(name), text(text), size(size) {}

void ListBox::render() {
    if (this->visible == GUIElementVisibility::Invisible) {
        return;
    }
    else if (this->visible == GUIElementVisibility::Disabled) {
        ImGui::BeginDisabled();
        if (ImGui::BeginListBox(std::format("{}##{}", this->text, this->uuid).c_str())) {
            for (size_t i = 0; i < this->items.size(); i++) {
                if (ImGui::Selectable(this->items.at(i).c_str())) {
                    this->currentSelected = i;
                }
            }
            ImGui::EndListBox();
        }
        ImGui::EndDisabled();
        return;
    }

    if (ImGui::BeginListBox(std::format("{}##{}", this->text, this->uuid).c_str())) {
        for (size_t i = 0; i < this->items.size(); i++) {
            if (ImGui::Selectable(this->items.at(i).c_str())) {
                this->currentSelected = i;
            }
        }
        ImGui::EndListBox();
    }
}
