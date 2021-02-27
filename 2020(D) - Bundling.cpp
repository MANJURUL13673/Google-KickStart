#include <bits/stdc++.h>
using namespace std;

int n, k;

struct node {
    int count;
    node* next[25+1];
    node () {
        count = 0;
        for(int i = 0; i < 26; i++) {
            next[i] = NULL;
        }
    }
} *root;

void insert(string str, int len)
{
    node* curr = root;
    for (int i = 0; i < len; i++) {
        int id = str[i] - 'A';
        if (curr->next[id] == NULL) {
            curr->next[id] = new node();
        }
        curr = curr->next[id];
        curr->count = curr->count + 1;
    }
}

void del(node* cur) {
    for(int i = 0; i < 26; i++) {
        if(cur->next[i]) {
            del(cur->next[i]);
        }
    }
    delete (cur);
}

int totalScores(node* cur) {
    int total = 0;
    for(int i = 0; i < 26; i++) {
        if(cur->next[i]) {
            total += totalScores(cur->next[i]);
        }
        //cout<<cur->count<<endl;
        if(i == 0)
            total += (cur->count / k);
    }
    return total;
}

int main()
{
    int test;
    cin>>test;
    string ch;

    for(int p = 1; p <= test; p++) {
        root = new node();
        cin>>n>>k;
        for(int i = 0; i < n; i++) {
            cin>>ch;
            insert(ch, ch.length());
        }
        int ans = totalScores(root);
        cout<<"Case #"<<p<<": "<<ans<<endl;
        del(root);
    }
    return 0;
}
