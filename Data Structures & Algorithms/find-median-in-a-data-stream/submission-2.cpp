class MedianFinder {
public:
    priority_queue<int> left_heap;  //this is a max heap
    priority_queue<int, vector<int>, greater<int>> right_heap;  //this is a min heap

    MedianFinder(){
        
    }
    
    void addNum(int num){
        left_heap.push(num);
        if(!right_heap.empty() && left_heap.top() > right_heap.top()){
            right_heap.push(left_heap.top());
            left_heap.pop();
        }

        if(left_heap.size() > right_heap.size() + 1){
            right_heap.push(left_heap.top());
            left_heap.pop();
        }

        if(right_heap.size() > left_heap.size() + 1){
            left_heap.push(right_heap.top());
            right_heap.pop();
        }
    }
    
    double findMedian() {
        if((right_heap.size() +left_heap.size()) % 2 == 0){
           return ((right_heap.top()+left_heap.top()))/2.0;
        }else if(right_heap.size() > left_heap.size()){
            return right_heap.top();
        }else if(left_heap.size() > right_heap.size()){
            return left_heap.top();
        }
    }
};
