/*
*
* D. Little Girl and Maximum XOR
*
* Suppose two cases:
* 1) 'a' and 'b' have the same number of bits
* 2) 'a' and 'b' have different number of bits
* If a=b, then XOR=0.
* For the case 1):
* Let's say that bitsb is the number of bits of b and that bitsa is the number of bits of a.
* We are located at number 2^(bitsb-1)-1. That is, the maximum number that can be represented with 'bitsb-1' bits
* We do the XOR operation of this number with its consecutive:
* 01111 .... 11111 ^ 1000 .... 00000 = 1111 .... 11111 (The maximum number that can be represented with 'bitsb' bits).
* MAX XOR = 2^(bitsb)-1
* It is trivial to note that it is not possible to form a larger number with the XOR operation.
* For the case 2):
* The first bit for both numbers must be 1 (otherwise it becomes case 1), we look at the second bit,
* if the bit is different then case 1 becomes), otherwise we test with the next bit.
* It can be solved by recursion, but we just need to know how many different bits have up to
* find an equal one (if there is one) for example:
* 1001110 and 1001001 have 4 equal bits until the first difference ('1001' ...)
* As in case 1) and following the previous example:
* MAX XOR (1001110|1001001)-->'1001'110|'1001'001. We are located at '1001'011 and do the XOR operation with its consecutive.
* '1001'011 &' 1001'100 = '1001'111.
* When doing the XOR operation we will have '0' in the bits equals and at most we can form '1' in the remaining bits.
* Let bitseq be the number of equal bits:
* MAX XOR = 2^(bitsb-bitseq)-1
*
* The main idea of the algorithm is to locate the number whose bit representation only contains '1' and that
* its bits are one less than that of the largest number.
*
*
* Complexity = O(lg(bitsb))
*
*/


#include<bits/stdc++.h>
using namespace std;
int main(){
    long long a;
    long long b;
    cin>>a>>b;
    int bitsa;
    int bitsb;
    int cont=0;
    if(a==b){
        cout<<0;
        return 0;
    }
    bitsa=floor(log2(a))+1;
    bitsb=floor(log2(b))+1;
    if(bitsb>bitsa) cout<<(1LLU<<(bitsb))-1;
    else{
        for(int i=bitsb-1; i>=0; i--){
            if(!((a>>i)^(b>>i))) cont++;
            else break;
        }
        cout<<(1LLU<<(bitsb-cont))-1;
    }
return 0;
}
