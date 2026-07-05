class Solution {
public:
    const int MOD = 1e9 + 7;

    int maxPathSum(vector<string>& board) {

        int n = board.size();

        priority_queue<pair<int,pair<int,int>>> pq;
        vector<vector<int>> dist(n, vector<int>(n, -1));

        dist[n-1][n-1] = 0;
        pq.push({0, {n-1, n-1}});

        int dx[3] = {-1, 0, -1};
        int dy[3] = {0, -1, -1};

        while (!pq.empty()) {

            auto cur = pq.top();
            pq.pop();

            int score = cur.first;
            int x = cur.second.first;
            int y = cur.second.second;

            if (score != dist[x][y]) continue;

            for (int k = 0; k < 3; k++) {

                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx < 0 || ny < 0) continue;
                if (board[nx][ny] == 'X') continue;

                int val = 0;
                if (board[nx][ny] >= '1' && board[nx][ny] <= '9')
                    val = board[nx][ny] - '0';

                int newScore = score + val;

                if (newScore > dist[nx][ny]) {
                    dist[nx][ny] = newScore;
                    pq.push({newScore, {nx, ny}});
                }
            }
        }

        return dist[0][0];
    }

    int countMaxPaths(vector<string>& board, int mx) {

        int n = board.size();

        vector<vector<int>> best(n, vector<int>(n, -1));
        vector<vector<int>> ways(n, vector<int>(n, 0));

        best[n-1][n-1] = 0;
        ways[n-1][n-1] = 1;

        for (int i = n - 1; i >= 0; i--) {

            for (int j = n - 1; j >= 0; j--) {

                if (board[i][j] == 'X') continue;
                if (i == n - 1 && j == n - 1) continue;

                int mxPrev = -1;

                if (i + 1 < n) mxPrev = max(mxPrev, best[i + 1][j]);
                if (j + 1 < n) mxPrev = max(mxPrev, best[i][j + 1]);
                if (i + 1 < n && j + 1 < n)
                    mxPrev = max(mxPrev, best[i + 1][j + 1]);

                if (mxPrev == -1) continue;

                best[i][j] = mxPrev;

                if (board[i][j] >= '1' && board[i][j] <= '9')
                    best[i][j] += board[i][j] - '0';

                long long cnt = 0;

                if (i + 1 < n && best[i + 1][j] == mxPrev)
                    cnt += ways[i + 1][j];

                if (j + 1 < n && best[i][j + 1] == mxPrev)
                    cnt += ways[i][j + 1];

                if (i + 1 < n && j + 1 < n &&
                    best[i + 1][j + 1] == mxPrev)
                    cnt += ways[i + 1][j + 1];

                ways[i][j] = cnt % MOD;
            }
        }

        if (best[0][0] != mx) return 0;
        return ways[0][0];
    }

    vector<int> pathsWithMaxScore(vector<string>& board) {

        int mx = maxPathSum(board);

        if (mx == -1)
            return {0, 0};

        return {mx, countMaxPaths(board, mx)};
    }
};