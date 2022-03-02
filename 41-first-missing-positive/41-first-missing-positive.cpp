class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
    if (n == 0)
        return 1;
    int id = 0;
    while (id < n)
    {
        if (nums[id] <= 0 || nums[id] > n || nums[id] - 1 == id)
        {
            id++;
            continue;
        }
        // sort this cycle
        {
            int num = nums[id];
            nums[id] = 0;
            int place = id;
            while (num > 0 && num <= n && num != place + 1)
            {

                int new_num = nums[num - 1];
                place = num - 1;
                nums[num - 1] = num;
                num = new_num;
            }
            id++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (nums[i] != i + 1)
        {
            return i + 1;
        }
    }
    return n + 1;
    }
};