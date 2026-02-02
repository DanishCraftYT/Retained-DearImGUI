#pragma once

#include "GUI/Containers/ContainerBoxGUIElement.hpp"
#include "GUI/GUIElements/Selectable/Selectable.hpp"

class ComboBox : public ContainerBoxGUIElement<Selectable<void>> {
public:
    ComboBox(std::string name, std::string text, std::string previewText="");
    void terminate() override;
    void render() override;
    using ContainerBoxGUIElement::addItem; // prevents overloaded-virtual warning.
    void addItem(std::string name, std::string text);
    int getIndexFromItem(Selectable<void>& selectable);
private:
    std::string text;
    std::string previewText;
};
