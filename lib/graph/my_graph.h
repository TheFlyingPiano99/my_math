//
// Created by simon on 2020. 09. 13..
//

#ifndef MY_MATH_MY_GRAPH_H
#define MY_MATH_MY_GRAPH_H

#include <list>
#include "../matrix/my_matrix.h"

class Graph {
    const int v; //Number of vertices
    int e;  //Number of edges
    std::list<int> *adj;

public:
    explicit Graph(int v): v(v), e(0) {
        adj = new std::list<int>[v];
    }

    ~Graph() {
        delete [] adj;
    }

    int getNumberOfVertices () const {
        return v;
    }

    int getNumberOfEdges () const {
        return e;
    }

    void addDirectedEdge(int v, int w) {
        adj[v].push_back(w);
        e++;
    }

    void addDirectedEdge(char v, char w) {
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
        e++;
    }

    void addUndirectedEdge(int v, int w) {
        adj[v].push_back(w);
        e++;
        adj[w].push_back(v);
        e++;
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
        e++;
        adj[wi].push_back(vi);
        e++;
    }


    enum ReturnType {
        breadth_first_tree,
        adjacencyM,
        incidenceM,
        distanceM,
        cycleM
    };

    void* BFS(const int s, ReturnType retT);
    void* DFS(const int s, ReturnType retT);

    /**
     * DFS algorithm, specifically for circuit analysis.
     * @param incidence - Matrix** Will be loaded with solution. (Needs to be deleted after!)
     * @param baseCycle - Matrix** Will be loaded with solution. (Needs to be deleted after!)
     */
    void DFS_forCircuit(Matrix** incidence, Matrix** baseCycle);

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

    Matrix IncidenceMatrix() const {
        auto mx = Matrix(e, v);
        mx.fill(0);
        int edge = 0;
        for (int from = 0; from < v; from++) {
            for (auto& to : adj[from]) {
                mx(edge, from) = 1;
                mx(edge, to) = -1;
                edge++;
            }
        }
        return mx;
    }

    Matrix CycleBaseMatrix () {
        //TODO
        ;
        return Matrix(0,0);
    }

protected:
    Graph* BFS_ReturnBreadthFirstTree (const int s);
    Matrix* BFS_ReturnAdjacencyM (const int s);
    Matrix* BFS_ReturnIncidenceM (const int s);
    Matrix* BFS_ReturnDistanceM (const int s);

    Matrix* DFS_ReturnCycleM (const int s);
};


#endif //MY_MATH_MY_GRAPH_H
