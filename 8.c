#include<stdio.h>
#include<stdlib.h>
#include"qsort.c"

int NumLines() {

    FILE *fp;
    int count=0;
    char c;
    if ((fp = fopen("data.txt","r")) == NULL){
        printf("Error! file not found");
        exit(1);
    }

    for(c=getc(fp);c!=EOF;c=getc(fp)){
        if(c=='\n'){
            count++;
        }
    }
    fclose(fp);
    return count;
}

int *conToList(int *arr) { //convert to list
    FILE *fp;
    int num=0,nLines=0;
    nLines=NumLines(); //number line

    if ((fp = fopen("data.txt","r")) == NULL){
        printf("Error! file not found");
        exit(1);
    }
    for(int i=0;i<nLines;i++){
        fscanf(fp,"%d",&num);
        arr[i]=num;
    }

    fclose(fp);
    return arr;   
}

int main () {
    FILE *fp;
    fp = fopen("data_sorted.txt","w");

    int i,USA[1000]; //Unsorted array
    int *USA_list = conToList(USA); 
    int *SA = quicksort(USA_list,0,999); //Sorted array
    for(i=0;i<1000;i++)
        fprintf(fp,"%d\n",SA[i]);   

    fclose(fp);
}