#include<bits/stdc++.h>
using namespace std;

int main()
{
    int test;
    cin>>test;
    string ch;
    stack<long long int>rakh;
    //stack< pair <long long int, long long int> >arr;
    for(int p = 1; p <= test; p++){
        cin>>ch;
        int siz = ch.length();
        long long int x = 1, y = 1;
        for(int i = 0; i < siz; i++){
            if(rakh.empty() && !(ch[i] >= '2' && ch[i] <= '9')){
                if(ch[i] == 'N') y-= 1;
                else if(ch[i] == 'S') y+=1;
                else if(ch[i] =='W') x-= 1;
                else x+= 1;
            }
            else if(ch[i] >= '2' && ch[i] <= '9'){
                if(rakh.empty()){
                    rakh.push(ch[i] - '0');
                }
                else{
                    rakh.push((rakh.top() * (ch[i] - '0')) % 1000000000);
                }
            }
            else if(ch[i] == ')'){
                rakh.pop();
            }
            else if(ch[i] != '('){
                if(ch[i] == 'N') y -= (1 * rakh.top());
                else if(ch[i] == 'S') y += (1 * rakh.top());
                else if(ch[i] == 'E') x += (1 * rakh.top());
                else x -= (1 * rakh.top());
            }
            x = x % 1000000000;
            y = y % 1000000000;
            if(x <= 0){
                x = 1000000000 + x;
            }
            if( y <= 0){
                y = 1000000000 + y;
            }
        }
        cout<<"Case #"<<p<<": "<<x<<" "<<y<<endl;
    }
    return 0;
}

