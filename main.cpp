#include <iostream>

#include "my_math.h"
#include "my_graph.h"

int main() {
    std::cout << "Test" << std::endl;

    Graph g1(10);

    g1.addEdge(0,1);
    g1.addEdge(1,2);
    g1.addEdge(2,3);

    Matrix* adjM;
    adjM = reinterpret_cast<Matrix*>(g1.BFS(0, Graph::ReturnType::incidenceM));
    std::cout << *adjM;
    delete adjM;
    return 0;
}
