class MedianFinder {
public:
priority_queue<int>maxheap;
priority_queue<int,vector<int>,greater<int>>minheap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxheap.size() == minheap.size()){
            if(num > findMedian()){
                // right me dalo
                minheap.push(num);
            }
            else{
                //left me dalo
                maxheap.push(num);
            }
        }
        else if( maxheap.size() == minheap.size()+1){
            if(num > findMedian()){
                //right me dalo
                minheap.push(num);
            }
            else{
                //left me dalo
                int element = maxheap.top();
                maxheap.pop();
                minheap.push(element);
                maxheap.push(num);
            }
        }
        else if(minheap.size() == maxheap.size()+1){
            if(num > findMedian()){
           //right me dalo;
            int element = minheap.top();
                minheap.pop();
                maxheap.push(element);
                minheap.push(num);

            }
            else{
            //left me dalo;
            maxheap.push(num);
            }
        }
        
    }
    
    double findMedian() {
        if(maxheap.size()==0 && minheap.size()==0){
            return 0;
        }
        else if(maxheap.size() == minheap.size()){
            return (maxheap.top()+ minheap.top())/2.0;
        }
        else if(maxheap.size() == minheap.size()+1){
            return maxheap.top();
        }
        else if(minheap.size() == maxheap.size()+1){
            return minheap.top();
        }
        else{
            return -1;
        }
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */