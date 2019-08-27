class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int element = nums[0], pos = 1;
        int cnt = 1;
        while (pos < nums.size()) {
            if (nums[pos] != element) {
                element = nums[pos];
                nums[cnt++] = element;
            }
            ++pos;
        }
        return cnt;
    }
};