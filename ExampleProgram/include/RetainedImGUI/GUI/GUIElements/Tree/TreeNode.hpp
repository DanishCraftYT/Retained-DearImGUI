#pragma once

#include "GUI/Containers/ContainerGUIElement.hpp"
#include "GUI/GUIElement.hpp"

class TreeNode : public ContainerGUIElement<std::shared_ptr<GUIElement>> {
public:
    TreeNode(std::string name, std::string text, ImGuiTreeNodeFlags nodeFlags = 0);
    void terminate() override;
    void render() override;
    ImGuiTreeNodeFlags getTreeNodeFlags();
    void setTreeNodeFlags(ImGuiTreeNodeFlags treeNodeFlags);
    int getIndexFromItem(GUIElement& guiElement);
    template <typename T>
    std::vector<std::shared_ptr<T>> getGUIElementsByName(std::string name) {
        std::vector<std::shared_ptr<T>> elements;
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
    std::string text;
    ImGuiTreeNodeFlags nodeFlags;
};
