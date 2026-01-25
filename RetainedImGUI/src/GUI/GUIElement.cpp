#include "GUIElement.hpp"

GUIElement::GUIElement(std::string name) : visible(GUIElementVisibility::Visible), name(name), uuid(UUIDGenerator::generateUUID()) {}

GUIElement::GUIElement() : visible(GUIElementVisibility::Visible), name(""), uuid(UUIDGenerator::generateUUID()) {}

void GUIElement::render() {}

std::string GUIElement::getName() {
    return this->name;
}

std::string GUIElement::getUUID() {
    return this->uuid;
}
