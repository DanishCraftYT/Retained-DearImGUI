# template <typename T> class ContainerBoxGUIElement : public ContainerGUIElement<T>
base class for "list" type GUI Elements (ListBox, ComboBox).<br>

## public ContainerBoxGUIElement(std::string name)
constructor for the Container Box GUI Element class.<br>

### params:
* std::string name - the name of the Container Box GUI Element.<br>

## public T getSelectedItem()
get's a selected item from the Container Box GUI Element.<br>

### returns:
* the selected item from the Container Box GUI Element.<br>

## public int getcurrentSelected()
get's the currently selected item integer.<br>

### returns:
* the currently selected item integer.<br>
* -1 if no item is selected.<br>

## protected int currentSelected
contains the currently selected item inside the "items" vector.<br>
