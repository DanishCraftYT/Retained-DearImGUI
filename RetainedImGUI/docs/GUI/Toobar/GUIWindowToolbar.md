# class GUIWindowToolbar
handles Toolbars that are attached to ImGUI Windows.<br>

## public GUIWindowToolbar(std::string name)
constructor for the GUIWindowToolbar class.<br>

### params:
* std::string name - the name of the Toolbar.<br>

## public GUIWindowToolbar()
constructor for the GUIWindowToolbar class.<br>

## public void terminate()
terminates the Toolbar.<br>

## public void render()
renders the Toolbar.<br>

## public ToolbarMenu& addToolbarMenu(std::string name, std::string text)
adds a Toolbar Menu to the Toolbar.<br>

### params:
* std::string name - the name of the Toolbar Menu.<br>
* std::string text - the text the Toolbar Menu should display.<br>

### returns:
* a reference to the created Toolbar Menu.<br>

## public std::vector<ToolbarMenu> getToolbarMenusByName(std::string name)
get's a Toolbar Menu from the Toolbar using it's name.<br>

### params:
* std::string name - the name of the Toolbar Menu(s) to get.<br>

### returns:
* a vector containing the Toolbar Menu(s) with a matching name.<br>
* a empty vector if no Toolbar Menu(s) with a matching name was found.<br>

## public ToolbarMenu& getToolbarMenuByUUID(std::string uuid)
get's a Toolbar Menu from the Toolbar using it's UUID.<br>

### params:
* std::string uuid - the UUID of the Toolbar Menu to get.<br>

### returns:
* a reference to the Toolbar Menu with a matching UUID.<br>
* a empty Toolbar Menu if no Toolbar Menu with a matching UUID was found.<br>

## public int removeToolbarMenuByUUID(std::string uuid)
removes a Toolbar Menu from the Toolbar using it's UUID.<br>

### params:
* std::string uuid - the UUID of the Toolbar Menu to get.<br>

### returns:
* 1 if the Toolbar Menu was removed.<br>
* 0 if no Toolbar Menu with a matching UUID was found.<br>

## public std::string getName()
get's the name of the Toolbar.<br>

### returns:
* a string containing the name of the Toolbar.<br>

## public std::string getUUID()
get's the UUID of the Toolbar.<br>

### returns:
* a string containing the UUID of the Toolbar.<br>

## public GUIElementVisibility visible
determines the Toolbar's visibility state.<br>

## private std::string name
contains the name of the Toolbar.<br>

## private std::string uuid
contains the UUID of the Toolbar.<br>

## private std::vector<ToolbarMenu> toolbarMenus
contains all the Toolbar Menu's that are inside the Toolbar.<br>
