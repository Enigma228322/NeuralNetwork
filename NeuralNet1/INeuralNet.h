#pragma once

#include <string>
#include "NetMatr.h"

class INeuralNet
{
private:
	// Activation func
	virtual NetMatr Activation_F(NetMatr layer) = 0;
public:
	// Neural network weights initialization
	virtual void Init_weights() = 0;
	// Setting learn coefficent
	virtual void SetLearnCoef(double learn_coef) = 0;
	// Reading input layer from the file
	virtual void Input(std::string filename) = 0;
	// Reading target list from the file
	virtual void Targets(std::string filename) = 0;
	// Training the neural net.
	virtual void Train(NetMatr input_layer, NetMatr targets_list) = 0;
	// Querying the neural net.
	virtual NetMatr Query(NetMatr input) = 0;
};