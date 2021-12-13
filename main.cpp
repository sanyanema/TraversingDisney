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


    // BFS Algorithm
    //BFS * bfs = new BFS();
    //bfs.bfsTraversal("data/disney_data.csv");
    // Need to save this output into a .txt file

    // Djikstra's Algorithm
    //Dijkstras dji;
    //Prince Charming Regal Carrousel,TRUE,5,Operating,-81.581255,28.420169

    Node* node = new Node(5, -81.581255, 28.420169, "Prince Charming Regal Carrousel");
    //dji.Dijkstras_Helper(node, graph);

    // Kruskal's Algorithm
    Kruskals krus;
    //krus.runKruskals();


















    delete graph;
}