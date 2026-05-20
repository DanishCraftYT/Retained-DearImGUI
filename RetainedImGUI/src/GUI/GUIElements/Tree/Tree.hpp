#pragma once

#include "GUI/Containers/ContainerBoxGUIElement.hpp"
#include "TreeNode.hpp"

class Tree : ContainerBoxGUIElement<std::shared_ptr<TreeNode>> {
public:
    Tree(std::string name, std::string text);
    void terminate() override;
    void render() override;
    using ContainerBoxGUIElement::addItem; // prevents overloaded-virtual warning.
    void addItem(std::string name, std::string text, ImGuiTreeNodeFlags nodeFlags = 0);
    std::shared_ptr<TreeNode> getItem(std::string name);
    int getIndexFromItem(TreeNode& treeNode);
private:
    std::string text;
};
