#include <iostream>
#include <string>
#include <fstream>
#include "Graph.h"

using namespace std;

Graph::Graph() {
    this->parameters = Parameters::getInstance();
}

void Graph::read() {
    ifstream instance_file(parameters.vm["instance"].as<string>());

    unsigned int n;

    instance_file >> n;

    edges.resize(n);

    for (unsigned int i = 0; i < edges.size(); i++) {
        edges[i].resize(edges.size());
    }

    for (unsigned int i = 0; i < edges.size(); i++) {
        for (unsigned int j = 0; j < edges[i].size(); j++) {
            instance_file >> edges[i][j];
        }
    }
}
