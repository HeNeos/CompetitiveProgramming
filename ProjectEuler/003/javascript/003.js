let N = 600851475143;
let ans = 1;
for(let i=2; i*i<=N; i++){
    while(N%i == 0){
        N /= i;
        ans = i;
    }
}
ans = Math.max(ans, N);
console.log(ans);