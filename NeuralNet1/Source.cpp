#include "NeuralNetwork2.h"
#include "NetMatr.h"
#include <conio.h>

#define NODES "Nodes.txt"
#define INPUT "input_layer.txt"
#define TARGETS "targets.txt"
#define OUTPUT "output_layer.txt"
#define WEIGHTS "weights.txt"


int main()
{
	std::srand(unsigned(time(NULL)));
	// Write nums of nodes in file: "Nodes.txt"
	// It should be like: 10 20 10 30 20 2
	// First - input nums, last - output nums
	NeuralNetwork2 nn(NODES);
	nn.SetLearnCoef(10);
	// Write input values of nodes in file: "input_layer.txt"
	// Number of values should be equal to first num in "Nodes.txt"
	nn.Input(INPUT);
	// Write nums of targets in file: "targets.txt"
	// Number of values should be equal to last num in "Nodes.txt"
	// or nodes in output layer
	nn.Targets(TARGETS);
	nn.SyncWeights(WEIGHTS);

	/*nn.Query(OUTPUT);
	nn.ShowOutput();*/
	
	for (int i = 0; i < 1000; i++)
	{
		nn.Train();
	}

	nn.ShowOutput();
	nn.SaveWeights(WEIGHTS);
	nn.SaveOutput(OUTPUT);
	system("pause");
	return 0;
}