#include<stdio.h>
#include<string.h>
#include<stdbool.h>

int findSubstring(char original[80], char substring[80]);
int replaceInString(char original[80], char substring[80], char replace[80]);
void insertString(char original[80], int start, int length, char toInsert[80]);

int main(int argc, char * argv[]){

    FILE * inputFile;
    char original[80];
    char substring[80];
    char replace[80];
    int substringPos = 0;
    for(int i = 0; i < 80; i++){
        original[i] = '\0';
        substring[i] = '\0';
        replace[i] = '\0';
    }

    if (argc == 2){
        inputFile = fopen(argv[1], "r+");
    }else{
        printf("NO FILE GIVEN\n");
        return -1;
    }

    fgets(original,80,inputFile);

    printf("(1) %s\n", original);
    printf("Enter the substring you want to change\n");
    fgets(substring,80,stdin);
    substring[strlen(substring)-1] = '\0';
    printf("Searching for %s\n", substring);

    substringPos = findSubstring(original, substring);
    if (substringPos == -1)
    {
        printf("substring not found!");
        return 0;
    }
    
    printf("\nType what you wish to replace '%s' with ", substring);
    fgets(replace,80,stdin);
    if ((strlen(original) - strlen(substring) + strlen(replace)) > 80)
    {
        printf("TOO long sorry\n");
        return 1;
    }
    if (replace[strlen(replace) - 1] == '\n')
    {
        replace[strlen(replace) - 1] = '\0';
    }

    int success = replaceInString(original, substring, replace);

    printf("\n\n%s", original);

    for (int i = 0 ; i <=5; i++){
          if (i == lineNum){
              fprintf(original);
          }          
    }

    return 0;
}

int findSubstring(char original[80], char substring[80])
{
    char * returnValue = strstr(original, substring);
    int position = returnValue - original;

    //check if the substring is even in the original string
    if (strstr(original, substring) == NULL){
        printf("The substring was not found in the original string");
        return -1;
    }

printf("The position is %d", position);

    return position;
}

int replaceInString(char original[80], char substring[80], char replace[80])
{
    int position = 0;

    position = findSubstring(original,substring);
    
    insertString(original, position, strlen(substring), replace);
    
    return 1;   

}

void insertString(char original[80], int start, int length, char toInsert[80])
{
    char temp1[80];
    char temp2[strlen(original) - start];

    strncpy(temp1, original, start);
    strcpy(temp2, &original[start + length]);
    
    strcpy(original, temp1);
    strcat(original, toInsert);
    strcat(original, temp2);

    return;
}
