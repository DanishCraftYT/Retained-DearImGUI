# class ComboBox : public ContainerBoxGUIElement<Selectable<void>>
handles ComboBox GUI Elements.<br>

## public ComboBox(std::string name, std::string text, std::string previewText="")
constructor for the ComboBox class.<br>

### params:
* std::string name - the name of the ComboBox.<br>
* std::string text - the text the ComboBox should display.<br>
* std::string previewText="" - the preview text the ComboBox should display.<br>

## public void terminate() override
terminates the ComboBox.<br>

## public void render() override
renders the ComboBox.<br>

## public using ContainerBoxGUIElement::addItem
fixes warning "overloaded-virtual". important: if you need your own callback lambda. you can use this function to add a "Selectable<void>" element with your own callback.<br>

## public void addItem(std::string name, std::string text)
adds a item to the Combo Box.<br>

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
contains the text the ComboBox should display.<br>

## private std::string previewText
contains the preview text the ComboBox should display.<br>
