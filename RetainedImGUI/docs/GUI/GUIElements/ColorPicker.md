# enum ColorFormat

# enum ColorAlpha

# template <typename T> class ColorPicker : public GUIElement
handles Color Pickers.<br>

## public ColorPicker(std::string name, std::string text, ColorFormat colorFormat, ColorAlpha alpha=ColorAlpha::NO_ALPHA, std::function<T(ColorPicker&)> callback=NULL)
constructor for the ColorPicker class.<br>

### params:
* std::string name - the name of the Color Picker.<br>
* std::string text - the text the Color Picker should display.<br>
* ColorFormat colorFormat - the Color Format the Color Picker should display.<br>
* ColorAlpha alpha=ColorAlpha::NO_ALPHA - determines if the Color Picker should display Alpha or not.<br>
* std::function<T(ColorPicker&)> callback=NULL - the callback the Color Picker should call when one of it's values changes.<br>

## public void render() override
renders the Color Picker.<br>

## public ColorFormat getColorFormat()
get's the Color Format of the Color Picker.<br>

### returns:
* the Color Format the Color Picker uses.<br>

## public ColorAlpha getAlpha()
determines if the color has Alpha or not.<br>

### returns:
* ALPHA if the Color Picker uses Alpha.<br>
* NO_ALPHA if the Color Picker doens't use Alpha.<br>

## public ImVec4 getColor()
get's the color from the Color Picker.<br>

### returns:
* a ImVec4 containing the color and it's Alpha (this includes Color Pickers without Alpha. it will just be set to 0 instead of being modifiable).<br>

## private std::string text
contains the text the Color Picker should display.<br>

## private ColorFormat colorFormat
determines which Color Format the Color Picker should display.<br>

## private ColorAlpha alpha
determines if the Color Picker should display Alpha or not.<br>

## private ImVec4 colors
contains the colors of the Color Picker.<br>

## private std::function<T(ColorPicker&)> callback
contains the callback the Color Picker should call when one of it's values changes.<br>
