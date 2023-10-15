main() {
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++) {
        printf("%d ",i);
        if(i%6==0||i==n) printf("Go! ");
    }
}