#include "NN.h"
#include <iostream>

using namespace std;

// Constructeur pour 1 seul Hidden layer
NN::NN(int nbOfInputs, int nbOfHiddens, int nbOfOutputs) {
  Inputs.push_back(0);
}

void NN::afficher() const {
  cout << "Ce réseau neuronal est composé de : " << endl;
  cout << "\t" << Inputs.size() << " Neurones d'Input" << endl;
  cout << "\t" << Hiddens.size() << " Neurones Hidden " << endl;
  cout << "\t" << Outputs.size() << " Neurones d'Output" << endl;
}
