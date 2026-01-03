#include <stdio.h>

int main() {
    
    int n;
    scanf("%d", &n);
    
    int arr[n];
    
    for(int i=0;i<n;i++){

        scanf("%d", &arr[i]);
 
    }

    int initial = 0;

    for(int i=0;i<n;i++){


        if ( (initial = initial + arr[i])%360 == 0 || (initial = initial - arr[i])%360 ==0){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
        
        


    }
    
    

    return 0;
}