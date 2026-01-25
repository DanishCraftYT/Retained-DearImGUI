# class GUIWindow
handles GUI Element's.<br>

## public GUIWindow(std::string name, std::string text)
constructor for the GUI Window class.<br>

### params:
* std::string name - the name of the GUI Window.<br>
* std::string text - the title of the GUI Window.<br>

## public GUIWindow()
constructor for the GUI Window class.<br>

## public void terminate()
terminates the GUI Window.<br>

## public void render()
renders the GUI Window.<br>

## public void addGUIElement(std::shared_ptr<GUIElement> element)
adds a GUI Element to the GUI Window.<br>

### params:
* std::shared_ptr<GUIElement> element - a shared pointer that points to a GUI Element.<br>

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

## public int removeGUIElementByUUID(std::string uuid)
removes a GUI Element by it's UUID.<br>

### params:
* std::string uuid - the UUID of the GUI Element.<br>

### returns:
* 1 if a GUI Element was removed.<br>
* 0 if no GUI Element was found.<br>

## public std::string getName()
get's the name of the GUI Window.<br>

### returns:
* a string containing the name of the GUI Window.<br>

## public std::string getUUID()
get's the UUID of the GUI Window.<br>

### returns:
* a string containing the UUID of the GUI Window.<br>

## public GUIElementVisibility visible
determines the GUI Window's visibility state.<br>

## private std::string name
contains the name of the GUI Window.<br>

## private std::string uuid
contains the UUID of the GUI Window.<br>

## private std::string text
contains the title of the GUI Window.<br>

## private std::vector<std::shared_ptr<GUIElement>> GUIElements
contains all the GUI Elements that are part of the GUI Window.<br>
