# template <typename T> class SliderInt : public SliderBase<int, T>
handles integer Sliders.<br>

## public SliderInt(std::string name, std::string text, int amountOfSliders, int minValue, int maxValue, std::function<T(SliderBase<int, T>&)> callback=NULL)
constructor for the SliderInt class.<br>

### params:
* std::string name - the name of the Slider.<br>
* std::string text - the text the Slider should display.<br>
* int amountOfSliders - the amount of sliders the Slider should display.<br>
* int minValue - the minimum value of the int Slider.<br>
* int maxValue - the maximum value of the int Slider.<br>
* std::function<T(SliderBase<int, T>&)> callback=NULL - the callback that should be called when one of the values inside the Slider changes.<br>
