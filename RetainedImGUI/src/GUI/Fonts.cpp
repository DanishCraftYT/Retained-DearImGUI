#include "Fonts.hpp"

Fonts::Fonts() {}

int Fonts::addFont(std::string fontName, std::filesystem::path fontPath, float fontSize) {
    if (!std::filesystem::exists(fontPath)) {
        return 0;
    }

    ImGuiIO& io = ImGui::GetIO();
    this->fonts.insert({ fontName, io.Fonts->AddFontFromFileTTF(fontPath.string().c_str(), fontSize) });
    return 1;
}

int Fonts::setFont(std::string fontName) {
    for (auto const& [key, value] : this->fonts) {
        if (key == fontName) {
            ImGui::PushFont(value);
            return 1;
        }
    }
    
    return 0;
}

void Fonts::popFont() {
    ImGui::PopFont();
}
