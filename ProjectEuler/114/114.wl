f[1] = 1;

f[2] = 1;

f[3] = 2;

f[4] = 4;

f[5] = 7;

f[6] = 11;

f[n_] := f[n] =
  f[n - 1] + f[n - 3] + f[n - 5] + f[n - 6];

f[50]