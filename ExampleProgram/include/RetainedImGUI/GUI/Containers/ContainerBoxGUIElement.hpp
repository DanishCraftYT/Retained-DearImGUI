#pragma once

#include "GUI/GUIElement.hpp"

template <typename T>
class ContainerBoxGUIElement : public GUIElement {
public:
    ContainerBoxGUIElement(std::string name) : GUIElement(name), currentSelected(-1) {}
    virtual void terminate() override {
        this->items.clear();
    }
    virtual void addItem(T item) {
        this->items.emplace_back(item);
    }
    virtual int removeItem(size_t index) {
        if (index >= this->items.size()) {
            return 0;
        }
        this->items.erase(this->items.begin() + index);
        return 1;
    }
    virtual void removeAllItems() {
        this->items.clear();
    }
    virtual T getSelectedItem() {
        /*
        if (this->currentSelected == -1) {
            return ""; // FIX THIS?
        }*/
        return this->items.at(this->currentSelected);
    }
    virtual int getcurrentSelected() {
        return this->currentSelected;
    }
protected:
    std::vector<T> items;
    int currentSelected;
};
