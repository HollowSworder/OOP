#pragma once

class Matrix {
private:
    int** data_;
    int rows_;
    int cols_;

    void allocate(int rows, int cols);
    void freeMemory();
    void copyData(const Matrix& other);
};