#pragma once

#include <vector>
#include <algorithm>
#include <string>

#include "graph.h"
#include "edge.h"

//skeleton of kruskal's header
class Kruskals {
    public:
        Kruskals(Graph * graph);
        void sortEdges();
        void makeDisjointSet(Graph * graph);
        std::vector<Edge*> traverse();

    private:
        Graph* graph_;
};