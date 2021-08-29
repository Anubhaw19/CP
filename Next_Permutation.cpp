class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int index=-1,l=nums.size();
        for(int i=l-1;i>0;i--)
        {
            
            if(nums[i]>nums[i-1] and index==-1)
                index=i-1;
           
        }
        if(index==-1)
        {
            // cout<<"inside-if"<<endl;
              reverse(nums.begin(),nums.end());
        }
        else
        {
            // cout<<"inside-else"<<endl;
            int c;
            for(int i=index+1;i<l;i++)
            {
                if(nums[i]>nums[index])
                    c=i;
                else
                    break;
            }
           // cout<<"sawp"<<endl;
           //  cout<<nums[index]<<"="<<nums[c]<<endl;
             swap(nums[index],nums[c]);
            // sort(nums.begin()+index+1,nums.end());
            reverse(nums.begin()+index+1,nums.end());
           
        }
        return;
    }
};
