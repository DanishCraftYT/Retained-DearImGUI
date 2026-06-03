# template <typename T, typename U> class SliderBase : public GUIElement

## public SliderBase(std::string name, std::string text, int amountOfSliders, T minValue, T maxValue, ImGuiDataType sliderDataType, std::function<U(SliderBase&)> callback=NULL)
constructor for the SliderBase class.<br>

### params:
* std::string name - the name of the Slider.<br>
* std::string text - the text the Slider should display.<br>
* int amountOfSliders - the amount of sliders the Slider should display.<br>
* T minValue - the minimum value of the Slider.<br>
* T maxValue - the maximum value of the Slider.<br>
* ImGuiDataType sliderDataType - the data type the Slider should use.<br>
* std::function<U(SliderBase&)> callback=NULL - the callback that should be called when one of the Slider's values has changed.<br>

## public virtual void render() override
renders the Slider.<br>

## public int setCurrentValue(T value, size_t index=0)
set's the current value of a slider.<br>

### params:
* T value - the new value of the slider.<br>
* size_t index=0 - the slider to set the value of (it's not neccesary to set this parameter if you only have 1 slider).<br>

### returns:
* 0 if the index is greater than the amount of sliders in the Slider.<br>
* 1 if the value of the slider was changed.<br>

## public int setCurrentValues(std::vector<T> values)
set's the current value of all sliders.<br>

### params:
* std::vector<T> values - the new values of the sliders (if there are more values than sliders. any additional values will be ignored).<br>

### returns:
* 0 if the values vector's size is less than the amount of sliders in the Slider.<br>
* 1 if the values of the sliders was changed.<br>

## public std::vector<T> getCurrentValues()
get's the current value of each of the sliders in the Slider.<br>

### returns:
* a vector containing the values of each of the sliders in the Slider.<br>

## protected std::string text
contains the text the Slider should display.<br>

## protected int amountOfSliders
contains the amount of sliders the Slider should display.<br>

## protected T minValue
contains the minimum value of the Slider.<br>

## protected T maxValue
contains the maximum value of the Slider.<br>

## protected std::vector<T> values
contains the current values of each of the sliders in the Slider.<br>

## protected ImGuiDataType sliderDataType
contains the data type the Slider should use.<br>

## protected std::function<U(SliderBase&)> callback
contains the callback for when one of the values inside the Slider changes.<br>
