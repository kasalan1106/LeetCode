class Solution {
public:
    int jump(vector<int>& nums) {
        int jumpTimes = 0;

        int lastLowerLimit = 0;
        int lastUpperLimit = 0;

        int currentUpperLimit = lastUpperLimit + 1;
        int currentLowerLimit = lastUpperLimit + 1;
        int numsSize = nums.size();
        while(lastUpperLimit < numsSize-1)
        {
            jumpTimes ++;

            currentLowerLimit = lastUpperLimit + 1;

            for(int i = lastLowerLimit; i <= lastUpperLimit; i++)
            {
                if(currentUpperLimit < i + nums.at(i))
                    currentUpperLimit = i + nums.at(i);
            }

            lastLowerLimit = currentLowerLimit;
            lastUpperLimit = currentUpperLimit;
        }
        return jumpTimes;
    }
};
