#include "graph.h"

Graph* readCSV(std::string filename) {
    Graph* graph = new Graph();

    std::ifstream infile(filename);
    std::string file_line;

    std::string ride_name, active_status, wait_time, status, longitude, latitude;

    if (infile.is_open()) {
        getline(infile, file_line);

        while (getline(infile, file_line)) {
            std::stringstream comma(line);

            getline(comma, ride_name, ',');
            getline(comma, active_status, ',');
            getline(comma, wait_time, ',');
            getline(comma, status, ',');
            getline(comma, longitude, ',');
            getline(comma, latitude, ',');

            Node* n = new Node(ride_name, ...)
            graph->addNode(n);
        }
    }

    for (Node* n1 : graph->getNodes()) {
        for (Node* n2 : graph->getNodes()) {
            if (n1 != n2) {
                // add edge
            } else {
                // self edge -- use wait time
            }
        }
    }
}