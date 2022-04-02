/*
Copyright 2022 by Néstor Nahuatlato
<soy_nestor@hotmail.com>

Licensed under GNU General Public License 3.0 or later.
@license GPL-3.0+
*/

#include <iostream>
#include <cctype>
#define t 100

char matrix[t][t], op;
int size, x(0), y(0);

void fill(const int&);
void print();
char decision(const char&);

int main(){
    std::cout<<"Type the matrix size."<<std::endl;
    std::cin>>size;
    
    fill(size);

    do{
        print();
        fflush(stdin); std::cin>>op;
    }while(decision(tolower(op)) != 'z');

    return 0;
}

void fill(const int& size){
    for(int i(0); i < size; i++)
        for(int j(0); j < size; j++)
            matrix[i][j] = '*';

    matrix[x][y] = '0';
}

void print(){
    system("clear");
    std::cout<<"Position X: "<<x<<std::endl;
    std::cout<<"Position Y: "<<y<<std::endl;

    for(int i(0); i < size; i++){
        for(int j(0); j < size; j++)
            std::cout<<matrix[i][j];
        std::cout<<std::endl;
    }
    
    std::cout<<"----------"<<std::endl;
    std::cout<<"w : Up"<<std::endl;
    std::cout<<"a : Left"<<std::endl;
    std::cout<<"s : Down"<<std::endl;
    std::cout<<"d : Right"<<std::endl;
    std::cout<<"z : Exit"<<std::endl;
    std::cout<<"----------"<<std::endl;
}

char decision(const char& op){
    switch (op){
        case 'w':
            matrix[x][y] = '*';
            x -= 1;
            if(x < 0)
                x = size - 1;
            matrix[x][y] = 'O';
        break;
        case 'a':
            matrix[x][y] = '*';
            y -= 1;
            if(y < 0)
                y = size - 1;
            matrix[x][y] = 'O';
        break;
        case 's':
            matrix[x][y] = '*';
            x += 1;
            if(x == size)
                x = 0;
            matrix[x][y] = 'O';
        break;
        case 'd':
            matrix[x][y] = '*';
            y += 1;
            if(y == size)
                y = 0;
            matrix[x][y] = 'O';
        break;
        case 'z': break;
        default: std::cout<<"Wrong option. Try again!"<<std::endl;
    }

    return op;
}