#pragma once

#include "SliderBase.hpp"

template <typename T>
class SliderUInt : public SliderBase<unsigned int, T> {
public:
    SliderUInt(std::string name, std::string text, int amountOfSliders, unsigned int minValue, unsigned int maxValue, std::function<T(SliderBase<unsigned int, T>&)> callback=NULL) : SliderBase<unsigned int, T>(name, text, amountOfSliders, minValue, maxValue, ImGuiDataType_::ImGuiDataType_U32, callback) {}
};
