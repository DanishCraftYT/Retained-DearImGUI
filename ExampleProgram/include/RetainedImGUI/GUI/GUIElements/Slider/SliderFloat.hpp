#pragma once

#include "SliderBase.hpp"

template <typename T>
class SliderFloat : public SliderBase<float, T> {
public:
    SliderFloat(std::string name, std::string text, int amountOfSliders, float minValue, float maxValue, std::function<T(SliderBase<float, T>&)> callback=NULL) : SliderBase<float, T>(name, text, amountOfSliders, minValue, maxValue, ImGuiDataType_::ImGuiDataType_Float, callback) {}
};
