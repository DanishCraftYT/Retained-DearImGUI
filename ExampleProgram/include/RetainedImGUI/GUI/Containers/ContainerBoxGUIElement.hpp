#pragma once

#include "ContainerGUIElement.hpp"

template <typename T>
class ContainerBoxGUIElement : public ContainerGUIElement<T> {
public:
    ContainerBoxGUIElement(std::string name) : ContainerGUIElement<T>(name), currentSelected(-1) {}
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
    int currentSelected;
};
