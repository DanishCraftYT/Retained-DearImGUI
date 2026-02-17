# template <typename T> class SliderFloat : public SliderBase<float, T>
handles floating point Sliders.<br>

## public SliderFloat(std::string name, std::string text, int amountOfSliders, float minValue, float maxValue, std::function<T(SliderBase<float, T>&)> callback=NULL)
constructor for the SliderFloat class.<br>

### params:
* std::string name - the name of the Slider.<br>
* std::string text - the text the Slider should display.<br>
* int amountOfSliders - the amount of sliders the Slider should display.<br>
* float minValue - the minimum value of the Float Slider.<br>
* float maxValue - the maximum value of the Float Slider.<br>
* std::function<T(SliderBase<float, T>&)> callback=NULL - the callback that should be called when one of the values inside the Slider changes.<br>
