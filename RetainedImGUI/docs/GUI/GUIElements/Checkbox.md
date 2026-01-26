# template<typename T> class Checkbox : public GUIElement
handles Checkbox GUI Elements.<br>

## public Checkbox(std::string name, std::string text, std::function<T(Checkbox&)> callback=NULL)
constructor for the Checkbox class.<br>

### params:
* std::string name - the name of the Checkbox.<br>
* std::string text - the text the Checkbox should display.<br>
* std::function<T(Checkbox&)> callback=NULL - the callback that the Checkbox should call when it's state changes.<br>

## public void render() override
renders the Checkbox.<br>

## public bool isChecked()
determines if the Checkbox is checked or not.<br>

### returns:
* a bool which can be used to determine if the Checkbox is checked or not.<br>

## private std::string text
contains the text the Checkbox should display.<br>

## private bool checked
determines if the Checkbox is checked or not.<br>

## private std::function<T(Checkbox&)> callback
contains the callback the Checkbox should call when it's state changes.<br>
