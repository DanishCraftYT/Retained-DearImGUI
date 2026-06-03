#pragma once

#include "GUI/GUIElement.hpp"

template <typename T, typename U>
class SliderBase : public GUIElement {
public:
    SliderBase(std::string name, std::string text, int amountOfSliders, T minValue, T maxValue, ImGuiDataType sliderDataType, std::function<U(SliderBase&)> callback=NULL) : GUIElement(name), text(text), amountOfSliders(amountOfSliders), minValue(minValue), maxValue(maxValue), sliderDataType(sliderDataType), callback(callback) {
        this->values.resize(amountOfSliders, this->minValue);
    }
    virtual void render() override {
        if (this->visible == GUIElementVisibility::Invisible) {
            return;
        }
        else if (this->visible == GUIElementVisibility::Disabled) {
            ImGui::BeginDisabled();
            if (ImGui::SliderScalarN(std::format("{}##{}", this->text, this->uuid).c_str(), this->sliderDataType, static_cast<void*>(this->values.data()), this->amountOfSliders, &this->minValue, &this->maxValue) && this->callback != NULL) {
                this->callback(*this);
            }
            ImGui::EndDisabled();
            return;
        }
        if (ImGui::SliderScalarN(std::format("{}##{}", this->text, this->uuid).c_str(), this->sliderDataType, static_cast<void*>(this->values.data()), this->amountOfSliders, &this->minValue, &this->maxValue) && this->callback != NULL) {
            this->callback(*this);
        }
    }
    int setCurrentValue(T value, size_t index=0) {
	if (index > this->values.size()) {
	    return 0;
	}
	this->values.at(index) = value;
	return 1;
    }
    int setCurrentValues(std::vector<T> values) {
	if (values.size() < this->values.size()) {
	    return 0;
	}
	for (int i = 0; i < this->values.size(); i++) {
	    this->values.at(i) = values.at(i);
	}
	return 1;
    }
    std::vector<T> getCurrentValues() {
        return this->values;
    }
protected:
    std::string text;
    int amountOfSliders;
    T minValue;
    T maxValue;
    std::vector<T> values;
    ImGuiDataType sliderDataType;
    std::function<U(SliderBase&)> callback;
};
