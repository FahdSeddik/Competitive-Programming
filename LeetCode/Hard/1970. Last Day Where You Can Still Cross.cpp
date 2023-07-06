class Solution {
    short static inline dsu[20000 + 2]; 
    char const static inline dx[] = {1, 1, 0, 1, -1, 0, -1, -1, 1};    
    public:    
    int latestDayToCross(int const m, int const n, vector<vector<int>> const& cells) {
        short left{20000-1 + 1}, right{20000-1 + 2};
        fill_n(dsu, m*n, -1); // init
        dsu[left] = left; dsu[right] = right; // init
        for(short day{0}; day < size(cells); ++day) {
            short const i = cells[day][0]-1, j = cells[day][1]-1, ij = i*n + j;
            dsu[ij] = (j == 0) ? dsuFind(left) : (j == n-1) ? dsuFind(right) : ij;
            // join neigbours
            for(char x{0}; x < 8; ++x) {
                short const i2 = i + dx[x], j2 = j + dx[x+1], i2j2 = i2*n + j2;
                if(0 <= i2 && i2 < m && 0 <= j2 && j2 < n && dsu[i2j2] >= 0) {
                    dsu[dsuFind(ij)] = dsuFind(i2j2); // join
                }
            }
            if(dsuFind(left) == dsuFind(right)) {
                return day;
            }
        }
        return -911; // never
    }
    short dsuFind(short const i) {
        return dsu[i] = (dsu[i] < 0 || dsu[i] == i) ? i : dsuFind(dsu[i]);
    }
};