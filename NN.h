#include <vector>

typedef float Neurons;
typedef std::vector<Neurons> Layer;

// Class pour un DEEP FEED FORWARD NN
class NN {
private:
  Layer Inputs;
  Layer Hiddens;
  Layer Outputs;

public:
  // Constructeur pour 1 seul Hidden layer
  NN(int nbOfInputs, int nbOfHiddens, int nbOfOutputs);

  void afficher() const;
};