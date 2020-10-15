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
/*
    Matrix M(3, 2);

    M(0,0) = 4;
    M(1,0) = 2;
    M(2,0) = 3;

    M(0,1) = 6;
    M(1,1) = 7;
    M(2,1) = 2;

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
*/
/*
    Graph g(4);
    g.addDirectedEdge(0,1);
    g.addDirectedEdge(1,2);
    g.addDirectedEdge(2,3);
    g.addDirectedEdge(3,0);

    g.addDirectedEdge(0,2);
    g.addDirectedEdge(1,3);

    ///Current:
    Vector resistance(g.getNumberOfEdges());

    resistance.fill(140);
    //resistance[1] = 0.5;

//    for (int i = 0; i < g.getNumberOfVertices(); i++) {
        Matrix* incidence = (Matrix*)g.BFS(0, Graph::ReturnType::incidenceM); //Iterated start vertex
        std::cout << incidence->row << " " << incidence->column << ", " << resistance.dimension << std::endl;

        //Matrix testInc = RemoveRows(g.IncidenceMatrix());

        *incidence = Diagonal(resistance) * (*incidence);
        std::cout << *incidence << std::endl;


        Vector rightSide(g.getNumberOfVertices());
        rightSide.fill(0);
        rightSide[2] = 10;
        rightSide[3] = -10;

        Matrix currentCoeff = CoefficientMatrix(*incidence, rightSide);
        delete incidence;

        Gauss::Eliminate(currentCoeff);

        std::cout << currentCoeff << std::endl;

 //   }

///------------------------------------------------------------------------------------------------------

    ///Voltage:
    //              = (Matrix*)g.DFS(0, Graph::ReturnType::cycleM);
    Matrix *cycle = new Matrix(6, 7);   //Manually constructed.
    (*cycle).fill(0);
    //cycle[0]:
    (*cycle)(0, 0) = 1;
    (*cycle)(5, 0) = 1;
    (*cycle)(3, 0) = 1;
    //--------------------------
    //cycle[1]:
    (*cycle)(1, 1) = 1;
    (*cycle)(2, 1) = 1;
    (*cycle)(5, 1) = -1;
    //--------------------------
    //cycle[2]:
    (*cycle)(0, 2) = 1;
    (*cycle)(1, 2) = 1;
    (*cycle)(4, 1) = -1;
    //--------------------------
    //cycle[3]:
    (*cycle)(4, 3) = 1;
    (*cycle)(2, 3) = 1;
    (*cycle)(3, 3) = 1;
    //--------------------------
    //cycle[4]:
    (*cycle)(0, 4) = 1;
    (*cycle)(1, 4) = 1;
    (*cycle)(2, 4) = 1;
    (*cycle)(3, 4) = 1;
    //--------------------------
    //cycle[5]:
    (*cycle)(4, 5) = 1;
    (*cycle)(1, 5) = -1;
    (*cycle)(5, 5) = 1;
    (*cycle)(3, 5) = 1;
    //--------------------------
    //cycle[6]:
    (*cycle)(0, 6) = 1;
    (*cycle)(5, 6) = 1;
    (*cycle)(2, 6) = -1;
    (*cycle)(4, 6) = -1;
    //--------------------------



    std::cout << *cycle << std::endl;
    Vector rightSide2(cycle->column);
    rightSide2.fill(0);
    Matrix voltCoeff = CoefficientMatrix(*cycle, rightSide2);
    //delete cycle;

    Gauss::Eliminate(voltCoeff);

    std::cout << voltCoeff << std::endl;
*/

/*
    Matrix *incidence = (Matrix*)g.BFS(0, Graph::ReturnType::incidenceM);

    Vector sourceI(incidence->column);
    sourceI.fill(0);
    sourceI[0] = 10;
    sourceI[2] = -10;
    Matrix coeffI = CoefficientMatrix(*incidence, sourceI);
    std::cout << Gauss::Eliminate(coeffI) << std::endl;


    Vector sourceU(cycle->column);
    sourceU.fill(0);
    sourceU[0] = 10;
    Matrix coeffU = CoefficientMatrix(*cycle, sourceU);
    std::cout << coeffU ;
    std::cout << Gauss::Eliminate(coeffU) << std::endl;*/

    //Define network:
    Graph g(3);
    g.addDirectedEdge(0,1);
    g.addDirectedEdge(1,2);
    g.addDirectedEdge(2,0);

    //Define the resistances of the edges:
    Vector r(g.getNumberOfEdges());

    //Create incidence (for i1 + i2 + ... = i_source) and cycle (for i1*r1 + i2*r2 +... = U0) matrix of the network:
    Matrix incidence = g.IncidenceMatrix();
    Matrix cycle(3, 1);
    cycle(0, 0) = 1;
    cycle(1, 0) = 1;
    cycle(2, 0) = 1;

    //Multiply by resistance: (i1*r1 + i2*r2 = U0)
    for (int i = 0; i < g.getNumberOfEdges(); i++) {
        MultiplyRow(cycle, i, r[i]);
    }

    Vector U0(1);
    U0[0] = 10;

    Matrix system(g.getNumberOfEdges() + 1, incidence.column + cycle.column);
    //The left  side of the system: (First e columns are the columns of the incidence matrix.
    //                              The remaining part of the matrix is the cycle matrix * resistance of the edges)
    //The right side of the system: (first e elements 0, then U0, if the source is part of given cycle)
    //_______________________________
    //| incidence   |  cycle matrix |   V -edges
    //|  matrix     |    * R        |   V
    //-------------------------------
    //|   0000000   |   U0 / 0      |   <- right side of equations.
    //-------------------------------

    for (int c = 0; c < system.column; c++) {
        for (int r = 0; r < system.row; r++) {
            if (g.getNumberOfVertices() <= c) {
                if (r == system.row-1) {
                    system(r, c) = U0[c - g.getNumberOfVertices()];
                }
                else {
                    system(r, c) = cycle(r, c - g.getNumberOfVertices());
                }
            }
            else if (g.getNumberOfVertices() > c) {
                if (r == system.row-1) {
                    system(r, c) = 0;
                }
                else {
                    system(r, c) = incidence(r, c);
                }
            }
        }
    }

    std::cout << system << std::endl;
    std::cout << Gauss::Eliminate(system);

    return 0;
}

