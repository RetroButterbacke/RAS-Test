#include <bits/stdc++.h>
#include <cstdio>
#include <cmath>
#include <unistd.h>

bool isPrime(float n)
{
    // Corner case
    if (n <= 0.1f)
        return false;
    // Check from 2 to n-1
    for (int i = 2; i <= n / 2; i++)
        if (std::fmod(n, i) == 0)
            return false; 
    return true;
}

int main () {

e:
  float e = 0;
  printf("Type in e:\n");
  scanf("%f", &e);
  if (!isPrime(e)) { printf("Not a Prime\n"); goto e; }
p:
  float p = 0;
  printf("Type in p:\n");
  scanf("%f", &p);
  if (!isPrime(p)) { printf("Not a Prime\n"); e = 0; goto p; }
q:
  float q = 0; 
  printf("Type in q:\n");
  scanf("%f", &q);
  if (!isPrime(q)) { printf("Not a Prime\n"); q = 0; goto q; }

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
