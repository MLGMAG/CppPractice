#include <iostream>

class Matrix {
    int col_num;
    int row_num;
    int *data;

public:
    Matrix() {
        col_num = 0;
        row_num = 0;
        data = new int[0][0];
    }

    Matrix(int col_num, int row_num) {
        this->row_num = row_num;
        this->col_num = col_num;
    }

    void reset(int new_col_num, int new_row_num) {
        col_num = new_col_num;
        row_num = new_row_num;
    }

    const int at(int col_num, int row_num) {

    }

};
