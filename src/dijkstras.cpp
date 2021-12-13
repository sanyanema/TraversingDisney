#include "dijkstras.h"

Dijkstras::Dijkstras(Graph* g) {
    graph = g;
}

std::vector<Node*> Dijkstras::Dijkstras_Helper(Node* a) {
    //Definitions
    const int INF = INT_MAX;
    double distance;
    std::pair<double, Node*> pair;

    Node* node = graph->getNode(a->getName());

    std::cout << node->getName();

    //Initializes map of distance for each vertex, all distances set to infinity at start
    std::unordered_map<std::string, Node*> map = graph->getNodes();
    std::vector<Node*> nodes;

    for (std::pair<std::string, Node*> node : map) {
        nodes.push_back(node.second);
        //std::cout << node.second->getName() << std::endl;
    }
   
    std::unordered_map<Node*, double> dist; // this is a dist array that specifically maps from a Node to its distance from Node A

    for (unsigned v = 0; v < nodes.size(); ++v) {
        // Finds the node to set the distance of, which is nodes[v]
        dist[nodes[v]] = INF; // setting the distance to all the nodes in the dist array to be INF because haven't been set yet
    }

    dist[node] = 0; // a is the starting node, so dist from a to a is 0

    //Initialize a map that maps current node to its previous node.
    //std::unordered_map<Node*, Node*> prev;

    //Initialize priority queue (min-heap), with source vertex's distance = 0
    std::priority_queue<std::pair<double, Node*>, std::vector<std::pair<double, Node*>>, std::greater<std::pair<double, Node*>>> pq;
    pq.push(std::make_pair(0, a));

    //Initialize unordered map of visited/unvisited nodes
    std::unordered_map<Node*, bool> visited;
    for (unsigned v = 0; v < nodes.size(); ++v) {
        visited[nodes[v]] = false;
    }

    // Loops through the priority queue until it is empty. 
    while (!pq.empty()) {
        //std::cout << "dist[i].second" << std::endl;
        //Node* current = pq.top().second; // to access the Node of the pair
        Node* curr = graph->getNode(pq.top().second->getName());
        //std::cout << curr->getName() << std::endl;
        pq.pop(); // after accessing, pop this value

        // Get access to only the adjacent nodes of this particular node, since
        // we are only concerned with what is directly adjacent.
        std::vector<Node*> adjacent_nodes = curr->getAdjacentNodes();
        //std::cout << adjacent_nodes.size() << std::endl;

        for (unsigned v = 0; v < adjacent_nodes.size(); ++v) {
            if (visited[adjacent_nodes[v]]) { // this means it has already been visited, distance has been decided
                
                continue;
            }
            else {
                Node* adjacent = adjacent_nodes[v];
                //std::cout << adjacent->getName();
                Edge* edge = new Edge(adjacent, curr);
                double edge_weight = edge->getEdgeWeight(); // get edge between current and adjacent
                //std::cout << edge_weight << std::endl;
                if (dist[adjacent] > dist[curr] + edge_weight) { // changed to <
                    std::cout << "hello";
                    dist[adjacent] = dist[curr] + edge_weight;
                    pq.push(std::make_pair(dist[adjacent], adjacent));
                }
            }
        }
        visited[curr] = true;
    }

    //Extracts shortest path from previous map
    std::vector<Node*> path;

    // double weight = 0;

    // for (curr = b; curr != a; curr = prev[curr]) {
    //     weight = g_.getEdgeWeight(prev[curr], curr);
    //     std::vector<Edge>::iterator it = path.begin();
    //     it = path.insert(it, Edge(prev[curr], curr, weight, prev[curr] + "-" + curr));
    // }
    
    // for (unsigned i = 0; i < dist.size(); i++) {
    //     std::cout << dist[i].second << std::endl;
    // }

    for (std::pair<Node*, double> node : dist) {
        std::cout << "\"";
        std::cout << node.first->getName() << std::endl << node.second << std::endl;
    }

    return path;
}

std::vector<Node*> Dijkstras::runDijkstras(std::string name, Node* a, Node* b) {
    //Dijkstras dijkstras = Dijkstras(data);
    int fileRow = 0; //number of rows in the data
    std::ifstream file(name);
    std::string line;
    // while( getline(name, line) ) {
    //     fileRow++;
    // }

    //return dijkstras.Dijkstras_Helper(a, b);
    std::vector<Node*> nodes;
    return nodes;
}

// Graph Dijkstras::getGraph() {
//     return g_;
// }

std::vector<Node*> Dijkstras::getActualPath() {
    // To print it out nicely for the .txt file.
    std::cout << "Node \t \t Distance from Starting Node" << std::endl;
    std::cout << "Node Name" << "\t \t \t" << "<Distance Goes Here>" << std::endl;
    std::vector<Node*> nodes;
    return nodes;
}