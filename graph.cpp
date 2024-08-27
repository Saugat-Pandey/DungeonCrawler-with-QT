/*#include "graph.h"


Graph::Graph()
{

}

void Graph::addNode(int row, int col)
{
    if (!hasNode(row, col)) {
        m_nodes.push_back({std::make_pair(row, col)});
    }
}

void Graph::addEdge(int from_r, int from_c, int to_r, int to_c)
{
    if (isConnected(from_r, from_c, to_r, to_c)) {
        return;
    }

    auto fromPointer = getNodePointer(std::make_pair(from_r,from_c));
    if (fromPointer == nullptr) {
        return;
    }

    auto toPointer = getNodePointer(std::make_pair(to_r, to_c));
    if (toPointer == nullptr) {
        return;
    }
    Edge newEdge;
    newEdge.from = fromPointer;
    newEdge.to = toPointer;
    newEdge.weight = 1;
    m_edges.push_back(newEdge);
}

void Graph::clearEdges()
{
    m_edges.clear();
}

bool Graph::hasNode(int row, int col)
{
    for (const auto &node : m_nodes) {
        if (node.Position.first == row && node.Position.second == col) {
            return true;
        }
    }
    return false;
}

bool Graph::isConnected(int from_r, int from_c, int to_r, int to_c)
{
    auto fromPointer = getNodePointer(std::make_pair(from_r,from_c));
    if (fromPointer == nullptr) {
        return false;
    }

    auto toPointer = getNodePointer(std::make_pair(to_r, to_c));
    if (toPointer == nullptr) {
        return false;
    }
    for (const auto &edge : m_edges) {
        if (edge.from == fromPointer && edge.to == toPointer) {
            return true;
        }
    }
    return false;

}

double Graph::getDist(Node *from, Node *to) {
    for (const auto &edge : m_edges) {
        if (edge.from == from && edge.to == to) {
            return edge.weight;
        }
    }
    return 0;
}


std::vector<Node> Graph::breadthFirstSearch(std::pair<int, int> from)
{
    Node* start =getNodePointer(from);
    for (auto &node : m_nodes) {
        node.color = 0;
        node.distance = std::numeric_limits<int>::max();
        node.parent = nullptr;
    }
    start->color = 1;
    start->distance = 0;
    start->parent = nullptr;

    std::queue<Node *> q;
    q.push(start);
    while (!q.empty()) {
        auto *u = q.front();
        q.pop();
        auto nearMe = getConnectedNodes(u);
        for (auto &v : nearMe) {
            if (v->color == 0) {
                v->color = 1;
                v->distance = u->distance + getDist(u, v);
                v->parent = u;
                q.push(v);
            }
        }
        u->color = 2;
    }
    for (auto &node : m_nodes) {
        std::cout << node.Position.first << "/"<< node.Position.second << " -> " << node.distance << std::endl;
    }
    std::cout << "-----------------------------------------------------------" << std::endl;
    return nodes();
}

std::vector<Node> Graph::nodes() const
{
    return m_nodes;
}

Node *Graph::getNodePointer(std::pair<int,int> pos) {
    for (auto &node : m_nodes) {
        if (node.Position.first == pos.first && node.Position.second == pos.second) {
            return &node;
        }
    }
    return nullptr;
}

std::vector<Node *> Graph::getConnectedNodes(Node *node)
{
    std::vector<Node*> tmp;
    for (auto &n : m_nodes) {
        if (isConnected(node->Position.first, node->Position.second , n.Position.first, n.Position.second)) {
            tmp.push_back(&n);
        }
    }
    return tmp;
}

*/
#include "graph.h"

Graph::Graph() {}

void Graph::addNode(int row, int col) {
    if (!isNodepresent(row, col)) {
        nodes.push_back({std::make_pair(row, col)});
    }
}

void Graph::addKante(int from_row, int from_col, int to_row, int to_col) {
    if (areConnected(from_row, from_col, to_row, to_col)) {
        return;
    }

    auto fromNode = searchNode(std::make_pair(from_row, from_col));
    auto toNode = searchNode(std::make_pair(to_row, to_col));

    if (!fromNode || !toNode) {
        return;
    }

    Kante newEdge;
    newEdge.gewicht = 1;
    newEdge.start_pos = fromNode;
    newEdge.end_pos = toNode;
    kanten.push_back(newEdge);
}

void Graph::clearKanten() {
    kanten.clear();
}

bool Graph::isNodepresent(int row, int col) {
    for (const auto& node : nodes) {
        if (node.position.first == row && node.position.second == col) {
            return true;
        }
    }
    return false;
}

bool Graph::areConnected(int from_row, int from_col, int to_row, int to_col) {
    auto startNode = searchNode(std::make_pair(from_row, from_col));
    auto endNode = searchNode(std::make_pair(to_row, to_col));

    if (!startNode || !endNode) {
        return false;
    }

    for (const auto& edge : kanten) {
        if (edge.start_pos == startNode && edge.end_pos == endNode) {
            return true;
        }
    }
    return false;
}
std::vector<Node> Graph::getNodes() const
{
    return nodes;
}

double Graph::getKantenGewicht(Node* startnode, Node* endnode) {
    for (const auto& edge : kanten) {
        if (edge.start_pos == startnode && edge.end_pos == endnode) {
            return edge.gewicht;
        }
    }
    return 0;
}
Node* Graph::searchNode(const std::pair<int, int>& pos) {
    for (auto& n1 : nodes) {
        if (n1.position == pos) {
            return &n1;
        }
    }
    return nullptr;
}

std::vector<Node*> Graph::getAdjacentNodes(Node* node) {
    std::vector<Node*> adjacent;
    for (auto& n : nodes) {
        if (areConnected(node->position.first, node->position.second, n.position.first, n.position.second)) {
            adjacent.push_back(&n);
        }
    }
    return adjacent;
}

std::vector<Node> Graph::bfsTraversal(const std::pair<int, int>& start) {
    Node* startNode = searchNode(start);

    for (auto& n1 : nodes) {
        n1.color = 0;
        n1.distance = std::numeric_limits<int>::max();
        n1.parent = nullptr;
    }

    if (startNode) {
        startNode->color = 1;
        startNode->distance = 0;
        startNode->parent = nullptr;

        std::queue<Node*> qe;
        qe.push(startNode);

        while (!qe.empty()) {
            auto* firstelement = qe.front();
            qe.pop();

            auto adjacentNodes = getAdjacentNodes(firstelement);
            for (auto& v : adjacentNodes) {
                if (v->color == 0) {
                    v->color = 1;
                    v->distance = firstelement->distance + getKantenGewicht(firstelement, v);
                    v->parent = firstelement;
                    qe.push(v);
                }
            }
            firstelement->color = 2;
        }
    }


    return nodes;
}

