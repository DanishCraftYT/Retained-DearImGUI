# class GUITab

## public GUITab(std::string name, std::string text)
constructor for tabs.<br>

### params:
* std::string name - the name of the tab.<br>
* std::string text - the text the tab should display.<br>

## public GUITab()
empty constructor.<br>

## public void render()
renders the tabs.<br>

## public void terminate()
terminates the tabs.<br>

## public std::shared_ptr<TabItem> addTabItem(std::string name, std::string text)
adds a tab.<br>

### params:
* std::string name - the name of the tab.<br>
* std::string text - the text the tab should display.<br>

### returns:
* a shared pointer to the tab.<br>

## public std::vector<std::shared_ptr<TabItem>> getTabItemsByName(std::string name)
get's tabs using a name.<br>

### params:
* std::string name - the name of the tab.<br>

### returns:
* a vector of shared pointers that contain the tabs.<br>

## public std::shared_ptr<TabItem> getTabItemByUUID(std::string uuid)
get's a tab using it's UUID.<br>

### params:
* std::string uuid - the uuid of the tab.<br>

### returns:
* a shared pointer to the tab.<br>

## public int removeTabItemByUUID(std::string uuid)
removes a tab using it's UUID.<br>

### params:
* std::string uuid - the uuid of the tab.<br>

### returns:
* 1 if the tab was found.<br>
* 0 if the tab wasn't found.<br>

## public std::string getName()
get's the name of the tab.<br>

### returns:
* the name of the tab.<br>

## public std::string getUUID()
get's the UUID of the tab.<br>

### returns:
* the UUID of the tab.<br>

## public GUIElementVisibility visible
determines if the tabs are visible, invisible, or disabled.<br>

## private std::string name
contains the name of the tab.<br>

## private std::string text
contains the text the tab should display.<br>

## private std::string uuid
contains the UUID.<br>

## private std::vector<std::shared_ptr<TabItem>> tabItems
contains the tabs.<br>
