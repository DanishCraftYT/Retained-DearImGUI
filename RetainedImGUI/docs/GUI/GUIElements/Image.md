# class Image : public GUIElement

## public Image(std::string name, ImVec2 size)
constructor for the Image class.<br>

### params:
* std::string name - the name of the Image GUI Element.<br>
* ImVec2 size - the size of the Image.<br>

## public Image()
empty constructor for the Image class.<br>

## public void render() override
renders the Image.<br>

## public int setTexture(std::filesystem::path imagePath, bool verticallyFlipTexture=true)
sets the texture the Image should render.<br>

### params:
* std::filesystem::path imagePath - the path to the image file.<br>
* bool verticallyFlipTexture=true - determines if the image file will be flipped vertically when rendered (if false. it will be upside down).<br>

### returns:
* 1 if it successfully sets the texture.<br>
* 0 if the path is invalid or it's a directory.<br>
* 0 if the texture file is using a unsupported file format (supported formats: .png, .jpg).<br>
* 0 if it failed to load the texture.<br>

## public bool hasTexture()
determines if the Image has a texture or not.<br>

### returns:
* true if the Image has a texture.<br>
* false if the Image doesn't have a texture.<br>

## private ImVec2 size
contains the size of the Image.<br>

## private unsigned int imageTexture
contains the texture that should be rendered by the Image.<br>

## private bool hasImageTexture
determines if the Image has a texture or not.<br>
