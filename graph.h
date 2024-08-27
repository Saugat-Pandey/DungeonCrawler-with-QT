

/*
#include <iostream>
#include <limits>
#include <queue>
#include <vector>
#include <string>

struct Node{
    std::pair<int,int> Position;
    int color = 0;
    int distance = std::numeric_limits<int>::max();
    Node *parent = nullptr;
};

struct Edge{
    Node* from;
    Node* to;
    double weight =1;
};

class Graph{
private:
    std::vector<Node> m_nodes;
    std::vector<Edge> m_edges;

    Node* getNodePointer(std::pair<int,int> pos);
    std::vector<Node*> getConnectedNodes(Node *node);
    double getDist(Node *from, Node *to);
public:
    Graph();
    ~Graph()=default;

    void addNode(int row, int col);
    void addEdge(int from_r, int from_c, int to_r, int to_c);
    void clearEdges();
    bool hasNode(int row, int col);
    bool isConnected(int from_r, int from_c, int to_r, int to_c);

    std::vector<Node> breadthFirstSearch(std::pair<int,int> from);
    std::vector<Node> nodes() const;
};*/
#ifndef GRAPH_H
#define GRAPH_H

#include <limits>
#include <queue>
#include <vector>
#include <iostream>

struct Node{
    std::pair<int, int> position;
    int color = 0;
    int distance = std::numeric_limits<int>::max();
    Node* parent = nullptr;
};

struct Kante {
    Node* start_pos;
    Node* end_pos;
    double gewicht = 1;
};

class Graph {
private:
    std::vector<Node> nodes;
    std::vector<Kante> kanten;

    Node* searchNode(const std::pair<int, int>& pos);
    std::vector<Node*> getAdjacentNodes(Node* node);
    double getKantenGewicht(Node* startnode, Node* endnode);
public:
    Graph();
    ~Graph() = default;

    void addNode(int row, int col);
    void addKante(int from_row, int from_col, int to_row, int to_col);
    bool isNodepresent(int row, int col);
    bool areConnected(int from_row, int from_col, int to_row, int to_col);
    void clearKanten();


    std::vector<Node> bfsTraversal(const std::pair<int, int>& start);
    std::vector<Node> getNodes() const;
};



#endif // GRAPH_H
