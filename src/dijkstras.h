#pragma once

#include <vector>
#include <algorithm>
#include <string>

#include "graph.h"
#include "edge.h"
#include "node.h"

class Dijkstras {
    public:
        //Constructor that creates a graph from the dataset of connected users
        //Dijkstras(std::vector<std::vector<std::string>> data);

        //Returns a vector of edges that represents the shortest path from Vertex a to b
        std::vector<Edge> Dijkstras_Helper(Node* a, Node* b);

        //Main Dijkstras function, condenses the helper functions
        std::vector<Edge> runDijkstras(std::vector<std::vector<std::string>> data, Node* a, Node* b);

        //Graph getter
        //Graph getGraph();

        std::vector<Node*> getActualPath();
    private:
        //Graph g_;
};