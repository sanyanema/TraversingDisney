#include "kruskals.h"

Kruskals::Kruskals(Graph * graph) {
    graph_ = graph;

    sortEdges();
    // ds_ = DisjointSets();
    // ds_.makeDisjointSet(graph);
}


void Kruskals::sortEdges() {
    // std::sort(graph_.edges_.begin(),graph_.edges_.end(),
    // [] (const Edge& lhs, const Edge& rhs)
    // {
    //     return lhs.length_ < rhs.length_;
    // });
}