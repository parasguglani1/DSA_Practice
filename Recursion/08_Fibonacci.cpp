// Fibonacci
// 0 1 1 2 3 5 8 13 21 34 55 89 144 233 377 610 987 1597 2584 4181 6765 10946 17711 28657 46368 75025 121393 196418 317811 514229 832040 1346269 2178309 3524578 5702887 9227465 14930352 24157817 39088169 63245986 65471475 102334155
#include <iostream>

using namespace std;

int fib(int n)
{
  int t0 = 0, t1 = 1, s = 0, i;
  if (n <= 1) return n;
  for (i = 2; i <= n; i++)
  {
    s = t0 + t1;
    t0 = t1;
  }
  t1 = s;
  return s;
}

int rfib(int n)
{
  if (n <= 1)
    return n;
  return rfib(n - 2) + rfib(n - 1);
}

int F[10];
int mfib(int n)
{
  if(n <= 1)
  {
    F[n] = n;
    return n;
  }
  else
  {
    if (F[n - 2] == -1)
      F[n - 2] = mfib(n - 2);
    if (F[n - 1] == -1)
      F[n - 1] = mfib(n - 1);
    F[n] = F[n - 2] + F[n - 1];
    return F[n - 2] + F[n - 1];
  }
}

int main()
{
  for (int i = 0; i < 10; i++)
    F[i]= -1;
  cout << mfib(5) << endl;
  // cout << rfib(10) << endl;

  return 0;
}