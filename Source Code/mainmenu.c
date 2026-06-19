#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include "main_menu.h"
extern int foundi;


void mainmenu(){
    int choice;
    while(1){

    printf("\n");
    printf("*****************************************************\n");
    printf("             WELCOME TO THE INVENTORY\n");
    printf("*****************************************************\n");

    printf("1.Add Product \n");
    printf("2.View All product \n");
    printf("3.Search Product \n");
    printf("4.Update Product\n");
    printf("5.Delete Product \n");
    printf("6.Check Expiry Alerts \n");
    printf("7.Low Stock Report \n");
    printf("8.Generate Inventory Report \n");
    printf("9.Logout \n");
    printf("10.Exit \n");
    
    printf("\n");
    printf("ENTER THE CHOICE:");
    scanf("%d",&choice);

    switch(choice){
        case 1:
        add();
        break;

        case 2:
        view();
        break;

        case 3:
        search();
        break;

        case 4:
        update();
        break;

        case 5:
        del();
        break;

        case 6:
        expiry();
        break;

        case 7:
        low_stock();
        break;

        case 8:
        generate();
        break;

        case 9:
        logout();
        return;

        case 10:
        printf("*****************************************************\n");
        printf("                     THANK YOU\n");
        printf("*****************************************************\n");
        exit(0);
        default:
        printf("\nINVALID CHOICE! PLEASE TRY AGAIN.\n");
    }
    }
} 
