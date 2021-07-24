#include <string>
#include <iostream>
#include <iomanip>
#include <memory>
#include <vector>
#include <cmath>

using namespace std;

class Figure {
public:
    virtual const string &Name() = 0;

    virtual const double &Perimeter() = 0;

    virtual const double &Area() = 0;
};

class Triangle : public Figure {
public:
    Triangle(double a, double b, double c) :
            perimeter(calculatePerimeter(a, b, c)),
            area(calculateArea(a, b, c)) {}

    const string &Name() override {
        return name_;
    }

    const double &Perimeter() override {
        return perimeter;
    }

    const double &Area() override {
        return area;
    }

private:
    const string name_ = "TRIANGLE";
    const double perimeter;
    const double area;

    static double calculatePerimeter(const double &a, const double &b, const double &c) {
        return a + b + c;
    }

    double calculateArea(const double &a, const double &b, const double &c) const {
        double halfPerimeter = perimeter / 2;
        double underSquare = halfPerimeter * (halfPerimeter - a) * (halfPerimeter - b) * (halfPerimeter - c);
        return sqrt(underSquare);
    }
};

class Rect : public Figure {

public:
    Rect(double a, double b) :
            perimeter(calculatePerimeter(a, b)),
            area(calculateArea(a, b)) {}

    const string &Name() override {
        return name_;
    }

    const double &Perimeter() override {
        return perimeter;
    }

    const double &Area() override {
        return area;
    }

private:
    const string name_ = "RECT";
    const double perimeter;
    const double area;

    static double calculatePerimeter(const double &a, const double &b) {
        return 2 * (a + b);
    }

    static double calculateArea(const double &a, const double &b) {
        return a * b;
    }
};

class Circle : public Figure {
public:
    Circle(double radius) :
            perimeter(calculatePerimeter(radius)),
            area(calculateArea(radius)) {}

    const string &Name() override {
        return name_;
    }

    const double &Perimeter() override {
        return perimeter;
    }

    const double &Area() override {
        return area;
    }

private:
    const string name_ = "CIRCLE";
    const double perimeter;
    const double area;

    static double calculatePerimeter(const double &radius) {
        return 2 * 3.14 * radius;
    }

    static double calculateArea(const double &radius) {
        return 3.14 * pow(radius, 2);
    }
};

shared_ptr<Figure> CreateFigure(istringstream &is) {
    string figureName;
    is >> figureName;

    shared_ptr<Figure> figure;

    if (figureName == "TRIANGLE") {
        int a;
        int b;
        int c;
        is >> a >> b >> c;
        figure = make_shared<Triangle>(a, b, c);
    } else if (figureName == "RECT") {
        int a;
        int b;
        is >> a >> b;
        figure = make_shared<Rect>(a, b);
    } else {
        int radius;
        is >> radius;
        figure = make_shared<Circle>(radius);
    }

    return figure;
}

int main() {
    vector<shared_ptr<Figure>> figures;
    for (string line; getline(cin, line);) {
        istringstream is(line);

        string command;
        is >> command;
        if (command == "ADD") {
            is >> ws;
            figures.push_back(CreateFigure(is));
        } else if (command == "PRINT") {
            for (const auto &current_figure : figures) {
                cout << fixed << setprecision(3)
                     << current_figure->Name() << " "
                     << current_figure->Perimeter() << " "
                     << current_figure->Area() << endl;
            }
        }
    }
    return 0;
}
