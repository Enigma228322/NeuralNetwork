#pragma once
// MA FIRST AI PROJECT, DONT JUDGE HARD PLS

#include "NetMatr.h"
#include "INeuralNet.h"
#include  <cmath>
#include <fstream>
#include <iomanip>

class NeuralNetwork2 : public INeuralNet
{
private:
	// Learning coeficent
	double learn_coef;
	// Vector with weights
	std::vector <NetMatr> w;
	// Nodes of net: input, hidden1, hidden2 ... , output 
	std::vector <Layer> nodes;
	// Targets for training
	Layer target;

	// Activation functions
	double Sigmoid(double x)
	{
		return 1 / (1 + exp(-x));
	}
	// Activation func. returns layer
	std::vector <double> Activation_F(std::vector <double> layer) override
	{
		//Bias(layer);
		for (int i = 0; i < layer.size(); i++)
		{
			// Using sigmoid function to vector
			layer[i] = Sigmoid(layer[i]);
		}
		return layer;
	}
	// Bias
	void Bias(std::vector <double> &values)
	{
		for (int i = 0; i < values.size(); i++)
		{
			int cnt = 0;
			double temp = fabs(values[i]);
			while (temp >= 1)
			{
				temp /= 10;
				cnt++;
			}
			if (values[i] > 1)
				values[i] /= 10 * cnt;
			if (values[i] < -1)
				values[i] /= 10 * cnt;
		}
	}
	// Wtights initialization
	void Init_weights() override
	{
		for (int i = 0; i < nodes.size() - 1; i++)
		{
			// Creating matrix, dim = n * m, where n - next layer size, m - current layer size
			w.push_back(NetMatr(nodes[i + 1].size, nodes[i].size));
		}
	}

public:
		
	NeuralNetwork2() {}
	~NeuralNetwork2() {}

	// File with number of nodes in every layer
	NeuralNetwork2(std::string filename)
	{
		std::ifstream in(filename);
		int temp;
		// Reading nums of nodes in every layer one by one
		while (in >> temp)
		{
			nodes.push_back(Layer(temp));
		}
		// Initialization of weights
		Init_weights();
		// Assigning value 'size' to tagrgets size
		target.size = nodes[nodes.size() - 1].size;
	}

	// Name of method says for himself i suppose
	void SetLearnCoef(double learn_c) override
	{
		this->learn_coef = learn_c;
	}

	// Initilization of Input Layer
	void Input(std::string filename) override
	{
		std::ifstream in(filename);
		// temporary value
		double temp;
		// Reading file
		for (int i = 0; i < nodes[0].size; i++)
		{
			in >> temp;
			nodes[0].values.push_back(temp);
		}
	}

	// Initilization of Target list
	void Targets(std::string filename) override
	{
		std::ifstream in(filename);
		// temporary variable
		double temp;
		// Reading file, while we didnt read whole file
		for (int i = 0; i < target.size; i++)
		{
			in >> temp;
			target.values.push_back(temp);
		}

		in.close();
	}

	// Copy weights from file to the array
	void SyncWeights(std::string filename)
	{
		// Create temporary var
		double temp;
		// Open in stream to file 'filename'
		std::ifstream in(filename);
		// Reading every element of matrix w[k] and write to array
		for (int k = 0; k < w.size(); k++)
		{
			for (int i = 0; i < w[k].NSize(); i++)
			{
				for (int j = 0; j < w[k].MSize(); j++)
				{
					in >> temp;
					w[k].SetMatr(i, j, temp);
				}
			}
		}
		in.close();
	}
	// Training neural net
	void Train()
	{
		// Calculating all layers
		LayerCalc();
		// Last layers
		Layer final_out = nodes[nodes.size() - 1];
		// Calculating all hidden errors by "Back propagation method" 
		std::vector <Layer> errors(nodes.size() - 1);
		// Calculating of output errors
		errors[errors.size() - 1] = target - final_out;
		// Calculating hidden layers
		// i = errors.size() - 2, because output_errors = errors.size() - 1
		for (int i = errors.size() - 2; i >= 0; i--)
		{
			errors[i] = Layer(w[i].MSize(), w[i + 1].Transpose() * errors[i + 1].values);
		}
		// Update weights using Gradient descent formula
		for (int i = nodes.size() - 1; i > 0; i--)
		{
			w[i - 1] -= (errors[i - 1] * nodes[i]) * ((nodes[i] - 1) * nodes[i - 1]) * learn_coef;
		}
	}
	// Quering out neural network
	void Query(std::string filename) override
	{
		// Calculating hidden layer
		LayerCalc();
	}
	// Calculating layers
	void LayerCalc()
	{
		for (int i = 0; i < nodes.size() - 1; i++)
		{
			nodes[i + 1].values = Activation_F(w[i] * nodes[i].values);
		}
	}
	// Saving output values to the file
	void SaveOutput(std::string filename)
	{
		std::ofstream out(filename);
		// Writting output layer to the file
		for (int i = 0; i < nodes[nodes.size() - 1].size; i++)
		{
			out << nodes[nodes.size() - 1].values[i] << "\n";
		}
		out.close();
	}
	// Weights saving
	void SaveWeights(std::string filename)
	{
		std::ofstream out(filename);

		for (int k = 0; k < w.size(); k++)
		{
			for (int i = 0; i < w[k].NSize(); i++)
			{
				for (int j = 0; j < w[k].MSize(); j++)
				{
					// Writting matrixes to the file
					out << w[k].GetEl(i, j) << std::setw(10);
				}
				out << "\n";
			}
			out << "\n";
		}
		out.close();
	}
	// Show weights in console
	void ShowWeights()
	{
		for (int k = 0; k < w.size(); k++)
		{
			for (int i = 0; i < w[k].NSize(); i++)
			{
				for (int j = 0; j < w[k].MSize(); j++)
				{
					// Writting matrixes to the file
					std::cout << w[k].GetEl(i, j) << std::setw(10);
				}
				std::cout << "\n";
			}
			std::cout << "\n";
		}
	}
	// Show output values in console
	void ShowOutput()
	{
		for (int i = 0; i < nodes[nodes.size() - 1].size; i++)
		{
			std::cout << nodes[nodes.size() - 1].values[i] << "\n";
		}
	}
};