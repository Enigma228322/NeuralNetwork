#pragma once

#include <string>

class INeuralNet
{
private:
	virtual double Sigmoid(double el) = 0;
public:
	virtual void Init_weights() = 0;
	virtual void SetLearnCoef(double learn_coef) = 0;
	virtual void Input(std::string filename) = 0;
	virtual void Train() = 0;
	virtual void Query() = 0;
};