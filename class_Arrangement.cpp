#include<bits/stdc++.h>
using namespace std;

int main()
{
string s;
cin>>s;
unsigned int n=s.length();
int g0=0,g1=0,b0=0,b1=0,g=0,b=0;
for(unsigned int i=0;i<n;i++)
{
    if(s[i]=='G')
    g++;
    else
    b++;
if(i%2==0){
    if(s[i]=='G')
    g0++;
    else
    b0++;
}
else{
    if(s[i]=='G')
    g1++;
    else
    b1++;
}
}
int swap0=min(g0,b1); //starting with 'B'
int swap1=min(g1,b0); //staring with 'G'
if(n%2==0)
cout<<min(swap0,swap1);
else{
    if(g>b)
    cout<<swap1; 
    else
    cout<<swap0;
}

return 0;
}
