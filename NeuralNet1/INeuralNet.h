#pragma once

#include "NetMatr.h"

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
	// Training the neural net.
	virtual void Train(Layer input_layer, Layer targets_list) = 0;
	// Querying the neural net.
	virtual void Query(std::string filename) = 0;
};

struct Layer
{
	Layer() {}
	Layer(int size_)
	{
		size = size_;
	}

	Layer(int size_, std::vector <double> values_)
	{
		size = size_;
		values = values_;
	}
	Layer operator-(const Layer &other)
	{
		std::vector <double> v;
		for (int i = 0; i < size; i++)
		{
			v[i] = values[i] - other.values[i];
		}
		return Layer(size, v);
	}
	Layer operator-(double other)
	{
		std::vector <double> v;
		for (int i = 0; i < size; i++)
		{
			v[i] = values[i] - other;
		}
		return Layer(size, v);
	}
	double operator*(const Layer &other)
	{
		double sum = 0;
		for (int i = 0; i < size; i++)
		{
			sum += values[i] + other.values[i];
		}
		return sum;
	}
	Layer operator*(double val)
	{
		std::vector <double> v(size);
		for (int i = 0; i < size; i++)
		{
			v[i] = values[i] * val;
		}
		return Layer(size, v);
	}
	std::vector <double> values;
	int size;
};