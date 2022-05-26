class Solution {
public:
    int jump(vector<int>& nums) {
        
        if(nums.size() == 1)
            return 0;
        
        vector<int> increaseIndex;
        increaseIndex.push_back(0);
        
        int calcIndex = 0;
        int lastIndex = 0;
        
        for(int i = 0; i < nums.size() && calcIndex < nums.size(); i++)
        {
            int startIndex = i;
            if(calcIndex > i)
                startIndex = calcIndex;
                
            lastIndex = increaseIndex.at(increaseIndex.size()-1);
            for(int j = startIndex; j <= i + nums.at(i) && j < nums.size(); j++)
            {
                if((j + nums.at(j) > lastIndex))
                    lastIndex = j + nums.at(j);
            }
            
            if(lastIndex > increaseIndex.at(increaseIndex.size()-1) &&
               lastIndex < nums.size())
                increaseIndex.push_back(lastIndex);
        }
        return increaseIndex.size();
    }
};
