//TLE AAYA LAST WALE ME

// class Solution {
// public:
//     vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
//         vector<int>ans;
//         vector<long long>v(words.size());
//         for(long long i=0 ;i< words.size();i++){
//             auto s = words[i];
//             long long n = s.size()-1;
//             if((s[0]=='a'||s[0]=='e'|| s[0]=='i'|| s[0]=='o' || s[0]=='u') && (s[n]=='a'|| s[n]=='e' || s[n]=='i'|| s[n]=='o' || s[n]=='u'))
//             {
//               v[i] = 1;
//             }
//             else{
//                 v[i] = 0;
//             }
//         }
//         for(long long i=0 ;i< queries.size();i++){
//             long long first = queries[i][0];
//             long long second = queries[i][1];
//             long long  count = 0;
//             for(long long i = first ;i<=second ;i++){
//               if(v[i]== 1){
//                 count++;
//               }
//             }
//             ans.push_back(count);
//         }
        
//         return ans;
//     }
// };
class Solution {
public:
    vector<int> vowelStrings(vector<string>& words,
                             vector<vector<int>>& queries) {
        int n = queries.size();
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        vector<int> ans;
        vector<int> prefix;
        int prefix_sum = 0;

        for (int i = 0; i < words.size(); i++) {
            int first = 0;
            int last = words[i].size() - 1;
            if (vowels.find(words[i][first]) != vowels.end() &&
                vowels.find(words[i][last]) != vowels.end()) {
                prefix_sum++;
            }
            prefix.push_back(prefix_sum);
        }


        for (int i = 0; i < n; i++) {
            int left = queries[i][0];
            int right = queries[i][1];

            int temp = prefix[right];
            if (left > 0) {
                temp -= prefix[left - 1];
            }

            ans.push_back(temp);
        }

        return ans;
    }
};