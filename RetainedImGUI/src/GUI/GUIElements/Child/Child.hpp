#pragma once

#include "GUI/GUIElement.hpp"

class Child : public GUIElement {
public:
    Child(std::string name, ImVec2 size=ImVec2(0, 0), bool border=false);
    void render() override;
    void addGUIElement(std::shared_ptr<GUIElement> element);
    template <typename T>
    std::vector<std::shared_ptr<T>> getGUIElementsByName(std::string name) {
        std::vector<T> elements;
        for (size_t i = 0; i < this->GUIElements.size(); i++) {
            if (this->GUIElements.at(i)->getName() == name) {
                elements.emplace_back(std::dynamic_pointer_cast<T>(this->GUIElements.at(i)));
            }
        }
        return elements;
    }
    template <typename T>
    std::shared_ptr<T> getGUIElementByUUID(std::string uuid) {
        for (size_t i = 0; i < this->GUIElements.size(); i++) {
            if (this->GUIElements.at(i)->getUUID() == uuid) {
                return std::dynamic_pointer_cast<T>(this->GUIElements.at(i));
            }
        }
        return nullptr;
    }
    int removeGUIElementByUUID(std::string uuid);
private:
    ImVec2 size;
    bool border;
    std::vector<std::shared_ptr<GUIElement>> GUIElements;
};
