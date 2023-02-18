int fakt[200005];
void init(){
    rep(i,1,200005)fakt[i]=(fakt[i-1]*i)%MOD;
}
int binpow(int a,int b){
    int res=1;
    while(b){
        if(b&1)
            res=(res*a)%MOD;
        a=(a*a)%MOD;
        b/=2;
    }
    return res;
}
int komb(int x,int y){
    int ust=fakt[x];
    int alt=(fakt[y]*fakt[x-y])%MOD;
    int ans=(ust*binpow(alt,MOD-2))%MOD;
    return ans;
}
