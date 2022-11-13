#include <iostream>
#include "main.h"
using std::cout;
using std::string;

class Matrix {
    double **value;
    int sizeX;
    int sizeY;

public:
    void setSquareSize(int sizeXY) {
        sizeX = sizeXY;
        sizeY = sizeXY;
        value = new double *[sizeX];
        for (int i = 0; i < sizeX; i++) {
            value[i] = new double[sizeX];
        }
    }

    void setValue() {
        int i, j;
        for (i = 0; i < sizeX; i++) {
            for (j = 0; j < sizeY; j++)
                *(*(value + i) + j) = 1;
        }
    };

    void print() {
        int i, j;
        for (i = 0; i < sizeX; i++) {
            for (j = 0; j < sizeY; j++) {
                cout << value[i][j] << " ";
            }
            cout << std::endl;
        }
    }

    Matrix operator+(Matrix &toAdd) {
        Matrix tempMatrix;
        tempMatrix.setSquareSize(sizeX);

        if (sizeX != toAdd.sizeX || sizeX != sizeY || toAdd.sizeX != sizeY) {
            cout << "Sizes dont match";
            return tempMatrix;
        }

        for (int i = 0; i < sizeX; i++) {
            for (int j = 0; j < sizeY; j++) {
                tempMatrix.value[i][j] = value[i][j] + toAdd.value[i][j];
            }
        }
        return tempMatrix;
    }
};

int main() {
    Matrix m1;
    m1.setSquareSize(3);
    m1.setValue();
    Matrix m2;
    m2.setSquareSize(3);
    m2.setValue();
    Matrix m3 = m1 + m2;
    m3.print();
}