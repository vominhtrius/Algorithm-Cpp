//
// Created by trivm2 on 6/4/22.
//

#ifndef ALGORITHM_CPP_253_MINMEETINGROOMS_H
#define ALGORITHM_CPP_253_MINMEETINGROOMS_H

#include "leetcode.h"

class Problem253_minMeetingRooms : public Solution {
public:
    Problem253_minMeetingRooms() : Solution("253.txt") {

    }

private:
    void readInput(Input &input) override {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int l, r;
            cin >> l >> r;
            input.firstVec2Int.push_back({l, r});
        }
    }

    void doSolve(Input input) override {
        show(minMeetingRooms(input.firstVec2Int));
    }

    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        const int n = intervals.size();
        pq.emplace(intervals[0][1], intervals[0][0]);

        for (int i = 1; i < n; i++) {
            auto pr = pq.top();
            if (pr.first <= intervals[i][0]) {
                pq.pop();
            }
            pq.emplace(intervals[i][1], intervals[i][0]);
        }

        return pq.size();
    }
};

#endif //ALGORITHM_CPP_253_MINMEETINGROOMS_H
