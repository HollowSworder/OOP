#include "Matrix.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdexcept>

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    Matrix m1;      
    Matrix m2(3);     
    Matrix m3(3, 4);   
    Matrix m4(2, 3);  

    std::cout << "Матрица M2\n";
    m2.print();

    std::cout << "Матрица M3\n";
    m3.print();

    std::cout << "Матрица M4\n";
    m4.print();

    for (int i = 0; i < m2.getRows(); ++i) {
        for (int j = 0; j < m2.getCols(); ++j) {
            m2.set(i, j, i * j);
        }
    }
    std::cout << "Матрица M2(i * j)\n";
    m2.print();

    m3.fillRandom();
    std::cout << "Матрица M3 после fillRandom()\n";
    m3.print();

    Matrix mm = m3;
    std::cout << "Матрица mm (копия M3 через mm = m3)\n";
    mm.print();

    Matrix m3Transposed = m3.transpose();
    std::cout << "Транспонированная матрица M3\n";
    m3Transposed.print();

    std::cout << "Заполнение M4 с клавиатуры\n";
    m4.inputFromKeyboard();
    std::cout << "\nМатрица M4 после ввода\n";
    m4.print();

    std::cout << "Сумма элементов матрицы M3: " << m3.sum() << "\n\n";

    std::cout << "Перехват исключений\n";
    try {
        Matrix bad(-1, 5); 
    } catch (const std::invalid_argument& e) {
        std::cout << "Caught: " << e.what() << '\n';
    }

    try {
        m3.get(100, 100); 
    } catch (const std::out_of_range& e) {
        std::cout << "Caught: " << e.what() << '\n';
    }

    return 0;
}