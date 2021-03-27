#include<bits/stdc++.h>
using namespace std;
int main()
{
int t,c=0;
cin>>t;
while(t>0)
{
    int n;
    cin>>n;
    int v[n];
    for(int k=0;k<n;k++)
    {
        cin>>v[k];
    }
int i,j=0,sum=0;
          
          for(i=0;i<n-1;i++)
          {
              
              int* m;
              m=min_element(v+i,v+n);
              for(int k=i;k<n;k++)
              {
                  if(v[k]==*m)
                  {
                    j=k;
                sum+=j-i+1;
                reverse(v+i,v+j+1);
                  break;  
                  }
              }

          }   
            c++;
            cout<<"Case #"<<c<<":"<<" ";
          cout<<sum<<endl;                          
                                       

    t--;
}

}

