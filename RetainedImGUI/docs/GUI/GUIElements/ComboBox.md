# class ComboBox : public ContainerBoxGUIElement<std::string>
handles ComboBox GUI Elements.<br>

## public ComboBox(std::string name, std::string text, std::string previewText)
constructor for the ComboBox class.<br>

### params:
* std::string name - the name of the ComboBox.<br>
* std::string text - the text the ComboBox should display.<br>
* std::string previewText - the preview text the ComboBox should display.<br>

## public void render() override
renders the ComboBox.<br>

## private std::string text
contains the text the ComboBox should display.<br>

## private std::string previewText
contains the preview text the ComboBox should display.<br>
