//
// Created by ojcch on 4/19/2020.
//

#include "../../include/algorithms/DijkstraAlgorithm.h"
#include "../../include/graph/Graph.h"
#include "../../include/entity/Object.h"
#include <climits>

//constructor
DijkstraAlgorithm::DijkstraAlgorithm(Graph *pGraph) {
    graph = pGraph;
    this->dist = new unordered_map<int, double>();
    this->prev = new unordered_map<int, int>();
    this->unknown = new unordered_set<int>();
}

//destructor
DijkstraAlgorithm::~DijkstraAlgorithm() {
    delete (dist);
    delete (prev);
    delete unknown;
}

//runs the algorithm on source vertex (data) v
DijkstraOutput *DijkstraAlgorithm::findShortestPaths(Object *v) {
    initialize(graph->getVertex(v, false));
    Vertex *source = graph->getVertex(v, false);
    relaxOutGoingEdges(source);


    int size = graph->getVertices()->size();

    int i = 0;
    while (i < size-1) {

        source = findMinDistVertex();
        unknown->erase(source->getId());

        relaxOutGoingEdges(source);
        i++;
    }

    //relax edges of source
    //select minimum dist from dist that is not in known
    //remove vertex from unknown
    //relax edges of vertex
    //repeat

    return new DijkstraOutput(graph, new unordered_map<int, double>(*dist), new unordered_map<int, int>(*prev));
}


//performs the initialization step of the algorithm
void DijkstraAlgorithm::initialize(Vertex *pVertex) {

    //every time there is an initialization, start over
    delete dist;
    delete prev;
    delete unknown;
    this->dist = new unordered_map<int, double>();
    this->prev = new unordered_map<int, int>();
    this->unknown = new unordered_set<int>();

    this->dist->insert(make_pair(pVertex->getId(),0));
    this->prev->insert(make_pair(pVertex->getId(),pVertex->getId()));

    //initialize dist, prev, and unknown to have values
    unordered_map<int, Vertex *> * vertices = graph->getVertices();

    for (pair<int, Vertex *> vertex : *vertices) {
        if (vertex.second->getId() != pVertex->getId()) {
            dist->insert(make_pair(vertex.second->getId(),INT_MAX));
            prev->insert(make_pair(vertex.second->getId(),-1));
            unknown->insert(vertex.second->getId());
        }
    }
}

//finds the vertex with the minimum dist from the unknown vertices
Vertex *DijkstraAlgorithm::findMinDistVertex() {
    Vertex *next = nullptr;
    //...
    //int unknownSize = unknown->size();
    //int distSize = dist->size();


    for (const int & element: *unknown) {
        if (next == nullptr) {
            next = graph->getVertex(element);
        } else if (dist->find(next->getId())->second > dist->find(element)->second) {
            next = graph->getVertex(element);
        }
    }


    /*
    for (int j = 0; j < unknownSize; j++) {
        if (unknown->find(dist->find(j)->first) != unknown->end()) {
            if (next == nullptr || dist->find(next->getId())->second > dist->find(j)->second) {
                next = graph->getVertex(j);
            }
        }
    }
     */

    /*
    for (int j = 0; j < distSize; j++) {
        if (unknown->find(dist->find(j)->first) != unknown->end()) {
            if (next == nullptr || dist->find(next->getId())->second > dist->find(j)->second) {
                next = graph->getVertex(j);
            }
        }
    }
     */

    return next;
}

//relaxes the outgoing edges of v
void DijkstraAlgorithm::relaxOutGoingEdges(Vertex *v) {

    //...
    vector<Edge *>* edges = graph->getOutGoingEdges(v);
    Edge* next = nullptr;
    Vertex* vertex;
    Vertex* alt;
    for (Edge* edge : *edges) {
        // for each edge, add dist and prev
        if (edge->getSrc() != v) {
            vertex = edge->getSrc();
            alt = edge->getTarget();
        } else {
            vertex = edge->getTarget();
            alt = edge->getSrc();
        }

        if (this->dist->find(vertex->getId()) == this->dist->end()) {
            this->dist->erase(vertex->getId());
            this->dist->insert(make_pair(vertex->getId(),edge->getWeight()));
            this->prev->erase(vertex->getId());
            this->prev->insert(make_pair(vertex->getId(),v->getId()));
        } else if (this->dist->find(vertex->getId())->second > edge->getWeight() + dist->find(alt->getId())->second) {
            this->dist->erase(vertex->getId());
            this->dist->insert(make_pair(vertex->getId(),edge->getWeight() + dist->find(alt->getId())->second));
            this->prev->erase(vertex->getId());
            this->prev->insert(make_pair(vertex->getId(),alt->getId()));
        }
    }
}