#include "node.h";

Node::Node(){
    next = NULL;
}

Node::Node(const Node& node){
    next = node.next;
}

Node::~Node(){

}