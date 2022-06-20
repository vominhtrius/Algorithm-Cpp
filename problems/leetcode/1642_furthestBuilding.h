//
// Created by trivm2 on 6/12/22.
//

#ifndef ALGORITHM_CPP_1642_FURTHESTBUILDING_H
#define ALGORITHM_CPP_1642_FURTHESTBUILDING_H

#include "leetcode.h"

class Problem1642_furthestBuilding : public Solution {
public:
    Problem1642_furthestBuilding() : Solution("1642.txt") {

    }

private:
    void readInput(Input &input) override {
        readVec(input.firstVecInt);
        cin >> input.secondInt >> input.thirdInt;
    }

    void doSolve(Input input) override {
        show(furthestBuilding(input.firstVecInt, input.secondInt, input.thirdInt));
    }

    int furthestBuilding(vector<int> &heights, int bricks, int ladders) {
        priority_queue<pair<int, int>> heap;
        const int size = heights.size();
        int total = 0;
        for (int i = 1; i < size; i++) {
            int dis = heights[i] - heights[i - 1];
            if (dis > 0) {
                heap.push({dis, i});
                total += dis;
            }
        }

        for (int i = size - 1; i > 0; i--) {

            while (ladders > 0 && !heap.empty()) {
                auto pr = heap.top();
                heap.pop();

                if (pr.second <= i) {
                    total -= pr.first;
                    ladders--;
                }
            }

            if (bricks >= total) {
                return i;
            }
            int dis = heights[i] - heights[i - 1];
            if (dis <= 0) {
                continue;
            }

            if (!heap.empty()) {
                if (dis > heap.top().first) {
                    ladders++;
                } else if (dis == heap.top().first && i > heap.top().second) {
                    ladders++;
                }else if (dis < heap.top().first) {
                    total -= dis;
                } else if (heap.top().second == i) {
                    heap.pop();
                    total -= dis;
                }
            }
        }

        return 0;
    }
};

#endif //ALGORITHM_CPP_1642_FURTHESTBUILDING_H
