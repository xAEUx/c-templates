struct node{
    int l,r,v=0,lazy=0;
    node *L=NULL,*R=NULL;
};
void add(node *cur){
    if(cur->L==NULL){
        cur->L = new node;
        cur->R = new node;
        int l=cur->l,r=cur->r;
        int m=(l+r)/2;
        cur->L->l=l,cur->L->r=m;
        cur->R->l=m+1,cur->R->r=r;
    }
}
void push(node *cur){
    cur->v+=cur->lazy*(cur->r-cur->l+1);
    if(cur->l!=cur->r){
        add(cur);
        cur->L->lazy += cur->lazy;
        cur->R->lazy += cur->lazy;
    }
    cur->lazy=0;
}
int find(node *cur,int ql,int qr){
    push(cur);
    if(cur->l>qr || cur->r<ql)
        return 0;
    if(cur->l>=ql && cur->r<=qr)
        return cur->v;
    return find(cur->L,ql,qr)+find(cur->R,ql,qr);
}
void update(node *cur,int ql,int qr,int val){
    push(cur);
    if(cur->l>qr || cur->r<ql)
        return;
    if(cur->l>=ql && cur->r<=qr){
        cur->lazy += val;
        push(cur);
        return;
    }
    update(cur->L,ql,qr,val);
    update(cur->R,ql,qr,val);
    cur->v = cur->L->v + cur->R->v;
}
node root;
