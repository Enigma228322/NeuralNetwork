#pragma once
// MA FIRST AI PROJECT, DONT JUDGE HARD PLS

#include "NetMatr.h"
#include  <cmath>
#include <string>
#include <fstream>
#include <vector>

class NeuralNetwork
{
private:
	// in_nodes - input nodes, o_nodes - output nodes,
	// h_nodes - hidden layer nodes in out neural net.
	// out_nodes - output layer nodes in out neural net.
	int in_nodes, h_nodes, out_nodes;
	// Learning coeficent
	double learn_coef;
	// Input and output layer matrix
	NetMatr inp, outp;
	// Two matrixes:
	// w_ih - link weights between input & hidden layer (n = hidden, m = input)
	// w_ih - link weights between hidden & output layer (n = output, m = hidden)
	NetMatr w_ih;
	NetMatr w_ho;
	// For more abstraction we can use array of matrixes
	// NetMatr *w; - but it's not conveniently

	// Activation function
	double Sigmoid(double x)
	{
		return 1 / (1 + exp(-x));
	}

public:
	NeuralNetwork() {}
	~NeuralNetwork() {}

	void Init_wights()
	{ 
		w_ih = NetMatr(h_nodes, in_nodes, 0, 1);
		w_ho = NetMatr(out_nodes, h_nodes, 0, 1);
	}

	NeuralNetwork(int in_nodes, int h_nodes, int out_nodes)
	{
		this->in_nodes = in_nodes;
		this->h_nodes = h_nodes;
		this->out_nodes = out_nodes;
		// Initialization of links between nodes.(weights)
		Init_wights();
	}
	// Name of method says for himself i suppose
	void SetLearnCoef(double learn_c)
	{
		this->learn_coef = learn_c;
	}
	// Initilization of Input Layer
	void Input(std::string filename)
	{
		std::ifstream in(filename);
		// We will save all input values in vector 'v'
		std::vector <double> v;
		// temporary variable
		double temp;
		// Reading file, while we didnt read whole file
		while (in >> temp)
		{
			v.push_back(temp);
		}
		// Create object input layer matrix
		inp = NetMatr(v.size(), 1);
		// Filling up out input layer
		for (int i = 0; i < v.size(); i++)
		{
			inp.SetMatr(i, 0, v[i]);
		}

		in.close();
	}
	// Training neural net
	void Train() {}
	// Check neural net
	void Query() {}
};
