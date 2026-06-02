// defining stb image in "Image.hpp" fails to compile due to multiple definitions of the same function. so we will define it here instead.
#define STB_IMAGE_IMPLEMENTATION

#include "Image.hpp"

Image::Image(std::string name, ImVec2 size) : GUIElement(name), size(size) {}

Image::Image() : GUIElement("") {}

void Image::render() {
    if (this->visible == GUIElementVisibility::Invisible) {
        return;
    }
    else if (this->visible == GUIElementVisibility::Disabled) {
        ImGui::BeginDisabled();
	if (this->hasImageTexture) {
	    ImGui::Image((ImTextureID)(intptr_t)this->imageTexture, this->size);
	}
        ImGui::EndDisabled();
        return;
    }

    if (this->hasImageTexture) {
	ImGui::Image((ImTextureID)(intptr_t)this->imageTexture, this->size);
    }
}

int Image::setTexture(std::filesystem::path imagePath, bool verticallyFlipTexture) {
    // checks if the texture path is valid.
    if (!std::filesystem::exists(imagePath)) {
	std::cout << std::format("Texture file doesn't exist: \"{}\"", imagePath.string()) << std::endl;
        return 0;
    }
    else if (std::filesystem::is_directory(imagePath)) {
	std::cout << std::format("Texture file is a directory: \"{}\"", imagePath.string()) << std::endl;
        return 0;
    }

    // OpenGL Texture Creation.
    glGenTextures(1, &this->imageTexture);
    glBindTexture(GL_TEXTURE_2D, this->imageTexture);

    // texture parameters.
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    // loading the texture using stb.
    int width, height, nrChannels;
    stbi_set_flip_vertically_on_load(verticallyFlipTexture); // flips texture so it isn't upside down.
    unsigned char *data = stbi_load(imagePath.string().c_str(), &width, &height, &nrChannels, 0);
    if (data) {
        if (imagePath.extension() == ".png") {
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        }
        else if (imagePath.extension() == ".jpg") {
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        }
        else {
	    std::cout << std::format("Texture file uses unsupported format: {}, supported formats: \".png\", \".jpg\", Texture file path: {}", imagePath.extension().string(), imagePath.string()) << std::endl;
            stbi_image_free(data);
            return 0;
        }
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else {
	std::cout << std::format("failed to load Texture from file: {}", imagePath.string()) << std::endl;
        stbi_image_free(data);
        return 0;
    }

    // free's texture data used by stb.
    stbi_image_free(data);
    this->hasImageTexture = true;
    return 1;
}

bool Image::hasTexture() {
    return this->hasImageTexture;
}
