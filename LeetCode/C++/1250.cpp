class Solution {
private:
public:
    bool isGoodArray(vector<int>& nums) {
        int g = nums[0];
        for(int m : nums) g = __gcd(g, m);
        return g == 1;
    }
};
