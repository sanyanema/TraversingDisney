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
void BFS::bfsTraversal(std::string path, Graph * graph) {
    int s = 0;     
    int fileRow = 0;
    std::ifstream file(path);
    std::string line;
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
    for (i = adj[s].begin(); i !=adj[s].end(); ++i) {
        if (!visited[*i]) {
            visited[*i] = true;
            queue.push_back(*i);
        }
    }

}


/**
    std::vector<bool> nodeExplore(fileRow);   //node_count_
    //bfs checks row by row
    std::vector<bool> t;
    std::vector<std::vector<bool>> edgeExploredList;
    nodeRows(fileRow);

    // for(int i = 0;i < fileRow; i++) {
    //     //edgeExploredList.push_back(nodeRows);
    // }
    // //Nodes not explored yet
    // for (int i=0; i < fileRow; i++) {
    //     if (!nodeExplore[i]) {
    //         bfsTraversal(edgeExploredList, nodeExplore, i);
    //         //need a count for all connected components 
    //         //connected_components++; ?????
    //     }
    // }
}
void BFS::bfsTraversal(std::vector<std::vector<bool>> &edgeExploredList, std::vector<bool> &nodeExplore, int Node) {
    // std::queue<int> q;
    // nodeExplore[Node] = true; //vertex
    // bfsVertexList.push_back(Node);
    // q.push(Node); //(vertex)

    // //^above don't necessarily know what should be inside the () and []

    // while (!q.empty()) {
    //     int frontNode = q.front();
    //     q.pop();
    //     for(int col = 0; col < fileRow; col++) {
    //         if (adjList[frontNode][col]) {  //adj_list_ dont know what to call in this
    //             if(!nodeExplore[col]) { //geekforgeek if(!visited[*i])
    //                 edgeExploredList[frontNode][col] = true;
    //                 bfsEdgeList.pushback(std::pair<int, int>(frontNode, col));
    //                 nodeExplore[col] = true;    //geekforgeek
    //                 bfsVertexList.push_back(col);
    //                 //queue.push_back(*i)
    //                 q.push(col);
    //             } else if (!edgeExploredList[frontNode][col]) {
    //                 edgeExploredList[frontNode][col] = true;
    //                 bfsEdgeList.pushback(std::pair<int, int>(frontNode, col));
    //             }
    //         }
    //     }
    // }
}

*/

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
