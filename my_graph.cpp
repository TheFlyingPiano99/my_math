//
// Created by simon on 2020. 09. 13..
//

#include "my_graph.h"

Matrix* Graph::BFS_ReturnDistanceM (int s) {
    int traversed[/*iterall*/v];
    int distance[/*vertex*/v];
    int previous[/*vertex*/v];

    ///Init:
    int numOfTraversed = 0;
    int current = 0;

    traversed[0] = s;
    distance[s] = 0;

    ///Using -1 as undefined value:
    previous[s] = -1;
    for (int i = 0; i < v; i++) {
        if (s != i) {
            distance[i] = -1;
            previous[i] = -1;
        }
    }

    ///Cycle:
    bool run = true;
    while (run) {
        ///Finding untraversed, adjacent vertex;
        std::list<int>::iterator adjv;
        for (adjv = adj[traversed[current]].begin(); adjv != adj[traversed[current]].end(); adjv++) {
            if (-1 == distance[*adjv]) {
                break;
            }
        }
        if (adj[traversed[current]].end() != adjv) {    ///Found
            traversed[++numOfTraversed] = *adjv;
            distance[*adjv] = distance[current] + 1;
            previous[*adjv] = traversed[current];
        }
        else {  ///Not found
            if (current == numOfTraversed) {
                run = false;
                break;
            }
            else {
                current++;
            }
        }
    }

    numOfTraversed++; //Compensate for 0 index.
    auto mx = new Matrix(numOfTraversed, numOfTraversed);
    for (int i = 0; i < numOfTraversed; i++) {
        if (-1 != previous[traversed[i]]) {
            (*mx)(traversed[i], previous[traversed[i]]) = distance[traversed[i]];
        }
    }
    return mx;
}

Graph *Graph::BFS_ReturnBreadthFirstTree(int s) {
    int traversed[/*iterall*/v];
    int distance[/*vertex*/v];
    int previous[/*vertex*/v];

    ///Init:
    int numOfTraversed = 0;
    int current = 0;

    traversed[0] = s;
    distance[s] = 0;

    ///Using -1 as undefined value:
    previous[s] = -1;
    for (int i = 0; i < v; i++) {
        if (s != i) {
            distance[i] = -1;
            previous[i] = -1;
        }
    }

    ///Cycle:
    bool run = true;
    while (run) {
        ///Finding untraversed, adjacent vertex;
        std::list<int>::iterator adjv;
        for (adjv = adj[traversed[current]].begin(); adjv != adj[traversed[current]].end(); adjv++) {
            if (-1 == distance[*adjv]) {
                break;
            }
        }
        if (adj[traversed[current]].end() != adjv) {    ///Found
            traversed[++numOfTraversed] = *adjv;
            distance[*adjv] = distance[current] + 1;
            previous[*adjv] = traversed[current];
        }
        else {  ///Not found
            if (current == numOfTraversed) {
                run = false;
                break;
            }
            else {
                current++;
            }
        }
    }

    numOfTraversed++;
    auto g = new Graph(numOfTraversed);
    for (int i = 0; i < numOfTraversed; i++) {
        if (-1 != previous[traversed[i]]) {
            g->addEdge(previous[traversed[i]], traversed[i]);
        }
    }
    return g;

}

Matrix *Graph::BFS_ReturnAdjacencyM(int s) {
    int traversed[/*iterall*/v];
    int distance[/*vertex*/v];
    int previous[/*vertex*/v];

    ///Init:
    int numOfTraversed = 0;
    int current = 0;

    traversed[0] = s;
    distance[s] = 0;

    ///Using -1 as undefined value:
    previous[s] = -1;
    for (int i = 0; i < v; i++) {
        if (s != i) {
            distance[i] = -1;
            previous[i] = -1;
        }
    }

    ///Cycle:
    bool run = true;
    while (run) {
        ///Finding untraversed, adjacent vertex;
        std::list<int>::iterator adjv;
        for (adjv = adj[traversed[current]].begin(); adjv != adj[traversed[current]].end(); adjv++) {
            if (-1 == distance[*adjv]) {
                break;
            }
        }
        if (adj[traversed[current]].end() != adjv) {    ///Found
            traversed[++numOfTraversed] = *adjv;
            distance[*adjv] = distance[current] + 1;
            previous[*adjv] = traversed[current];
        }
        else {  ///Not found
            if (current == numOfTraversed) {
                run = false;
                break;
            }
            else {
                current++;
            }
        }
    }

    numOfTraversed++;
    auto mx = new Matrix(numOfTraversed, numOfTraversed);
    mx->fill(0);
    for (int i = 0; i < numOfTraversed; i++) {
        if (-1 != previous[traversed[i]]) {
            (*mx)(traversed[i], previous[traversed[i]]) = 1;
            (*mx)(previous[traversed[i]], traversed[i]) = 1;
        }
    }
    return mx;
}

Matrix *Graph::BFS_ReturnIncidenceM(int s) {
    int traversed[/*iterall*/ v];
    int distance[/*vertex*/ v];
    int previous[/*vertex*/ v];

    ///Init:
    int numOfTraversed = 0;
    int current = 0;

    traversed[0] = s;
    distance[s] = 0;

    ///Using -1 as undefined value:
    previous[s] = -1;
    for (int i = 0; i < v; i++) {
        if (s != i) {
            distance[i] = -1;
            previous[i] = -1;
        }
    }

    ///Cycle:
    bool run = true;
    while (run) {
        ///Finding untraversed, adjacent vertex;
        std::list<int>::iterator adjv;
        for (adjv = adj[traversed[current]].begin(); adjv != adj[traversed[current]].end(); adjv++) {
            if (-1 == distance[*adjv]) {
                break;
            }
        }
        if (adj[traversed[current]].end() != adjv) {    ///Found
            traversed[++numOfTraversed] = *adjv;
            distance[*adjv] = distance[current] + 1;
            previous[*adjv] = traversed[current];
        }
        else {  ///Not found
            if (current == numOfTraversed) {
                run = false;
                break;
            }
            else {
                current++;
            }
        }
    }

    numOfTraversed++;
    auto mx = new Matrix(numOfTraversed-1, numOfTraversed);
    mx->fill(0);
    int e = 0;
    for (int i = 0; i < numOfTraversed; i++) {
        if (-1 != previous[traversed[i]]) {
            (*mx)(e, traversed[i]) = -1;
            (*mx)(e, previous[traversed[i]]) = 1;
            e++;
        }
    }
    return mx;

}


///-----------------------------------------------------------------------------------

void* Graph::BFS(int s, ReturnType retT) {
    void* retP;
    switch (retT) {
        case Graph::ReturnType::breadth_first_tree: {
            retP = BFS_ReturnBreadthFirstTree(s);
            break;
        }
        case adjacencyM: {
            retP = BFS_ReturnAdjacencyM(s);
            break;
        }
        case incidenceM: {
            retP = BFS_ReturnIncidenceM(s);
            break;
        }
        case distanceM: {
            retP = BFS_ReturnDistanceM(s);
            break;
        }
        default: {
            retP = nullptr;
            break;
        }
    }
    return retP;
}



