#include "graph.h"

Graph::Graph() {}

void Graph::addNode(double wait_time, double latitude, double longitude, std::string name) {

}

void Graph::addEdge(Node* first, Node* second, double edge_weight) {

}

bool Graph::isAdjacent(Node* first, Node* second) const {
    return false;
}

const std::vector<Node*> & getVertices() {
    static std::vector<Node*> placeholder;
    return placeholder;
}

Graph* Graph::readCSV(std::string filename) {
    Graph* graph = new Graph();

    std::ifstream infile(filename);
    std::string file_line;

    std::string ride_name, active_status, wait_time, status, longitude, latitude;

    if (infile.is_open()) {
        getline(infile, file_line);

        while (getline(infile, file_line)) {
            std::stringstream comma(file_line);

            getline(comma, ride_name, ',');
            getline(comma, active_status, ',');
            getline(comma, wait_time, ',');
            getline(comma, status, ',');
            getline(comma, longitude, ',');
            getline(comma, latitude, ',');

            //Node* n = new Node(s);
            graph->addNode(std::stod(wait_time), std::stod(latitude), std::stod(longitude), ride_name);
        }
    }

    // THERE'S A LINKER COMMAND ERROR HERE. 
    
    // for (Node* n1 : graph->getNodes()) {
    //     for (Node* n2 : graph->getNodes()) {
    //         if (n1 != n2) {
    //             // add edge
    //             graph->addEdge(n1, n2, 1.0); // calculate the distance
    //         } else {
    //             // self edge -- use wait time
    //             graph->addEdge(n1, n2, std::stod(wait_time));
    //         }
    //     }
    // }

    return graph;
}