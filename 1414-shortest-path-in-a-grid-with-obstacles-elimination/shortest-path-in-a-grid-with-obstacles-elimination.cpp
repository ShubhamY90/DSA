// 1st iteration: DFS -> TLE
// 2nd iteration: Thought of memoization

/*
Key observations:

    Hum 4 adjacent cells pe jayenge.

    Agar obstacle hai aur k > 0 hai toh usko remove karke bhi dekh sakte hain.
    Agar obstacle hai aur k == 0 hai toh uss direction me nhi ja sakte.
    Agar obstacle nhi hai toh normally move karenge.

Why DFS + Memoization doesn't work:

    State (i,j,k) lag rha tha sufficient hai, lekin grid ek graph hai jisme cycles hain.

    Example:

            A <----> B

    helper(A,k)
        -> helper(B,k)
                -> helper(A,k)

    Jab helper(A,k) dobara call hota hai tab dp[A][k] abhi compute hi nhi hua hota,
    isliye memoization recursion ko stop nhi kar pata.

    Agar visited[][] use karte hain toh cycle toh ruk jati hai,
    lekin ab answer visited cells pe bhi depend karega.
    Matlab dp(i,j,k) valid state nhi bachta.

    Isliye DFS + Memoization is problem ke liye correct formulation nhi hai.

Why BFS works:

    Har move ki cost exactly 1 hai.
    Isliye BFS shortest path guarantee karta hai.

    State = (row, col, remainingK)

    Agar obstacle mila aur remainingK > 0:
        obstacle remove karke remainingK-1 ke sath move karenge.

    Agar obstacle nhi hai:
        normally move karenge.

Visited:

    visited[row][col][remainingK]

    Same cell pe dobara aa sakte hain agar is baar zyada obstacle eliminations
    bachi hui hain.

Time Complexity:
    O(n * m * k)

Space Complexity:
    O(n * m * k)
*/

class Solution {
public:
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};

    int shortestPath(vector<vector<int>>& grid, int k) {

        int n = grid.size();
        int m = grid[0].size();

        // vis[row][col][remainingK]
        vector<vector<vector<bool>>> vis(
            n,
            vector<vector<bool>>(m, vector<bool>(k + 1, false))
        );

        // {row, col, remainingK, distance}
        queue<tuple<int,int,int,int>> q;

        q.push({0, 0, k, 0});
        vis[0][0][k] = true;

        while(!q.empty()) {

            auto [i, j, rem, dist] = q.front();
            q.pop();

            if(i == n - 1 && j == m - 1)
                return dist;

            for(int d = 0; d < 4; d++) {

                int ni = i + dx[d];
                int nj = j + dy[d];

                if(ni < 0 || nj < 0 || ni >= n || nj >= m)
                    continue;

                // Empty cell
                if(grid[ni][nj] == 0) {

                    if(!vis[ni][nj][rem]) {
                        vis[ni][nj][rem] = true;
                        q.push({ni, nj, rem, dist + 1});
                    }
                }

                // Obstacle
                else {

                    if(rem > 0 && !vis[ni][nj][rem - 1]) {
                        vis[ni][nj][rem - 1] = true;
                        q.push({ni, nj, rem - 1, dist + 1});
                    }
                }
            }
        }

        return -1;
    }
};