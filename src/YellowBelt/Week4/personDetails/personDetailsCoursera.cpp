#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void PrintStats(vector<Person> persons) {
    cout << "Median age = " << ComputeMedianAge(begin(persons), end(persons)) << endl;

    vector<Person>::iterator iter;
    iter = partition(begin(persons), end(persons),
                     [](const Person &person) { return person.gender == Gender::FEMALE; });
    cout << "Median age for females = " << ComputeMedianAge(begin(persons), iter) << endl;

    iter = partition(begin(persons), end(persons), [](const Person &person) { return person.gender == Gender::MALE; });
    cout << "Median age for males = " << ComputeMedianAge(begin(persons), iter) << endl;

    iter = partition(begin(persons), end(persons), [](const Person &person) {
        return person.gender == Gender::FEMALE && person.is_employed;
    });
    cout << "Median age for employed females = " << ComputeMedianAge(begin(persons), iter) << endl;

    iter = partition(begin(persons), end(persons), [](const Person &person) {
        return person.gender == Gender::FEMALE && !person.is_employed;
    });
    cout << "Median age for unemployed females = " << ComputeMedianAge(begin(persons), iter) << endl;

    iter = partition(begin(persons), end(persons), [](const Person &person) {
        return person.gender == Gender::MALE && person.is_employed;
    });
    cout << "Median age for employed males = " << ComputeMedianAge(begin(persons), iter) << endl;

    iter = partition(begin(persons), end(persons), [](const Person &person) {
        return person.gender == Gender::MALE && !person.is_employed;
    });
    cout << "Median age for unemployed males = " << ComputeMedianAge(begin(persons), iter) << endl;
}
