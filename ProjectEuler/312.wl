c[n_, m_] :=
   Mod[8 * PowerMod[12, (3 ^ (n - 2) - 3) / 2, m], m];

cc[n_, m_] :=
   Mod[8 * PowerMod[12, Mod[(PowerMod[3, c[n, EulerPhi[EulerPhi[m]]] 
      - 2, EulerPhi[m]] - 3) / 2, EulerPhi[m]], m], m];

ccc[n_, m_] :=
   Mod[8 * PowerMod[12, Mod[(PowerMod[3, cc[n, EulerPhi[EulerPhi[m]]]
       - 2, EulerPhi[m]] - 3) / 2, EulerPhi[m]], m], m];
