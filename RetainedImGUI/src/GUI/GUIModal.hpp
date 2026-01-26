#pragma once

#include "Containers/ContainerMultipleGUIElements.hpp"

class GUIModal : public ContainerMultipleGUIElements {
public:
    GUIModal(std::string name, std::string text);
    GUIModal();
    void terminate() override;
    void render() override;
    int open();
    void close();
private:
    bool shouldOpenModal;
};
