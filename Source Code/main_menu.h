#ifndef MAIN_MENU_H
#define MAIN_MENU_H

struct date{
    int year;
    int month;
    int date;
};

struct Product{
    int id;
    char pname[20];
    int qt;
    int price;
    struct date exp,man;
};

void add();
void view();
void search();
void update();
void del();
void expiry();
void low_stock();
void generate();
void logout();

#endif