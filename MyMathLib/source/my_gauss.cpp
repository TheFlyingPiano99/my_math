//
// Created by simon on 2020. 09. 13..
//

#include "../include/my_gauss.h"
#include <algorithm>

Vector Gauss::Eliminate(Matrix &M) {

    SingularityFlag flag = Reduce(M);
    switch (flag) {
        case noSolution: {
            throw NoSolution();
        }
        case infiniteSolutions: {
            throw InfiniteSolutions();
        }
        case cleanSolution: {
//Second fase of Gauss eliminaton after reducton:----------------------------
            int r = M.row-2;
            int rightSideRow = M.row-1;     //The right side of the equation.
            for (int c = M.column-1; c > 0; c--) {    //Reverse iteration on columns
                for (int ci = c-1; ci >= 0; ci--) {
                        M(rightSideRow, ci) -= M(rightSideRow, c) * M(r, ci);
                        M(r, ci) = 0;
                }
                r--;
            }
            Vector ret(M.column);
            for (int c = 0; c < M.column; c++) {
                ret[c] = M(rightSideRow, c);
            }
            return ret;
//---------------------------------------------------------------------------
        }
    }
    return Vector(0);
}


void SwapRow(Matrix &M, int row1, int row2) {
    ;
}

void SwapColumn(Matrix &M, int col1, int col2) {
    ;
}

Gauss::SingularityFlag Gauss::Reduce(Matrix& M) {
    int c = 0;
    int r = 0;

    while (true) {
        if (0 != M(r,c)) {
            //Divide column[c] by M(r,c).
            float divider = 1 / M(r, c);
            for (int i = 0; i < M.row; i++) {
                M(i, c) *= divider;
            }
            if (c < M.column - 1) {
                //Add the -M(r, i) * M[c] column to all "M[i]" columns:
                for (int i = c+1; i < M.column; i++) {
                    float fact = M(r, i);
                    for (int j = 0; j < M.row; j++) {
                        M(j, i) -= fact * M(j, c);
                    }
                }
            }
            if ((r == M.row - 2) || (c == M.column - 1)) {  //Crossed matrix
                break;
            }
            else {                 //Proceed diagonally
                r++;
                c++;
            }
        }
        else {                    //if 0 == M(r,c)
            bool foundSwappable = false;
            if (c < M.column-1) {
                //Search for swappable. Criteria: 0 != M(r, i)
                for (int i = c+1; i < M.column; i++) {
                    if (0 != M(r, i)) {     //if swappable found swap columns
                        SwapColumn(M, c, i);
                        foundSwappable = true;
                        break;
                    }
                }
            }
            if (!foundSwappable) {  //No swappable found
                if (r == M.row - 2) {   //if current row == n.
                    c--;
                    break;
                }
                else {
                    r++;
                }
            }
        }
    }

    if (M.column < M.row - 1) {
        return SingularityFlag::infiniteSolutions;
    }


    //Final steps of Reduce:
    if (c < M.column-1) {
        std::vector<int> toRemoveIndexes;     //Only if shrink matrix section is not commented out.
        for (int i = c; i < M.column; i++) {    //Iterate on columns
            bool foundNotZeroInColumn = false;
            for (int j = 0; j < M.row; j++) {   //Iterate element in current column
                if (0 != M(j, i)) {
                    if (j == M.row-1) {     //Found a forbidden column, where all elements are 0 except the last element.
                        return SingularityFlag::noSolution;
                    }
                    foundNotZeroInColumn = true;
                    break;
                }
            }
            if (!foundNotZeroInColumn) {    //Zero columns should be removed.
                toRemoveIndexes.push_back(i);
            }
        }

        //Shrink matrix by removing zero columns:-----------------------
        RemoveColumns(M, toRemoveIndexes);

        if (M.column < M.row - 1) {
            return SingularityFlag::infiniteSolutions;
        }

        return SingularityFlag::cleanSolution;
    }
    else {
        return SingularityFlag::cleanSolution;
        //return SingularityFlag::noSolution;
    }
}

void Gauss::SwapColumn(Matrix &M, int col1, int col2) {
    float temp;
    for (int r = 0; r < M.row; r++) {
        temp = M(r, col1);
        M(r, col1) = M(r, col2);
        M(r, col2) = temp;
    }
}

Matrix CoefficientMatrix (const Matrix& M, const Vector& v) {
    if (M.column == v.dimension) {
        Matrix retM(M.row+1, M.column);
        for (int c = 0; c < M.column; c++) {
            for (int r = 0; r < M.row; r++) {
                retM(r, c) = M(r, c);
            }
            retM(M.row, c) = v[c];
        }
        return retM;
    }
    else {
        throw std::exception();
    }
}
