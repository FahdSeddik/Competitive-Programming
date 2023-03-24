class Solution {
public:
    int catMouseGame(vector<vector<int>> &graph) {
        int n = graph.size();
        vector<vector<vector<unsigned int>>> status(
            2, vector<vector<unsigned int>>(n, vector<unsigned int>(n)));

        function<void(int, int, int)> visit = [&](int k, int i, int j) {
            for (int i1 : graph[j]) {
                int k1 = (k + 1) % 2, j1 = i, s = status[k][i][j] & 3;
                unsigned int &t = status[k1][i1][j1];
                if ((t & 3) == 0 && (s == 2 || s == 1 && (t -= 4) < 4)) {
                    t = 3 - s;
                    visit(k1, i1, j1);
                }
            }
        };

        for (int i = 1; i < n; i++) {
            status[0][i][i] = 2;
            status[1][i][i] = 1;
            status[1][i][0] = 2; 
            status[0][i][0] = 1; 

            for (int j = 1; j < n; j++)
            for (int k = 0; k < 2; k++) status[k][i][j] += graph[i].size() * 4;
        }

        for (int i = 1; i < n; i++) {
            visit(0, i, i);
            visit(1, i, i);
            visit(1, i, 0);
            visit(0, i, 0);
        }
        int res = status[0][1][2] & 3;
        return res;
    }
};