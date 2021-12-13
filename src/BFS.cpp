#include "BFS.h"

#include <queue>
#include <vector>


//skeleton of BFS graph traversal

void BFS::BFS() {
    //Input: Graph, G
    //Output: A labeling of the edges on G as discovery and cross edges
}
void BFS::BFS(const Graph& other) {
    _copy(other);
}
void BFS:bfsTraversal() {
    vector<bool> nodeExplore(nodeCount);
    //bfs checks row by row
    vector<bool> t;
    vector<vector<bool>> edgeExploredList
    nodeRows(nodeCount);

    for(int i = 0;i < nodeCount; i++) {
        edgeExploredList.push_back(nodeRows);
    }
    //Nodes not explored yet
    for (int i=0; i < nodeCount; i++) {
        if (!nodeExplore[i]) {
            bfsTraversal(edgeExploredList, nodeExplore, i);
            //need a count for all connected components 
            //connected_components++; ?????
        }
    }
}
void Graph::bfsTraversal() {
    queue<int> q;
    nodeExplore[Node*] = true; //vertex
    bfsVertexList.push_back(Node*);
    q.push(Node*); //(vertex)

    while (!q.empty()) {
        int frontNode = q.front();
        q.pop();

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