// Time  : 0 ms
// Memory: 8.8 MB

class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> res(num_people);
        int i = 0, perPeopleCandies = 1;
        while (candies) {
            res[i] += min(perPeopleCandies, candies);
            candies -= min(perPeopleCandies, candies);
            i = (i + 1) % num_people;
            ++perPeopleCandies;
        }
        return res;
    }
};
