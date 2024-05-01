#include <iostream>
#include <string>
#include <cmath>
using namespace std;

long long int karatsuba(long long int x, long long int y)
{
    if (x < 10 || y < 10)
    {
        return x * y;
    }
    int n = max(to_string(x).size(), to_string(y).size());
    int m = n / 2;
    long long int a = x / static_cast<long long int>(pow(10, m));
    long long int b = x % static_cast<long long int>(pow(10, m));
    long long int c = y / static_cast<long long int>(pow(10, m));
    long long int d = y % static_cast<long long int>(pow(10, m));
    long long int ac = karatsuba(a, c);
    long long int bd = karatsuba(b, d);
    long long int ad_bc = karatsuba(a + b, c + d) - ac - bd;

    return ac * static_cast<long long int>(pow(10, 2 * m)) + ad_bc * static_cast<long long int>(pow(10, m)) + bd;
}

int main()
{
    long long int x, y;
    x = 123567890, y = 98987610;
    cout << karatsuba(x, y);
    return 0;
}
