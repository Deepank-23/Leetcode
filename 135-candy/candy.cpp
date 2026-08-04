class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n, 1);  // everyone starts with 1 candy

        // Pass 1: left to right — compare to LEFT neighbor only
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i-1]) {
                candies[i] = candies[i-1] + 1;
            }
        }

        // Pass 2: right to left — compare to RIGHT neighbor only
        for (int i = n-2; i >= 0; i--) {
            if (ratings[i] > ratings[i+1]) {
                candies[i] = max(candies[i], candies[i+1] + 1);
            }
        }

        // Sum up all candies
        int total = 0;
        for (int c : candies) total += c;
        return total;
    }
};