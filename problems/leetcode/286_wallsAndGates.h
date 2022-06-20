//
// Created by trivm2 on 6/19/22.
//

#ifndef ALGORITHM_CPP_286_WALLSANDGATES_H
#define ALGORITHM_CPP_286_WALLSANDGATES_H

#include "leetcode.h"
#include <stack>

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

class Problem286_wallsAndGates : public Solution {
public:
    Problem286_wallsAndGates() : Solution("286.txt") {

    }

private:
    void readInput(Input &input) override {
        readVec2(input.firstVec2Int);
    }

    void doSolve(Input input) override {
        wallsAndGates(input.firstVec2Int);
        show(input.firstVec2Int);
    }

    void wallsAndGates(vector<vector<int>> &rooms) {
        int m = rooms.size();
        int n = rooms[0].size();

        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < rooms[i].size(); j++) {
                if (rooms[i][j] == 0) {
                    // BFS
                    q.push({i, j});
                }
            }
        }

        while (!q.empty()) {
            auto pr = q.front();
            q.pop();
            // traver all neighbor
            for (int i = 0; i < 4; i++) {
                int x = pr.first + dx[i];
                int y = pr.second + dy[i];

                if (x < 0 || x >= m || y < 0 || y >= n) continue;

                if (rooms[x][y] == -1 || rooms[x][y] != INT_MAX) continue;
                rooms[x][y] = rooms[pr.first][pr.second] + 1;
                q.push({x, y});
            }
        }
    }
};

#endif //ALGORITHM_CPP_286_WALLSANDGATES_H
