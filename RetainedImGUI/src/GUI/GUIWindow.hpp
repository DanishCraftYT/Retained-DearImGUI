#pragma once

#include <vector>
#include <memory>

#include "GUIElement.hpp"

class GUIWindow {
public:
    GUIWindow(std::string name, std::string text);
    GUIWindow();
    void terminate();
    void render();
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
    std::string getName();
    std::string getUUID();
    GUIElementVisibility visible;
private:
    std::string name;
    std::string uuid;
    std::string text;
    std::vector<std::shared_ptr<GUIElement>> GUIElements;
};
