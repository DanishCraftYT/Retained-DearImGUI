#include "GUIWindow.hpp"

GUIWindow::GUIWindow(std::string name, std::string text, ImVec2 position, ImVec2 size) : ContainerMultipleGUIElements(name, text), toolbar(std::format("{}Toolbar", name)), position(position), size(size) {
    toolbar.visible = GUIElementVisibility::Invisible;
}

GUIWindow::GUIWindow() : ContainerMultipleGUIElements("", ""), toolbar("Toolbar"), position(0, 0), size(0, 0) {
    toolbar.visible = GUIElementVisibility::Invisible;
}

void GUIWindow::terminate() {
    this->GUIElements.clear();
    this->toolbar.terminate();
}

void GUIWindow::render() {
    if (this->visible == GUIElementVisibility::Invisible) {
        return;
    }
    else if (this->visible == GUIElementVisibility::Disabled) {
        ImGui::BeginDisabled();
        ImGui::SetNextWindowPos(this->position, ImGuiCond_FirstUseEver);
        ImGui::SetNextWindowSize(this->size, ImGuiCond_FirstUseEver);
        if (this->toolbar.visible != GUIElementVisibility::Invisible) {
            ImGui::Begin(std::format("{}##{}", this->text, this->uuid).c_str(), (bool *)__null, ImGuiWindowFlags_MenuBar);
            this->toolbar.render();
        }
        else {
            ImGui::Begin(std::format("{}##{}", this->text, this->uuid).c_str());
        }
        for (size_t i = 0; i < this->GUIElements.size(); i++) {
            this->GUIElements.at(i)->render();
        }
        ImGui::End();
        ImGui::EndDisabled();
        return;
    }

    ImGui::SetNextWindowPos(this->position, ImGuiCond_FirstUseEver);
    ImGui::SetNextWindowSize(this->size, ImGuiCond_FirstUseEver);

    if (this->toolbar.visible != GUIElementVisibility::Invisible) {
        ImGui::Begin(std::format("{}##{}", this->text, this->uuid).c_str(), (bool *)__null, ImGuiWindowFlags_MenuBar);
        this->toolbar.render();
    }
    else {
        ImGui::Begin(std::format("{}##{}", this->text, this->uuid).c_str());
    }
    for (size_t i = 0; i < this->GUIElements.size(); i++) {
        this->GUIElements.at(i)->render();
    }
    ImGui::End();
}
