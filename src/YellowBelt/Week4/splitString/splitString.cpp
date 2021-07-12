#include "splitString.h"

vector<string> SplitIntoWords(const string &s) {
    vector<string> words;
    auto tempIter = s.begin();
    for (auto i = begin(s); i < end(s); ++i) {
        if (*i == ' ') {
            string word = string(tempIter, i);
            words.push_back(word);
            tempIter = i + 1;
        }
    }

    string word = string(tempIter, end(s));
    words.push_back(word);
    return words;
}

