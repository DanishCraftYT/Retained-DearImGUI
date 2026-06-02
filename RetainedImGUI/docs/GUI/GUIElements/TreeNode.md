# public TreeNode : public ContainerGUIElement<std::shared_ptr<GUIElement>>

## public TreeNode(std::string name, std::string text, ImGuiTreeNodeFlags nodeFlags = 0)
constructor for the TreeNode class.<br>

### params:
* std::string name - the name of the Tree Node.<br>
* std::string text - the text the Tree Node should display.<br>
* ImGuiTreeNodeFlags nodeFlags = 0 - the ImGUI flags the Tree Node should use.<br>

## public void terminate() override
terminates the Tree Node.<br>

## public void render() override
renders the Tree Node.<br>

## public ImGuiTreeNodeFlags getTreeNodeFlags()
get's the Tree Node's ImGUI flags.<br>

### returns:
* the ImGUI Tree Node flags used by the Tree Node.<br>

## public void setTreeNodeFlags(ImGuiTreeNodeFlags treeNodeFlags)
set's the Tree Node's ImGUI flags.<br>

### params:
* ImGuiTreeNodeFlags nodeFlags = 0 - the new ImGUI flags the Tree Node should use.<br>

## public template <typename T> std::vector<std::shared_ptr<T>> getGUIElementsByName(std::string name)
get's GUI Elements from the Tree Node by their name.<br>

### params:
* std::string name - the name of the GUI Elements to get.<br>

### returns:
* a vector containing the GUI Elements with the specified name.<br>

## public template <typename T> std::shared_ptr<T> getGUIElementByUUID(std::string uuid)
get's a GUI Element from the Tree Node by it's UUID.<br>

### params:
* std::string uuid - the UUID of the GUI Element to get.<br>

### returns:
* a shared ptr to the GUI Element.<br>
* a nullptr if no GUI Element was found.<br>

## public int removeGUIElementByUUID(std::string uuid)
removes a GUI Element from the Tree Node by it's UUID.<br>

### params:
* std::string uuid - the UUID of the GUI Element to remove.<br>

### returns:
* 0 if the GUI Element was removed.<br>
* 1 if the GUI Element wasn't found.<br>

## private std::string text
contains the text the Tree Node should display.<br>

## private ImGuiTreeNodeFlags nodeFlags
contains the Tree Node ImGUI flags.<br>
