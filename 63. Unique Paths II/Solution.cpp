class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int resultCount = 0;
        
        vector<vector<int>> vecPathCount;
        initPathCountVec(vecPathCount, obstacleGrid);
        
        return getPathCount(vecPathCount, 0, 0);
    }
    
    void initPathCountVec(vector<vector<int>> &vecPathCount, vector<vector<int>> &obstacleGrid)
    {
        vecPathCount.clear();
        vector<int> tmpVec;
        
        int width = obstacleGrid.size();
        int height = obstacleGrid.at(0).size();
        
        for(int i = 0; i < height; i++)
            tmpVec.push_back(-1);
        for(int j = 0; j < width; j++)
            vecPathCount.push_back(tmpVec);
        
        for(int i = 0; i < width; i++)
            for(int j = 0; j < height; j++)
                if(obstacleGrid[i][j] == 1)
                    vecPathCount[i][j] = 0;
    }
    
    int getPathCount(vector<vector<int>> &vecPathCount, int xIndex, int yIndex)
    {
        if(vecPathCount[xIndex][yIndex] == -1)
            calcPathCountVec(vecPathCount, xIndex, yIndex);
        return vecPathCount[xIndex][yIndex];
    }
    
    void calcPathCountVec(vector<vector<int>> &vecPathCount, int xIndex, int yIndex)
    {
        int width = vecPathCount.size();
        int height = vecPathCount.at(0).size();
        
        if(xIndex == (width-1) && yIndex == (height-1))
            vecPathCount[xIndex][yIndex] = 1;
        else if(xIndex == (width-1) && yIndex < (height-1))
            vecPathCount[xIndex][yIndex] = getPathCount(vecPathCount, xIndex, yIndex+1);
        else if(xIndex < (width-1) && yIndex == (height-1))
            vecPathCount[xIndex][yIndex] = getPathCount(vecPathCount, xIndex+1, yIndex);
        else
            vecPathCount[xIndex][yIndex] = getPathCount(vecPathCount, xIndex+1, yIndex) + getPathCount(vecPathCount, xIndex, yIndex+1);
        
    }
};
