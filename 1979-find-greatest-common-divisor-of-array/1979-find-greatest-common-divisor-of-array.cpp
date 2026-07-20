class Solution {
public:
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    int findGCD(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        int min = nums[0];
        int max = nums[n-1];

        return gcd(min , max);
    }
};