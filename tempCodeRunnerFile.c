// Emmanuel Colas
// Lex.c A lexical analayzer

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

int assign_token(char *token)   // This function takes in a token from main, compares it to strings, and 
{                               //return the token number corresponding to the token

    if (strcmp(token, "skip") == 0)
    {
        
        return 1;
    }
    else if (strcmp(token, "+") == 0)
    {
        
        return 4;
    }
    else if (strcmp(token, "-") == 0)
    {
        
        return 5;
    }
    else if (strcmp(token, "*") == 0)
    {
        
        return 6;
    }
    else if (strcmp(token, "/") == 0)
    {
        
        return 7;
    }
    else if (strcmp(token, "xor") == 0)
    {
        
        return 8;
    }
    else if (strcmp(token, "=") == 0)
    {
        
        return 9;
    }
    else if (strcmp(token, "<>") == 0)
    {
        
        return 10;
    }
    else if (strcmp(token, "<") == 0)
    {
        
        return 11;
    }
    else if (strcmp(token, "<=") == 0)
    {
        
        return 12;
    }
    else if (strcmp(token, ">") == 0)
    {
        
        return 13;
    }
    else if (strcmp(token, ">=") == 0)
    {
        return 14;
        
    }
    else if (strcmp(token, "(") == 0)
    {
        return 15;
        
    }
    else if(strcmp(token,")") == 0){
        return 16;
        
    }
    else if (strcmp(token, ",") == 0)
    {
        return 17;
        
    }
    else if (strcmp(token, ";") == 0)
    {
        return 18;
        
    }
    else if (strcmp(token, ".") == 0)
    {
        return 19;
        
    }
    else if (strcmp(token, ":=") == 0)
    {
        return 20;
        
    }
    else if (strcmp(token, "begin") == 0)
    {
        return 21;
        
    }
    else if (strcmp(token, "end") == 0)
    {
        return 22;
        
    }
    else if (strcmp(token, "if") == 0)
    {
        return 23;
        
    }
    else if (strcmp(token, "then") == 0)
    {
        return 24;
        
    }
    else if (strcmp(token, "while") == 0)
    {
        return 25;
        
    }
    else if (strcmp(token, "do") == 0)
    {
        return 26;
        
    }
    else if (strcmp(token, "call") == 0)
    {
        return 27;
        
    }
    else if (strcmp(token, "const") == 0)
    {
        return 28;
        
    }
    else if (strcmp(token, "var") == 0)
    {
        return 29;
        
    }
    else if (strcmp(token, "procedure") == 0)
    {
        return 30;
        
    }
    else if (strcmp(token, "write") == 0)
    {
        return 31;
        
    }
    else if (strcmp(token, "read") == 0)
    {
        return 32;
    }
    else if (strcmp(token, "else") == 0)
    {
        return 33;
    }
    else if (atoi(token) == 0)
    {
        
        return 2;
    }
    else if (atoi(token) > 0)
    {
        
        return 3;
    }
}

bool check_identifier(char token[])    // This function is used to check that an identifier does not start with a letter
{
    for (int i = 1; i < strlen(token); i++)
    {
        if (isdigit(token[i]) != 1){
            return false;
        }
    }
    return true;
}

bool check_invalid(char token[])    // This function is used to check that an identifier does not contain a invalid character

{
    for (int i = 0; i < strlen(token); i++)
    {
        if (token[i] == 33 || token[i] == 64 || token[i] == 95 || token[i] == 35 
        || token[i] == 36 || token[i] == 94 || token[i] == 63 || token[i] == 25
        || token[i] == 38 || token[i] == 37)
        {
            return false;
        }
    }
    return true;
}

bool check_operation(char source_code[],int i)     // looks for a comma, semi colon, period, order of operations, etc and makes sure to be counted as
            {                                      // its own token
    if(source_code[i] == 44 || source_code[i] == 59 || source_code[i] == 46 || source_code[i] == 43 
                || source_code[i] == 45 || source_code[i] == 42 || source_code[i] == 47 || source_code[i] == 40 
                || source_code[i] == 41 || source_code[i] == 59 || (source_code[i-1] != 58 && source_code[i] == 61)) return true;

                return false;
}
    int main()
    {
        int count = 0;                      // Initialization of variables. Setting pointers to files.
        int j = 0;
        char source_code[300] = {'\0'};
        char editted_array[300] = {'\0'};
        char *token;
        FILE *output = fopen("output.txt","w");
        FILE *file = fopen("test.txt", "r");
        while (fscanf(file, "%c", &source_code[count]) == 1)  // Assinging values to the array source code array
            count++;
        
            fprintf(output,"%s \n",source_code);
        
        for (int i = 0; i < count; i++)// goes through the source code array and transfers characters to a new array. This is to remove white spaces
        {                               // its also seperates operators from variables so that they can be tokenized. 

            if (source_code[i] == 47 & source_code[i + 1] == 42)// looks for /* in the source code
            {
                i = i + 2;
                while (source_code[i] != 42 && source_code[i + 1] != 47) // skips chars wntil it finds */ which marks the end of the comment
                {
                    i++;
                }
                i = i + 2;
            }
            if (source_code[i] == 9 || source_code[i] == 10) // Replace \n and \t with a space
            {
                source_code[i] = ' ';
            }
            if (check_operation(source_code,i) == true){
                editted_array[j] = ' ';
                editted_array[j + 1] = source_code[i];
                editted_array[j+2] = ' ';
                j = j + 3;
            }
            else
            {
                editted_array[j] = source_code[i];
                j++;
            }
        }
        fclose(file);
        
        
         
        fprintf(output, "\nLexeme Table\n\nLexeme\tToken\n");
        
        strcpy(source_code,editted_array);
        token = strtok(editted_array, " ");

        while (token != NULL)  // Goes through our new array and tokenized the charcters. Will look for invalid token with the if statements.
        {
            if (strlen(token) > 12)
            {
                fprintf(output,"%s is too long.\n", token);
                token = strtok(NULL, " ");
                continue;
            }
            else if (atoi(token) > 0 && atoi(token) >= 100000)
            {
                fprintf(output,"%s is too large of a number\n", token);
                token = strtok(NULL, " ");
                continue;
            }
            else if (atoi(token) > 0)
            {
                if(check_identifier(token) == false){
                    fprintf(output,"Identifier %s can not start with an interger\n", token);
                    token = strtok(NULL, " ");
                    continue;
                }
            }else if(check_invalid(token) == false){
                fprintf(output,"Contains an invalid character\n");
                token = strtok(NULL, " ");
                continue;
            }
        
        fprintf(output," %s \t", token); // after statement will print the valid lexeme with the valid token.
        fprintf(output,"%d \n", assign_token(token));
        token = strtok(NULL, " ");

    }

fprintf(output,"\nLexeme List:\n\n"); // This uses the same if statements to print Just the token numbers. 

    token = strtok(source_code, " ");
    while (token != NULL)
        {
            if (strlen(token) > 12)
            {
                token = strtok(NULL, " ");
                continue;
            }
            else if (atoi(token) > 0 && atoi(token) >= 100000)
            {
                token = strtok(NULL, " ");
                continue;
            }
            else if (atoi(token) > 0)
            {
                if(check_identifier(token) == false){

                    token = strtok(NULL, " ");
                    continue;
                }
            }else if(check_invalid(token) == false){
                token = strtok(NULL, " ");
                continue;
            }
        

        fprintf(output,"%d ", assign_token(token));
        if(assign_token(token) == 2 || assign_token(token) == 3){
            fprintf(output,"%s ", token);
        }
        
        token = strtok(NULL, " ");

            
 