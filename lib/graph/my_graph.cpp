//
// Created by simon on 2020. 09. 13..
//

#include "my_graph.h"

Matrix* Graph::BFS_ReturnDistanceM (const int s) {
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

Graph *Graph::BFS_ReturnBreadthFirstTree(const int s) {
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
            g->addDirectedEdge(previous[traversed[i]], traversed[i]);
        }
    }
    return g;

}

Matrix *Graph::BFS_ReturnAdjacencyM(const int s) {
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

Matrix *Graph::BFS_ReturnIncidenceM(const int s) {
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

///--------DFS-algorithm------------------------------------------------------------------

void *Graph::DFS(const int s, Graph::ReturnType retT) {
    switch (retT) {
        case cycleM: {
            return DFS_ReturnCycleM(s);
        }
        default:
            return nullptr;
    }
}

Matrix *Graph::DFS_ReturnCycleM(const int s) {
    

    return nullptr;
}

void Graph::DFS_forCircuit(Matrix** incidence, Matrix** baseCycle) {
    int s = 0;  //Starting vertex

    int depth[v]; /*vertex*/
    int finish[v]; /*vertex*/
    int previous[v]; /*vertex*/
    int current;
    int GreatestDepth;
    int GreatestFinish;

    ///Init:
    depth[s] = 1;

    ///Using -1 as undefined value:
    previous[s] = -1;
    for (int i = 0; i < v; i++) {
        if (s != i) {
            depth[i] = -1;
        }
        finish[i] = -1;
        previous[i] = -1;
    }

    GreatestDepth = 1;
    GreatestFinish = 0;
    current = s;

    ///Cycle:
    bool run = true;
    while (run) {
        ///Finding adjacent vertex with (*) depth:
        int v = current;
        for (auto &iter : adj[current]) {
            if (-1 == depth[iter]) {
                v = iter;
                break;
            }
        }
        if (current != v) { //Found adjacent vertex with (*) depth
            GreatestDepth++;
            depth[v] = GreatestDepth;
            previous[v] = current;
            current = v;
        } else {
            GreatestFinish++;
            finish[current] = GreatestFinish;
            if (-1 != previous[current]) {
                current = previous[current];
            } else {
                ///Finding vertex with (*) depth:
                int v = current;
                for (int i = 0; i < this->v; i++) {
                    if (-1 == depth[i]) {
                        v = i;
                        break;
                    }
                }
                if (current != v) { //Found adjacent vertex with (*) depth
                    current = v;
                } else {
                    run = false;
                }
            }
        }
    }
    *incidence = new Matrix(this->e, this->v);
    (*incidence)->fill(0);
    for (int i = 0; i < this->v; i++) {
        if (-1 != previous[i]) {
            (**incidence)(i, previous[i]) = 1;
            (**incidence)(i, i) = -1;
        }
    }

    //Getting fundamental base cycles:
    int noOfCycles = 0;             //First count the cycles:
    for (int i = 0; i < this->v; i++) {
        if (-1 == previous[i]) {
            noOfCycles++;
        }
    }
    *baseCycle = new Matrix(this->e, noOfCycles);
    (*baseCycle)->fill(0);
    for (int i = 0; i < this->v; i++) {     //Then fill cycle matrix
        if (-1 == previous[i]) {
            (**baseCycle)(i, i) = 1;
            for (int j = 0; j < this->v; j++) {
                if (-1 != previous[j]) {
                    (**baseCycle)(j, i) = 1;
                }
            }
        }
        //TODO
    }
}



