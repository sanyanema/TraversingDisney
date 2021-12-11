#pragma once

class Edge;

// getter for wait time, latitude, long, name
#include <string>
#include <vector>
#include "edge.h"

class Node {
    public:
        Node();
        Node(int wait_time, double latitude, double longitude, std::string name);
        int getWaitTime();
        double getLatitude();
        double getLongitude();
        std::string getName();
    private:
        int wait_time_;
        double latitude_;
        double longitude_;
        std::string name_;
        std::vector<Edge*> edges_; // this is the incident edges for the specific node
    
};