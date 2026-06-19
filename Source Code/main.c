#include<stdio.h>
#include<string.h>
#include "auth.h"
extern int foundi;

int main(){
    int choice;
    while(!(foundi)){
    printf("\n");
    printf("*****************************************************\n");
    printf("          INVENTORY MANAGEMENT SYSTEM\n");
    printf("*****************************************************\n");
    printf("1.LOGIN \n");
    printf("2.FORGET PASSWORD \n");
    printf("3.REGISTER \n");
    printf("4.CHANGE PASSWORD\n");
    printf("5.EXIT \n");
    printf("ENTER THE CHOICE:");
    scanf("%d",&choice);
    switch(choice){
        case 1:
        loginuser();
        break;
        case 2:
        forgetpass();
        break;
        case 3:
        regist();
        break;
        case 4:
        changepassw();
        break;
        case 5:
        printf("*****************************************************\n");
        printf("                     THANK YOU\n");
        printf("*****************************************************\n");
        return 0;
        default:
        printf("\nINVALID CHOICE! PLEASE TRY AGAIN.\n");
    }
}
}