#include<stdio.h>
#include <stdlib.h>
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int x;
        int y;
        int k;
        scanf("%d",&x);
        scanf("%d",&y);
        scanf("%d",&k);
        int arr[100000];
        int dup = x;
        int i=99999;
        while(dup!=0){
            arr[i]=dup%y;
            dup = dup/y;
            i--;
        }
        for(int j=0;j<=i;j++){
            arr[j]=0;
        }
        int lowest = i;
        i=99999;    
        int num = 0;
        while(num<k){
            num = num+y-arr[i];
            if(num<=k){
                arr[i]=0;
                arr[i-1]=arr[i-1]+1;
                while(arr[i-1]==y){
                    i--;
                    // if(i<lowest){
                    //     i=32;
                    // }
                    arr[i-1] = arr[i-1]+1;
                }
                i--;
            }else{
                num=num-y+arr[i];
                // printf("%d\n",arr[31]);
                arr[i]=arr[i]+k-num;
                // printf("%d\n",arr[31]);
                num=k;
            }
        }
        // printf("i:%d\n",i);
        // printf("%d\n",arr[30]);
        // printf("%d\n",arr[31]);
        int n = 0;
        for(int j=0;j<=i;j++){
            n=n+arr[j];
            n=n*y;
        }
        n=n/y;
        printf("%d\n",n);
    }
}