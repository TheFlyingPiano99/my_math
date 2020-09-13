//
// Created by simon on 2020. 09. 13..
//

#ifndef MY_MATH_MY_GRAPH_H
#define MY_MATH_MY_GRAPH_H

#include <list>
#include "my_matrix.h"

class Graph {
    int v; //Number of vertices

    std::list<int> *adj;

public:
    explicit Graph(int v): v(v) {
        adj = new std::list<int>[v];
    }

    ~Graph() {
        delete [] adj;
    }

    void addEdge(int v, int w) {
        adj[v].push_back(w);
    }

    enum ReturnType {
        breadth_first_tree,
        adjacencyM,
        incidenceM,
        distanceM
    };

    void* BFS(int s, ReturnType retT);

protected:
    Graph* BFS_ReturnBreadthFirstTree (int s);
    Matrix* BFS_ReturnAdjacencyM (int s);
    Matrix* BFS_ReturnIncidenceM (int s);
    Matrix* BFS_ReturnDistanceM (int s);
};


#endif //MY_MATH_MY_GRAPH_H
