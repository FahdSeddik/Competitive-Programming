/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

Node* zero = new Node(false, true);
Node* one = new Node(true, true);

class Solution {
public:
    Node* construct(vector<vector<int>>& v) {
        return construct(v, 0, 0, v.size());    
    }
private:
    Node* construct(const vector<vector<int>>& v, int x, int y, int sz) {
        if (sz == 1) {
            return v[x][y] == 1 ? one : zero;
        }
        int hsz = sz / 2;
        Node *tl = construct(v, x, y, hsz);
        Node *tr = construct(v, x, y+hsz, hsz);
        Node *bl = construct(v, x+hsz, y, hsz);
        Node *br = construct(v, x+hsz, y+hsz, hsz);
        if (tl == tr && bl == br && tl == bl) {
            return tl;
        }
        return new Node(false, false, tl, tr, bl, br);
    }
};