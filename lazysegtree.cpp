int seg[4*N], la[4*N];
void bu(int i, int l, int r){
    if(l == r) {
        seg[i] = a[l-1];
        return;
    }
    int m = (l+r) / 2;
    bu(i*2, l, m);
    bu(i*2+1, m+1, r);
    seg[i] = seg[i*2] + seg[i*2+1];
}
void pu(int i, int l, int r){
    seg[i] += la[i] * (r-l+1);
    if(l != r){
        la[i*2] += la[i];
        la[i*2+1] += la[i];
    }
    la[i] = 0;
}
int f(int i, int l, int r, int ql, int qr){
    pu(i, l, r);
    if(l > qr || r < ql) return 0;
    if(l >= ql && r <= qr) return seg[i];
    int m = (l+r) / 2;
    return f(i*2, l, m, ql, qr) + f(i*2+1, m+1, r, ql, qr);
}
void up(int i, int l, int r, int ql, int qr, int v){
    pu(i, l, r);
    if(l > qr || r < ql) return;
    if(l >= ql && r <= qr){
        la[i] += v;
        pu(i, l, r);
        return;
    }
    int m = (l+r) / 2;
    up(i*2, l, m, ql, qr, v);
    up(i*2+1, m+1, r, ql, qr, v);
    seg[i] = seg[i*2] + seg[i*2+1];
}
