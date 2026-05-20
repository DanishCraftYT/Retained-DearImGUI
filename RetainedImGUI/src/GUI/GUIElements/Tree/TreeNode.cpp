#include "TreeNode.hpp"
#include "GUI/GUIElement.hpp"
#include "GUI/GUIElements/Tree/Tree.hpp"

TreeNode::TreeNode(std::string name, std::string text, ImGuiTreeNodeFlags nodeFlags) : ContainerGUIElement(name), text(text) {}

void TreeNode::terminate() {
    for (size_t i = 0; i < this->GUIElements.size(); i++) {
        this->GUIElements.at(i)->terminate();
    }
    this->GUIElements.clear();
}

void TreeNode::render() {
    if (this->visible == GUIElementVisibility::Invisible) {
        return;
    }
    else if (this->visible == GUIElementVisibility::Disabled) {
        ImGui::BeginDisabled();
        if (ImGui::TreeNodeEx(this->text.c_str(), this->nodeFlags)) {
	    for (size_t i = 0; i < this->GUIElements.size(); i++) {
                this->GUIElements.at(i)->render();
            }
	    ImGui::TreePop();
	}
        ImGui::EndDisabled();
        return;
    }

    if (ImGui::TreeNodeEx(this->text.c_str(), this->nodeFlags)) {
	for (size_t i = 0; i < this->GUIElements.size(); i++) {
            this->GUIElements.at(i)->render();
        }
	ImGui::TreePop();
    }
}

ImGuiTreeNodeFlags TreeNode::getTreeNodeFlags() {
    return this->nodeFlags;
}

void TreeNode::setTreeNodeFlags(ImGuiTreeNodeFlags treeNodeFlags) {
    this->nodeFlags = treeNodeFlags;
}

int TreeNode::removeGUIElementByUUID(std::string uuid) {
    for (size_t i = 0; i < this->GUIElements.size(); i++) {
        if (this->GUIElements.at(i)->getUUID() == uuid) {
            this->GUIElements.erase(this->GUIElements.begin() + i);
            return 0;
        }
    }
    return 1;
}
