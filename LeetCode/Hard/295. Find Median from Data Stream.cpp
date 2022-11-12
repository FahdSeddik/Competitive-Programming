class MedianFinder {
    priority_queue<int> large;
    priority_queue<int,vector<int>,greater<int>> small;
    bool even;
public:
    MedianFinder() {
        even = true;
    }
    
    void addNum(int num) {
        if(even){
            large.push(num);
            small.push(large.top());
            large.pop();
        }else{
            small.push(num);
            large.push(small.top());
            small.pop();
        }
        even=!even;
    }
    
    double findMedian() {
        if(even) return (double)(large.top()+small.top())/2;
        else return small.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */