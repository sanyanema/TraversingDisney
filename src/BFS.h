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
        BFS(const Graph& other);
        void bfsTraversal(std::string path); 
        void bfsTraversal(vector<vector<bool>> &edgeExploredList, vector<bool> &nodeExplore, int vertex);
    private:
        // possibly make a variable for explored nodes
        
};

