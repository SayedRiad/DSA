#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int low = 0, high = 0;
    while (high < n)
    {
        if (a[low] < 0 and a[high] < 0)
        {
            low++, high++;
        }
        else if (a[low] > 0 and a[high] < 0)
        {
            swap(a[low], a[high]);
            low++, high++;
        }
        else if (a[low] > 0 and a[high] > 0)
        {
            high++;
        }
    }
    for (auto i : a)
    {
        cout << i << ' ';
    }
}