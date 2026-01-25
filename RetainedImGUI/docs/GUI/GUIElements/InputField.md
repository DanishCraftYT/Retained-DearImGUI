# class InputField : public GUIElement
handles InputField GUI Elements.<br>

## public InputField(std::string name, std::string text)
constructor for the InputField class.<br>

### params:
* std::string name - the name of the Input Field.<br>
* std::string text - the text the Input Field should display.<br>

## public void render() override
renders the Input Field.<br>

## public std::string getInputFieldText()
get's the text from the Input Field.<br>

### returns:
* a string containing the text from the Input Field.<br>

## private std::string text
contains the text that the Input Field should display.<br>

## private std::string buffer
contains the input text that the Input Field should display.<br>
