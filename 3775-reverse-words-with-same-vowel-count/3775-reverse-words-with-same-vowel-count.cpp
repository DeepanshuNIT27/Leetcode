class Solution {
public:
    string reverseWords(string s) {
        int i=0;
        int count = 0;
        while(i<s.size() && s[i]!=' '){
            if(s[i]=='a' ||s[i]=='e' ||s[i]=='i' ||s[i]=='o' ||s[i]=='u'){
                count++;
            }
           
            i++;
        }
        cout<<count<<" ";
        i++;
        int counti = 0;
        int prev = i;
        cout<<s.size()<<" ";
        cout<<i<<" ";
        while(i<s.size()){
            if(s[i]=='a' ||s[i]=='e' ||s[i]=='i' ||s[i]=='o' ||s[i]=='u'){
                counti++;
            }
          else  if(s[i]==' ') {
            if(counti == count){
               reverse(s.begin()+prev , s.begin()+i);
            }
               prev = i +1;
               counti = 0;
            }
            i++;
        }
        if(counti==count) reverse(s.begin()+prev , s.end());
        return s;
    }
};