class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int count = 0;
        for(int i=num1;i<=num2;i++){
            int d = i;
            auto s = to_string(i);
            if(s.size()<=2) continue;
            for(int i=1;i<s.size()-1;i++){
                if(s[i]>s[i-1] && s[i]>s[i+1]) count++;
                if(s[i]<s[i-1] && s[i]<s[i+1] )count++;
            }
        }
        return count;
    }
};