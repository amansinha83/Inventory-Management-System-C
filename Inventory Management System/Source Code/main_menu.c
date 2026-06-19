#include<stdio.h>
#include<string.h>
#include "main_menu.h"
extern int foundi;

void add(){

    struct Product a,temp;
    FILE *f;

    printf("ENTER THE PRODUCT ID:");
    scanf("%d",&a.id);

    f = fopen("product.txt", "r");

    if (f != NULL) {
        while (fscanf(f, "%d %s %d %d %d %d %d %d %d %d",&temp.id,temp.pname,&temp.qt,&temp.price,&temp.exp.date,&temp.exp.month,
                      &temp.exp.year,&temp.man.date,&temp.man.month,&temp.man.year) == 10) {

            if (temp.id == a.id) {
                printf("*****************************************************\n");
                printf("  ERROR: PRODUCT ID %d ALREADY EXISTS!\n", a.id);
                printf("*****************************************************\n");
                fclose(f);
                return;
            }
        }
        fclose(f);
    }


    getchar();
    printf("ENTER THE PRODUCT NAME: ");
    fgets(a.pname, sizeof(a.pname), stdin);
    a.pname[strcspn(a.pname, "\n")] = '\0';

    printf("ENTER THE QUANTITY: ");
    scanf("%d",&a.qt);

    printf("ENTER THE PRICE OF THE PRODUCT: ");
    scanf("%d",&a.price);

    printf("ENTER THE EXPIRY DATE (DD/MM/YYYY): ");
    scanf("%d %d %d", &a.exp.date, &a.exp.month, &a.exp.year);

    printf("ENTER THE MANUFACTURING DATE (DD/MM/YYYY): ");
    scanf("%d %d %d", &a.man.date, &a.man.month, &a.man.year);

    if(a.id<=0 || strlen(a.pname)==0 || a.price <=0 || a.exp.date >31 || a.exp.month> 12 || a.exp.year <0 ||
     a.man.date >31 || a.man.month> 12 || a.man.year <0 || a.qt<=0 || a.exp.date <1 || a.exp.month < 1 ||
     a.man.date <1 || a.man.month < 1 ){

    printf("*****************************************************\n");
    printf("                INAPROPIATE ADD OF PRODUCT\n");
    printf("                   PLEASE TRY AGAIN\n");
    printf("*****************************************************\n");
    return;
    }


    f=fopen("product.txt","a");
    if(f == NULL){
        printf("*****************************************************\n");
        printf("          ERROR OPENING FILE!\n");
        printf("*****************************************************\n");
    }

    fprintf(f,"%d %s %d %d %d %d %d %d %d %d\n",a.id,a.pname,a.qt,a.price,a.exp.date,a.exp.month,a.exp.year,a.man.date,a.man.month,
        a.man.year);
    fclose(f);

    printf("*****************************************************\n");
    printf("\n         PRODUCT ADDED SUCCESSFULLY!\n");
    printf("*****************************************************\n");
}

void view(){
    struct Product a;
    FILE *f;

    char choice;

    f=fopen("product.txt","r");

    if(f == NULL){
        printf("*****************************************************\n");
        printf("           NO PRODUCT LIST FOUND!\n");
        printf("*****************************************************\n");
        return;
    }

    while( ( fscanf(f,"%d %s %d %d %d %d %d %d %d %d\n",&a.id,a.pname,&a.qt,&a.price,&a.exp.date,&a.exp.month,&a.exp.year,&a.man.date,
    &a.man.month, &a.man.year) )!= EOF ){
        
        printf("\n=================================\n");

        printf("PRODUCT ID : %d\n", a.id);
        printf("NAME       : %s\n", a.pname);
        printf("QUANTITY   : %d\n", a.qt);
        printf("PRICE      : %d\n", a.price);
        printf("EXPIRY DATE: %d/%d/%d\n", a.exp.date, a.exp.month, a.exp.year);
        printf("MFG DATE   : %d/%d/%d\n",a.man.date, a.man.month, a.man.year);

        printf("=================================\n");

        printf(" DO YOU WANT TO READ NEXT RECORD(Y/y= YES OR N/n= N0): ");
        scanf(" %c",&choice);

        if(choice=='N' || choice =='n'){
            break;
        }
    }
    printf("\n=================================\n");
    printf("           LIST ENDED");
    printf("\n=================================\n");
    fclose(f);
}

void search()
{
   struct Product a;
    FILE *f;

    int num,found=0;

    f=fopen("product.txt","r");

    if(f == NULL){
        printf("NO PRODUCT LIST FOUND!\n");
        return;
    }
    printf("ENTER THE PRODUCT ID: ");
    scanf("%d",&num);

    while( ( fscanf(f,"%d %s %d %d %d %d %d %d %d %d\n",&a.id,a.pname,&a.qt,&a.price,&a.exp.date,&a.exp.month,&a.exp.year,&a.man.date,
    &a.man.month, &a.man.year) )!= EOF ){

        if(a.id==num){
        found=1;
        printf("\n=================================\n");

        printf("PRODUCT ID : %d\n", a.id);
        printf("NAME       : %s\n", a.pname);
        printf("QUANTITY   : %d\n", a.qt);
        printf("PRICE      : %d\n", a.price);
        printf("EXPIRY DATE: %d/%d/%d\n", a.exp.date, a.exp.month, a.exp.year);
        printf("MFG DATE   : %d/%d/%d\n",a.man.date, a.man.month, a.man.year);

        printf("=================================\n");

        }
    }
    fclose(f);
    if(found==0){
        printf("=================================\n");
        printf("        NO ITEM FOUNDED\n");
        printf("=================================\n");
    }
}

void update(){
    struct Product a;
    FILE *f, *temp;

    int pid;
    int found = 0;

    printf("ENTER THE PRODUCT ID TO UPDATE: ");
    scanf("%d", &pid);

    f = fopen("product.txt", "r");
    temp = fopen("temp.txt", "w");

    if(f == NULL){
        printf("*****************************************************\n");
        printf("          NO PRODUCT LIST FOUND!\n");
        printf("*****************************************************\n");
        return;
    }

    while(fscanf(f,"%d %s %d %d %d %d %d %d %d %d",&a.id,a.pname,&a.qt,&a.price,&a.exp.date,&a.exp.month,&a.exp.year,&a.man.date,
        &a.man.month,&a.man.year) != EOF){

        if(a.id == pid){

            printf("\nPRODUCT FOUND!\n");

            printf("ENTER NEW QUANTITY: ");
            scanf("%d",&a.qt);

            printf("ENTER NEW PRICE: ");
            scanf("%d",&a.price);

            if(a.qt<=0 || a.price <=0){

                printf("*****************************************************\n");
                printf("                INAPROPIATE UPDATE\n");
                printf("                 PLEASE TRY AGAIN\n");
                printf("*****************************************************\n");

                fclose(f);
                fclose(temp);
                return;
            }

            found = 1;
        }

        fprintf(temp,"%d %s %d %d %d %d %d %d %d %d\n",a.id,a.pname,a.qt,a.price,a.exp.date,a.exp.month,a.exp.year,a.man.date,
            a.man.month,a.man.year);
    }

    fclose(f);
    fclose(temp);


    if(found){
        printf("\nPRODUCT UPDATED SUCCESSFULLY!\n");
        remove("product.txt");
        rename("temp.txt","product.txt");

    }
    else{
        printf("\nPRODUCT NOT FOUND!\n");
        remove("temp.txt");
    }
}

void del(){
       struct Product a;
    FILE *fp,*temp;

    int pid;
    int found=0;


    printf("ENTER THE PRODUCT ID: ");
    scanf("%d",&pid);

    fp=fopen("product.txt","r");
    temp = fopen("temp.txt", "w");

    if(fp == NULL){
        printf("*****************************************************\n");
        printf("             NO PRODUCT LIST FOUND!\n");
        printf("*****************************************************\n");
        return;
    }

    while( ( fscanf(fp,"%d %s %d %d %d %d %d %d %d %d\n",&a.id,a.pname,&a.qt,&a.price,&a.exp.date,&a.exp.month,&a.exp.year,&a.man.date,
    &a.man.month, &a.man.year) )!= EOF ){

            if(a.id==pid){
                found =1;
                continue;
            }
            fprintf(temp,"%d %s %d %d %d %d %d %d %d %d\n",a.id,a.pname,a.qt,a.price,a.exp.date,a.exp.month,a.exp.year,a.man.date,
            a.man.month,a.man.year);
        
        }
        
    fclose(fp);
    fclose(temp);

    remove("product.txt");
    rename("temp.txt", "product.txt");

    if(found){
        printf("*****************************************************\n");
        printf("          PRODUCT DELETED SUCCESSFULLY!\n");
        printf("*****************************************************\n");
    }
    else{
        printf("*****************************************************\n");
        printf("           NO PRODUCT FOUND!\n");
        printf("*****************************************************\n");
    } 
}


void low_stock(){
    struct Product a;
    FILE *f;

    int num,found=0;

    f=fopen("product.txt","r");

    if(f == NULL){
        printf("*****************************************************\n");
        printf("          NO PRODUCT LIST FOUND!\n");
        printf("*****************************************************\n");
        return;
    }
    printf("ENTER THE NUMBER FOR THE LOW STOCK: ");
    scanf("%d",&num);
    if(num<0){
        printf("*****************************************************\n");
        printf("         LOW STOCK NUMBER IS NEGATIVE\n");  
        printf("*****************************************************\n");
        fclose(f);
        return;
    }

    while( ( fscanf(f,"%d %s %d %d %d %d %d %d %d %d\n",&a.id,a.pname,&a.qt,&a.price,&a.exp.date,&a.exp.month,&a.exp.year,&a.man.date,
    &a.man.month, &a.man.year) )!= EOF ){

        if(a.qt<=num){
            found=1;
        printf("\n=================================\n");

        printf("PRODUCT ID : %d\n", a.id);
        printf("NAME       : %s\n", a.pname);
        printf("QUANTITY   : %d\n", a.qt);
        printf("PRICE      : %d\n", a.price);
        printf("EXPIRY DATE: %d/%d/%d\n", a.exp.date, a.exp.month, a.exp.year);
        printf("MFG DATE   : %d/%d/%d\n",a.man.date, a.man.month, a.man.year);

        printf("=================================\n");

        }
    }

    if(found==0){
        printf("=================================\n");
        printf("        NO ITEM FOUNDED\n");
        printf("=================================\n");
    }

    printf("\n=================================\n");
    printf("           LIST ENDED");
    printf("\n=================================\n");
    fclose(f);
}

void logout(){
    foundi=0;
}


void expiry(){
    struct Product a;
    FILE *f;

    int cdate, cmonth, cyear;
    int found = 0;

    printf("ENTER TODAY'S DATE (DD MM YYYY): ");
    scanf("%d %d %d",&cdate,&cmonth,&cyear);

    f = fopen("product.txt","r");

    if(f == NULL){

        printf("*****************************************************\n");
        printf("         NO PRODUCT LIST FOUND!\n");
        printf("*****************************************************\n");
        return;
    }

    while(fscanf(f,"%d %s %d %d %d %d %d %d %d %d", &a.id,a.pname,&a.qt,&a.price, &a.exp.date,&a.exp.month,&a.exp.year,
        &a.man.date,&a.man.month,&a.man.year) != EOF){

        if(a.exp.year < cyear || (a.exp.year == cyear && a.exp.month < cmonth) || 
        (a.exp.year == cyear && a.exp.month == cmonth && a.exp.date < cdate)) {

            found = 1;

            printf("\n=================================\n");

            printf("PRODUCT ID : %d\n", a.id);
            printf("NAME       : %s\n", a.pname);
            printf("QUANTITY   : %d\n", a.qt);
            printf("PRICE      : %d\n", a.price);

            printf("EXPIRY DATE: %d/%d/%d\n",a.exp.date,a.exp.month,a.exp.year);

            printf("=================================\n");
        }
    }

    if(found == 0){

        printf("=================================\n");
        printf("\nNO EXPIRED PRODUCTS FOUND!\n");
        printf("=================================\n");

    }
    fclose(f);
}

void generate(){
    struct Product a;
    FILE *f;

    int total_products = 0;
    int total_quantity = 0;
    int total_value = 0;

    int low_stock_count = 0;
    int expired_count = 0;

    int cdate, cmonth, cyear;

    printf("ENTER TODAY'S DATE (DD MM YYYY): ");
    scanf("%d %d %d",&cdate,&cmonth,&cyear);

    f = fopen("product.txt","r");

    if(f == NULL){
        printf("*****************************************************\n");
        printf("          NO PRODUCT LIST FOUND!\n");
        printf("*****************************************************\n");
        return;
    }

    while(fscanf(f,"%d %s %d %d %d %d %d %d %d %d",&a.id,a.pname,&a.qt,&a.price,&a.exp.date,&a.exp.month,&a.exp.year,
        &a.man.date,&a.man.month,&a.man.year) != EOF){

        total_products++;
        total_quantity += a.qt;
        total_value += (a.qt * a.price);

        if(a.qt <= 10){
            low_stock_count++;
        }

        if(a.exp.year < cyear || (a.exp.year == cyear && a.exp.month < cmonth) || (a.exp.year == cyear &&
            a.exp.month == cmonth && a.exp.date < cdate)){
                
            expired_count++;
        }
    }

    fclose(f);

    printf("\n=====================================\n");
    printf("         INVENTORY REPORT\n");
    printf("=====================================\n");

    printf("TOTAL PRODUCTS        : %d\n", total_products);
    printf("TOTAL QUANTITY        : %d\n", total_quantity);
    printf("TOTAL INVENTORY VALUE : %d\n", total_value);
    printf("LOW STOCK PRODUCTS    : %d\n", low_stock_count);
    printf("EXPIRED PRODUCTS      : %d\n", expired_count);

    printf("=====================================\n");
}



