class Solution {
public:
    int jump(vector<int>& nums) {
        
        vector<int> steps;
        for(int i = 0; i < nums.size(); i++)
            steps.push_back(-1);
        
        steps[0] = 0;
        
        int calcIndex = 0;
        
        for(int i = 0; (i < nums.size()) && (calcIndex != nums.size()-1); i++)
        {
            for(int j = i; j <= i + nums.at(i); j++)
            {
                if(steps[j] == -1)
                    steps[j] = steps[i] + 1;
            }
            
            calcIndex = i + nums.at(i);
        }
        
        return steps[nums.size()-1];
    }
    
};
