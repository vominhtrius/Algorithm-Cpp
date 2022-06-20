//
// Created by trivm2 on 6/12/22.
//

#ifndef ALGORITHM_CPP_119_GETROWPASCALTRIANGLE_H
#define ALGORITHM_CPP_119_GETROWPASCALTRIANGLE_H
#include "leetcode.h"

class Problem119_getRowTriangle : public Solution {
public:
    Problem119_getRowTriangle() : Solution("119.txt") {

    }

private:
    void readInput(Input &input) override {
        cin >> input.firstInt;
    }

    void doSolve(Input input) override {
        show(getRow(input.firstInt));
    }

    vector<int> getRow(int rowIndex) {
        vector<int> ans(rowIndex + 1, 1);
        for (int i = 0; i <= rowIndex; i++) {
            int prevAnsJ = ans[0];
            for (int j = 1; j < i; j++) {
                int t = ans[j];
                printf("%d %d %d \n", j, prevAnsJ, ans[j]);
                ans[j] = ans[j] + prevAnsJ;
                prevAnsJ = t;

            }
            cout << endl;
        }

        return ans;
    }
};

#endif //ALGORITHM_CPP_119_GETROWPASCALTRIANGLE_H
