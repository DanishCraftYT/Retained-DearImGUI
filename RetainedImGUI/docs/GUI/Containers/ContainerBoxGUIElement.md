# template <typename T> class ContainerBoxGUIElement : public GUIElement
base class for "list" type GUI Elements (ListBox, ComboBox).<br>

## public ContainerBoxGUIElement(std::string name)
constructor for the Container Box GUI Element class.<br>

### params:
* std::string name - the name of the Container Box GUI Element.<br>

## public virtual void terminate() override
terminates the GUI Element Box Container.<br>

## public virtual void addItem(T item)
adds a item to the Container GUI Element.<br>

### params:
* T item - the item to add to the Container GUI Element.<br>

## public virtual int removeItem(size_t index)
removes a item from the Container GUI Element.<br>

### params:
* size_t index - removes a item from the Container GUI Element using a index.<br>

### returns:
* 1 if it removed the item from the Container GUI Element.<br>
* 0 if the index larger than the amount of items in Container GUI Element.<br>

## public virtual void removeAllItems()
removes all items from the Container GUI Element.<br>

## public virtual T getSelectedItem()
get's a selected item from the Container Box GUI Element.<br>

### returns:
* the selected item from the Container Box GUI Element.<br>

## public virtual int getcurrentSelected()
get's the currently selected item integer.<br>

### returns:
* the currently selected item integer.<br>
* -1 if no item is selected.<br>

## protected int currentSelected
contains the currently selected item inside the "items" vector.<br>

## protected std::vector<T> items
contains all the items inside the Container GUI Element.<br>
