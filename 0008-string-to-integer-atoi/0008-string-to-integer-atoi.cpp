class Solution {
public:
    int myAtoi(string s) {
        
        int n = s.size();
        bool flag = true;
        long long ans  = 0LL;
        int j = 0;
        while(j<n && (s[j]==' ' || s[j]=='+' || s[j]=='-')){

            if(s[j]=='-') {
                flag = false;
                j++;
                break;
            }
            if(s[j]=='+') {
                j++;
                break;
                
            }
            j++;
        }

        while(j<n && (s[j]>='0' && s[j]<='9')){
             
           int digit =   s[j] - '0';
            if( flag && (ans > INT_MAX/10 || (ans==INT_MAX/10 && digit>7) ) ){
                return INT_MAX;
            }
            else if( !flag && (ans>INT_MAX/10 || (ans==INT_MAX/10 && digit>8))){
                return INT_MIN;
            }

             ans  =  1LL* ans *10 + digit;
             j++;
        }
        if(!flag){
            ans  = -ans;
        }
        return (int) ans;
    }
};