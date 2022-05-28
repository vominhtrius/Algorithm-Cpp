//
// Created by trivm2 on 5/28/22.
//

#ifndef ALGORITHM_CPP_443_STRINGCOMPRESSION_H
#define ALGORITHM_CPP_443_STRINGCOMPRESSION_H
#include "leetcode.h"

class Problem442_stringCompression : public Solution {
public:
    Problem442_stringCompression() : Solution("443.txt") {

    }

private:
    void readInput(Input &input) override {
        readVec(input.firstVecChar);
    }

    void doSolve(Input input) override {
        int len = compress(input.firstVecChar);
        for (int i = 0; i < len; i++) {
            cout << input.firstVecChar[i];
        }
    }

    int compress(vector<char>& chars) {
        int i = 0;
        int size = chars.size();
        int c = 1;

        for (int j = 1; j <= size; j++) {
            if (j == size || chars[j] != chars[j - 1]) {
                chars[i++] = chars[j - 1];
                if (c > 1) {
                    for(auto it : to_string(c)) {
                        chars[i++]=it;
                    }
                }
                c = 0;
            }
            c++;
        }
        return i;
    }
};
#endif //ALGORITHM_CPP_443_STRINGCOMPRESSION_H
