#pragma once
class NeuralNetwork
{
private:
	int in_nodes, h_nodes, o_nodes;
	double learn_coef;
public:
	NeuralNetwork();
	~NeuralNetwork();
	NeuralNetwork(int in_nodes, int h_nodes, int o_nodes)
	{
		this->in_nodes = in_nodes;
		this->h_nodes = h_nodes;
		this->o_nodes = o_nodes;
	}

	void SetLearnCoef(double learn_c)
	{
		this->learn_coef = learn_c;
	}
	void train() {}
	void query() {}
};

