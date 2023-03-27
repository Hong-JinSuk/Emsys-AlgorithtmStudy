#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    vector <pair<int,int> > vec;
    priority_queue <int,vector<int>,greater<int> > pq;
    int n;
    cin>> n;
    for(int i=0;i<n;i++){
        int st, en;
        cin>> st>> en;
        vec.push_back(make_pair(st,en));
    }
    
    sort(vec.begin(),vec.end());
    pq.push(vec[0].second);

    for(int i=1;i<n;i++){
        if(pq.top()>vec[i].first) pq.push(vec[i].second);
        else {
            pq.push(vec[i].second);
            pq.pop();
        }
    }
    cout<< pq.size();
}
