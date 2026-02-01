# template <typename T> class ContainerGUIElement : public GUIElement
base class for GUI Elements which need to contain items.<br>

## public ContainerGUIElement(std::string name)
the constructor for the ContainerGUIElement class.<br>

### params:
* std::string name - the name of the Container GUI Element.<br>

## public virtual void terminate() override
terminates the GUI Element Container.<br>

## public virtual void addGUIElement(T GUIElement)
adds a GUI Element to the Container GUI Element.<br>

### params:
* T GUIElement - the GUI Element to add to the Container GUI Element.<br>

## public virtual int removeGUIElement(size_t index)
removes a GUI Element from the Container GUI Element.<br>

### params:
* size_t index - removes a GUI Element from the Container GUI Element using a index.<br>

### returns:
* 1 if it removed the GUI Element from the Container GUI Element.<br>
* 0 if the index larger than the amount of GUI Elements in Container GUI Element.<br>

## public virtual void removeAllGUIElements()
removes all GUI Elements from the Container GUI Element.<br>

## protected std::vector<T> GUIElements
contains all the GUI Elements inside the Container GUI Element.<br>
