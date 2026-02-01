#include "ContainerMultipleGUIElements.hpp"

ContainerMultipleGUIElements::ContainerMultipleGUIElements(std::string name, std::string text) : visible(GUIElementVisibility::Visible), name(name), uuid(UUIDGenerator::generateUUID()), text(text) {}

ContainerMultipleGUIElements::ContainerMultipleGUIElements() : visible(GUIElementVisibility::Visible), name(""), uuid(UUIDGenerator::generateUUID()), text("") {}

void ContainerMultipleGUIElements::terminate() {
    for (size_t i = 0; i < this->GUIElements.size(); i++) {
        this->GUIElements.at(i)->terminate();
    }
    this->GUIElements.clear();
}

void ContainerMultipleGUIElements::render() {}

void ContainerMultipleGUIElements::addGUIElement(std::shared_ptr<GUIElement> element) {
    this->GUIElements.emplace_back(element);
}

int ContainerMultipleGUIElements::removeGUIElementByUUID(std::string uuid) {
    for (size_t i = 0; i < this->GUIElements.size(); i++) {
        if (this->GUIElements.at(i)->getUUID() == uuid) {
            this->GUIElements.erase(this->GUIElements.begin() + i);
            return 0;
        }
    }
    return 1;
}

std::string ContainerMultipleGUIElements::getName() {
    return this->name;
}

std::string ContainerMultipleGUIElements::getUUID() {
    return this->uuid;
}
