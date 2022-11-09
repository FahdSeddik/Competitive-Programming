class StockSpanner {
    stack<pair<int,int>> st;
public:
    
    StockSpanner() {

    }
    
    int next(int price) {
        int span =1;
        while(!st.empty() && st.top().second<=price){
            span+=st.top().first;
            st.pop();
        }
        st.push({span,price});
        return span;
    }
};