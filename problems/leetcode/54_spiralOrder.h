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

        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> ans;
        ans.reserve(n * m);

        int rowLevel = 0;
        int columnLevel = 0;

        int row = 0;
        int column = 0;
        int direction = 0;

        while (ans.size() < n * m) {
            // get current row. column
            ans.push_back(matrix[row][column]);
            if (ans.size() == n * m) {
                break;
            }

            if (direction == 0) { // right
                // get
                if (column == m - columnLevel - 1) {
                    // go down
                    direction = 1;
                    column = m - columnLevel - 1;
                    row = rowLevel + 1;
                } else {
                    column++;
                }
            } else if (direction == 1) { //down
                if (row == n - rowLevel - 1) {
                    // go left
                    direction = 2;
                    row = n - rowLevel - 1;
                    column = m - columnLevel - 2;
                } else {
                    row++;
                }
            }  else if (direction == 2) { // left
                if (column == columnLevel) {
                    // go up
                    column = columnLevel;
                    row = n - rowLevel - 2;
                    direction = 3;
                } else {
                    column--;
                }
            } else { // up
                if (row == rowLevel + 1) {
                    // go right
                    direction = 0;
                    rowLevel++;
                    columnLevel++;
                    row = rowLevel;
                    column = columnLevel;
                } else {
                    row--;
                }
            }

        }

        return ans;
    }
};
#endif //ALGORITHM_CPP_54_SPIRALORDER_H
