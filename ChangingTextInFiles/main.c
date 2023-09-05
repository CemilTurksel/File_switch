#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *ptr1,*ptr2,*ptr3;
    char folder1[20],folder2[20];
    int n,i;
    char ch;

    puts("Enter the name of the first file: ");fgets(folder1,20,stdin);
    n=strlen(folder1);
    folder1[n-1]='\0';

    puts("Enter the name of the second file: ");fgets(folder2,20,stdin);
    n=strlen(folder2);
    folder2[n-1]='\0';

    if ((ptr1 = fopen(folder1, "r")) == NULL)
    {
        puts("No such file!");
        exit(1);
    }
    if ((ptr2 = fopen(folder2, "r")) == NULL) {
        puts("No such file!");
        exit(1);
    }

    if ((ptr3 = fopen("temp.txt", "w")) == NULL) {
        puts("Temporary file could not be created...");
        exit(1);
    }

    while ((ch=fgetc(ptr2))!=EOF){
        fputc(ch,ptr3);
    }
    fclose(ptr2);
    fclose(ptr3);

    //Open ptr2(Second file) again.
    if ((ptr2 = fopen(folder2, "w")) == NULL) {
        puts("No such file!");
        exit(1);
    }
    while ((ch=fgetc(ptr1))!=EOF){
        fputc(ch,ptr2);
    }
    fclose(ptr1);
    fclose(ptr2);

    if ((ptr1 = fopen(folder1, "w")) == NULL)
    {
        puts("No such file!");
        exit(1);
    }
    if ((ptr3 = fopen("temp.txt", "r")) == NULL) {
        puts("Temporary file could not be created...");
        exit(1);
    }
    while ((ch=fgetc(ptr3))!=EOF){
        fputc(ch,ptr1);
    }
    fclose(ptr1);
    fclose(ptr3);
    remove("temp.txt");
    printf("Successful!");
    return 0;
}
