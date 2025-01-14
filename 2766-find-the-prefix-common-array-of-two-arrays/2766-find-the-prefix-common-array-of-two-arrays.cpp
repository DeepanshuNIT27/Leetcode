#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> ans;
        unordered_set<int> seenA;
        
        // Loop through the elements of A and B.
        for (int i = 0; i < A.size(); i++) {
            int count = 0;
            seenA.insert(A[i]);  // Add current element of A to seen set

            // Check if the current element of B exists in seen set.
            if (seenA.find(B[i]) != seenA.end()) {
                count++;
            }

            // Count common elements in the prefix up to index i
            for (int j = 0; j < i; j++) {
                if (seenA.find(B[j]) != seenA.end()) {
                    count++;
                }
            }
            
            ans.push_back(count);
        }
        return ans;
    }
};
