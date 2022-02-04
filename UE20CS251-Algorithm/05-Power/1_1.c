int power(int b,int p){
    int res;
    if(p == 0)
        res = 1;
    else{
        res = b * power(b,p-1);
    }
    return res;
}

int power_with_count(int b,int p,int* count){
    int res;
    if(p == 0){
        res = 1;
        *count+=1;
    }else{
        *count+=1;
        res = b*power_with_count(b,p-1,count);
    }
    return res;
}

