#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>

using namespace std;

void validateInputData(int row_num, int col_num) {
    if (row_num < 0) {
        throw out_of_range("Out of range");
    }

    if (col_num < 0) {
        throw out_of_range("Out of range");
    }
}

class Matrix {
private:
    int col_num_;
    int row_num_;
    vector<vector<int>> data_;

public:
    Matrix() {
        Reset(0, 0);
    }

    Matrix(int row_num, int col_num) {
        Reset(row_num, col_num);
    }

    void Reset(int row_num, int col_num) {
        validateInputData(row_num, col_num);

        if (row_num == 0 || col_num == 0) {
            col_num = row_num = 0;
        }

        row_num_ = row_num;
        col_num_ = col_num;
        data_.assign(row_num, vector<int>(col_num));
    }

    int At(int row_num, int col_num) const {
        return data_.at(row_num).at(col_num);
    }

    int &At(int row_num, int col_num) {
        return data_.at(row_num).at(col_num);
    }

    int GetNumRows() const {
        return row_num_;
    }

    int GetNumColumns() const {
        return col_num_;
    }
};

bool isMatricesSameSize(const Matrix &matrix1, const Matrix &matrix2) {
    if (matrix1.GetNumRows() != matrix2.GetNumRows()) {
        return false;
    }

    if (matrix1.GetNumColumns() != matrix2.GetNumColumns()) {
        return false;
    }

    return true;
}

istream &operator>>(istream &stream, Matrix &matrix) {
    int row_num;
    int col_num;
    stream >> row_num;
    stream.ignore(1);
    stream >> col_num;
    stream.ignore(1);
    matrix.Reset(row_num, col_num);

    for (int i = 0; i < matrix.GetNumRows(); ++i) {
        for (int j = 0; j < matrix.GetNumColumns(); ++j) {
            stream >> matrix.At(i, j);
            stream.ignore(1);
        }
    }
    return stream;
}

ostream &operator<<(ostream &stream, const Matrix &matrix) {
    stream << matrix.GetNumRows() << ' ';
    stream << matrix.GetNumColumns() << '\n';

    for (int i = 0; i < matrix.GetNumRows(); ++i) {
        for (int j = 0; j < matrix.GetNumColumns(); ++j) {
            stream << matrix.At(i, j) << ' ';
        }
        stream << '\n';
    }
    return stream;
}

bool operator==(const Matrix &matrix1, const Matrix &matrix2) {

    if (!isMatricesSameSize(matrix1, matrix2)) {
        return false;
    }

    for (int i = 0; i < matrix1.GetNumRows(); ++i) {
        for (int j = 0; j < matrix1.GetNumColumns(); ++j) {
            if (matrix1.At(i, j) != matrix2.At(i, j)) {
                return false;
            }
        }
    }
    return true;
}

Matrix operator+(const Matrix &matrix1, const Matrix &matrix2) {

    if (!isMatricesSameSize(matrix1, matrix2)) {
        throw invalid_argument("Matrices have different sizes");
    }

    Matrix sumMatrix(matrix1.GetNumRows(), matrix1.GetNumColumns());
    for (int i = 0; i < matrix1.GetNumRows(); ++i) {
        for (int j = 0; j < matrix1.GetNumColumns(); ++j) {
            sumMatrix.At(i, j) = matrix1.At(i, j) + matrix2.At(i, j);
        }
    }
    return sumMatrix;
}

int main() {
    Matrix one;
    Matrix two;

    cin >> one >> two;
    cout << one + two << endl;
    return 0;
}
