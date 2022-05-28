//
// Created by trivm2 on 5/28/22.
//

#ifndef ALGORITHM_CPP_242_ISANAGRAM_H
#define ALGORITHM_CPP_242_ISANAGRAM_H

#include "leetcode.h"

class Problem242_isAnagram : public Solution {
public:
    Problem242_isAnagram() : Solution("242.txt") {}

private:
    void readInput(Input &input) override {
        cin >> input.firstStr;
        cin >> input.secondStr;
    }

    void doSolve(Input input) override {
        show(isAnagram(input.firstStr, input.secondStr));
    }

    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        int c[256] = {0};

        for (int i = 0; i < s.length(); ++i) {
            c[s[i]]++;
        }

        for (int i = 0; i < t.length(); i++) {
            c[t[i]]--;
            if (c[t[i]] < 0) {
                return false;
            }
        }

        return true;
    }
};

#endif //ALGORITHM_CPP_242_ISANAGRAM_H
