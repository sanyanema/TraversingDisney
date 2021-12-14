#pragma once

#include <iostream>
#include <vector>
#include <queue>
#include <map>

#include "graph.h"
#include "edge.h"

//skeleton of BFS header file

class BFS {
    public:
        BFS();
        BFS(Graph & graph);
        void bfsTraversal(Graph * graph, Node* node); 
        void generateTXT(std::vector<Node*> nodes, std::string outfilename);
    private:
        // possibly make a variable for explored nodes
        
};

