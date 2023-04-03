#include<stdio.h>
#include<stdlib.h>

int * array; int *dup;
int dup_count=0;
int g_size;
int flag=0;

void merge(int left,int mid,int right){
    int i=left;
    int j=mid+1;
    int count=0;
    // for(int i=left;i<=right;i++){
    //         printf("%d",array[i]);
            
    //     }
        printf("\n-----\n");

    
    while(i<=mid && j<=right){
        printf("%d--%d\n",array[i],array[j]);
        if(array[i]==array[j]){
            // printf("insiedS\n");
            dup[dup_count]=array[i];
            dup_count++;
            flag++;
            i++;
            j++;
            count++;
        }
        else if (array[i]<array[j]){
            i++;count++;

        }
        else{
            j++;count++;
        }

    }
    if(flag==1){
        flag++;
        printf("insied flag \n\n");
        for(int i=left;i<=right;i++){
            printf("%d",array[i]);
            
        }
        printf("\n\n");
        // flag=-12;
    }
}
void merge_over(int left,int right){
    if(left==right){
        printf("");

    }
    else{
        int mid=(right+left)/2;
    if(mid>=left){
    merge_over(left,mid);
    }
    if(mid<right){
    merge_over(mid+1,right);
    }
    merge(left,mid,right);

    }

    

}

int main(){
    printf("enter the size");
    scanf("%d",&g_size);
    dup=(int*)malloc(sizeof(int)*(g_size));
    array=(int*)malloc(g_size*sizeof(int));
    for(int i=0;i<g_size;i++){
        scanf("%d",&array[i]);
    }
    printf("input array\n");
    for(int i=0;i<g_size;i++){
        printf("%d",array[i]);
    }
    printf("\n\n");
    merge_over(0,g_size-1);



    return 0;
}