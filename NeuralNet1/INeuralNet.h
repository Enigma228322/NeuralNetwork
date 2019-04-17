#pragma once

#include <string>
#include "NetMatr.h"

class INeuralNet
{
private:
	virtual NetMatr Sigmoid(NetMatr layer) = 0;
public:
	virtual void Init_weights() = 0;
	virtual void SetLearnCoef(double learn_coef) = 0;
	virtual void Input(std::string filename) = 0;
	virtual void Train() = 0;
	virtual void Query(NetMatr input) = 0;
};