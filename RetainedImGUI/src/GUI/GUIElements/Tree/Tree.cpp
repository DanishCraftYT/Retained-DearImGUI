#include "Tree.hpp"
#include "GUI/GUIElements/Tree/TreeNode.hpp"
#include "ImGUI/imgui.h"
#include <memory>

Tree::Tree(std::string name, std::string text) : ContainerBoxGUIElement(name), text(text) {}

void Tree::terminate() {
    for (size_t i = 0; i < this->items.size(); i++) {
        this->items.at(i)->terminate();
    }
    this->items.clear();
}

void Tree::render() {
    if (this->visible == GUIElementVisibility::Invisible) {
        return;
    }
    else if (this->visible == GUIElementVisibility::Disabled) {
        ImGui::BeginDisabled();
        if (ImGui::TreeNode(this->text.c_str())) {
            for (size_t i = 0; i < this->items.size(); i++) {
                this->items.at(i)->render();
            }
            ImGui::TreePop();
        }
        ImGui::EndDisabled();
        return;
    }

    if (ImGui::TreeNode(this->text.c_str())) {
        for (size_t i = 0; i < this->items.size(); i++) {
            this->items.at(i)->render();
        }
        ImGui::TreePop();
    }
}

void Tree::addItem(std::string name, std::string text, ImGuiTreeNodeFlags nodeFlags) {
    this->items.emplace_back(std::make_shared<TreeNode>(name, text, nodeFlags));
}

std::shared_ptr<TreeNode> Tree::getItem(std::string name) {
    for (size_t i = 0; i < this->items.size(); i++) {
	if (items.at(i)->getName() == name) {
	    return items.at(i);
	}
    }
    return nullptr;
}

int Tree::getIndexFromItem(TreeNode& treeNode) {
    for (size_t i = 0; i < this->items.size(); i++) {
        if (this->items.at(i)->getUUID() == treeNode.getUUID()) {
            return i;
        }
    }
    return -1;
}
