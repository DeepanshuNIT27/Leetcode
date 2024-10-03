string copyorder;
class Solution {
public:

 static bool cmp(char a, char b){

    return(copyorder.find(a)<copyorder.find(b));
}
    string customSortString(string order, string s) {
        copyorder= order;
        sort(s.begin(),s.end(),cmp);
        return s;
        
    }
};