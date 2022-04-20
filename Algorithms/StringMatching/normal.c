#include<stdio.h>
#include<stdlib.h>


int main(){
    /*
     *printf("Enter string to search for : ");
     *char input[1000];
     *scanf("%[^\n]c",input);
     */
    char input[]="The end of the Project Gutenberg";
    FILE* search_fd = fopen("./input.txt","r");
    fseek (search_fd, 0, SEEK_END);
    int length = ftell (search_fd);
    fseek (search_fd, 0, SEEK_SET);
    char* search_content = malloc (length*sizeof(char));
    fread (search_content, 1, length, search_fd);
    fclose (search_fd);   

    int i=0,j=0;
    int is_found = 0;
    int line=1;
    while(!is_found && search_content[i] != '\0'){
        if(search_content[i] == '\n')
            line++;
        int k=i;
        while(input[j]!='\0' && search_content[k] == input[j]){
            k++;
            j++;
        }
        if(input[j] == '\0')
            is_found =1;
        else{
            j=0;
        }
        i++;
    }
    if(is_found){
        printf("[First hit] Found! at : line %d \n",line);
    }else{
        printf("Not found :( \n");
    }
    return 0;
}
