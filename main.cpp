#include "problems/leetcode/3_lengthOfLongestSubstring.h"
#include "problems/leetcode/167_twoSum_II.h"
#include "problems/leetcode/15_3Sum.h"
#include "problems/leetcode/242_isAnagram.h"
#include "problems/leetcode/54_spiralOrder.h"
#include "problems/leetcode/88_mergeSortedArray.h"
#include "problems/leetcode/118_pascalTriangle.h"
#include "problems/leetcode/283_moveZeroes.h"
#include "problems/leetcode/443_stringCompression.h"
#include "problems/leetcode/560_subarraySumEqualK.h"
#include "problems/leetcode/56_mergeIntervals.h"
#include "problems/leetcode/33_searchInRotatedSortedArray.h"
#include "problems/leetcode/4_findMedianSortedArrays.h"
#include "problems/leetcode/problem_chotot.h"
#include "problems/leetcode/239_maxSlidingWindow.h"
#include "problems/leetcode/253_minMeetingRooms.h"
#include "problems/leetcode/119_getRowPascalTriangle.h"
#include "problems/leetcode/1642_furthestBuilding.h"
#include "problems/leetcode/286_wallsAndGates.h"

//#include "problems/leetcode/"

Solution *getSolution() {
    return new Problem286_wallsAndGates();
}

int main() {
    Solution *solution = getSolution();

#ifdef LOCAL
    string filePath = solution->getInputPath();
    FILE *file = freopen(solution->getInputPath().c_str(), "r+", stdin);
    if (file == nullptr) {
        cout << filePath << " NOT FOUND" << endl;
    }

//    freopen("../OUTPUT.txt", "w", stdout);
#endif

    solution->solve();
    return 0;
}
