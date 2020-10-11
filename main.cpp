#include <iostream>

#include "my_math.h"
#include "my_graph.h"
#include <time.h>
#include <math.h>
#include "my_gauss.h"

int randBit() {
    return std::rand()%2;
}


int main() {
/*    std::cout << "Test" << std::endl;

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

    delete adjM; */

/*
    std::cout << "Probability of det(M1 * M2 * M3) != 0:" << std::endl;

    std::srand(time(0));

    std::vector<double> probs;
    for (int k = 0; k < 100; k++) {
        int good = 0;
        int all = 100000;
        for (int i = 0; i < all; i++) {
            Matrix2D M1(randBit(),randBit(),randBit(),randBit());
            Matrix2D M2(randBit(),randBit(),randBit(),randBit());
            Matrix2D M3(randBit(),randBit(),randBit(),randBit());

            if (Determinant(M1 * M2 * M3) != 0) {
                good++;
            }
        }
        probs.push_back((double)good / (double)all);
    }
    int n = 0;
    double prob = 0;
    for (auto iter : probs) {
        prob += iter;
        n++;
    }

    std::cout << prob/(double)n  << std::endl;


    double sum = 0;
    for (int i = 0; i <= 2; i++) {
        sum += ((-10) * pow(0.1*(9), (double)i) * cos(((2 * 3.14) / 5) * i + 0.4))
                *
                10 * (i == 2)? 1 : 0 + (-6) * pow((0.1 *(-5)),2-i+1);
    }
    std::cout << "Sum = " << sum * 1.0 << std::endl;
*/
    Matrix M(10, 9);
    M.fill(10);

    M(4,5) = 2;
    M(4,4) = 2;
    M(4,8) = 2;

    std::cout << "The matrix:" << std::endl;
    std::cout << M << std::endl;

    Gauss::Reduce(M);

    std::cout << "After Reduction:" << std::endl;
    std::cout << M << std::endl;

    Vector sol(0);
    try {
        sol = Gauss::Eliminate(M);

        std::cout << "After Elimination:" << std::endl;
        std::cout << M << std::endl;
    }
    catch (Gauss::GaussException& e) {
        std::cout << e.what() <<std::endl;
    }

    std::cout << "Solution vector:" << std::endl;
    std::cout << sol << std::endl;

    return 0;
}

