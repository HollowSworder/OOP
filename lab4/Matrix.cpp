#include "Matrix.h"
#include <iostream>
#include <stdexcept>
#include <cstdlib>

void Matrix::allocate(int rows, int cols) {
    rows_ = rows;
    cols_ = cols;
    if (rows_ == 0 || cols_ == 0) {
        data_ = nullptr;
        rows_ = 0;
        cols_ = 0;
        return;
    }

    data_ = new int*[rows_];
    for (int i = 0; i < rows_; ++i) {
        data_[i] = new int[cols_]{};
    }
}

void Matrix::freeMemory() {
    if (data_ == nullptr) {
        return;
    }
    for (int i = 0; i < rows_; ++i) {
        delete[] data_[i];
    }
    delete[] data_;
    data_ = nullptr;
    rows_ = 0;
    cols_ = 0;
}

void Matrix::copyData(const Matrix& other) {
    rows_ = other.rows_;
    cols_ = other.cols_;
    if (rows_ == 0 || cols_ == 0 || other.data_ == nullptr) {
        data_ = nullptr;
        rows_ = 0;
        cols_ = 0;
        return;
    }

    data_ = new int*[rows_];
    for (int i = 0; i < rows_; ++i) {
        data_[i] = new int[cols_];
        for (int j = 0; j < cols_; ++j) {
            data_[i][j] = other.data_[i][j];
        }
    }
}
