const N = 4000000;
const f = [1, 2];

function build(){
	let a = 1, b = 2;
	for(;;){
		b += a;
		a = b-a;
		if(b > N) break;
		f.push(b);
	}
}

build();
let ans = 0;
for(x of f)
	ans += (1 - x&1)*x;

console.log(ans)