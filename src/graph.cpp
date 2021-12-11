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

            Node* n = new Node(s);
            graph->addNode(std::stod(wait_time), std::stod(latitude), std::stod(longitude), ride_name);
        }
    }

    for (Node* n1 : graph->getNodes()) {
        for (Node* n2 : graph->getNodes()) {
            if (n1 != n2) {
                // add edge
                graph->insertEdge(n1, n2, ); // calculate the distance
            } else {
                // self edge -- use wait time
                graph->insertEdge(n1, n2, std::stod(wait_time));
            }
        }
    }
}