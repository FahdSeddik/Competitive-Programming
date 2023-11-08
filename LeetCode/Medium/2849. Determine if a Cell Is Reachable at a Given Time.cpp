class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int dx = abs(sx - fx);
        int dy = abs(sy - fy);
        int mn = min(dx, dy);
        int moves = dx - mn + dy;
        if (moves > t) return false;
        if (moves == 0 && t - moves == 1) return false;
        return true;
    }
};