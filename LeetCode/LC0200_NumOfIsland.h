#pragma once

#include "LeetCodeDefines.h"
#include "ILeetCodeEntry.h"

class LC0200_NumOfIsland : public ILeetCodeEntry
{
public:
    int MainEntry() override
    {
        //11110
        //11010
        //11000
        //00000
        // 1个
        std::vector<std::vector<char>> inputGrid1;
        inputGrid1.push_back(std::vector<char>({ '1', '1', '1', '1', '0' }));
        inputGrid1.push_back(std::vector<char>({ '1', '1', '0', '1', '0' }));
        inputGrid1.push_back(std::vector<char>({ '1', '1', '0', '0', '0' }));
        inputGrid1.push_back(std::vector<char>({ '0', '0', '0', '0', '0' }));
        std::cout << "LC0200_NumOfIsland --> Result 1 : " << this->NumOfIslands(inputGrid1) << std::endl;

        //11000
        //11000
        //00100
        //00011
        // 3个
        std::vector<std::vector<char>> inputGrid2;
        inputGrid2.push_back(std::vector<char>({ '1', '1', '0', '0', '0' }));
        inputGrid2.push_back(std::vector<char>({ '1', '1', '0', '0', '0' }));
        inputGrid2.push_back(std::vector<char>({ '0', '0', '1', '0', '0' }));
        inputGrid2.push_back(std::vector<char>({ '0', '0', '0', '1', '1' }));
        std::vector<int> input2 = { 2, 2, 2, 0, 1 };
        std::cout << "LC0200_NumOfIsland --> Result 2 : " << this->NumOfIslands(inputGrid2) << std::endl;

        return 0;
    }

public:
    int NumOfIslands(std::vector<std::vector<char>>& grid)
    {
        return this->NumberOfIsland_LowMemery(grid);
        //return this->NumberOfIsland_LowTime(grid);
    }

private:
    int NumberOfIsland_LowMemery(std::vector<std::vector<char>>& grid)
    {
        if (grid.size() == 0) return 0;

        struct GridCell
        {
            int row;
            int col;
        };
        // copy 同等规模矩阵
        std::vector<std::vector<bool>> visited(grid.size(), std::vector<bool>(grid[0].size(), false));
        std::vector<GridCell> islandVec;
        int islandCount = 0;
        size_t maxRow = grid.size();
        size_t maxCol = grid[0].size();

        GridCell nextCell = { 0, 0 };
        GridCell tempCell = { 0, 0 };
        int tempRow = 0, tempCol = 0;

        for (int row = 0; row < maxRow; ++row)
        {
            for (int col = 0; col < maxCol; ++col)
            {
                if (false == visited[row][col])
                {
                    visited[row][col] = true;
                    if ('1' == grid[row][col])
                    {
                        ++islandCount;

                        tempCell.row = row;
                        tempCell.col = col;
                        islandVec.push_back(tempCell);

                        while (islandVec.size() > 0)
                        {
                            tempCell = islandVec.front();
                            islandVec.erase(islandVec.begin());
                            // 上侧
                            tempRow = tempCell.row - 1;
                            tempCol = tempCell.col;
                            if (tempRow >= 0 && false == visited[tempRow][tempCol] && '1' == grid[tempRow][tempCol])
                            {
                                nextCell.row = tempRow;
                                nextCell.col = tempCol;
                                islandVec.push_back(nextCell);
                                visited[tempRow][tempCol] = true;
                            }
                            // 右侧
                            tempRow = tempCell.row;
                            tempCol = tempCell.col + 1;
                            if (tempCol < maxCol && false == visited[tempRow][tempCol] && '1' == grid[tempRow][tempCol])
                            {
                                nextCell.row = tempRow;
                                nextCell.col = tempCol;
                                islandVec.push_back(nextCell);
                                visited[tempRow][tempCol] = true;
                            }
                            // 下侧
                            tempRow = tempCell.row + 1;
                            tempCol = tempCell.col;
                            if (tempRow < maxRow && false == visited[tempRow][tempCol] && '1' == grid[tempRow][tempCol])
                            {
                                nextCell.row = tempRow;
                                nextCell.col = tempCol;
                                islandVec.push_back(nextCell);
                                visited[tempRow][tempCol] = true;
                            }
                            // 左侧
                            tempRow = tempCell.row;
                            tempCol = tempCell.col - 1;
                            if (tempCol >= 0 && false == visited[tempRow][tempCol] && '1' == grid[tempRow][tempCol])
                            {
                                nextCell.row = tempRow;
                                nextCell.col = tempCol;
                                islandVec.push_back(nextCell);
                                visited[tempRow][tempCol] = true;
                            }
                        }
                    }
                }
            }
        }

        return islandCount;
    }

    // breadth first search
    // depth first search
    void dfs(std::vector<std::vector<char>>& grid, int i, int j)
    {
        if (i < 0 || i >= grid.size() ||
            j < 0 || j >= grid[0].size() ||
            grid[i][j] != '1')
            return;
        grid[i][j] = '2';
        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j - 1);
        dfs(grid, i, j + 1);
    }

    int NumberOfIsland_LowTime(std::vector<std::vector<char>>& grid)
    {
        int res = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == '1')
                {
                    res++;
                    dfs(grid, i, j);
                }
            }
        }
        return res;
    }
};
