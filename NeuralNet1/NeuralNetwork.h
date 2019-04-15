#pragma once
// MA FIRST AI PROJECT, DONT JUDGE HARD PLS

class NeuralNetwork
{
private:
	// in_nodes - input nodes, o_nodes - output nodes,
	// h_nodes - hidden layer nodes in out neural net.
	int in_nodes, h_nodes, o_nodes;
	// Learning coeficent
	double learn_coef;
public:
	NeuralNetwork() {}
	~NeuralNetwork() {}

	NeuralNetwork(int in_nodes, int h_nodes, int o_nodes)
	{
		this->in_nodes = in_nodes;
		this->h_nodes = h_nodes;
		this->o_nodes = o_nodes;
	}
	// Name of method says for himself i suppose
	void SetLearnCoef(double learn_c)
	{
		this->learn_coef = learn_c;
	}
	// Training neural net
	void Train() {}
	// Check neural net
	void Query() {}
};

