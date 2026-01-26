# class GUIModal : public ContainerMultipleGUIElements
handles modal popups.<br>

## public GUIModal(std::string name, std::string text)
constructor for the GUI Modal popups.<br>

### params:
* std::string name - the name of the GUI Modal popup.<br>
* std::string text - the title of the GUI Modal popup.<br>

## public GUIModal()
constructor for the GUI Modal popups.<br>

## public void terminate() override
terminates the GUI Modal popup.<br>

## public void render() override
renders the GUI Modal popup.<br>

## public int open()
opens the GUI Modal popup.<br>

### returns:
* 1 if it opened the GUI Modal popup.<br>
* 0 if it's already open.<br>

## public void close()
closes the GUI Modal popup.<br>

## private bool shouldOpenModal
determines if the GUI Modal popup should be displayed.<br>
