#include <bits/stdc++.h>
using namespace std;

vector< vector <int> > graph(200);
bool color[200];
bool value[200];
vector<int>ans;

void topological_sort(int u) {
    //cout<<(char)u<<endl;
    color[u] = true;
    for(int i = 0; i < graph[u].size(); i++) {
        //cout<<(char)graph[u][i]<<endl;
        if(!color[graph[u][i]]) {
            topological_sort(graph[u][i]);
        }
    }
    ans.push_back(u);
}

bool detectCycle(int u, bool *reVisit) {
    //cout<<(char)u<<endl;
    if(color[u] && reVisit[u]) {
        return true;
    }
    else if(color[u]) {
        return false;
    }
    color[u] = true;
    reVisit[u] = true;
    bool ans = false;
    for(int i = 0; i < graph[u].size(); i++) {
        ans = ans | detectCycle(graph[u][i], reVisit);
        if(ans) {
            return true;
        }
    }
    reVisit[u] = false;
    return ans;
}
int main()
{
    int test, n, m;
    cin>>test;
    string arr[30];
    for(int p = 1; p <= test; p++) {
        cin>>n>>m;
        for(int i = 0; i < n; i++) {
            cin>>arr[i];
        }
        bool edge[130][130];
        memset(edge, false, sizeof(edge));
        memset(value, false, sizeof(value));
        for(int i = 1; i < (n); i++) {
            for(int j = 0; j < m; j++) {
                value[arr[i][j]] = true;
                if(arr[i][j] != arr[i-1][j] && edge[arr[i][j]][arr[i-1][j]] != true) {
                    graph[arr[i][j]].push_back(arr[i-1][j]);
                    edge[arr[i][j]][arr[i-1][j]] = true;
                }
            }
        }
        for(int j = 0; j < m; j++) {
            value[arr[0][j]] = true;
        }
        memset(color, false, sizeof(color));
        bool reVisit[200];
        bool temp = false;
        for(int i = 'A'; i <= 'Z'; i++) {
            if(value[i] && color[i]==false) {
                //cout<<"Haque"<<" "<<(char)i<<endl;
                memset(reVisit, false, sizeof(reVisit));
                temp = temp | detectCycle(i, reVisit);
                if(temp) break;
            }
        }
        cout<<"Case #"<<p<<": ";
        if(temp) {
            cout<<"-1"<<endl;
        }
        else {
            memset(color, false, sizeof(color));
            for(int i = 'A'; i <= 'Z'; i++) {
                if(value[i] && !color[i]) {
                    //cout<<"Haque"<<endl;
                    topological_sort(i);
                }
            }
            reverse(ans.begin(), ans.end());
            for(int i = 0; i < ans.size(); i++) {
                cout<<(char)ans[i];
            }
            cout<<endl;
        }
        ans.clear();
        for(int i = 'A'; i <= 'Z'; i++) {
            graph[i].clear();
        }
    }
    return 0;
}
