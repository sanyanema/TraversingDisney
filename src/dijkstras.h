#pragma once

#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <utility>
#include <map>
#include <functional>
#include <sstream>
#include <string>
#include <iostream>

#include "graph.h"
#include "edge.h"
#include "node.h"

class Dijkstras {
    public:
        //Constructor that creates a graph from the dataset of connected users
        //Dijkstras(std::vector<std::vector<std::string>> data);

        Dijkstras();

        //Returns a vector of edges that represents the shortest path from Vertex a to b
        std::vector<Node*> Dijkstras_Helper(Node* a, Graph* g);

        //Main Dijkstras function, condenses the helper functions
        std::vector<Node*> runDijkstras(std::string name, Node* a, Node* b);

        //Graph getter
        //Graph getGraph();

        std::vector<Node*> getActualPath();
    private:
        //Graph g_;
};