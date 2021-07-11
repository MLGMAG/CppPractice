#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

bool IsPalindrom(const string &str);

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

void shouldBeTrueOnEmptyString() {
    bool expected = true;

    bool actual = IsPalindrom("");

    AssertEqual(actual, expected);
}

void shouldBeTrueOnSingleSymbol() {
    bool expected = true;

    bool actual = IsPalindrom("a");

    AssertEqual(actual, expected);
}

void shouldBeTrueOnEvenSymbolsCount() {
    bool expected = true;

    bool actual = IsPalindrom("abccba");

    AssertEqual(actual, expected);
}

void shouldBeFalseOnEvenSymbolsCount() {
    bool expected = false;

    bool actual = IsPalindrom("abcdba");

    AssertEqual(actual, expected);
}

void shouldBeTrueOnOddSymbolsCount() {
    bool expected = true;

    bool actual = IsPalindrom("abc|cba");

    AssertEqual(actual, expected);
}

void shouldBeFalseOnOddSymbolsCount() {
    bool expected = false;

    bool actual = IsPalindrom("abc|eba");

    AssertEqual(actual, expected);
}

void shouldCheckSpaceSymbolCase() {
    bool actual1 = IsPalindrom("a b c | c b a");
    AssertEqual(actual1, true);

    bool actual2 = IsPalindrom("a b c| c b a");
    AssertEqual(actual2, false);
}

void shouldCheckTwoSymbolsCase() {
    bool actual1 = IsPalindrom("aa");
    AssertEqual(actual1, true);

    bool actual2 = IsPalindrom("ab");
    AssertEqual(actual2, false);
}

int main() {
    TestRunner runner;
    runner.RunTest(shouldBeTrueOnEmptyString, "shouldBeTrueOnEmptyString");
    runner.RunTest(shouldBeTrueOnSingleSymbol, "shouldBeTrueOnSingleSymbol");
    runner.RunTest(shouldBeTrueOnEvenSymbolsCount, "shouldBeTrueOnEvenSymbolsCount");
    runner.RunTest(shouldBeFalseOnEvenSymbolsCount, "shouldBeFalseOnEvenSymbolsCount");
    runner.RunTest(shouldBeTrueOnOddSymbolsCount, "shouldBeTrueOnOddSymbolsCount");
    runner.RunTest(shouldBeFalseOnOddSymbolsCount, "shouldBeFalseOnOddSymbolsCount");
    runner.RunTest(shouldCheckSpaceSymbolCase, "shouldCheckSpaceSymbolCase");
    runner.RunTest(shouldCheckTwoSymbolsCase, "shouldCheckTwoSymbolsCase");

    return 0;
}
