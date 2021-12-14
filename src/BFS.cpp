#include "BFS.h"
#include <list>
#include <vector>
#include "node.h"
#include "edge.h"

using namespace std;

BFS::BFS() {

}
void BFS::bfsTraversal(Graph * graph, Node* node) {

    Node* start_node = graph->getNode(node->getName());
    unordered_map<string, Node*> map = graph->getNodes();

    std::vector<Node*> nodes;

    for (std::pair<std::string, Node*> node : map) {
        nodes.push_back(node.second);
    }

    //bool *visited = new bool[nodes.size()];

    unordered_map<Node*, bool> visited;

    for(unsigned i = 0; i < nodes.size(); i++) {
        visited[nodes[i]] = false;
    }

    //list<int>queue;
    queue<Node*> queue;

    //marks the current nodes as visited and enqueue it
    visited[start_node] = true;
    queue.push(start_node);

    list<int>::iterator i;

    std::vector<Node*> nodes_traversed;

    while(!queue.empty()) { //dequeue the value at when checking next ride
        start_node = queue.front();
        std::vector<Node*> adj = start_node->getAdjacentNodes();

        queue.pop();
        for (Node* node : adj) {
            if (visited[node] == false) {
                visited[node] = true;
                queue.push(node);
                nodes_traversed.push_back(node);
            }
        }
       
    }

    generateTXT(nodes_traversed, "bfs_output.txt");
    

}

void BFS::generateTXT(vector<Node*> nodes_traversed, string outfilename) {
    std::ofstream outfile;
    outfile.open(outfilename);

    for (Node * node : nodes_traversed) {
        outfile << "Name of Ride \t" << node->getName() << "->" << std::endl;
    }

}
