function test(x){
    let s = x.toString();
    for(let i=0, j=s.length-1; i<j; i++, j--){
        if(s[i] != s[j]) return false;
    }
    return true;
}

let ans = -1;

for(let i=110; i<1000; i+=11){
    for(let j=100; j<1000; j++){
        let p = i*j;
        if(test(p)) ans = Math.max(ans, p);
    }
}
console.log(ans);