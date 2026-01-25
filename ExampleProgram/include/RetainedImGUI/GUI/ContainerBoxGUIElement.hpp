#pragma once

#include "ContainerGUIElement.hpp"

template <typename T>
class ContainerBoxGUIElement : public ContainerGUIElement<T> {
public:
    ContainerBoxGUIElement(std::string name) : ContainerGUIElement<T>(name), currentSelected(-1) {}
    T getSelectedItem() {
        if (this->currentSelected == -1) {
            return "";
        }
        return this->items.at(this->currentSelected);
    }
    int getcurrentSelected() {
        return this->currentSelected;
    }
protected:
    int currentSelected;
};
