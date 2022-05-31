//
// Created by trivm2 on 5/31/22.
//

#ifndef ALGORITHM_CPP_56_MERGEINTERVALS_H
#define ALGORITHM_CPP_56_MERGEINTERVALS_H

#include "leetcode.h"

class Problem56_mergeIntervals : public Solution {
public:
    Problem56_mergeIntervals() : Solution("56.txt") {

    }

private:
    void readInput(Input &input) override {
        int n;
        int l, r;
        cin >> n;

        for (int i = 0; i < n; i++) {
            cin >> l >> r;
            vector<int> a;
            a.push_back(l);
            a.push_back(r);
            input.firstVec2Int.push_back(a);
        }
    }

    void doSolve(Input input) override {
        show(merge(input.firstVec2Int));
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;

        for (auto interval : intervals) {
            if (ans.empty() || ans.back()[1] < interval[0]) {
                ans.push_back(interval);
            } else {
                ans.back()[1] = std::max(ans.back()[1], interval[1]);
            }
        }
        return ans;
    }
};
#endif //ALGORITHM_CPP_56_MERGEINTERVALS_H
