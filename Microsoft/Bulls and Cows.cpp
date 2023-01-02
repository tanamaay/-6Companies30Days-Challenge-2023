class Solution {
public:
    Bulls and Cowsstring getHint(string secret, string guess) {
        unordered_map<char, int> m;
        int b =0;
        int c=0;
        for(int i =0;i<secret.size();i++){
            if(secret[i]== guess[i]){
                b++;
            }
            else{
                m[secret[i]]++;
            }
        }

        for(int i =0;i<secret.size();i++){
            if(secret[i]!= guess[i]){
                if(m[guess[i]]>0){
                    c++;
                    m[guess[i]]--;
                }
            }
        }
        string a = to_string(b) + "A" + to_string(c) + "B";
        return a ;
    }
};

