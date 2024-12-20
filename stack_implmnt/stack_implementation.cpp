
//  stack_implementation.cpp
//  Project_2
//  Created by Bianca Amoako on 7/27/23.

#include "stack_implementation.hpp"
#include <iostream>

int main(){
    Stack<int> s;
    bool flag = true;
    while (flag == true){
        std::cout << "1. Push   2. Pop    3. Print    4. Swap   5.Quit" << std::endl;
    int choice;
    std::cin >> choice;
    switch (choice) {
        case(1):
            std::cout << "Enter a number to push in Stack? ";
            int n;
            std::cin >> n;
            s.push(n);
            break;
        case(2):
            s.pop();
            break;
        case(3):
            s.print();
            std::cout << std::endl;
            break;
        case(4):
            int x, y;
            std::cout << "Enter two numbers to swap ";
            std::cin >> x >> y;
            s.swap(x, y);
            std::cout << "Numbers swapped: ";
            s.print();
        case(5):
            std::cout << "Quitting program........." << std::endl;
            return 1;
        default:
            std::cout << "Invalid choice!!" << std::endl;
            break;
        }
      }
 return 0;
 }
