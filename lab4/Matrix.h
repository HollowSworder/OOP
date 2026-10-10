#pragma once

class Matrix {
private:
    int** data_;
    int rows_;
    int cols_;

    void allocate(int rows, int cols);
    void freeMemory();
    void copyData(const Matrix& other);

public:
    Matrix();
    explicit Matrix(int size);
    Matrix(int rows, int cols);

    Matrix(const Matrix& other);
    Matrix& operator=(const Matrix& other);

    ~Matrix();

    int get(int i, int j) const;
    void set(int i, int j, int value);

    void inputFromKeyboard();
    void fillRandom();
    void print() const;

    int sum() const;
    int getRows() const;
    int getCols() const;

    Matrix transpose() const;
};