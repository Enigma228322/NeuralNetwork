#include "NeuralNetwork.h"
#include "NetMatr.h"

int main()
{
	int h_nodes = 3, in_nodes = 3, out_nodes = 3;
	NeuralNetwork nn(in_nodes, h_nodes, out_nodes);
	nn.SetLearnCoef(0.3);


	system("pause");
	return 0;
}