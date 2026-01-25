#include "GUIWindow.hpp"

GUIWindow::GUIWindow(std::string name, std::string text) : visible(GUIElementVisibility::Visible), name(name), uuid(UUIDGenerator::generateUUID()), text(text) {}

GUIWindow::GUIWindow() : visible(GUIElementVisibility::Visible), name(""), uuid(UUIDGenerator::generateUUID()), text("") {}

void GUIWindow::terminate() {
    this->GUIElements.clear();
}

void GUIWindow::render() {
    if (this->visible == GUIElementVisibility::Invisible) {
        return;
    }
    else if (this->visible == GUIElementVisibility::Disabled) {
        ImGui::BeginDisabled();
        ImGui::Begin(std::format("{}##{}", this->text, this->uuid).c_str());
        for (size_t i = 0; i < this->GUIElements.size(); i++) {
            this->GUIElements.at(i)->render();
        }
        ImGui::End();
        ImGui::EndDisabled();
        return;
    }

    ImGui::Begin(std::format("{}##{}", this->text, this->uuid).c_str());
    for (size_t i = 0; i < this->GUIElements.size(); i++) {
        this->GUIElements.at(i)->render();
    }
    ImGui::End();
}

void GUIWindow::addGUIElement(std::shared_ptr<GUIElement> element) {
    this->GUIElements.emplace_back(element);
}

int GUIWindow::removeGUIElementByUUID(std::string uuid) {
    for (size_t i = 0; i < this->GUIElements.size(); i++) {
        if (this->GUIElements.at(i)->getUUID() == uuid) {
            this->GUIElements.erase(this->GUIElements.begin() + i);
            return 0;
        }
    }
    return 1;
}

std::string GUIWindow::getName() {
    return this->name;
}

std::string GUIWindow::getUUID() {
    return this->uuid;
}
