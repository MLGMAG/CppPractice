#include <cmath>
#include <vector>

using namespace std;

double calculateDiscriminant(double k1, double k2, double k3);

vector<double> calculateLinearEquation(double k1, double k2);

vector<double> calculateRoots(double k1, double k2, double k3) {
    if (k1 == 0) {
        return calculateLinearEquation(k2, k3);
    }

    double discriminant = calculateDiscriminant(k1, k2, k3);

    if (discriminant < 0) {
        return vector<double>{};
    }

    if (discriminant == 0) {
        double root = -k2 / (2 * k1);
        return vector<double>{root};
    }

    double first_root = (-k2 + sqrt(discriminant)) / (2 * k1);
    double second_root = (-k2 - sqrt(discriminant)) / (2 * k1);

    return vector<double>{first_root, second_root};
}

double calculateDiscriminant(double k1, double k2, double k3) {
    return pow(k2, 2) - 4 * k1 * k3;
}

vector<double> calculateLinearEquation(double k1, double k2) {
    if (k1 != 0) {
        double root = -k2 / k1;
        return vector<double>{root};
    }

    return vector<double>{};
}
