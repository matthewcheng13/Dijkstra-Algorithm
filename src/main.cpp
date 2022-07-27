#include <iostream>
#include "../include/graph/Vertex.h"
#include "../include/graph/Graph.h"
#include "../include/entity/City.h"
#include "../include/entity/StringElement.h"
#include "../include/algorithms/DijkstraAlgorithm.h"

void buildGraphOfCities();

void buildCitiesQ4();

void buildGraphOfStringElements();

void buildStringElementsQ4();

void runDijkstraAlgorithm(Graph *graph, Object *sourceObj, Object *targetObj);

int main() {
    //buildGraphOfStringElements();
    buildStringElementsQ4();
    cout << "\n\n-------------------------------------" << endl;
    buildCitiesQ4();
    //buildGraphOfCities();
    return 0;
}

void buildStringElementsQ4() {

    Object *A = new StringElement("A");
    Object *B = new StringElement("B");
    Object *C = new StringElement("C");
    Object *D = new StringElement("D");
    Object *E = new StringElement("E");
    Object *F = new StringElement("F");
    Object *G = new StringElement("G");
    Object *H = new StringElement("H");
    Object *I = new StringElement("I");
    Object *J = new StringElement("J");

    auto *undirectedGraph = new Graph(true);
    undirectedGraph->addEdge(A, D, 9);
    undirectedGraph->addEdge(A, C, 12);
    undirectedGraph->addEdge(A, B, 20);
    undirectedGraph->addEdge(C, D, 3);
    undirectedGraph->addEdge(B,C,11);
    undirectedGraph->addEdge(B,E,13);
    undirectedGraph->addEdge(C,E,4);
    undirectedGraph->addEdge(D,F,10);
    undirectedGraph->addEdge(C,G,17);
    undirectedGraph->addEdge(E,H,6);
    undirectedGraph->addEdge(F,G,7);
    undirectedGraph->addEdge(G,H,16);
    undirectedGraph->addEdge(F,I,8);
    undirectedGraph->addEdge(G,I,5);
    undirectedGraph->addEdge(G,J,18);
    undirectedGraph->addEdge(H,J,2);
    undirectedGraph->addEdge(I,J,21);

    cout << endl << "* Graph of strings: " << endl;
    undirectedGraph->print();

    //running Dijkstra's algorithm

    runDijkstraAlgorithm(undirectedGraph, A, H);

    delete(undirectedGraph);
}

void buildCitiesQ4() {

    Object *seattle = new StringElement("Seattle");
    Object *sanFrancisco = new StringElement("San Francisco");
    Object *losAngeles = new StringElement("Los Angeles");
    Object *riverside = new StringElement("Riverside");
    Object *phoenix = new StringElement("Phoenix");
    Object *dallas = new StringElement("Dallas");
    Object *houston = new StringElement("Houston");
    Object *miami = new StringElement("Miami");
    Object *atlanta = new StringElement("Atlanta");
    Object *chicago = new StringElement("Chicago");
    Object *detroit = new StringElement("Detroit");
    Object *washington = new StringElement("Washington");
    Object *philadelphia = new StringElement("Philadelphia");
    Object *newYork = new StringElement("New York");
    Object *boston = new StringElement("Boston");

    auto *undirectedGraph = new Graph(true);
    undirectedGraph->addEdge(seattle,chicago,1737);
    undirectedGraph->addEdge(seattle,sanFrancisco,678);
    undirectedGraph->addEdge(sanFrancisco,riverside,386);
    undirectedGraph->addEdge(sanFrancisco,losAngeles,348);
    undirectedGraph->addEdge(losAngeles,riverside,50);
    undirectedGraph->addEdge(losAngeles,phoenix,357);
    undirectedGraph->addEdge(riverside,phoenix,307);
    undirectedGraph->addEdge(phoenix,dallas,887);
    undirectedGraph->addEdge(phoenix,houston,1015);
    undirectedGraph->addEdge(dallas,houston,225);
    undirectedGraph->addEdge(houston,miami,968);
    undirectedGraph->addEdge(houston,atlanta,702);
    undirectedGraph->addEdge(dallas,atlanta,721);
    undirectedGraph->addEdge(atlanta,miami,604);
    undirectedGraph->addEdge(riverside,chicago,1704);
    undirectedGraph->addEdge(dallas,chicago,805);
    undirectedGraph->addEdge(atlanta,chicago,588);
    undirectedGraph->addEdge(miami,washington,923);
    undirectedGraph->addEdge(atlanta,washington,543);
    undirectedGraph->addEdge(chicago,detroit,238);
    undirectedGraph->addEdge(detroit,washington,396);
    undirectedGraph->addEdge(washington,philadelphia,123);
    undirectedGraph->addEdge(philadelphia,newYork,81);
    undirectedGraph->addEdge(detroit,newYork,482);
    undirectedGraph->addEdge(detroit,boston,612);
    undirectedGraph->addEdge(newYork,boston,190);

    cout << endl << "* Graph of cities: " << endl;
    undirectedGraph->print();

    //running Dijkstra's algorithm

    runDijkstraAlgorithm(undirectedGraph, riverside, philadelphia);
    //running Dijkstra's algorithm

    runDijkstraAlgorithm(undirectedGraph, sanFrancisco, atlanta);

    delete(undirectedGraph);
}

void buildGraphOfStringElements() {

    //----------------
    //objects to be stored in the graph

    Object *A = new StringElement("A");
    Object *D = new StringElement("D");
    Object *C = new StringElement("C");

    //------------------
    //building the graph

    auto *undirectedGraph = new Graph(true);
    undirectedGraph->addEdge(A, D, 9);
    undirectedGraph->addEdge(A, C, 12);
    undirectedGraph->addEdge(C, D, 3);

    //----------------
    //printing the graph

    cout << endl << "* Graph of strings: " << endl;
    undirectedGraph->print();

    //----------------
    //running Dijkstra's algorithm

    runDijkstraAlgorithm(undirectedGraph, A, D);

    delete (undirectedGraph);
}

void buildGraphOfCities() {

    //----------------
    //cities to be stored in the graph

    City *sanFrancisco = new City("San Francisco");
    City *losAngeles = new City("Los Angeles");
    City *riverside = new City("Riverside");

    //------------------
    //building the graph

    auto *undirectedGraph = new Graph(true);
    undirectedGraph->addEdge(sanFrancisco, riverside, 386);
    undirectedGraph->addEdge(sanFrancisco, losAngeles, 348);
    undirectedGraph->addEdge(losAngeles, riverside, 50);

    //----------------
    //printing the graph

    cout << endl << "* Graph of cities: " << endl;
    undirectedGraph->print();

    //----------------
    //running Dijkstra's algorithm

    runDijkstraAlgorithm(undirectedGraph, sanFrancisco, riverside);

    delete (undirectedGraph);
}

/*
 * Runs Dijkstra's algorithm on the provided graph using source object.
 * It prints the result of the algorithm and also the shortest path from the source object to the target object.
 */
void runDijkstraAlgorithm(Graph *graph, Object *sourceObj, Object *targetObj) {
    auto *algorithm = new DijkstraAlgorithm(graph);
    DijkstraOutput *output = algorithm->findShortestPaths(sourceObj);


    cout << endl << "* Dijkstra's result: " << endl;
    if (output != nullptr) {
        output->print();
        cout << endl;
        output->printShortestPath(targetObj);
    } else {
        cout << "No output" << endl;
    }


    delete (output);
    delete (algorithm);
}
