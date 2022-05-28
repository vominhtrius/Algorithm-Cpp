//
// Created by trivm2 on 5/28/22.
//

#ifndef ALGORITHM_CPP_54_SPIRALORDER_H
#define ALGORITHM_CPP_54_SPIRALORDER_H

#include "leetcode.h"

class Problem54_spiralOrder : public Solution {
public:
    Problem54_spiralOrder() : Solution("54.txt") {}

private:
    void readInput(Input &input) override {
        readVec2(input.firstVec2Int);
    }

    void doSolve(Input input) override {
        show(spiralOrder(input.firstVec2Int));
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        int rows = matrix.size();
        int columns = matrix[0].size();
        vector<int> ans;

        int up = 0;
        int left = 0;
        int right = columns - 1;
        int down = rows - 1;

        while (ans.size() < rows * columns) {
            for (int col = left; col <= right; col++) {
                ans.push_back(matrix[up][col]);
            }

            for (int row = up + 1; row <= down; row++) {
                ans.push_back(matrix[row][right]);
            }

            if (up != down) {
                for (int col = right - 1; col >= left; col--) {
                    ans.push_back(matrix[down][col]);
                }
            }

            if (left != right) {
                for (int row = down - 1; row > up; row--) {
                    ans.push_back(matrix[row][left]);
                }
            }

            left++;
            right--;
            up++;
            down--;
        }

        return ans;
    }
};
#endif //ALGORITHM_CPP_54_SPIRALORDER_H
