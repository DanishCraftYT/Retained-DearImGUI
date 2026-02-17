#pragma once

#include "SliderBase.hpp"

template <typename T>
class SliderInt : public SliderBase<int, T> {
public:
    SliderInt(std::string name, std::string text, int amountOfSliders, int minValue, int maxValue, std::function<T(SliderBase<int, T>&)> callback=NULL) : SliderBase<int, T>(name, text, amountOfSliders, minValue, maxValue, ImGuiDataType_::ImGuiDataType_S32, callback) {}
};
