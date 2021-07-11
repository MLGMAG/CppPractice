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

//class Person {
//public:
//
//    void ChangeFirstName(int year, const string &first_name);
//
//    void ChangeLastName(int year, const string &last_name);
//
//    string GetFullName(int year);
//};

void shouldReturnIncognitoOnEmptyData() {
    Person person;
    string expected = "Incognito";

    string actual = person.GetFullName(2020);

    AssertEqual(actual, expected);
}

void shouldReturnIncognitoOnNoData() {
    Person person;
    string expected = "Incognito";

    person.ChangeFirstName(2000, "fName1");
    person.ChangeFirstName(1990, "fName2");
    person.ChangeLastName(2000, "lName1");
    person.ChangeLastName(1990, "lName2");
    string actual = person.GetFullName(1900);

    AssertEqual(actual, expected);
}

void shouldReturnValueBetween() {
    Person person;
    string expected = "fName2 lName2";

    person.ChangeFirstName(2000, "fName1");
    person.ChangeLastName(2000, "lName1");
    person.ChangeFirstName(1990, "fName2");
    person.ChangeLastName(1990, "lName2");

    string actual = person.GetFullName(1995);

    AssertEqual(actual, expected);
}

void shouldReturnValueTop() {
    Person person;
    string expected = "fName1 lName1";

    person.ChangeFirstName(2000, "fName1");
    person.ChangeLastName(2000, "lName1");
    person.ChangeFirstName(1990, "fName2");
    person.ChangeLastName(1990, "lName2");

    string actual = person.GetFullName(2020);

    AssertEqual(actual, expected);
}

void generalTest() {
    Person person;

    string actual1 = person.GetFullName(1995);
    AssertEqual(actual1, "Incognito");

    person.ChangeFirstName(2000, "fName1");
    person.ChangeLastName(2000, "lName1");
    string actual2 = person.GetFullName(1995);
    AssertEqual(actual2, "Incognito");

    person.ChangeFirstName(1990, "fName2");
    person.ChangeLastName(1990, "lName2");
    string actual3 = person.GetFullName(1995);
    AssertEqual(actual3, "fName2 lName2");

    string actual4 = person.GetFullName(1989);
    AssertEqual(actual4, "Incognito");

    string actual5 = person.GetFullName(2020);
    AssertEqual(actual5, "fName1 lName1");
}

void shouldReturnSpecialOnNoFirstName() {
    Person person;
    string expected = "first_name with unknown last name";

    person.ChangeFirstName(1990, "first_name");
    string actual = person.GetFullName(1990);

    AssertEqual(actual, expected);
}

void shouldReturnSpecialOnNoLastName() {
    Person person;
    string expected = "last_name with unknown first name";

    person.ChangeLastName(1990, "last_name");
    string actual = person.GetFullName(1990);

    AssertEqual(actual, expected);
}

int main() {
    TestRunner runner;
    runner.RunTest(shouldReturnIncognitoOnEmptyData, "shouldReturnIncognitoOnEmptyData");
    runner.RunTest(shouldReturnIncognitoOnNoData, "shouldReturnIncognitoOnNoData");
    runner.RunTest(shouldReturnValueBetween, "shouldReturnValueBetween");
    runner.RunTest(shouldReturnValueTop, "shouldReturnValueTop");
    runner.RunTest(generalTest, "generalTest");
    runner.RunTest(shouldReturnSpecialOnNoFirstName, "shouldReturnSpecialOnNoFirstName");
    runner.RunTest(shouldReturnSpecialOnNoLastName, "shouldReturnSpecialOnNoLastName");

    return 0;
}
