# class Child : public ContainerGUIElement<std::shared_ptr<GUIElement>>
handles child GUI Elements (these elements can hold other GUIElements).<br>

## public Child(std::string name, ImVec2 size=ImVec2(0, 0), bool border=false)
constructor for the Child class.<br>

### params:
* std::string name - the name of the Child.<br>
* ImVec2 size=ImVec2(0, 0) - the size of the Child.<br>
* bool border=false - determines if the Child has a border or not.<br>

## public void terminate() override
terminates the Child.<br>

## public void render() override
renders the Child.<br>

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

## private ImVec2 size
contains the size of the Child.<br>

## private bool border
determines if the Child has a border or not.<br>
