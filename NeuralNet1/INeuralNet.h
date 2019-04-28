#pragma once

#include "NetMatr.h"
#include "Layer.h"

class INeuralNet
{
private:
	// Activation func
	virtual std::vector <double> Activation_F(std::vector <double> layer) = 0;
public:
	// Neural network weights initialization
	virtual void Init_weights() = 0;
	// Setting learn coefficent
	virtual void SetLearnCoef(double learn_coef) = 0;
	// Reading input layer from the file
	virtual void Input(std::string filename) = 0;
	// Reading target list from the file
	virtual void Targets(std::string filename) = 0;
	// Querying the neural net.
	virtual void Query(std::string filename) = 0;
};