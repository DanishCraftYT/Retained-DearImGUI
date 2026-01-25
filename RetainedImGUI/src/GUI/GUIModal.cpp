#include "GUIModal.hpp"

GUIModal::GUIModal(std::string name, std::string text) : visible(GUIElementVisibility::Visible), name(name), uuid(UUIDGenerator::generateUUID()), text(text), shouldOpenModal(false) {}

GUIModal::GUIModal() : visible(GUIElementVisibility::Visible), name(""), uuid(UUIDGenerator::generateUUID()), text(""), shouldOpenModal(false) {}

void GUIModal::terminate() {
    ImGui::CloseCurrentPopup();
    this->GUIElements.clear();
}

void GUIModal::render() {
    if (this->shouldOpenModal) {
        this->shouldOpenModal = false;
        ImGui::OpenPopup(std::format("{}##{}", this->text, this->uuid).c_str());
    }

    if (this->visible == GUIElementVisibility::Invisible) {
        return;
    }
    else if (this->visible == GUIElementVisibility::Disabled) {
        // center modal popup.
        ImVec2 center = ImGui::GetMainViewport()->GetCenter();
        ImGui::SetNextWindowPos(center, ImGuiCond_Appearing, ImVec2(0.5f, 0.5f));

        ImGui::BeginDisabled();
        if (ImGui::BeginPopupModal(std::format("{}##{}", this->text, this->uuid).c_str())) {
            for (size_t i = 0; i < this->GUIElements.size(); i++) {
                this->GUIElements.at(i)->render();
            }
            ImGui::EndPopup();
        }
        ImGui::EndDisabled();
        return;
    }

    // center modal popup.
    ImVec2 center = ImGui::GetMainViewport()->GetCenter();
    ImGui::SetNextWindowPos(center, ImGuiCond_Appearing, ImVec2(0.5f, 0.5f));

    if (ImGui::BeginPopupModal(std::format("{}##{}", this->text, this->uuid).c_str())) {
        for (size_t i = 0; i < this->GUIElements.size(); i++) {
            this->GUIElements.at(i)->render();
        }
        ImGui::EndPopup();
    }
}

int GUIModal::open() {
    if (this->shouldOpenModal) {
        return 0;
    }
    this->shouldOpenModal = true;
    return 1;
}

void GUIModal::close() {
    ImGui::CloseCurrentPopup();
}

void GUIModal::addGUIElement(std::shared_ptr<GUIElement> element) {
    this->GUIElements.emplace_back(element);
}

int GUIModal::removeGUIElementByUUID(std::string uuid) {
    for (size_t i = 0; i < this->GUIElements.size(); i++) {
        if (this->GUIElements.at(i)->getUUID() == uuid) {
            this->GUIElements.erase(this->GUIElements.begin() + i);
            return 0;
        }
    }
    return 1;
}

std::string GUIModal::getName() {
    return this->name;
}

std::string GUIModal::getUUID() {
    return this->uuid;
}
