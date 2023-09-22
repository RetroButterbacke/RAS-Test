#include <bits/stdc++.h>
#include <cstdio>
#include <cmath>
#include <unistd.h>

bool isPrime(int n)
{
    // Corner case
    if (n <= 1)
        return false;
    // Check from 2 to n-1
    for (int i = 2; i <= n / 2; i++)
        if (n % i == 0)
            return false; 
    return true;
}

int main () {
  int e = 0;
  int p = 0;
  int q = 0; 

e:
  printf("Type in e:\n");
  scanf("%d", &e);
  if (!isPrime(e)) { printf("Not a Prime\n"); goto e; }
p:
  printf("Type in p:\n");
  scanf("%d", &p);
  if (!isPrime(p)) { printf("Not a Prime\n"); goto p; }
q:
  printf("Type in q:\n");
  scanf("%d", &q);
  if (!isPrime(q)) { printf("Not a Prime\n"); goto q; }

  float N = p*q;
  float d = ((p-1)*(q-1));
  if (std::fmod(d, e) != 0.0f) { 
    d += 1;
    if (std::fmod((d / e), 1.0f) != 0.0f) {
      printf("Couldn't calculate key.\n");
      return 0;
    } else d /= e;
  } else d /= e;
  printf("public key: %d %d\nprivate key: %d %d\n", (int)e, (int) N, (int)d, (int)N);
  sleep(5);
  return 0;
}
