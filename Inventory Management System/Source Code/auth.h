#ifndef AUTH_H
#define AUTH_H


struct User{
        char username[20];
        char security[20];
        char pass[20];
    };
extern int foundi;
void loginuser();
void regist();
void forgetpass();
void changepassw();
#endif