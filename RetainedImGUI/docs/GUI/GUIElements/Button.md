# class Button : public GUIElement
handles Button GUI Elements.<br>

## public Button(std::string name, std::string text, ImVec2 size)
constructor for the Button class.<br>

### params:
* std::string name - the name of the Button.<br>
* std::string text - the text the Button should display.<br>
* ImVec2 size - the size of the Button.<br>

## public void render() override
renders the Button.<br>

## private std::string text
contains the text the Button should display.<br>

## private ImVec2 size
contains the size of the Button.<br>
