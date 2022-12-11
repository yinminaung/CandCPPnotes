#include <stdio.h>

int main(){
    int i=0;
    int c;
    int data[100];
    FILE *fptr;

    /* writes to file */
    fptr = fopen("winthut.txt","w");

    if (fptr){
        for (int i=1;i<=100;i++){
            fprintf(fptr,"%d\n",i);
        }
        fclose(fptr);
        
        /* reads from file */
        fptr = fopen("winthut.txt","r");
        if (fptr){
            while ((fscanf(fptr, "%d",&c)) != EOF) {
                data[i] = c;
                i++;
            }
            fclose(fptr);
        } else { 
            printf("[!] File can't be opened.");
        }
    } else { 
        printf("[!] File can't be opened.");
    }

    /* displays data array on console */
    printf("array: {");
    for (int j=0;j<99;j++){ 
        printf("%d, ",data[j]); 
    }
    printf("%d}",data[99]);
    
    return 0;
}