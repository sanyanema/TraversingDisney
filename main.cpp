#include <iostream>

#include "src/graph.h"
#include "src/edge.h"
#include "src/node.h"

int main() {
    Graph* graph = Graph::readCSV("data/disney_data.csv");
    graph->printNodes();
}