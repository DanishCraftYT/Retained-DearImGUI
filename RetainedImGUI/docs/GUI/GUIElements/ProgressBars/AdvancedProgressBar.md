# class AdvancedProgressBar : public GUIElement
handles more complex Progress Bars (you will need to manually update the progression of the Progress Bar).<br>

## public AdvancedProgressBar(std::string name, float& progress, ImVec2 size)
constructor for the AdvancedProgressBar class.<br>

### params:
* std::string name - the name of the Progress Bar.<br>
* float& progress - the progression of the Progress Bar.<br>
* ImVec2 size - the size of the Progress Bar.<br>

## public void render() override
renders the Progress Bar.<br>

## private float& progress
contains a reference to the progress of the Progress Bar.<br>

## private ImVec2 size
contains the size of the Progress Bar.<br>
