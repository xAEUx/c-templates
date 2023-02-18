void init(){
    rep(i,0,N)p[i]=i;
    rep(i,0,N)size[i]=1;
}
int find(int n){
    return (p[n]==n?n:p[n]=find(p[n]));
}
void merge(int x,int y){
    x=find(x),y=find(y);
    if(size[x]<size[y])swap(x,y);
    if(x!=y)
        p[y]=x,size[x]+=size[y];
}
