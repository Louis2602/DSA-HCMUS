#include <iostream>
using namespace std;

void print(int n, char a[])
{
    for (int i = 1; i <= n; i++)
        cout << a[i];
    cout << '\n';
}
void Try(int i, char a[], bool check[], char ans[], int n)
{
    for (int j = 1; j <= n; j++)
    {
        if (!check[j])
        {
            check[j] = 1;
            ans[i] = a[j - 1];
            if (i == n)
                print(n, ans);
            else
                Try(i + 1, a, check, ans, n);
            check[j] = 0;
        }
    }
}
int main()
{
    char a[4] = {'A', 'B', 'C', 'D'};
    int n = 4;
    bool check[5] = {0};
    char ans[100];
    Try(1, a, check, ans, n);
    return 0;
}