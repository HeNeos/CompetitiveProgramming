f[a_, 1, m_] = Mod[a, m];
f[a_, b_, m_] := f[a, b, m] = PowerMod[a, Mod[f[a, b - 1, EulerPhi[m]], EulerPhi[m]], m];
Print[f[1777,1855,10^8]];