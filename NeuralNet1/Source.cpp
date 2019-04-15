#include "NeuralNetwork.h"
#include "NetMatr.h"

int main()
{
	NeuralNetwork nn(3, 3, 3);
	nn.SetLearnCoef(0.3);

	NetMatr m(3, 3, 0, 1);
	m.Show();
	system("pause");
	return 0;
}