//
// Created by ojcch on 4/24/2020.
//

#include <iomanip>
#include "../../include/algorithms/DijkstraOutput.h"
#include "../../include/graph/Graph.h"

//constructor
DijkstraOutput::DijkstraOutput(Graph *graph, unordered_map<int, double> *dist, unordered_map<int, int> *prev) {
    this->graph = graph;
    this->dist = dist;
    this->prev = prev;
}

//prints this output
void DijkstraOutput::print() {
    //....
    std::cout << "dist[]: ";
    for (auto iter = dist->begin(); iter != dist->end(); ++iter) {
        if (iter == dist->begin()) {
            std::cout << "{" << graph->getVertex(iter->first)->toString() << " -> " << fixed << setprecision(2) << iter->second << "}";
        } else {
            std::cout << ", {" << graph->getVertex(iter->first)->toString() << " -> " << fixed << setprecision(2) << iter->second << "}";
        }
    }

    std::cout << "\nprev[]: ";
    for (auto iter = prev->begin(); iter != prev->end(); ++iter) {
        if (iter == prev->begin()) {
            std::cout << "{" << graph->getVertex(iter->first)->toString() << " -> " << graph->getVertex(iter->second)->toString() << "}";
        } else {
            std::cout << ", {" << graph->getVertex(iter->first)->toString() << " -> " << graph->getVertex(iter->second)->toString() << "}";
        }
    }
}

//prints the shortest path from the source vertex to targetObj
void DijkstraOutput::printShortestPath(Object *targetObj) {
   //....
   graph->getVertex(targetObj,false)->getId();
   //starting with the target object, check its previous element
   //then repeat until the corresponding distance to the element
   //is 0
   //Vs -> V2 -> … -> Vt, Total cost: dist[Vt]
   Vertex* source = graph->getVertex(targetObj,false);
   string output = source->toString() + ", Total cost: ";
   double total = dist->find(source->getId())->second;
   while (dist->find(source->getId())->second != 0) {
       source = graph->getVertex(prev->find(source->getId())->second);
       output = source->toString() + " -> " + output;
   }
   std::cout << output << fixed << setprecision(2) << total;
           //targetObj->toString();

}

//destructor
DijkstraOutput::~DijkstraOutput() {
    delete (dist);
    delete (prev);
}
