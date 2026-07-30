class MedianFinder {
public:
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;
    MedianFinder() {

    }
    
    void addNum(int num) {
        if(left.empty()){
            left.push(num);
            return;
        }        
        if(num < left.top()){
            left.push(num);
            if(left.size() == right.size() || left.size() - 1 == right.size()){
                return;
            }
            else{
                int temp = left.top();
                right.push(temp);
                left.pop();
            }
        }
        else{
            right.push(num);
            if(left.size() == right.size() || left.size() - 1 == right.size()){
                return;
            }
            else{
                int temp = right.top();
                left.push(temp);
                right.pop();
            }
        }
        return;
    }
    
    double findMedian() {
        if(left.size() > right.size()){
            return left.top();
        }
        return (double)((double)left.top() + (double)right.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */