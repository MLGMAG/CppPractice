#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

template<class T>
ostream &operator<<(ostream &os, const vector<T> &s) {
    os << "{";
    bool first = true;
    for (const auto &x : s) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << x;
    }
    return os << "}";
}

template<class T>
ostream &operator<<(ostream &os, const set<T> &s) {
    os << "{";
    bool first = true;
    for (const auto &x : s) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << x;
    }
    return os << "}";
}

template<class K, class V>
ostream &operator<<(ostream &os, const map<K, V> &m) {
    os << "{";
    bool first = true;
    for (const auto &kv : m) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << kv.first << ": " << kv.second;
    }
    return os << "}";
}

template<class T, class U>
void AssertEqual(const T &t, const U &u, const string &hint = {}) {
    if (t != u) {
        ostringstream os;
        os << "Assertion failed: " << t << " != " << u;
        if (!hint.empty()) {
            os << " hint: " << hint;
        }
        throw runtime_error(os.str());
    }
}

void Assert(bool b, const string &hint) {
    AssertEqual(b, true, hint);
}

class TestRunner {
public:
    template<class TestFunc>
    void RunTest(TestFunc func, const string &test_name) {
        try {
            func();
            cerr << test_name << " OK" << endl;
        } catch (exception &e) {
            ++fail_count;
            cerr << test_name << " fail: " << e.what() << endl;
        } catch (...) {
            ++fail_count;
            cerr << "Unknown exception caught" << endl;
        }
    }

    ~TestRunner() {
        if (fail_count > 0) {
            cerr << fail_count << " unit tests failed. Terminate" << endl;
            exit(1);
        }
    }

private:
    int fail_count = 0;
};

//class Rational {
//public:
//
//    Rational();
//
//    Rational(int numerator, int denominator) {
//    }
//
//    int Numerator() const {
//    }
//
//    int Denominator() const {
//    }
//};

void shouldSetCorrectValuesByDefaultConstructor() {
    int expectedNumerator = 0;
    int expectedDenominator = 1;

    Rational rational;
    int actualNumerator = rational.Numerator();
    AssertEqual(actualNumerator, expectedNumerator);
    int actualDenominator = rational.Denominator();
    AssertEqual(actualDenominator, expectedDenominator);
}

void shouldTestCuttingDown() {
    int expectedNumerator = 1;
    int expectedDenominator = 2;

    Rational rational = Rational(5, 10);
    int actualNumerator = rational.Numerator();
    AssertEqual(actualNumerator, expectedNumerator);
    int actualDenominator = rational.Denominator();
    AssertEqual(actualDenominator, expectedDenominator);
}

void shouldTestNonCutDown() {
    int expectedNumerator = 2;
    int expectedDenominator = 3;

    Rational rational = Rational(2, 3);
    int actualNumerator = rational.Numerator();
    AssertEqual(actualNumerator, expectedNumerator);
    int actualDenominator = rational.Denominator();
    AssertEqual(actualDenominator, expectedDenominator);
}

void shouldSetNegativeOnNumeralOnNegativeRational() {
    int expectedNumerator = -2;
    int expectedDenominator = 3;

    Rational rational = Rational(2, -3);
    int actualNumerator = rational.Numerator();
    AssertEqual(actualNumerator, expectedNumerator);
    int actualDenominator = rational.Denominator();
    AssertEqual(actualDenominator, expectedDenominator);
}

void shouldProcessBothNegative() {
    int expectedNumerator = 2;
    int expectedDenominator = 3;

    Rational rational = Rational(-2, -3);
    int actualNumerator = rational.Numerator();
    AssertEqual(actualNumerator, expectedNumerator);
    int actualDenominator = rational.Denominator();
    AssertEqual(actualDenominator, expectedDenominator);
}

void shouldProcessZeroOnNumerator() {
    int expectedNumerator = 0;
    int expectedDenominator = 1;

    Rational rational = Rational(0, 10);
    int actualNumerator = rational.Numerator();
    AssertEqual(actualNumerator, expectedNumerator);
    int actualDenominator = rational.Denominator();
    AssertEqual(actualDenominator, expectedDenominator);
}

int main() {
    TestRunner runner;
    runner.RunTest(shouldSetCorrectValuesByDefaultConstructor, "shouldSetCorrectValuesByDefaultConstructor");
    runner.RunTest(shouldTestCuttingDown, "shouldTestCuttingDown");
    runner.RunTest(shouldTestNonCutDown, "shouldTestNonCutDown");
    runner.RunTest(shouldSetNegativeOnNumeralOnNegativeRational, "shouldSetNegativeOnNumeralOnNegativeRational");
    runner.RunTest(shouldProcessBothNegative, "shouldProcessBothNegative");
    runner.RunTest(shouldProcessZeroOnNumerator, "shouldProcessZeroOnNumerator");

    return 0;
}
