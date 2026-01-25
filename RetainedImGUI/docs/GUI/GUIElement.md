# enum GUIElementVisibility
determines the visibility state of GUI Elements.<br>

### values:
* Visible - the GUI Element is visible and can be interacted with.<br>
* Invisible - the GUI Element is invisible and can't be interacted with.<br>
* Disabled - the GUI Element is visible and can't be interacted with.<br>

# class GUIElement
base class for all GUI Elements.<br>

## public GUIElement(std::string name)
constructor for the GUIElement class.<br>

### params:
* std::string name - the name of the GUI Element.<br>

## public GUIElement()
constructor for the GUIElement class.<br>

## public virtual void render()
renders the GUI Element.<br>

## public std::string getName()
get's the name of the GUI Element.<br>

### returns:
* a string containing the GUI Element's name.<br>

## public std::string getUUID()
get's the UUID of the GUI Element.<br>

### returns:
* a string containing the GUI Element's UUID.<br>

## public GUIElementVisibility visible
determines the GUI Element's visibility state.<br>

## private std::string name
contains the name of the GUI Element.<br>

## private std::string uuid
contains the UUID of the GUI Element.<br>
