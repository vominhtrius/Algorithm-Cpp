//
// Created by trivm2 on 5/28/22.
//

#ifndef ALGORITHM_CPP_283_MOVEZEROES_H
#define ALGORITHM_CPP_283_MOVEZEROES_H
#include "leetcode.h"

class Problem283_moveZeroes : public Solution {
public:
    Problem283_moveZeroes() : Solution("283.txt") {

    }

private:
    void readInput(Input &input) override {
        readVec(input.firstVecInt);
    }

    void doSolve(Input input) override {
        moveZeroes(input.firstVecInt);
        show(input.firstVecInt);
    }

    void moveZeroes(vector<int>& nums) {
        const int n = nums.size();
        for (int i = 0, j = 0; i < n; i++) {
            if (nums[i] != 0) {
                swap(nums[i], nums[j++]);
            }
        }
    }
};
#endif //ALGORITHM_CPP_283_MOVEZEROES_H
