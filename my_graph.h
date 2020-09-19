//
// Created by simon on 2020. 09. 13..
//

#ifndef MY_MATH_MY_GRAPH_H
#define MY_MATH_MY_GRAPH_H

#include <list>
#include "my_matrix.h"

class Graph {
    const int v; //Number of vertices

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

    void addEdge(char v, char w) {
        int vi;
        int wi;
        if ('a' <= v && v <= 'z') {
            vi = v - 'a';
        }
        else if ('A' <= v && v <= 'Z') {
            vi = v - 'A';
        }

        if ('a' <= w && w <= 'z') {
            wi = w - 'a';
        }
        else if ('A' <= w && w <= 'Z') {
            wi = w - 'A';
        }

        adj[vi].push_back(wi);
    }

    void addUndirectedEdge(int v, int w) {
        adj[v].push_back(w);
        adj[w].push_back(v);
    }

    void addUndirectedEdge(char v, char w) {
        int vi;
        int wi;
        if ('a' <= v && v <= 'z') {
            vi = v - 'a';
        }
        else if ('A' <= v && v <= 'Z') {
            vi = v - 'A';
        }

        if ('a' <= w && w <= 'z') {
            wi = w - 'a';
        }
        else if ('A' <= w && w <= 'Z') {
            wi = w - 'A';
        }

        adj[vi].push_back(wi);
        adj[wi].push_back(vi);
    }


    enum ReturnType {
        breadth_first_tree,
        adjacencyM,
        incidenceM,
        distanceM
    };

    void* BFS(const int s, ReturnType retT);

    Matrix AdjacencyMatrix() {
        Matrix retM(v, v);
        retM.fill(0);
        for (int c = 0; c < v; c++) {
            for (auto & iter : adj[c]) {
                retM(iter, c) = 1;
            }
        }
        return retM;
    }


protected:
    Graph* BFS_ReturnBreadthFirstTree (const int s);
    Matrix* BFS_ReturnAdjacencyM (const int s);
    Matrix* BFS_ReturnIncidenceM (const int s);
    Matrix* BFS_ReturnDistanceM (const int s);
};


#endif //MY_MATH_MY_GRAPH_H
