//’€∞Î≤È’“
int Binary_search(Seqlist L,Elemtype key)
{
    int low=0,high=L.Table-1,mid;
    while(low<=high){
        mid = (high+low)/2;
        if(L.ele[mid]==key)
            return mid;
        else if (L.ele[mid]>key)
            high = mid-1;
        else low = mid+1;
    }
    return -1;
}


