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
    private:
        Graph* graph_;
};