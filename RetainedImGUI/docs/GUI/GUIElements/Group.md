# class Group : public ContainerGUIElement<std::shared_ptr<GUIElement>>

## public Group(std::string name)
constructor for the Group class.<br>

### params:
* std::string name - the name of the Group.<br>

## public void terminate() override
terminates the Group and it's GUI Elements.<br>

## public void render() override
renders the Group.<br>

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
