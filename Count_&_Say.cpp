class Solution {
public:
    string countAndSay(int n) {
     // Recursive Solution
      
        string s="";

        
        if(n==1)
        s+=to_string(1);
        else
        {
            int c=1;
            string temp="";
            s=countAndSay(n-1);
            for(int i=0;i<s.length();i++)
            {
                if(s[i]==s[i+1])
                    c++;
                else{
                    temp+=to_string(c)+s[i];
                    c=1;
                }
            }
            s=temp;
            
            
        }
        cout<<"s="<<s<<endl;
        return s;
    }
};
