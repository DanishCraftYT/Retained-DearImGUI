#pragma once

#include "GUI/GUIElement.hpp"

template <typename T>
class ContainerGUIElement : public GUIElement {
public:
    ContainerGUIElement(std::string name) : GUIElement(name) {}
    virtual void terminate() override {
        this->GUIElements.clear();
    }
    virtual void addGUIElement(T item) {
        this->GUIElements.emplace_back(item);
    }
    virtual int removeGUIElement(size_t index) {
        if (index >= this->GUIElements.size()) {
            return 0;
        }
        this->GUIElements.erase(this->GUIElements.begin() + index);
        return 1;
    }
    virtual void removeAllGUIElements() {
        this->GUIElements.clear();
    }
protected:
    std::vector<T> GUIElements;
};
