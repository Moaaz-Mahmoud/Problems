class Solution {
public:
    string minRemoveToMakeValid(string &s) {
        string ans;
        int cnt = 0;
        for(char c : s){
            if(c == '('){
                ans += c;
                cnt++;
            }
            else if(c == ')'){
                if(cnt > 0){
                    ans += c;
                    cnt--;
                }
            }
            else{
                ans += c;
            }
        }
        if(cnt == 0) return ans;
        for(int i = ans.size()-1; i >= 0; i--){
            if(ans[i] == '(') {
                ans.erase(ans.begin() + i);
                cnt--;
                if(cnt == 0) break;
            }
        }
        return ans;
    }
};
