//
//  stack_implementation.hpp
//  Project_2
//
//  Created by Bianca Amoako on 7/27/23.
//

#ifndef stack_implementation_hpp
#define stack_implementation_hpp
#include <iostream>

template <class T>
class node {
public:
  T data;
  node<T>* next; //next pointer
};

template <class T>
class Stack {
private:
  node<T>* top;  //top of stack pointer
public:
  Stack(){
    top = nullptr; //default constructor where top of stack is NULL
  }
    ~Stack(){
    node<T>* temp = top;
    top = top->next;
    delete temp;
}
    Stack(Stack& rhs){ ///UNSURE ABOUT THIS
        rhs->data = top->data;
        rhs->next = top->next;
    }
bool isEmpty() {
    if (top == nullptr)
        return false;
    else
        return true;
}
T Top() {
    if (top)
        return top->data;
    else
        std::cout << "Stack is empty" << std::endl;
}
void push(const T & value) {
    if (top == nullptr) { //if top is null new node, move next pointer, push new data
        top = new node<T>;
        top->next = nullptr;
        top->data = value;
    }
    else {
        node<T>* temp = new node<T>; //make temp pointer with new node
        temp->data = value;  //assign value to temp node data
        temp->next = top;  //assing next pointer to top of stack
        top = temp; //top of stack is temp
    }
}
void pop() {
    if (top == nullptr) {
        std::cout << "Stack is empty" << std::endl;
        return;
    }
    else {
        std::cout << top->data << " is popped" << std::endl;
        node<T>* temp = top; //temp node = top of stack
        top = top->next;  //top of stack is next pointer
        delete temp;  //delete the temp node
    }
}
void print() {
    node<T>* temp = top;
    std::cout << "Stack: ";
    while (temp != nullptr)
    {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
   }
    void swap(int x, int y){
        if (x == y)
            return;
        node<T>* prevX = NULL; //tracking x
        node<T>* currX = top;
        while (currX && currX->data != x){
            prevX = currX;
            currX = currX->next;
        }
        node<T>* prevY = NULL;  //tracking y
        node<T>* currY = top;
        while (currY && currY->data != y){
            prevY = currY;
            currY = currY->next;
        }
        if (currX == NULL ||currY == NULL) //if both are null return
            return;
        if (prevX != NULL)
            prevX->next = currY;
        else
            top = currY;
        if (prevY != NULL)
            prevY->next = currX;
        else
            top = currX;
        node<T>* temp = currY->next;
        currY->next = currX->next;
        currX->next = temp;
    }
    ///NEEDED assignment operator (copy semantics): Makes a copy of the given stack on the right-hand side of the symbol “=”.
};

#endif /* stack_implementation_hpp */
