#include <iostream>
#include <stdexcept>

template <typename T>
class Matrix {
private:
    T** data;
    int rows;
    int cols;

public:
    Matrix(int rows, int cols) : rows(rows), cols(cols) {
        if (rows <= 0 || cols <= 0) {
            std::cout << "ERROR, ROWS OR/AND COLS IS CAN'T BE NEGATIVE!" << std::endl;
        }
        else {
            data = new T * [rows];
            for (int i = 0; i < rows; ++i) {
                data[i] = new T[cols];
            }
        }
    }

    ~Matrix() {
        for (int i = 0; i < rows; ++i) {
            delete[] data[i];
        }
        delete[] data;
    }

    T* operator[](int i) {
        if (i < 0 || i >= rows) {
            std::cout << "Index is out of range." << std::endl;
        }
        else { return data[i]; }
    }

    const T* operator[](int i) const {
        if (i < 0 || i >= rows) {
            std::cout << "Index is out of range." << std::endl;
        }
        else{ return data[i]; }
    }

    int Size() const {
        return rows * cols;
    }
};

template <typename T>
Matrix<T> table(int rows, int cols) {
    return Matrix<T>(rows, cols);
}

int main() {

        auto test = table<int>(2, 3);
        test[0][0] = 4;
        std::cout << test[0][0] << std::endl;
        std::cout << "Size of array: " << test.Size() << std::endl;
    return 0;
}