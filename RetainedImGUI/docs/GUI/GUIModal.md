# class GUIModal
handles modal popups.<br>

## public GUIModal(std::string name, std::string text)
constructor for the GUI Modal popups.<br>

### params:
* std::string name - the name of the GUI Modal popup.<br>
* std::string text - the title of the GUI Modal popup.<br>

## public GUIModal()
constructor for the GUI Modal popups.<br>

## public void terminate()
terminates the GUI Modal popup.<br>

## public void render()
renders the GUI Modal popup.<br>

## public int open()
opens the GUI Modal popup.<br>

### returns:
* 1 if it opened the GUI Modal popup.<br>
* 0 if it's already open.<br>

## public void close()
closes the GUI Modal popup.<br>

## public void addGUIElement(std::shared_ptr<GUIElement> element)
adds a GUI Element to the GUI Modal popup.<br>

### params:
* std::shared_ptr<GUIElement> element - the GUI Element to add to the GUI Modal popup.<br>

## public template <typename T> std::vector<std::shared_ptr<T>> getGUIElementsByName(std::string name)
get's GUI Element(s) from the GUI Modal popup using their names.<br>

### params:
* std::string name - the name of the GUI Element(s) to get.<br>

### returns:
* a vector containing the GUI Element(s) with a matching name.<br>
* a empty vector if no GUI Element(s) with the matching name was found.<br>

## public template <typename T> std::shared_ptr<T> getGUIElementByUUID(std::string uuid)
get's a GUI Element from the GUI Modal popup using it's UUID.<br>

### params:
* std::string uuid - the UUID of the GUI Element to get.<br>

### returns:
* a shared pointer to a GUI Element.<br>
* a nullptr if no GUI Element with a matching UUID was found.<br>

## public int removeGUIElementByUUID(std::string uuid)
removes a GUI Element from the GUI Modal popup using it's UUID.<br>

### params:
* std::string uuid - the UUID of the GUI Element to remove.<br>

### returns:
* 1 if it removed the GUI Element.<br>
* 0 if no GUI Elements with a matching UUID was found.<br>

## public std::string getName()
get's the name of the GUI Modal popup.<br>

### returns:
* a string containing the name of the GUI Modal popup.<br>

## public std::string getUUID()
get's the UUID of the GUI Modal popup.<br>

### returns:
* a string containing the UUID of the GUI Modal popup.<br>

## public GUIElementVisibility visible
determines the GUI Modal popup's visibility state.<br>

## private std::string name
contains the name of the GUI Modal popup.<br>

## private std::string uuid
contains the UUID of the GUI Modal popup.<br>

## private std::string text
contains the title of the GUI Modal popup.<br>

## private bool shouldOpenModal
determines if the GUI Modal popup should be displayed.<br>

## private std::vector<std::shared_ptr<GUIElement>> GUIElements
contains all the GUI Elements inside the GUI Modal popup.<br>
