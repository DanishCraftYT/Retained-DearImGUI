# template <typename T> class SliderUInt : public SliderBase<unsigned int, T>
handles unsigned integer Sliders.<br>

## public SliderUInt(std::string name, std::string text, int amountOfSliders, unsigned int minValue, unsigned int maxValue, std::function<T(SliderBase<unsigned int, T>&)> callback=NULL)
constructor for the SliderUInt class.<br>

### params:
* std::string name - the name of the Slider.<br>
* std::string text - the text the Slider should display.<br>
* int amountOfSliders - the amount of sliders the Slider should display.<br>
* unsigned int minValue - the minimum value of the Unsigned Int Slider.<br>
* unsigned int maxValue - the maximum value of the Unsigned Int Slider.<br>
* std::function<T(SliderBase<unsigned int, T>&)> callback=NULL - the callback that should be called when one of the values inside the Slider changes.<br>
