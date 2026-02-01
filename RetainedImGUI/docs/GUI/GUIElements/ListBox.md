# class ListBox : public ContainerBoxGUIElement<Selectable<void>>
handles ListBox GUI Elements.<br>

## public ListBox(std::string name, std::string text, ImVec2 size)
constructor for the ListBox class.<br>

### params:
* std::string name - the name of the ListBox.<br>
* std::string text - the text the ListBox should display.<br>
* ImVec2 size - the size of the ListBox.<br>

## public void terminate() override
terminates the ListBox.<br>

## public void render() override
renders the ListBox.<br>

## public using ContainerBoxGUIElement::addItem
fixes warning "overloaded-virtual". important: if you need your own callback lambda. you can use this function to add a "Selectable<void>" element with your own callback.<br>

## public void addItem(std::string name, std::string text)
adds a item to the ListBox.<br>

### params:
* std::string name - the name of the Selectable.<br>
* std::string text - the text the Selectable should display.<br>

## public int getIndexFromItem(Selectable<void>& selectable)
get's the location of a item inside the "items" vector.<br>

### params:
* Selectable<void>& selectable - a reference to a Selectable from the "items" vector.<br>

### returns:
* a positive integer containing the location of the Selectable inside the "items" vector.<br>
* -1 if the Selectable is not present inside the "items" vector.<br>

## private std::string text
contains the text the ListBox should display.<br>

## private ImVec2 size
contains the size of the ListBox.<br>
