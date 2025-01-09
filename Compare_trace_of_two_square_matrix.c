#include <stdio.h>
#include <stdlib.h>
int main()
{
    //trace
    int dimension;
    scanf("%d",&dimension);
    int *array1[dimension];
    int *array2[dimension];
    for(int index=0;index<dimension;index++){
        array1[index]= (int *)malloc(sizeof(int)*dimension);
        array2[index]= (int *)malloc(sizeof(int)*dimension);
    }
    for(int outer_index=0;outer_index<dimension;outer_index++){
        for(int inner_index=0;inner_index<dimension;inner_index++){
            scanf("%d",(*(array1+outer_index)+inner_index));
        }
    }
    for(int outer_index=0;outer_index<dimension;outer_index++){
        for(int inner_index=0;inner_index<dimension;inner_index++){
            scanf("%d",(*(array2+outer_index)+inner_index));
        }
    }
    int trace1=0,trace2=0;
    for(int index=0;index<dimension;index++){
                trace1+= *(*(array1+index)+index);
                trace2+= *(*(array2+index)+index);
    }
    if(trace1==trace2){
        printf("Both Trace are equal \n");
    }
    else{
        printf("Trace is not equal \n");
    }
    return 0;
}
