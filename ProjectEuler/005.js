let ans = 1;

function gcd(a, b){
    let c;
    while(b){
        c = b;
        b = a%b;
        a = c;
    }
    return a;
}

function lcm(a, b){
    return a/gcd(a,b)*b;
}

for(let i=2; i<=20; i++){
    ans = lcm(ans, i);
}

console.log(ans);