# class GUIWindow : public ContainerMultipleGUIElements
handles GUI Element's.<br>

## public GUIWindow(std::string name, std::string text, ImVec2 position, ImVec2 size, bool resizable=true, bool movable=true)
constructor for the GUI Window class.<br>

### params:
* std::string name - the name of the GUI Window.<br>
* std::string text - the title of the GUI Window.<br>
* ImVec2 position - the position of the GUI Window.<br>
* ImVec2 size - the size of the GUI Window.<br>
* bool resizable=true - determines if the GUI Window can be resized by the user.<br>
* bool movable=true - determines if the GUI Window can be moved around by the user.<br>

## public GUIWindow()
constructor for the GUI Window class.<br>

## public void terminate() override
terminates the GUI Window.<br>

## public void render() override
renders the GUI Window.<br>

## public GUIWindowToolbar toolbar
contains the Toolbar for the GUI Window. important: the Toolbar is invisible by default so to use it you will need to make it visible.<br>

## public GUITab tab
contains the class that handles Tabs for the GUIWindow. important: the Tabs handler class is set to invisible by default. to use tabs. make sure to make it visible.<br>

## private ImVec2 position
contains the original position of the GUI Window.<br>

## private ImVec2 size
contains the original size of the GUI Window.<br>

## private int resizable
contains 0 or the value of the ImGUI Window Flag for non resizable windows.<br>

## private int movable
contains 0 or the value of the ImGUI Window Flag for non movable windows.<br>
