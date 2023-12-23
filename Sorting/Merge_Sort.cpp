#include<bits/stdc++.h>
using namespace std;

vector<int> merge_sort(vector<int> a){

    if(a.size() <= 1)
        return a;

    int mid = a.size()/2;

    vector<int> b, c;

    for(int i=0;i<mid;i++)
        b.push_back(a[i]);
    
    for(int i=mid;i<a.size();i++)
        c.push_back(a[i]);

    vector<int> sorted_a, sorted_b, sorted_c;

    sorted_b = merge_sort(b);
    sorted_c = merge_sort(c);

    int index1 = 0, index2 = 0;

    for(int i=0;i<a.size();i++){
        if(index1 == sorted_b.size()){
            sorted_a.push_back(sorted_c[index2]);
            index2++;
        }
        else if(index2 == sorted_c.size()){
            sorted_a.push_back(sorted_b[index1]);
            index1++;
        }
        else if(sorted_b[index1] < sorted_c[index2]){
            sorted_a.push_back(sorted_b[index1]);
            index1++;
        }
        else{
            sorted_a.push_back(sorted_c[index2]);
            index2++;
        }
    }

    return sorted_a;
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);

    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    vector<int> ans = merge_sort(a);

    for(auto u:ans)
        cout << u << " ";
}