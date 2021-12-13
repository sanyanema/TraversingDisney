#include "BFS.h"
#include <list>
#include <vector>
#include "node.h"
#include "edge.h"

using namespace std;

//skeleton of BFS graph traversal

BFS::BFS() {
    //Input: Gph, G
    //Output: A labeling of the edges on G as discovery and cross edges
}



/**

BFS::BFS(Graph & graph) {
    graph_ = graph;

    std::vector<bool> nodeExplore(fileRow);   //node_count_
    //bfs checks row by row
    std::vector<bool> t;
    std::vector<std::vector<bool>> edgeExploredList;


    sortEdges();
    ds_ = DisjointSets();
    ds_.makeDisjointSet(graph);
}


void BFS::bfsTraversal(std::string path) {
    int fileRow = 0; //number of rows in the data
    ifstream file(path);
    String line;
    while( getline(file, line) ) {
        fileRow++;
    }
    bool *visited = new bool[fileRow];
    for(int i = 0; i < fileRow; i++) {
        visited[i] = false;
    }
    //list<int>queue;
    list<int> queue;

    //marks the current nodes as visited and enqueue it
    visited[s] = true;
    queue.push_back(s);

    list<int>::iterator i;
    list<int> *adj = new list<int>[fileRow];
    for (pair<string, Node*> n1 : graph->getNodes()) 
        adj->push_back(n1.second->getAdjacentNodes());

    while(!queue.empty()) { //dequeue the value at when checking next ride
        s = queue.front();
        std::cout << s << " ";
        queue.pop_front();

    }

    for(int i = 0;i < fileRow; i++) {
        edgeExploredList.push_back(nodeRows);
    }
    //Nodes not explored yet
    for (int i=0; i < fileRow; i++) {
        if (!nodeExplore[i]) {
            bfsTraversal(edgeExploredList, nodeExplore, i); 
            //need a count for all connected components 
            //connected_components++; ?????
        }
    }
}

/**
foreach (Vertex v : G.vertices()):
        setLabel(v, UNEXPLORED)
    foreach (Edge e : G.edges()):
        setLabel(e, UNEXPLORED)
    foreach (Vertex v : G.vertices()):
        if getLabel(v) == UNEXPLORED:
            BFS(G, v)

BFS(G, v):
    Queue q
    setLabel(v, VISITED)
    q.enqueue(v)
    
    while !q.empty():
        v = q.dequeue()
        foreach (Vertex w : G.adjacent(v)):
            if getLabel(w) == UNEXPLORED:
                setLabel(v, w, DISCOVERY)
                setLabel(w, VISITED)
                q.enqueue(w)
            elseif getLabel(v, w) == UNEXPLORED:
                setLabel(v, w, CROSS)
*/