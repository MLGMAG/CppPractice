#include <gtest/gtest.h>
#include <matrixSum.h>
#include <fstream>

using namespace std;

const string testData1 = "3 5\n"
                         "6 4 -1 9 8\n"
                         "12 1 2 9 -5\n"
                         "-4 0 12 8 6\n"
                         "\n"
                         "3 5\n"
                         "5 1 0 -8 23\n"
                         "14 5 -6 6 9\n"
                         "8 0 5 4 1\n"
                         "\n"
                         "3 5\n"
                         "11 5 -1 1 31\n"
                         "26 6 -4 15 4\n"
                         "4 0 17 12 7";

const string testData2 = "2 2\n"
                         "2 1\n"
                         "1 0\n"
                         "\n"
                         "2 2\n"
                         "0 1\n"
                         "1 2\n"
                         "\n"
                         "2 2\n"
                         "2 2\n"
                         "2 2";

const string testData3 = "0 0\n"
                         "\n"
                         "0 0\n"
                         "\n"
                         "0 0";

const string testData4 = "1 2\n"
                         "1 1\n"
                         "\n"
                         "2 1\n"
                         "1\n"
                         "1";

const string testData5 = "3 3\n"
                         "1 2 3\n"
                         "4 5 6\n"
                         "7 8 9";

int main() {
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}

TEST(MatrixSumTests, generalTest1) {
    stringstream inputData(testData1);

    Matrix matrix1;
    Matrix matrix2;
    Matrix expected;
    inputData >> matrix1 >> matrix2 >> expected;

    Matrix actual = matrix1 + matrix2;
    EXPECT_EQ(expected, actual);
}

TEST(MatrixSumTests, generalTest2) {
    stringstream inputData(testData2);

    Matrix matrix1;
    Matrix matrix2;
    Matrix expected;
    inputData >> matrix1 >> matrix2 >> expected;

    EXPECT_EQ(expected, matrix1 + matrix2);
    EXPECT_FALSE(matrix1 == matrix2);
    EXPECT_FALSE(matrix1 == (matrix2 + matrix1));
}

TEST(MatrixSumTests, generalTest3) {
    stringstream inputData(testData3);

    Matrix matrix1;
    Matrix matrix2;
    Matrix expected;
    inputData >> matrix1 >> matrix2 >> expected;

    EXPECT_EQ(expected, matrix1 + matrix2);
    EXPECT_TRUE(matrix1 == matrix2);
    EXPECT_TRUE((matrix1 + matrix2) == matrix2);
}

TEST(MatrixSumTests, shouldCreateEmptyMatrixOnDefaultConst) {
    Matrix matrix;

    EXPECT_EQ(matrix.GetNumRows(), 0);
    EXPECT_EQ(matrix.GetNumColumns(), 0);
}


TEST(MatrixSumTests, shouldThrowExceptionOnInvalidInput) {
    try {
        Matrix matrix(-1, -1);
        FAIL();
    } catch (out_of_range const &ex) {
        EXPECT_EQ(ex.what(), string("Out of range"));
    } catch (...) {
        FAIL();
    }
}

TEST(MatrixSumTests, shouldThrowExceptionOnInvalidInputInReset) {
    try {
        Matrix matrix;
        matrix.Reset(0, -1);
        FAIL();
    } catch (out_of_range const &ex) {
        EXPECT_EQ(ex.what(), string("Out of range"));
    } catch (...) {
        FAIL();
    }
}

TEST(MatrixSumTests, shouldThrowExceptionOnInvalid) {
    try {
        stringstream inputData(testData4);
        Matrix matrix1;
        Matrix matrix2;

        inputData >> matrix1 >> matrix2;

        matrix1 + matrix2;
        FAIL();
    } catch (invalid_argument const &ex) {
        EXPECT_EQ(ex.what(), string("Matrices have different sizes"));
    } catch (...) {
        FAIL();
    }
}

//TEST(MatrixSumTests, shouldGetElementWithAt) {
//    stringstream inputData(testData5);
//    Matrix matrix;
//    inputData >> matrix;
//
//    int k = 1;
//    for (int i = 0; i < matrix.GetNumColumns(); ++i) {
//        for (int j = 0; j < matrix.GetNumRows(); ++j) {
//            int actual = matrix.At(i, j);
//            actual++;
//            EXPECT_EQ(actual, k++);
//        }
//    }
//}

TEST(MatrixSumTests, shouldChangeElementWithAt) {
    stringstream inputData(testData5);
    Matrix matrix;
    inputData >> matrix;

    int k = 2;
    for (int i = 0; i < matrix.GetNumColumns(); ++i) {
        for (int j = 0; j < matrix.GetNumRows(); ++j) {
            matrix.At(i, j)++;
            EXPECT_EQ(matrix.At(i, j), k++);
        }
    }
}


TEST(MatrixSumTests, shouldReturnFalseOnDiffrentSizeEquation) {
    Matrix matrix1(1, 2);
    Matrix matrix2(1, 1);

    ASSERT_FALSE(matrix1 == matrix2);
}

TEST(MatrixSumTests, shouldReturnToStreamMatrixInRightFormat) {
    stringstream dataStream(testData5);
    Matrix matrix;
    dataStream >> matrix;
    cout << matrix;
}
