# class Tree : ContainerBoxGUIElement<std::shared_ptr<TreeNode>>

## public Tree(std::string name, std::string text)
constructor for the Tree class.<br>

### params:
* std::string name - the name of the Tree.<br>
* std::string text - the text the Tree should display.<br>

## public void terminate() override
terminates the Tree and it's Tree Nodes.<br>

## public void render() override
renders the Tree and it's Tree Nodes.<br>

## public void addItem(std::string name, std::string text, ImGuiTreeNodeFlags nodeFlags = 0)
adds a Tree Node to the Tree.<br>

### params:
* std::string name - the name of the Tree Node.<br>
* std::string text - the text the Tree Node should display.<br>
* ImGuiTreeNodeFlags nodeFlags = 0 - the ImGUI flags the Tree Node should use.<br>

## public std::shared_ptr<TreeNode> getItem(std::string name)
get's a Tree Node by it's name.<br>

### params:
* std::string name - the name of the Tree Node to get.<br>

### returns:
* a shared ptr to a Tree Node.<br>
* a nullptr if no Tree Node was found.<br>

## public int getIndexFromItem(TreeNode& treeNode)
get's the index of the specified Tree Node from the vector containing the Tree Nodes.<br>

### params:
* TreeNode& treeNode - the Tree Node to get it's index in the Tree Nodes vector.<br>

### returns:
* the index of the Tree Node in the Tree Nodes vector.<br>
* -1 if the Tree Node isn't in the Tree Nodes vector.<br>

## private std::string text
contains the text the Tree should display.<br>
