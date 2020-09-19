#include <iostream>

#include "my_math.h"
#include "my_graph.h"

int main() {
    std::cout << "Test" << std::endl;

    Graph g1(4);
    g1.addUndirectedEdge('a','b');
    g1.addUndirectedEdge('b','c');
    g1.addUndirectedEdge('c','d');
    g1.addUndirectedEdge('a','c');
    g1.addUndirectedEdge('d','b');

    Matrix* adjM;
    adjM = new Matrix (g1.AdjacencyMatrix());

    std::cout << *adjM << std::endl;

    //2
    *adjM = *adjM * *adjM;
    std::cout << *adjM << std::endl;

    //3
    *adjM = *adjM * *adjM;
    std::cout << *adjM << std::endl;

    delete adjM;

    adjM = reinterpret_cast<Matrix*>(g1.BFS(0, Graph::ReturnType::adjacencyM));

    std::cout << *adjM;

    delete adjM;

    return 0;
}
