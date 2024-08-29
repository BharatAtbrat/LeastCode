//Similar to no. of islands , but this time we need to find the area of the biggest island
//since we are already using dfs to count the number of land pieces we just add them together 
//all 4 directions and return the area and return the max area so far 

//TC O(m*n)
//SC O(m*n)


class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int ar = 0;
        int area = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // call dfs if element is 1
                if (grid[i][j] == 1) {
                    area = max(area, dfs(grid, i, j, m, n));
                }
            }
        }
        return area;
    }

private:
    int dfs(vector<vector<int>>& grid, int i, int j, int m, int n) {
        // base case for dfs
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) {
            return 0;
        }
        grid[i][j] = 0;
        // marking the grid as zero
        // to ensure =1 wali condn na accept hojaye for nodes we have already
        // visited ow we iterate through 4 directions using dfs

        return (1 + dfs(grid, i + 1, j, m, n) + dfs(grid, i - 1, j, m, n) +
                dfs(grid, i, j + 1, m, n) + dfs(grid, i, j - 1, m, n));
        // we are adding the area of all islands together
        // and returning it (its building upon max area of island)
    }
};