#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);

    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    for(int i=0;i<n;i++){
        int last = n-1-i;
        for(int j=0;j<last;j++){
            if(a[j] > a[j+1]){
                swap(a[j+1], a[j]);
            }
        }
    }

    for(auto u:a)
        cout << u << " ";
}