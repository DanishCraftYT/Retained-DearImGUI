# class Child : public GUIElement
handles child GUI Elements (these elements can hold other GUIElements).<br>

## public Child(std::string name, ImVec2 size=ImVec2(0, 0), bool border=false)
constructor for the Child class.<br>

### params:
* std::string name - the name of the Child.<br>
* ImVec2 size=ImVec2(0, 0) - the size of the Child.<br>
* bool border=false - determines if the Child has a border or not.<br>

## public void render() override
renders the Child.<br>

## public void addGUIElement(std::shared_ptr<GUIElement> element)
adds a GUI Element to the Child.<br>

### params:
* std::shared_ptr<GUIElement> element - the GUI Element to add to the Child.<br>

## public template <typename T> std::vector<std::shared_ptr<T>> getGUIElementsByName(std::string name)
get's GUI Element(s) from the Child using their names.<br>

### params:
* std::string name - the name of the GUI Element(s) to get.<br>

### returns:
* a vector containing the GUI Element(s) with matching name.<br>
* a empty vector if no GUI Element(s) with matching name was found.<br>

## public template <typename T> std::shared_ptr<T> getGUIElementByUUID(std::string uuid)
get's a GUI Element from the Child using it's UUID.<br>

### params:
* std::string uuid - the UUID of the GUI Element to get.<br>

### returns:
* a shared pointer to the GUI Element with a matching UUID.<br>
* a nullptr if no GUI Element with a matching UUID was found.<br>

## public int removeGUIElementByUUID(std::string uuid)
removes a GUI Element from the Child using it's UUID.<br>

### params:
* std::string uuid - the UUID of the GUI Element to remove.<br>

### returns:
* 1 if it removed the GUI Element.<br>
* 0 if it no GUI Element with matching UUID was found.<br>

## private ImVec2 size
contains the size of the Child.<br>

## private bool border
determines if the Child has a border or not.<br>

## std::vector<std::shared_ptr<GUIElement>> GUIElements
contains all the GUI Elements inside the Child.<br>
