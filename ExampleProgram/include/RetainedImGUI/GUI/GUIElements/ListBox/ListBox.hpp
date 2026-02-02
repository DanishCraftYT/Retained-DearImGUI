#pragma once

#include "GUI/Containers/ContainerBoxGUIElement.hpp"
#include "GUI/GUIElements/Selectable/Selectable.hpp"

class ListBox : public ContainerBoxGUIElement<Selectable<void>> {
public:
    ListBox(std::string name, std::string text, ImVec2 size);
    void terminate() override;
    void render() override;
    using ContainerBoxGUIElement::addItem; // prevents overloaded-virtual warning.
    void addItem(std::string name, std::string text);
    int getIndexFromItem(Selectable<void>& selectable);
private:
    std::string text;
    ImVec2 size;
};
