#pragma once

#include <iostream>
#include <filesystem>

#include "glad/glad.h"
#include "stb/stb_image.h"

#include "GUI/GUIElement.hpp"
#include "ImGUI/imgui.h"

class Image : public GUIElement {
public:
    Image(std::string name, ImVec2 size);
    Image();
    void render() override;
    int setTexture(std::filesystem::path imagePath, bool verticallyFlipTexture=true);
    bool hasTexture();
private:
    ImVec2 size;
    unsigned int imageTexture;
    bool hasImageTexture;
};
