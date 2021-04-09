#include<bits/stdc++.h>
using namespace std;

class graph{
int V;
list<pair<int,int>> *l;

public:
graph(int V)
{
    this->V=V;
    l=new list<pair<int,int>>[V];
}
// adding a new node to the Adjacency List 
void addEdge(int u, int v,int s)
{
    pair<int,int> p(v,s);
    l[u].push_back(p);
        // l[u].first=v;
        // l[u].second=s;
    
    // l[u].push_back(v);
    //  l[v].push_back(u);
}
void printGraph()
{
    cout<<"printing graph:"<<endl;
    for(int i=0;i<V;i++)
    {
        cout<<"vertex "<<i<<"->";
        for(auto x:l[i])
        {
            cout<<x.first<<"-("<<x.second<<")->";
        }
        cout<<endl;

    }
}
 // Breadth first search
  void BFS(int s)
    {
        cout<<"breadth first traversal: "<<endl;
       bool *visit=new bool[V];
       for(int i=0;i<V;i++)
       visit[i]=false; 
        list<int> queue;
       
       if(!visit[s])
       {
           queue.push_back(s);
           visit[s]=true;

       }
       while(!queue.empty())
       {
           s=queue.front();
            cout<<s<<",";
            queue.pop_front();

            for( auto x:l[s])
            {
                if(!visit[x.first])
                {
                    queue.push_back(x.first);
                    visit[x.first]=true;
                }
                
            }
       }
    }

};
int main()
{
   
graph g(6);
g.addEdge(0,1,10);
g.addEdge(0,2,20);
g.addEdge(0,3,20);
g.addEdge(0,4,20);
g.addEdge(0,5,20);
g.addEdge(2,1,30);
g.addEdge(2,3,40);
g.addEdge(2,4,20);
g.addEdge(3,5,100);
g.addEdge(4,5,400);
g.addEdge(4,0,400);

g.printGraph();
g.BFS(2);

return 0;


}

