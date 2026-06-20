//O(n log n + q log q + 32(n + q))
struct Node {

    Node * links[2] = {};

    bool containskey(int bit){
        return (links[bit]!=NULL);
    }

    Node* get(int bit){
        return links[bit];
    }
    void put(int bit , Node* node){
        links[bit] = node;
    }
};

class Trie{
    private :
    Node * root;

    public : 
    Trie(){
        root = new Node();
    }

    void insert(int num){
        Node* node = root;
        for(int i=31;i>=0;i--){
            int bit = (num>>i) & 1;
            if(!node->containskey(bit)){
                node->put(bit,new Node());
            }
            node = node->get(bit);
        }
    }

    int getMax(int num){
        Node* node = root;
         int maxi = 0;
        for(int i=31;i>=0;i--){
           int bit = (num>>i)&1;
           if(node->containskey(1-bit)){
              maxi =  maxi | (1<<i);
              node = node->get(1-bit);
           }
           else{
            node = node->get(bit);
           }
        }
        return maxi;
    }

};
class Solution {
public:
//OFFLINE QUERY KI TARAH USE KRO
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        Trie trie;
        sort(nums.begin(),nums.end());

        vector<pair<int,pair<int,int>>>offque;
        int q = queries.size();
        for(int i=0;i<q;i++){
            int x = queries[i][0];
            int lim = queries[i][1];
           offque.push_back({lim,{x,i}});
        }
        sort(offque.begin(),offque.end());
        vector<int>ans(q);
        int n = nums.size();
          int j = 0;

        for(int i=0;i<q;i++){
            int lim = offque[i].first;
            int x = offque[i].second.first;
            int idx = offque[i].second.second;
          

            while(j<n && nums[j]<=lim){
                trie.insert(nums[j]);
                j++;
            }

        if(j==0){
            ans[idx] = -1;
        }
        else{
            ans[idx] = trie.getMax(x);
        }
        }
        return  ans;

    }
};