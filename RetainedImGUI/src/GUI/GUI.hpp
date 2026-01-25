#pragma once

#include "GUIWindow.hpp"

class GUI {
public:
    GUI(std::string name);
    GUI();
    void renderAllWindows();
    GUIWindow& createWindow(std::string name, std::string text);
    GUIWindow& getWindowByUUID(std::string uuid);
    int removeWindowByUUID(std::string uuid);
    std::string getName();
    std::string getUUID();
    GUIElementVisibility visible;
private:
    std::string name;
    std::string uuid;
    std::vector<GUIWindow> GUIWindows;
};
