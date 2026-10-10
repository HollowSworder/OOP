#include "Matrix.h"
#include <iostream>
#include <stdexcept>
#include <cstdlib>

void Matrix::allocate(int rows, int cols) {
    rows_ = rows;
    cols_ = cols;
    data_ = new int*[rows_];
    for (int i = 0; i < rows_; ++i) {
        data_[i] = new int[cols_]; 
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

void Matrix::copyFrom(const Matrix& other) {
    if (other.rows_ == 0 || other.cols_ == 0 || other.data_ == nullptr) {
        return;
    }
    allocate(other.rows_, other.cols_); 
    for (int i = 0; i < rows_; ++i) {
        for (int j = 0; j < cols_; ++j) {
            data_[i][j] = other.data_[i][j];
        }
    }
}


Matrix::Matrix() 
    : data_(nullptr), rows_(0), cols_(0) {}

Matrix::Matrix(int size) 
    : data_(nullptr), rows_(0), cols_(0) {
    if (size < 0) {
        throw std::invalid_argument("Размерность не может быть отрицательной");
    }
    if (size == 0) {
        return; 
    }
    allocate(size, size);
    for (int i = 0; i < size; ++i) {
        data_[i][i] = 1; 
    }
}

Matrix::Matrix(int rows, int cols) 
    : data_(nullptr), rows_(0), cols_(0) {
    if (rows < 0 || cols < 0) {
        throw std::invalid_argument("Размерность не может быть отрицательной");
    }
    if (rows == 0 || cols == 0) {
        return; 
    }
    allocate(rows, cols);
    for (int i = 0; i < rows_; ++i) {
        for (int j = 0; j < cols_; ++j) {
            data_[i][j] = 0; 
        }
    }
}

Matrix::Matrix(const Matrix& other) 
    : data_(nullptr), rows_(0), cols_(0) {
    copyFrom(other);
}

Matrix& Matrix::operator=(const Matrix& other) {
    if (this == &other) {
        return *this; 
    }
    freeMemory();
    copyFrom(other);
    return *this;
}

Matrix::~Matrix() {
    freeMemory();
}

int Matrix::get(int i, int j) const {
    if (i < 0 || i >= rows_ || j < 0 || j >= cols_) {
        throw std::out_of_range("Индексы выходят за границы матрицы");
    }
    return data_[i][j];
}

void Matrix::set(int i, int j, int value) {
    if (i < 0 || i >= rows_ || j < 0 || j >= cols_) {
        throw std::out_of_range("Индексы выходят за границы матрицы");
    }
    data_[i][j] = value;
}

void Matrix::inputFromKeyboard() {
    if (rows_ == 0 || cols_ == 0) {
        std::cout << "Нельзя заполнить пустую матрицу (0x0).\n";
        return;
    }

    std::cout << "Введите элементы матрицы (" << rows_ << "x" << cols_ << "):\n";
    for (int i = 0; i < rows_; ++i) {
        for (int j = 0; j < cols_; ++j) {
            std::cin >> data_[i][j];
        }
    }
}

void Matrix::fillRandom() {
    for (int i = 0; i < rows_; ++i) {
        for (int j = 0; j < cols_; ++j) {
            data_[i][j] = rand() % 100;
        }
    }
}

void Matrix::print() const {
    if (rows_ == 0 || cols_ == 0 || data_ == nullptr) {
        std::cout << "Матрица пуста (0x0)\n\n";
        return;
    }

    for (int i = 0; i < rows_; ++i) {
        for (int j = 0; j < cols_; ++j) {
            std::cout << data_[i][j] << "\t";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

int Matrix::sum() const {
    int total = 0;
    for (int i = 0; i < rows_; ++i) {
        for (int j = 0; j < cols_; ++j) {
            total += data_[i][j];
        }
    }
    return total;
}

int Matrix::getRows() const {
    return rows_;
}

int Matrix::getCols() const {
    return cols_;
}

Matrix Matrix::transpose() const {
    Matrix result(cols_, rows_);
    for (int i = 0; i < rows_; ++i) {
        for (int j = 0; j < cols_; ++j) {
            result.set(j, i, data_[i][j]);
        }
    }
    return result;
}