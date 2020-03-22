#include <iostream>
#include <vector>
#include <array>
#include <queue>
using namespace std;

class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        if (grid.size() == 1 && grid[0].size() == 1) return true;
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<bool>> g(rows, vector<bool>(cols, false));
        // vector<vector<bool>> g;
        // for (int i=0; i<rows;++i) g.push_back(vector<bool>(cols, false));
        g[0][0] = true;
        int r = 0, c = 0;
        queue<pair<int, int>> q;
        q.push({0, 0});
        while (!q.empty()) {
            r = q.front().first;
            c = q.front().second;
            q.pop();
            if (r == rows-1 && c == cols-1) return true;
            switch (grid[r][c])
            {
            case 1:
                if (c > 0 && !g[r][c-1] && (grid[r][c-1] == 1 || grid[r][c-1] == 4 || grid[r][c-1] == 6)) {
                    g[r][c-1] = true;
                    q.push({r, c-1});
                }
                if (c < cols - 1 && !g[r][c+1] && (grid[r][c+1] == 1 || grid[r][c+1] == 3 || grid[r][c+1] == 5)) {
                    g[r][c+1] = true;
                    q.push({r, c+1});
                }
                break;
            case 2:
                if (r > 0 && !g[r-1][c] && (grid[r-1][c] == 2 || grid[r-1][c] == 4 || grid[r-1][c] == 3)) {
                    g[r-1][c] = true;
                    q.push({r-1, c});
                }
                if (r < rows - 1 && !g[r+1][c] && (grid[r+1][c] == 2 || grid[r+1][c] == 6 || grid[r+1][c] == 5)) {
                    g[r+1][c] = true;
                    q.push({r+1, c});
                }
                break;
            case 3:
                if (c > 0 && !g[r][c-1] && (grid[r][c-1] == 1 || grid[r][c-1] == 4 || grid[r][c-1] == 6)) {
                    g[r][c-1] = true;
                    q.push({r, c-1});
                }
                if (r < rows - 1 && !g[r+1][c] && (grid[r+1][c] == 2 || grid[r+1][c] == 6 || grid[r+1][c] == 5)) {
                    g[r+1][c] = true;
                    q.push({r+1, c});
                }
                break;
            case 4:
                if (c < cols - 1 && !g[r][c+1] && (grid[r][c+1] == 1 || grid[r][c+1] == 3 || grid[r][c+1] == 5)) {
                    g[r][c+1] = true;
                    q.push({r, c+1});
                }
                if (r < rows - 1 && !g[r+1][c] && (grid[r+1][c] == 2 || grid[r+1][c] == 6 || grid[r+1][c] == 5)) {
                    g[r+1][c] = true;
                    q.push({r+1, c});
                }
                break;
            case 5:
                if (c > 0 && !g[r][c-1] && (grid[r][c-1] == 1 || grid[r][c-1] == 4 || grid[r][c-1] == 6)) {
                    g[r][c-1] = true;
                    q.push({r, c-1});
                }
                if (r > 0 && !g[r-1][c] && (grid[r-1][c] == 2 || grid[r-1][c] == 4 || grid[r-1][c] == 3)) {
                    g[r-1][c] = true;
                    q.push({r-1, c});
                }
                break;
            case 6:
                if (c < cols - 1 && !g[r][c+1] && (grid[r][c+1] == 1 || grid[r][c+1] == 3 || grid[r][c+1] == 5)) {
                    g[r][c+1] = true;
                    q.push({r, c+1});
                }
                if (r > 0 && !g[r-1][c] && (grid[r-1][c] == 2 || grid[r-1][c] == 4 || grid[r-1][c] == 3)) {
                    g[r-1][c] = true;
                    q.push({r-1, c});
                }
                break;
            default:
                break;
            }
        }
        return false;
    }
};
