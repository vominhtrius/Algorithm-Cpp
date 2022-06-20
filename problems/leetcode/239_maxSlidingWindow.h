//
// Created by trivm2 on 6/4/22.
//

#ifndef ALGORITHM_CPP_239_MAXSLIDINGWINDOW_H
#define ALGORITHM_CPP_239_MAXSLIDINGWINDOW_H

#include "leetcode.h"

class Problem239_maxSlidingWindow : public Solution {
public:
    Problem239_maxSlidingWindow() : Solution("239.txt") {

    }

private:
    void readInput(Input &input) override {
        readVec(input.firstVecInt);
        cin >> input.secondInt;
    }

    void doSolve(Input input) override {
        show(maxSlidingWindow(input.firstVecInt, input.secondInt));
    }

    vector<int> maxSlidingWindow(vector<int> &a, int k) {
        deque<int> q;
        for (int i = 0; i < k; i++) {
            while (!q.empty() && a[q.back()] <= a[i]) {
                q.pop_back();
            }
            q.push_back(i);
        }

        vector<int> ans;
        if (!q.empty()) {
            ans.push_back(a[q.front()]);
        }

        const int n = a.size();
        for (int i = k; i < n; i++) {
            if (q.front() <= i - k) {
                q.pop_front();
            }

            while (!q.empty() && a[q.back()] < a[i]) {
                q.pop_back();
            }

            q.push_back(i);
            ans.push_back(a[q.front()]);
        }

        return ans;
    }
};

#endif //ALGORITHM_CPP_239_MAXSLIDINGWINDOW_H
