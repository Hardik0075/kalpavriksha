#include<stdio.h>
#include<stdlib.h>

int main(){
    int rows , columns;
    scanf("%d",&rows);
    scanf("%d",&columns);
    int *array[rows];
    for(int index=0;index<rows;index++){
        array [index] = (int *)malloc(columns*sizeof(int));
    }
    for(int index1=0;index1<rows;index1++){
        for(int index2=0;index2<columns;index2++){
            scanf("%d",(*(array+index1)+index2));
        }
    }
    for(int index1=0;index1<rows;index1++){
        for(int index2=0;index2<columns;index2++){
            printf("%d ",*(*(array+index1)+index2));
        }
        printf("\n");
    }

    int row_start = 0;
    int row_end = rows-1;
    int columns_start = 0;
    int columns_end = columns-1;
    while(row_start<=row_end && columns_start<=columns_end){
        for(int index=columns_start;index<=columns_end;index++){
            printf("%d ",*(*(array+row_start)+index));                     
        }
        row_start++;
        for(int index=row_start;index<=row_end;index++){
            printf("%d ",*(*(array+index)+columns_end));
        }
        columns_end--;
        for(int index=columns_end;index>=columns_start;index--){
            printf("%d ",*(*(array+row_end)+index));
        }
        row_end--;
        for(int index=row_end;index>=row_start;index--){
            printf("%d ",*(*(array+index)+columns_start));
        }
        columns_start++;
    }    
    for(int i=0;i<rows;i++){
        free(array[i]);
    }
    return 0;
}
