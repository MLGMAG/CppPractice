#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Human {
public:
    Human(const string &name, const string &speciality) : Name(name), Speciality(speciality) {}

    virtual void Walk(const string &destination) const = 0;

    const string &getName() const {
        return Name;
    }

    const string &getSpeciality() const {
        return Speciality;
    }

    virtual ~Human() = default;

protected:
    const string Name;
    const string Speciality;
};

class Student : public Human {
public:

    Student(const string &name, const string &favouriteSong) : Human(name, "Student"), FavouriteSong(favouriteSong) {}

    void Walk(const string &destination) const override {
        cout << "Student: " << Name << " walks to: " << destination << endl;
        cout << "Student: " << Name << " sings a song: " << FavouriteSong << endl;
    }

    void Learn() {
        cout << "Student: " << Name << " learns" << endl;
    }

    void SingSong() {
        cout << "Student: " << Name << " sings a song: " << FavouriteSong << endl;
    }

private:
    const string FavouriteSong;
};


class Teacher : public Human {
public:

    Teacher(const string &name, const string &subject) : Human(name, "Teacher"), Subject(subject) {}

    void Walk(const string &destination) const override {
        cout << "Teacher: " << Name << " walks to: " << destination << endl;
    }

    void Teach() const {
        cout << "Teacher: " << Name << " teaches: " << Subject << endl;
    }

private:
    const string Subject;
};


class Policeman : public Human {
public:
    Policeman(const string &name) : Human(name, "Policeman") {
    }

    void Walk(const string &destination) const override {
        cout << "Policeman: " << Name << " walks to: " << destination << endl;
    }

    void Check(const Human &human) {
        cout << "Policeman: " << Name << " checks " << human.getSpeciality() << ". "
             << human.getSpeciality() << "'s name is: " << human.getName() << endl;
    }
};

void VisitPlaces(const Human &human, const vector<string> &places) {
    for (const auto &p : places) {
        human.Walk(p);
    }
}


int main() {
    Teacher t("Jim", "Math");
    Student s("Ann", "We will rock you");
    Policeman p("Bob");

    VisitPlaces(t, {"Moscow", "London"});
    p.Check(s);
    VisitPlaces(s, {"Moscow", "London"});
    return 0;
}
