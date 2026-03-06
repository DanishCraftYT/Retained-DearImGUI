# class Fonts
handles loading and using Fonts.<br>

## public Fonts()
constructor for the Fonts class.<br>

## public int addFont(std::filesystem::path fontPath, float fontSize)
add's a font (currently .ttf files are supported).<br>

### params:
* std::filesystem::path fontPath - the path to the font file.<br>
* float fontSize - the size of the font.<br>

### returns:
* 0 if the font path doesn't exist.<br>
* 1 if the font was added.<br>

## public int setFont(std::string fontName)
set's the font used by the GUI.<br>

### params:
* std::string fontName - the name of the font to use.<br>

### returns:
* 0 if the font name wasn't found (please make sure the font name is correct and that the font was added to the class).<br>
* 1 if the font has been set.<br>

## public static void popFont()
pop's the current font.<br>

## private std::map<std::string, ImFont*> fonts
contains fonts.<br>
