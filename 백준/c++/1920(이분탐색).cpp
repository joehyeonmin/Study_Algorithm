#include <iostream> 
#include <vector>
#include <algorithm>

using namespace std;
//vector<int> a; 
int arr[100000];
int n;
bool result = false;

void binary_search(int x) {
    int left = 0, mid = 0, right = n - 1;

    while (left <= right) {
        mid = (left + right) / 2;

        if (arr[mid] == x)
        {
            result = true;
            break;
        }
        else if (arr[mid] > x)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];

    }
    //sort(a.begin(), a.end());
    sort(arr, arr + n);

    int m;
    cin >> m;

    int input;

    for (int i = 0; i < m; i++)
    {
        cin >> input;
        result = false;

        binary_search(input);

        if (result == true)
            cout << "1" << "\n";
        else
            cout << "0" << "\n";

    }
    return 0;
}