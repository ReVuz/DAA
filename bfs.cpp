#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        int* vis = new int[V];
        for(int i = 0;i<V;i++){
          vis[i] = 0;
        } 
        vis[0] = 1; 
        queue<int> q;
        // push the initial starting node 
        q.push(0); 
        vector<int> bfs; 
        // iterate till the queue is empty 
        while(!q.empty()) {
           // get the topmost element in the queue 
            int node = q.front(); 
            q.pop(); 
            bfs.push_back(node); 
            // traverse for all its neighbours 
            for(auto it : adj[node]) {
                // if the neighbour has previously not been visited, 
                // store in Q and mark as visited 
                if(!vis[it]) {
                    vis[it] = 1; 
                    q.push(it); 
                }
            }
        }
        return bfs; 
    }
};

void addEdge(vector <int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printAns(vector <int> &ans) {
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
}

int main() 
{
  cout<<"BFS Traversal"<<endl;
  cout<<"Enter no of vertices : ";
  int vertices;
  cin>>vertices;
    vector <int> adj[vertices];
    int a,b;
    char answer;
    do{
      cout<<"Add Edges : ";
      cin>>a>>b;
      addEdge(adj,a,b);
      cout<<"Do you want to add more ?(y/n) : ";
      cin>>answer;
    }while(answer == 'y');
    // addEdge(adj, 0, 1);
    // addEdge(adj, 1, 2);
    // addEdge(adj, 1, 3);
    // addEdge(adj, 0, 4);

    Solution obj;
    cout<<"Visited Nodes : ";
    vector <int> ans = obj.bfsOfGraph(vertices, adj);
    printAns(ans);

    return 0;
}