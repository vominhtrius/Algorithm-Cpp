//
// Created by trivm2 on 5/28/22.
//

#ifndef ALGORITHM_CPP_118_PASCALTRIANGLE_H
#define ALGORITHM_CPP_118_PASCALTRIANGLE_H

#include "leetcode.h"

class Problem118_pascalTriangle : public Solution {
public:
    Problem118_pascalTriangle() : Solution("118.txt") {

    }

private:
    void readInput(Input &input) override {
        cin >> input.firstInt;
    }

    void doSolve(Input input) override {
        auto ans = generate(input.firstInt);
        show(ans);
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        for (int i = 0; i < numRows; i++) {
            ans.emplace_back(i + 1, 1);
            if (i < 2) continue;

            for (int j = 1; j < i; j++) {
                ans[i][j] = ans[i - 1][j] +  ans[i - 1][j - 1];
            }
        }

        return ans;
    }
};
#endif //ALGORITHM_CPP_118_PASCALTRIANGLE_H
