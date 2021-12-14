#include <iostream>

#include "src/graph.h"
#include "src/edge.h"
#include "src/node.h"
#include "src/BFS.h"
#include "src/dijkstras.h"
#include "src/kruskals.h"

int main() {
    Graph* graph = Graph::readCSV("data/disney_data.csv");
    graph->printNodes();

    Node* node = new Node(5, -81.581255, 28.420169, "Prince Charming Regal Carrousel");


    // BFS Algorithm
    BFS bfs;
    bfs.bfsTraversal(graph, node);
    
    // Need to save this output into a .txt file

    // Djikstra's Algorithm
    Dijkstras dji(graph);

    //Node* node = new Node(5, -81.581255, 28.420169, "Prince Charming Regal Carrousel");
    dji.Dijkstras_Helper(node);

    // std::ofstream outfile;
    // outfile.open("djikstras_output.txt");

    // Kruskal's Algorithm
    Kruskals krus(graph);
    //krus.runKruskals();


















    delete graph;
}