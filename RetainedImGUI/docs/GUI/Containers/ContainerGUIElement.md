# template <typename T> class ContainerGUIElement : public GUIElement
base class for GUI Elements which need to contain items.<br>

## public ContainerGUIElement(std::string name)
the constructor for the ContainerGUIElement class.<br>

### params:
* std::string name - the name of the Container GUI Element.<br>

## public void addItem(T item)
adds a item to the Container GUI Element.<br>

### params:
* T item - the item to add to the Container GUI Element.<br>

## public int removeItem(size_t index)
removes a item from the Container GUI Element.<br>

### params:
* size_t index - removes a item from the Container GUI Element using a index.<br>

### returns:
* 1 if it removed the item from the Container GUI Element.<br>
* 0 if the index larger than the amount of items in Container GUI Element.<br>

## public void removeAllItems()
removes all items from the Container GUI Element.<br>

## protected std::vector<T> items
contains all the items inside the Container GUI Element.<br>
