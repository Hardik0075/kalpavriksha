#include<stdio.h>
long long calculate(long long base, long long exp , long long mod){
    long long result=1;
    base = base % mod;
    while(exp>0){
        if(exp%2==1){
            result *= (base)%mod;
            exp-=1;
        }
        exp = exp/2;
        base = (base * base)% mod;
    }
    return result;
}
int main(){
    long long base,exp,mod,result;
    scanf("%lld",&base);
    scanf("%lld",&exp);
    scanf("%lld",&mod);
    if(mod==0){
        printf("0");
        return 0;
    }
    if(exp==0){
        printf("1");
        return 0;
    }   
    result =  calculate(base,exp,mod);
    printf("%lld",result);
}
