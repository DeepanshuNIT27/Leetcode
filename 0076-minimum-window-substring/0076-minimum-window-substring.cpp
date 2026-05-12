class Solution {
public:
//OPTIMAL SOLUTION O(M+N) WHERE CHECKING HASH IS DONE IN CONSTANT TIME
// NOT ITERATING T AGAIN AND AGAIN
    string minWindow(string s, string t) {
     unordered_map<char,int>need;
     int n = s.size();
     int m = t.size();
     if(m>n)return "";
     int start = -1;
     int minlength = INT_MAX;
     int ans = 0;
     int i =0 ;
     int j = 0;
     for(auto&it:t) need[it]++;

     while(j<n){

        char ch = s[j];
     if(need[ch]>=1) ans++;
     need[ch]--;

      while(ans==m && i<=j){

       if(j-i+1<minlength) {
        start = i;
        minlength = j-i+1;
       }
       need[s[i]]++;
       if(need[s[i]]>=1) ans--;
      
      i++;
      }
      j++;

     }
     if(minlength==INT_MAX) return "";
     return s.substr(start,minlength);
    }
};