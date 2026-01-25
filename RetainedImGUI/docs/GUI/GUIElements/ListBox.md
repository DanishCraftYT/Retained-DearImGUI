# class ListBox : public ContainerBoxGUIElement<std::string>
handles ListBox GUI Elements.<br>

## public ListBox(std::string name, std::string text, ImVec2 size)
constructor for the ListBox class.<br>

### params:
* std::string name - the name of the ListBox.<br>
* std::string text - the text the ListBox should display.<br>
* ImVec2 size - the size of the ListBox.<br>

## public void render() override
renders the ListBox.<br>

## private std::string text
contains the text the ListBox should display.<br>

## private ImVec2 size
contains the size of the ListBox.<br>
