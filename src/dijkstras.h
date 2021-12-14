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

        Dijkstras(Graph* graph);

        //Returns a vector of edges that represents the shortest path from Vertex a to b
        std::vector<Node*> Dijkstras_Helper(Node* a);

        std::vector<Node*> generateTXT(std::unordered_map<Node*, double> dist, std::string outfilename);
    private:
        Graph* graph;
};