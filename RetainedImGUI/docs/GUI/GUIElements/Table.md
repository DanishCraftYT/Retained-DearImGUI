# class Table : public ContainerGUIElement<std::shared_ptr<GUIElement>>
handles Tables.<br>

## public Table(std::string name, int columns)
constructor for the Table class.<br>

### params:
* std::string name - the name of the Table.<br>
* int columns - the amount of columns each row should have in the Table.<br>

## public void terminate() override
terminates the Table.<br>

## public void render() override
renders the Table.<br>

## public template <typename T> std::vector<std::shared_ptr<T>> getGUIElementsByName(std::string name)
get's GUI Elements by their names.<br>

### params:
* std::string name - the name of the GUI Element(s).<br>

### returns:
* a vector containing the GUI Elements with the matching name.<br>
* a empty vector if no GUI Elements with matching name was found.<br>

## public template <typename T> std::shared_ptr<T> getGUIElementByUUID(std::string uuid)
get's a GUI Element by it's UUID.<br>

### params:
* std::string uuid - the UUID of the GUI Element.<br>

### returns:
* a GUI Element with matching UUID.<br>
* a nullptr if no GUI Element with the specified UUID was found.<br>

## public int removeGUIElementByUUID(std::string UUID)
removes a GUI Element using it's UUID.<br>

### params:
* std::string uuid - the UUID of the GUI Element.<br>

### returns:
* 1 if a GUI Element was removed.<br>
* 0 if no GUI Element was found.<br>

## private int columns
contains the amount of columns each row should have.<br>
