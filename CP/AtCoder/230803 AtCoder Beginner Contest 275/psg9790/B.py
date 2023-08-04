s = list(map(int, input().split()))

_abc = s[0] * s[1] * s[2];
_def = s[3] * s[4] * s[5];

print((_abc-_def)% 998244353);