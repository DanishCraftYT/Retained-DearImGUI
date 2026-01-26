# class GUI
handles GUIWindow's.<br>

## public GUI(std::string name)
constructor for the GUI class.<br>

### params:
* the name of the GUI.<br>

## public GUI()
constructor for the GUI class.<br>

## public void terminate()
terminates the GUI and it's GUI Windows.<br>

## public void renderAllWindows()
renders all the windows that are part of the GUI.<br>

## public GUIWindow& createWindow(std::string name, std::string text, ImVec2 position, ImVec2 size)
creates a GUI Window that's part of the GUI.<br>

### params:
* std::string name - the name of the GUI Window.<br>
* std::string text - the title of the GUI Window.<br>
* ImVec2 position - the position of the GUI Window.<br>
* ImVec2 size - the size of the GUI Window.<br>

### returns:
* a reference to the created GUI Window.<br>

## public GUIWindow& getWindowByUUID(std::string uuid)
get's a GUI Window from the GUI based on it's UUID.<br>

### params:
* std::string uuid - the UUID of the GUI Window to get.<br>

### returns:
* a reference to the GUI Window with the matching UUID.<br>
* a reference to a empty GUI Window object.<br>

## public int removeWindowByUUID(std::string uuid)
removes a GUI Window from the GUI based on it's UUID.<br>

### params:
* std::string uuid - the UUID of the GUI Window to remove.<br>

### returns:
* 1 if it removed the GUI Window.<br>
* 0 if it failed to find the GUI Window.<br>

## public std::string getName()
get's the name of the GUI.<br>

### returns:
* a string containing the name of the GUI.<br>

## public std::string getUUID()
get's the UUID of the GUI.<br>

### returns:
* a string containing the UUID of the GUI.<br>

## public GUIElementVisibility visible
determines the GUI's visibility state.<br>

## public GUIToolbar toolbar
contains the Toolbar for the GLFW Window.<br>

## private std::string name
contains the name of the GUI.<br>

## private std::string uuid
contains the UUID of the GUI.<br>

## private std::vector<GUIWindow> GUIWindows
contains the GUI Windows that are part of the GUI.<br>
