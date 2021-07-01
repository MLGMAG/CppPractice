#include <iostream>
#include <vector>

using namespace std;

void validateInputData(int col_num, int row_num);

class Matrix {
private:
    int col_num_;
    int row_num_;
    vector<vector<int>> data_;

public:
    Matrix();

    Matrix(int col_num, int row_num);

    void Reset(int col_num, int row_num);

    int At(int col_num, int row_num) const;

    int &At(int col_num, int row_num);

    int GetNumRows() const;

    int GetNumColumns() const;

    vector<vector<int>> &GetData();

    vector<vector<int>> GetData() const;
};

bool isMatricesSameSize(const Matrix &matrix1, const Matrix &matrix2);

istream &operator>>(istream &stream, Matrix &matrix);

ostream &operator<<(ostream &stream, const Matrix &matrix);

bool operator==(const Matrix &matrix1, const Matrix &matrix2);

Matrix operator+(const Matrix &matrix1, const Matrix &matrix2);
