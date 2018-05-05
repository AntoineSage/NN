#include "Matrix.h"
#include <vector>

typedef double Neurons;
typedef Matrix Layer;
typedef Matrix Weight;
typedef Matrix Bias;

// Class pour un DEEP FEED FORWARD NN
class NN {
private:
  Layer Inputs;
  Layer Hiddens;
  Layer Outputs;

  Weight HiddenWeights;
  Weight OutputWeights;

  Bias HiddenBias;
  Bias OutputBias;

  int nbOfInputs;
  int nbOfHiddens;
  int nbOfOutputs;

public:
  NN(int _nbOfInputs, int _nbOfHiddens, int _nbOfOutputs);
  void afficher() const;

  void feedForward(std::vector< double > _Inputs);
};

double sigmoid(double x);