#include "NN.h"
#include <iostream>
#include <math.h>

using namespace std;

// Constructeur pour 1 seul Hidden layer
NN::NN(int _nbOfInputs, int _nbOfHiddens, int _nbOfOutputs) {
  nbOfInputs = _nbOfInputs;
  nbOfHiddens = _nbOfHiddens;
  nbOfOutputs = _nbOfOutputs;

  Inputs.init(_nbOfInputs, 1);
  Hiddens.init(_nbOfHiddens, 1);
  Outputs.init(_nbOfOutputs, 1);

  HiddenWeights.init(nbOfHiddens, nbOfInputs, true);
  OutputWeights.init(nbOfOutputs, nbOfHiddens, true);

  HiddenBias.init(nbOfHiddens, 1, true);
  OutputBias.init(nbOfOutputs, 1, true);
}

void NN::afficher() const {
  cout << "Ce reseau neuronal est compose de : " << endl;
  cout << "\t" << nbOfInputs << " Neurones d'Input" << endl;
  cout << "\t" << nbOfHiddens << " Neurones Hidden " << endl;
  cout << "\t" << nbOfOutputs << " Neurones d'Output" << endl;
  cout << "Inputs :" << endl;
  Inputs.afficher();
  cout << "Hiddens :" << endl;
  Hiddens.afficher();
  cout << "Outputs :" << endl;
  Outputs.afficher();
  cout << "HiddenWeights :" << endl;
  HiddenWeights.afficher();
  cout << "OutputWeights :" << endl;
  OutputWeights.afficher();
  cout << "HiddenBiases :" << endl;
  HiddenBias.afficher();
  cout << "OutputBiases :" << endl;
  OutputBias.afficher();
}

void NN::feedForward(std::vector< double > _Inputs) {
  Inputs = _Inputs;
  Inputs.map(sigmoid);
  Hiddens = Inputs * HiddenWeights + HiddenBias;
  Hiddens.map(sigmoid);
  Outputs = Hiddens * OutputWeights + OutputBias;
  Outputs.map(sigmoid);
}

double sigmoid(double x) { return 1.0 / (1.0 + exp(-x)); }
