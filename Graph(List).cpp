#include<bits/stdc++.h>
using namespace std;

class graph{
int V;
list<pair<int,int>> *l;
// or list<int> *l; // for un-weighted graph

public:
graph(int V)
{
    this->V=V;
    l=new list<pair<int,int>>[V];
    //or l=new list<int>[n]; //  for un-weighted graph
}
// adding a new node to the Adjacency List 
void addEdge(int u, int v,int s)
{
    pair<int,int> p(v,s);
    l[u].push_back(p);
        // l[u].first=v;
        // l[u].second=s;
    
    // l[u].push_back(v);  for un-weighted graph
    //  l[v].push_back(u);   for un-weighted graph and bi-directional
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
        cout<<endl<<"breadth first search: "<<endl;
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

    void DFS_until(int s,bool visited[])
    {

     visited[s]=true;
     cout<<s<<",";

     for(auto x:l[s])
     {
         if(!visited[x.first])
         DFS_until(x.first,visited);
     }
        
    }

    void DFS_connected(int s)
    {
        cout<<endl<<"depth first search:(connected graph)"<<endl;
        bool visited[V];
        for(int i=0;i<V;i++)
        visited[i]=false;

        //for connected graphs
        if(!visited[s])
        DFS_until(s,visited);

    }
    void DFS_disconnected()
    {
         cout<<endl<<"depth first search:(disconnected graph)"<<endl;
        bool visited[V];
        for(int i=0;i<V;i++)
        visited[i]=false;

        /** for disconnected graphs*/
        for(int j=0;j<V;j++)
        {
            if(!visited[j])
            DFS_until(j,visited);
        }
    }

};
int main()
{
   int size=6;
graph g(size);
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
g.DFS_connected(5);
g.DFS_disconnected();

return 0;


}

