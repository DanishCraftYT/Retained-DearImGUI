#include "TabItem.hpp"
#include "GUI/Containers/ContainerMultipleGUIElements.hpp"

TabItem::TabItem(std::string name, std::string text) : ContainerMultipleGUIElements(name, text) {}

TabItem::TabItem() : ContainerMultipleGUIElements("", "") {}

void TabItem::render() {
    if (this->visible == GUIElementVisibility::Invisible) {
        return;
    }
    else if (this->visible == GUIElementVisibility::Disabled) {
        ImGui::BeginDisabled();
        if (ImGui::BeginTabItem(std::format("{}##{}", this->text, this->uuid).c_str())) {
            for (size_t i = 0; i < this->GUIElements.size(); i++) {
                this->GUIElements.at(i)->render();
            }
            ImGui::EndTabItem();
        }
        ImGui::EndDisabled();
        return;
    }

    if (ImGui::BeginTabItem(std::format("{}##{}", this->text, this->uuid).c_str())) {
        for (size_t i = 0; i < this->GUIElements.size(); i++) {
            this->GUIElements.at(i)->render();
        }
        ImGui::EndTabItem();
    }
}
