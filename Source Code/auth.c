#include<stdio.h>
#include<string.h>
#include "auth.h"
#include"mainmenu.h"

void regist(){
    FILE *fp,*temp;
    struct User a,temps;

    getchar();  

    printf("ENTER THE USERNAME: ");
    fgets(a.username, sizeof(a.username), stdin);

    printf("WHAT IS YOUR FAVOURITE COLOUR: ");
    fgets(a.security, sizeof(a.security), stdin);

    printf("ENTER THE PASSWORD: ");
    fgets(a.pass, sizeof(a.pass), stdin);

    // WE ARE DOING THIS TO REMOVE NEWLINE
    a.username[strcspn(a.username, "\n")] = '\0';
    a.security[strcspn(a.security, "\n")] = '\0';
    a.pass[strcspn(a.pass, "\n")] = '\0';

    if(strcmp(a.username,"")==0 || strcmp(a.security,"")==0 || strcmp(a.pass,"")==0 ){
    printf("*****************************************************\n");
    printf("                INAPROPIATE REGISTER\n");
    printf("                 PLEASE TRY AGAIN\n");
    printf("*****************************************************\n");
    return;
    }

    temp=fopen("users.txt","r");
    if(temp!= NULL){
        while((fscanf(temp,"%s %s %s",temps.username,temps.security,temps.pass))!=EOF){
            if(strcmp(a.username,temps.username)==0){
                printf("*****************************************************\n");
                printf("            USERNAME ALREADY EXISTS\n");
                printf("*****************************************************\n");
                fclose(temp);
                return;
            }
        }
        fclose(temp);
    }


    fp=fopen("users.txt", "a");
    if(fp == NULL){
        printf("*****************************************************\n");
        printf("          ERROR OPENING FILE!\n");
        printf("*****************************************************\n");
        return;
    }
    fprintf(fp, "%s %s %s\n", a.username, a.security, a.pass);
    fclose(fp);

    printf("*****************************************************\n");
    printf("          REGISTRATION SUCCESSFUL!\n");
    printf("*****************************************************\n");
}


int foundi=0;
void loginuser(){
    getchar();
    struct User a;
    FILE *fp;
    char name[20],passw[20];
    

    printf("ENTER THE USERNAME: ");
    fgets(name, sizeof(name), stdin);

    printf("ENTER THE PASSWORD: ");
    fgets(passw, sizeof(passw), stdin);

    // SAME AS REGISTER
    name[strcspn(name, "\n")] = '\0';
    passw[strcspn(passw, "\n")] = '\0';
    
    fp=fopen("users.txt","r");

    if(fp == NULL){
        printf("NO REGISTERED USERS FOUND!\n");
        return;
    }

    while((fscanf(fp,"%s %s %s",a.username,a.security,a.pass))!=EOF){

        if(strcmp(name,a.username)==0 && strcmp(passw,a.pass)==0){
            foundi=1;
            break;
        }else{
            foundi=0;
        }
    }
    fclose(fp);

    if(foundi==1){

    printf("*****************************************************\n");
    printf("                LOGIN SUCCESSFULL\n");
    printf("             WELCOME TO THE INVENTORY\n");
    printf("*****************************************************\n");

   printf("*****************************************************\n"); mainmenu();
    }else{
    printf("*****************************************************\n");
    printf("               INVALID LOGIN\n ");
    printf("*****************************************************\n");
    }
}


void changepassw(){ // USED CHAT GPT
    struct User a;
    FILE *fp,*temp;

    getchar();
    char name[20],passw[20],secur[20],newpass[20];
    int found=0;

    printf("ENTER THE USERNAME:");
    fgets(name, sizeof(name), stdin);

    printf("ENTER THE CURRENT PASSWORD: ");
    fgets(passw, sizeof(passw), stdin);

    printf("ENTER THE SECURITY ANSWER: ");
    fgets(secur, sizeof(secur), stdin);

    name[strcspn(name, "\n")] = '\0';
    passw[strcspn(passw, "\n")] = '\0';
    secur[strcspn(secur, "\n")] = '\0';

    fp=fopen("users.txt","r");
    temp = fopen("temp.txt", "w");

    if(fp == NULL){
        printf("*****************************************************\n");
        printf("          NO REGISTERED USERS FOUND!\n");
        printf("*****************************************************\n");
        return;
    }

    while((fscanf(fp,"%s %s %s",a.username,a.security,a.pass))!=EOF){

        if(strcmp(name,a.username)==0 && strcmp(passw,a.pass)==0 && strcmp(a.security,secur)==0){
            printf("ENTER THE NEW PASSWORD: ");
            fgets(newpass, sizeof(newpass), stdin);
            newpass[strcspn(newpass, "\n")] = '\0';

            if(strlen(newpass)==0 ){    
                    printf("*****************************************************\n");
                    printf("                INAPROPIATE PASSWORD\n");
                    printf("                 PLEASE TRY AGAIN\n");
                    printf("*****************************************************\n");
                    fclose(fp);
                    fclose(temp);
                    remove("temp.txt");
                    return;
                }


            strcpy(a.pass,newpass);
            found =1;
        
        }
        fprintf(temp, "%s %s %s\n",a.username,a.security,a.pass);
    }
    fclose(fp);
    fclose(temp);

    remove("users.txt");
    rename("temp.txt", "users.txt");

    if(found){
        printf("*****************************************************\n");
        printf("      PASSWORD CHANGED SUCCESSFULLY!\n");
        printf("*****************************************************\n");
    }
    else{
        printf("*****************************************************\n");
        printf("               NO USER FOUND!\n");
        printf("*****************************************************\n");
    }
}

void forgetpass(){
    struct User a;
    FILE *fp,*temp;

    getchar();
    char name[20],passw[20],secur[20],newpass[20];
    int found=0;

    printf("ENTER THE USERNAME:");
    fgets(name, sizeof(name), stdin);

    name[strcspn(name, "\n")] = '\0';

    fp=fopen("users.txt","r");
    temp = fopen("temp.txt", "w");

    if(fp == NULL){
        printf("*****************************************************\n");
        printf("          NO REGISTERED USERS FOUND!\n");
        printf("*****************************************************\n");
        return;
    }

    while((fscanf(fp,"%s %s %s",a.username,a.security,a.pass))!=EOF){

        if(strcmp(name,a.username)==0){
            printf("ENTER THE SECURITY ANSWER: ");
            fgets(secur, sizeof(secur), stdin);
            
            secur[strcspn(secur, "\n")] = '\0';

            if(strcmp(secur,a.security)==0){
                printf("ENTER THE NEW PASSWORD: ");
                fgets(newpass, sizeof(newpass), stdin);

                newpass[strcspn(newpass, "\n")] = '\0';

                if(strlen(newpass)==0 ){    
                    printf("*****************************************************\n");
                    printf("                INAPROPIATE PASSWORD\n");
                    printf("                 PLEASE TRY AGAIN\n");
                    printf("*****************************************************\n");
                    fclose(fp);
                    fclose(temp);
                    remove("temp.txt");
                    return;
                }

                strcpy(a.pass, newpass);

                found=1;
            }
        
        }
        fprintf(temp, "%s %s %s\n",a.username,a.security,a.pass);
    }
    fclose(fp);
    fclose(temp);

    remove("users.txt");
    rename("temp.txt", "users.txt");

    if(found){
        printf("*****************************************************\n");
        printf("        PASSWORD CHANGED SUCCESSFULLY!\n");
        printf("*****************************************************\n");
    }
    else{
        printf("*****************************************************\n");
        printf("               NO USER FOUND!\n");
        printf("*****************************************************\n");
    }
}