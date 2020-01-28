#include "../LeetCode/leetcode_helper.hpp"

class Solution {
   public:
    int findUnsortedSubarray(vector<int> &nums) {
        int minVal = INT_MAX, maxVal = INT_MIN;
        bool flag = false;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1]) flag = true;
            if (flag && nums[i] < minVal) minVal = nums[i];
        }

        if (!flag) { // already sorted.
            return 0;
        }

        flag = false;
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (nums[i] > nums[i + 1]) flag = true;
            if (flag && nums[i] > maxVal) maxVal = nums[i];
        }

        int minLeftPos = 0, maxRightPos = nums.size() - 1;

        while (minLeftPos < nums.size() && nums[minLeftPos] <= minVal) ++minLeftPos;
        while (maxRightPos >= 0 && nums[maxRightPos] >= maxVal) --maxRightPos;

        return maxRightPos - minLeftPos + 1;
    }
};

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);

        int ret = Solution().findUnsortedSubarray(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}