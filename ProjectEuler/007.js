const N = 5000000;
const p = Array(N).fill(true);
const primes = [];

function sieve(){
    for(let i=2; i<N; i++){
        if(p[i]){
            primes.push(i);
            for(let j=i*i; j<N; j+=i) p[j] = false;
        }
    }
}

sieve();

console.log(primes[10001-1]);