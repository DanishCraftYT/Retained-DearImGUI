#pragma once

#include <string>
#include <filesystem>
#include <map>

#include "ImGUI/imgui.h"
#include "ImGUI/imgui_impl_glfw.h"
#include "ImGUI/imgui_impl_opengl3.h"

class Fonts {
public:
    Fonts();
    int addFont(std::string fontName, std::filesystem::path fontPath, float fontSize);
    int setFont(std::string fontName);
    static void popFont();
private:
    std::map<std::string, ImFont*> fonts;
};
