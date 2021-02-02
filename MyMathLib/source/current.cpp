//
// Created by simon on 2020. 10. 15..
//

#include "../include/current.h"
#include "../include/my_gauss.h"

Vector Circuit::calculateCurrentOnLinear(const Graph &g, const Vector &r, const Vector &U0) {
    //Create incidence (for i1 + i2 + ... = i_source) and cycle (for i1*r1 + i2*r2 +... = U0) matrix of the network:
    Matrix incidence = g.IncidenceMatrix();
    Matrix cycle(3, 1);
    cycle(0, 0) = 1;
    cycle(1, 0) = 1;
    cycle(2, 0) = 1;

    //Multiply by resistance: (i1*r1 + i2*r2 = U0)
    //std::cout << cycle;
    for (int i = 0; i < cycle.row; i++) {
        cycle = MultiplyRow(cycle, i, r[i]);
    }
    cycle.fill(10);
    cycle(0,0) = 0;       //Resistance of ideal voltage source is 0;
    //std::cout << cycle;

    Matrix system = buildSystem(g, incidence, cycle, U0);

    std::cout << system << std::endl;

    return Gauss::Eliminate(system);
}

Matrix Circuit::buildSystem(const Graph& g, const Matrix& incidence, const Matrix& cycle, const Vector& U0) {
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


    return system;
}
