class Info{
public:
       int data;
       int rIndex;
       int cIndex;
       Info(int a, int b, int c){
        this->data = a;
        this->rIndex = b;
        this->cIndex = c;
       }
};
class compare{
    public:
    bool operator()(Info* a ,Info* b){
        return a->data > b->data;
    }
};
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<Info* ,vector<Info*> , compare> pq;
        vector<int>ans;
        int totalrow = nums.size();
        int maxi = INT_MIN;
        int mini = INT_MAX;

        for(int row=0; row<totalrow;row++){
            int element = nums[row][0];
            Info* temp = new Info(element,row,0);
            pq.push(temp);
            maxi = max(maxi,element);
            mini = min(mini,element);
        }
        int ans_start = mini;
        int ans_end = maxi;
        while(!pq.empty()){
            auto front = pq.top();
            int element = front->data;
            int rIndex = front->rIndex;
            int cIndex = front->cIndex;
            pq.pop();
            
            mini = element ;
            if(maxi-mini < ans_end-ans_start){
                ans_start = mini;
                ans_end = maxi;
            }
            int currentcolumn = nums[rIndex].size();
            if(cIndex+1 <currentcolumn){
                int element = nums[rIndex][cIndex+1];
               Info* temp = new Info(element,rIndex,cIndex+1);
               pq.push(temp);
               maxi = max(element ,maxi);
            }
            else{
                break;
            }
        }
        ans.push_back(ans_start);
        ans.push_back(ans_end);
        return ans;
        
    }
};