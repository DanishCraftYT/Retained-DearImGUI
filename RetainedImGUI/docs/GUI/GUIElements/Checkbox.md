# template<typename T> class Checkbox : public GUIElement
handles Checkbox GUI Elements.<br>

## public Checkbox(std::string name, std::string text, std::function<T(Checkbox&)> callback=NULL, std::string tooltipText="")
constructor for the Checkbox class.<br>

### params:
* std::string name - the name of the Checkbox.<br>
* std::string text - the text the Checkbox should display.<br>
* std::function<T(Checkbox&)> callback=NULL - the callback that the Checkbox should call when it's state changes.<br>
* std::string tooltipText="" - the text the tooltip for the Checkbox should display.<br>

## public void render() override
renders the Checkbox.<br>

## public bool isChecked()
determines if the Checkbox is checked or not.<br>

### returns:
* a bool which can be used to determine if the Checkbox is checked or not.<br>

## public GUITooltip tooltip
contains the tooltip the Checkbox should use. important: the tooltip is invisible by default so to use it you will need to make it visible.<br>

## private std::string text
contains the text the Checkbox should display.<br>

## private bool checked
determines if the Checkbox is checked or not.<br>

## private std::function<T(Checkbox&)> callback
contains the callback the Checkbox should call when it's state changes.<br>
