#include<bits/stdc++.h>
using namespace std;
int maxprofit(int price[],int n)
{
    int res=0;
    int* profit=new int[n];
    for(int i=0;i<n;i++)
    profit[i]=0;
    int max_price=price[n-1];

    for(int j=n-2;j>=0;j--)
    {
        if(max_price<price[j])
        max_price=price[j];

        profit[j]=max(profit[j+1],max_price-price[j]);
    }
    int min_price=price[0];
    for(int k=1;k<n;k++)
    {
        if(min_price>price[k])
        min_price=price[k];

        profit[k]=max(profit[k-1],profit[k]+(price[k]-min_price));
    }
res=profit[n-1];
return res;
}
int main()
{
int t,c=0;
cin>>t;
int arr[t];
for(int i=0;i<t;i++)
cin>>arr[i];
// while(t>0)
// {
                         
//         cin>>arr[t]; 
//         t--;
// }

int res= maxprofit(arr,t);
cout<<res<<endl;

}

