#pragma once

class Edge;

// getter for wait time, latitude, long, name
#include "edge.h"

class Node {
    public:
        Node();
        Node(int waitTime, double latitude, double longitude, std::string name);
        int getWaitTime();
        double getLatitude();
        double getLongitude();
        std::string getName();
    private:
        int waitTime;
        double latitude;
        double longitude;
        std::string name;
        std::vector<Edge*> edges; // this is the incident edges for the specific node
    
};