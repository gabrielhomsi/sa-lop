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

    edges.resize(n + 1);

    for (unsigned int i = 1; i < edges.size(); i++) {
        edges[i].resize(edges.size());
    }

    for (unsigned int i = 1; i < edges.size(); i++) {
        for (unsigned int j = 1; j < edges[i].size(); j++) {
            instance_file >> edges[i][j];
        }
    }
}
