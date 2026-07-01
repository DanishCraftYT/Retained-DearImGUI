#include "GUIWindow.hpp"
#include "GUI/GUIElement.hpp"

GUIWindow::GUIWindow(std::string name, std::string text, ImVec2 position, ImVec2 size, bool resizable, bool movable) : ContainerMultipleGUIElements(name, text), toolbar(std::format("{}Toolbar", name)), position(position), size(size), resizable(ImGuiWindowFlags_None), movable(ImGuiWindowFlags_None) {
    // determines if the GUI Window is resizable.
    if (!resizable) {
        this->resizable = ImGuiWindowFlags_NoResize;
    }

    // determines if the GUI Window is movable.
    if (!movable) {
        this->movable = ImGuiWindowFlags_NoMove;
    }

    this->toolbar.visible = GUIElementVisibility::Invisible;
    this->tab.visible = GUIElementVisibility::Invisible;
}

GUIWindow::GUIWindow() : ContainerMultipleGUIElements("", ""), toolbar("Toolbar"), position(0, 0), size(0, 0), resizable(ImGuiWindowFlags_None), movable(ImGuiWindowFlags_None) {
    this->toolbar.visible = GUIElementVisibility::Invisible;
    this->tab.visible = GUIElementVisibility::Invisible;
}

void GUIWindow::terminate() {
    this->GUIElements.clear();
    this->toolbar.terminate();
    this->tab.terminate();
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
            ImGui::Begin(std::format("{}##{}", this->text, this->uuid).c_str(), (bool *)__null, ImGuiWindowFlags_MenuBar | this->movable | this->resizable);
            this->toolbar.render();
        }
        else {
            ImGui::Begin(std::format("{}##{}", this->text, this->uuid).c_str(), (bool *)__null, this->movable | this->resizable);
        }
	if (this->tab.visible == GUIElementVisibility::Visible) {
	    tab.render();
	}
	else {
	    for (size_t i = 0; i < this->GUIElements.size(); i++) {
		this->GUIElements.at(i)->render();
	    }
	}
	ImGui::End();
        ImGui::EndDisabled();
	return;
    }

    ImGui::SetNextWindowPos(this->position, ImGuiCond_FirstUseEver);
    ImGui::SetNextWindowSize(this->size, ImGuiCond_FirstUseEver);

    if (this->toolbar.visible != GUIElementVisibility::Invisible) {
        ImGui::Begin(std::format("{}##{}", this->text, this->uuid).c_str(), (bool *)__null, ImGuiWindowFlags_MenuBar | this->movable | this->resizable);
        this->toolbar.render();
    }
    else {
        ImGui::Begin(std::format("{}##{}", this->text, this->uuid).c_str(), (bool *)__null, this->movable | this->resizable);
    }
    if (this->tab.visible == GUIElementVisibility::Visible) {
	tab.render();
    }
    else {
	for (size_t i = 0; i < this->GUIElements.size(); i++) {
	   this->GUIElements.at(i)->render();
	}
    }
    ImGui::End();
}
