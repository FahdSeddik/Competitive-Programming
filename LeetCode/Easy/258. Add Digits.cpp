class Solution {
public:
    int addDigits(int num) {
        if(num==0)return 0;
        if(num%9==0)return 9;
        return num%9;
    }
};

/*
0->0
->1
->2
->9
10->1
11->2
12->3
18->9
19->1
20->2
21->3
...
27->9
28->10->1
29->11->2

37->1
38->2
39->3

*/