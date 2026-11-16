class Solution {
public:
    string digitSum(string s, int k) {
        while(s.size()>k){
            int i = 0;
            int j = 0;
            string temp = "";
            while(i<s.size()){
                for(int t = i; t<k+i; t++){
                    if(t>=s.size()) break;
                    j += s[t] - '0';
                }
                temp += to_string(j);
                j=0;
                i+=k;
            }
            s = temp;
        }
        return s;
    }
};
