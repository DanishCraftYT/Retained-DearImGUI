#pragma once

#include "GUI/Containers/ContainerGUIElement.hpp"

class Table : public ContainerGUIElement<std::shared_ptr<GUIElement>> {
public:
    Table(std::string name, int columns);
    void render() override;
    template <typename T>
    std::vector<std::shared_ptr<T>> getGUIElementsByName(std::string name) {
        std::vector<std::shared_ptr<GUIElement>> elements;
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
    int columns;
};
