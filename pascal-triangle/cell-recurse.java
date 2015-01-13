public void pascal(int n){
    for(int i = 0 ; i <= n ;++i){
        println(pascalAus(n,i));
    }
 
}

public int pascalAus(int n, int m){
    if(n == 0 || n == 1){
        return 1;
    }
    if(m == 0 || m == n) {
        return 1;
    }
    return pascalAus(n-1,m-1) + pascalAus(n-1,m);
}
