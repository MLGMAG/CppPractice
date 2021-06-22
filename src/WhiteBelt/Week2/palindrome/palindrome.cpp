#include <string>
#include <algorithm>

using namespace std;

bool isPalindromeEven(const string& word) {
    unsigned long partSize = word.size() / 2;
    string firstPart = word.substr(0, partSize);
    string secondPart = word.substr(partSize, partSize);

    reverse(secondPart.begin(), secondPart.end());

    return firstPart == secondPart;
}

bool isPalindromeOdd(const string& word) {
    unsigned long partSize = word.size() / 2;
    string firstPart = word.substr(0, partSize);
    string secondPart = word.substr(partSize + 1, partSize);

    reverse(secondPart.begin(), secondPart.end());

    return firstPart == secondPart;
}

bool isPalindrome(const string& word) {

    if (word.length() == 1) {
        return true;
    }

    if (word.length() % 2 == 0) {
        return isPalindromeEven(word);
    } else {
        return isPalindromeOdd(word);
    }
}
