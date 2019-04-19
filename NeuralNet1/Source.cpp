#include "NeuralNetwork2.h"
#include "NetMatr.h"

int main()
{
	int in_nodes = 30,h_nodes = 100, out_nodes = 10;
	NeuralNetwork2 nn(in_nodes, h_nodes, out_nodes);
	nn.SetLearnCoef(0.3);
	
	system("pause");
	return 0;
}