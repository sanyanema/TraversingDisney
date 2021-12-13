#include "BFS.h"

//skeleton of BFS graph traversal

BFS::BFS() {
    //Input: Graph, G
    //Output: A labeling of the edges on G as discovery and cross edges

}

BFS::BFS(const Graph& other) {
    _copy(other);
}

void BFS::bfsTraversal(std::string path) {
    int fileRow = 0; //number of rows in the data
    ifstream file(path);
    String line;
    while( getline(file, line) ) {
        fileRow++
    }
    vector<bool> nodeExplore(fileRow);   //node_count_
    //bfs checks row by row
    vector<bool> t;
    vector<vector<bool>> edgeExploredList
    nodeRows(fileRow);

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
void BFS::bfsTraversal(vector<vector<bool>> &edgeExploredList, vector<bool> &nodeExplore, int Node) {
    queue<int> q;
    nodeExplore[Node] = true; //vertex
    bfsVertexList.push_back(Node);
    q.push(Node); //(vertex)

    //^above don't necessarily know what should be inside the () and []

    while (!q.empty()) {
        int frontNode = q.front();
        q.pop();
        for(int col = 0; col < fileRow; col++) {
            if (adjList[frontNode][col]) {  //adj_list_ dont know what to call in this
                if(!nodeExplore[col]) {
                    edgeExploredList[frontNode][col] = true;
                    bfsEdgeList.pushback(std::pair<int, int>(frontNode, col));
                    nodeExplore[col] = true;
                    bfsVertexList.push_back(col);
                    q.push(col);
                } else if (!edgeExploredList[frontNode][col]) {
                    edgeExploredList[frontNode][col] = true;
                    bfsEdgeList.pushback(std::pair<int, int>(frontNode, col));
                }
            }
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