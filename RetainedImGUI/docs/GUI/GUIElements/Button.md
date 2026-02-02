# template<typename T> class Button : public GUIElement
handles Button GUI Elements.<br>

## public Button(std::string name, std::string text, ImVec2 size, std::function<T(Button&)> callback=NULL, std::string tooltipText="")
constructor for the Button class.<br>

### params:
* std::string name - the name of the Button.<br>
* std::string text - the text the Button should display.<br>
* ImVec2 size - the size of the Button.<br>
* std::function<T(Button&)> callback=NULL - the callback the Button should call when pressed.<br>
* std::string tooltipText="" - the text the tooltip for the Button should display.<br>

## public void render() override
renders the Button.<br>

## public GUITooltip tooltip
contains the tooltip the Button should use. important: the tooltip is invisible by default so to use it you will need to make it visible.<br>

## private std::string text
contains the text the Button should display.<br>

## private ImVec2 size
contains the size of the Button.<br>

## private std::function<T(Button&)> callback
contains the callback that the Button should call when pressed.<br>
