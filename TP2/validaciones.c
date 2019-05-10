#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "validaciones.h"

int getInt(int* input,char message[],char eMessage[], int lowLimit, int hiLimit){
    int todoOk=1;
    int isInteger=0;
    int numeroValidado=0;
    char auxNum[10]={'0'};

    printf("%s : ", message);
    scanf("%s", auxNum);
    isInteger=isInt(auxNum);

    if(isInteger){
        numeroValidado=atoi(auxNum);
        if(numeroValidado<lowLimit || numeroValidado>hiLimit){
            printf("%s : ", eMessage);
            scanf("%s", auxNum);
            todoOk=-1;
        }else{
            *input=numeroValidado;
        }
    }else{
        printf("Ingrese solo numeros!\n");
        todoOk=-1;
    }

    return todoOk;
}

int isInt(char auxNum[]){
   int i=0;
   int todoOk = 1;
   while(auxNum[i] != '\0'){
       if((atoi(auxNum))==0){
           todoOk = 0;
       }
       i++;
   }
   return todoOk;
}

int getFloat(float* input,char message[],char eMessage[], float lowLimit, float hiLimit){
    int todoOk=1;
    int isFloating=0;
    int numeroValidado=0;
    char auxNum[10]={'0'};

    printf("%s : ", message);
    scanf("%s", auxNum);
    isFloating=isFloat(auxNum);

    if(isFloating){
        numeroValidado=atof(auxNum);
        if(numeroValidado<lowLimit || numeroValidado>hiLimit){
            printf("%s : ", eMessage);
            scanf("%s", auxNum);
            todoOk=-1;
        }else{
            *input=numeroValidado;
        }
    }else{
        printf("Ingrese solo numeros!\n");
        todoOk=-1;
    }
    return todoOk;
}

int isFloat(char auxNum[]){
   int i=0;
   int todoOk = 1;
   int contadorComas=0;

   while(auxNum[i] != '\0'){
       if(auxNum[i]<'0' || auxNum[i]>'9'){
           if(auxNum[i]=='.'){
               contadorComas++;
           }
       }
       if((atof(auxNum))==0 || contadorComas>1){
           todoOk = 0;
       }
       i++;
   }
   return todoOk;
}

int getChar(char* input,char message[],char eMessage[], char lowLimit, char hiLimit){
    printf("%s: ", message);
    fflush(stdin);
    scanf("%c", input);
    *input=toupper(*input);

    while (*input>hiLimit || *input<lowLimit){
        printf("Reingrese %s: ", eMessage);
        fflush(stdin);
        scanf("%c", input);
        *input=toupper(*input);
    }

    return 1;
}

int validateSex(char* input,char message[],char eMessage[]){

    printf("%s: ", message);
    fflush(stdin);
    scanf("%c", input);
    *input=toupper(*input);

    while (*input!='F' && *input!='M'){
        printf("%s: ", eMessage);
        fflush(stdin);
        scanf("%c", input);
        *input=toupper(*input);
    }

    return 1;
}

int getString(char* input,char message[],char eMessage[], int lowLimit, int hiLimit){
    char auxString[100]={"0"};
    int sizeOfString=0;
    int todoOk=0;
    int isCharacter=0;

    printf("%s: ", message);
    fflush(stdin);
    scanf("%s", auxString);

    isCharacter=isChar(auxString);

    if(isCharacter){
      sizeOfString=strlen(auxString);
        if(sizeOfString>hiLimit || sizeOfString<lowLimit){
            system("cls");
            printf("%s ", eMessage);
            todoOk=-1;

        }else{
            auxString[0]=toupper(auxString[0]);
            strcpy(input,auxString);
            todoOk=1;
        }
    }
    else{
        printf("Ingrese solo letras!\n");
        todoOk=-1;
    }

    return todoOk;
}

int isChar(char auxString[]){
   int i=0;
   int todoOk = 1;
   while(auxString[i] != '\0'){
       if((auxString[i] < 'a' || auxString[i] > 'z') && (auxString[i] < 'A' || auxString[i] > 'Z')){
           todoOk = 0;
       }
       i++;
   }
   return todoOk;
}
