# class GUIWindow
handles GUI Element's.<br>

## public GUIWindow(std::string name, std::string text, ImVec2 position, ImVec2 size)
constructor for the GUI Window class.<br>

### params:
* std::string name - the name of the GUI Window.<br>
* std::string text - the title of the GUI Window.<br>
* ImVec2 position - the position of the GUI Window.<br>
* ImVec2 size - the size of the GUI Window.<br>

## public GUIWindow()
constructor for the GUI Window class.<br>

## public void terminate() override
terminates the GUI Window.<br>

## public void render() override
renders the GUI Window.<br>

## public GUIWindowToolbar toolbar
contains the Toolbar for the GUI Window. important: the Toolbar is invisible by default so to use it you will need to make it visible.<br>

## private ImVec2 position
contains the original position of the GUI Window.<br>

## private ImVec2 size
contains the original size of the GUI Window.<br>
