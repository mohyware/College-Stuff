// لا حول ولا قوة إلا بالله
#pragma once
#ifndef MANGER_H
#define MANGER_H
#include "AVLTree.h"
#include<string>
#include <sstream>
#include <windows.h>
#include<vector>
class Manger
{
private:

public:
    AVLTree *at;
     Manger();
     ~Manger();

    void addUser();

    void removeUser();
    
    void updateUser();

    void searchUser();
  
    void printAllUser();

    void checkVlidUser(std::string& ,  int& , std::string , std::string);

    void Handle_users();

    bool IsValidChoice(std::string num);

    AVLTree* get_reference_tree();
};

#endif // MANGER_H

