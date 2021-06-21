#include <string>

using namespace std;

string minString(string firstString, string secondString, string thirdString) {
    if (firstString <= secondString && firstString <= thirdString) {
        return firstString;
    }

    if (secondString <= thirdString) {
        return secondString;
    }

    return thirdString;
}
