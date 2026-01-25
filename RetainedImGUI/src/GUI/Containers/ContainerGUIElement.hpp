#pragma once

#include "GUI/GUIElement.hpp"

template <typename T>
class ContainerGUIElement : public GUIElement {
public:
    ContainerGUIElement(std::string name) : GUIElement(name) {}
    void addItem(T item) {
        this->items.emplace_back(item);
    }
    int removeItem(size_t index) {
        if (index >= this->items.size()) {
            return 0;
        }
        this->items.erase(this->items.begin() + index);
        return 1;
    }
    void removeAllItems() {
        this->items.clear();
    }
protected:
    std::vector<T> items;
};
