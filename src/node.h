#pragma once

class Node{
    public:
        Node();
        Node(const Node& node);
        virtual ~Node();
    private:
        Node* next;
        int value;
};
