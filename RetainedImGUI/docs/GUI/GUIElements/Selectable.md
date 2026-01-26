# template <typename T> class Selectable : public GUIElement
handles selectable GUI Elements.<br>

## public Selectable(std::string name, std::string text, std::function<T(Selectable&)> callback=NULL)
constructor for the Selectable class.<br>

### params:
* std::string name - the name of the Checkbox.<br>
* std::string text - the text the Checkbox should display.<br>
* std::function<T(Selectable&)> callback=NULL - the callback that should be called when a selectable GUI Element has been selected.<br>

## public void render() override
renders the selectable GUI Element.<br>

## private std::string text
contains the text the selectable GUI Element should display.<br>

## private std::function<T(Selectable&)> callback
contains the callback the selectable GUI Element should call when it's been selected.<br>
