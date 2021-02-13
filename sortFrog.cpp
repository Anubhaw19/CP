#include<bits/stdc++.h>
using namespace std;
bool sortArr(vector<int> z)
{ 
	for(int i=z.size()-1;i>0;i--)
	{
		if(z[i]<=z[i-1])
		return false;
		
	}
	return true;
}

void again(vector<int> x,vector<int> y, vector<int> z,int s)
{
	for(int k=y.size()-1;k>0;k--)
{
	if(y[k]<=y[k-1])
	{
		y[k]=y[k]+z[k];
		s++;
		//again(x,y,z,s);
	}
}
if(sortArr(y))
{
	cout<<s<<endl;
// 	cout<<"*********"<<endl;
// for(int i=0;i<x.size();i++)
// {
// 	cout<<x[i]<<"=";
// 	cout<<y[i]<<endl;
// }

}

else
again(x,y,z,s);

}


int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
	int n,s=0;
	cin>>n;
	vector<int> w,l;
	vector<int> jump(n),p(n);
	for(int j=0;j<n;j++)
	{
		int temp;
		cin>>temp;
		
		 p[temp-1]=j;
		 w.push_back(temp);
	}
	
	
	for(int q=0;q<n;q++)
	{
		int temp;
		cin>>temp;
		
		 jump[w[q]-1]=temp;
		 l.push_back(temp);
	}
	
sort(w.begin(),w.end());
again(w,p,jump,s);

// cout<<"*********"<<endl;
// for(int i=0;i<w.size();i++)
// {
// 	cout<<w[i]<<"=";
// 	cout<<p[w[i]]<<endl;
// }

	}
}
