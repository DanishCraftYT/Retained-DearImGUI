#pragma once

#include "GUIWindow.hpp"
#include "Toolbar/GUIToolbar.hpp"

class GUI {
public:
    GUI(std::string name);
    GUI();
    void terminate();
    void renderAllWindows();
    GUIWindow& createWindow(std::string name, std::string text, ImVec2 position, ImVec2 size);
    GUIWindow& getWindowByUUID(std::string uuid);
    int removeWindowByUUID(std::string uuid);
    std::string getName();
    std::string getUUID();
    GUIElementVisibility visible;
    GUIToolbar toolbar;
private:
    std::string name;
    std::string uuid;
    std::vector<GUIWindow> GUIWindows;
};
