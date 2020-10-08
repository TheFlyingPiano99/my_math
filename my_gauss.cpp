//
// Created by simon on 2020. 09. 13..
//

#include "my_gauss.h"
#include <algorithm>

Vector Gauss::Eliminate(Matrix &M) {

    SingularityFlag flag = Reduce(M);
    switch (flag) {
        case noSolutin: {
            throw NoSolution();
            break;
        }
        case infiniteSoultions: {
            throw InfiniteSolutions();
            break;
        }
        case cleanSolution: {
//Second fase of Gauss eliminaton after reducton:----------------------------
            int r = M.row-2;
            for (int c = M.column-1; c > 0; c--) {    //Reverse iteration on columns
                for (int ci = c-1; ci >= 0; ci--) {
//                        M(r, ci) -= M(r, c) * M(, ci);
//                        M(r, ci) -= M(r, c) * M(, ci);
                }

            }
//---------------------------------------------------------------------------
            break;
        }
    }
/*
    // if matrix is singular
    if (singular_flag != -1) {
        //Singular Matrix.

        // if the RHS of equation corresponding to
        //   zero row  is 0, * system has infinitely
        //   many solutions, else inconsistent
        if (M[singular_flag][M])
            printf("Inconsistent System.");
        else
            printf("May have infinitely many "
                   "solutions.");

        return Vector;
    }

    // get solution to system and print it using
    //   backward substitution
    backSub(M);
    */
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
                    for (int j = 0; j < M.row; j++) {
                        M(j, i) += -M(r, i) * M(j, c);
                    }
                }
            }
            if ((r == M.row - 1) || (c == M.column - 1)) {  //Crossed matrix
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

    //Final steps of Reduce:
    if (c < M.column-1) {
        bool zeroColumn = false;
        std::vector<int> toRemoveIndexes;     //Only if shrink matrix section is not commented out.
        for (int i = c+1; i < M.column; i++) {    //Iterate on columns
            bool foundNotZeroInColumn = false;
            for (int j = 0; j < M.row; j++) {   //Iterate element in current column
                if (0 != M(j, i)) {
                    if (j == M.row-1) {     //Found a forbidden column, where all elements are 0 except the last element.
                        return SingularityFlag::noSolutin;
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
        Matrix tempM(M.row, M.column - toRemoveIndexes.size());
        //Fill up M with M-s data, except zero columns.
        int ct = 0; //Index of the temp matrix.
        for (int c = 0; c < M.column; c++) {
            if (toRemoveIndexes.end() == std::find(toRemoveIndexes.begin(), toRemoveIndexes.end(), c)) {
                for (int r = 0; r < M.row; r++) {
                    tempM(r, ct) = M(r, c);
                }
                ct++;
            }
        }
        M.copyWithResize(tempM);
        //--------------------------------------------------------------
    }

    if (M.column < M.row - 1) {
        return SingularityFlag::infiniteSoultions;
    }

    return SingularityFlag::cleanSolution;
}

void Gauss::SwapColumn(Matrix &M, int col1, int col2) {
    float temp;
    for (int r = 0; r < M.row; r++) {
        temp = M(r, col1);
        M(r, col1) = M(r, col2);
        M(r, col2) = temp;
    }
}
