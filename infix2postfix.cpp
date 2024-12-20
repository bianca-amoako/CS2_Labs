//Project 2 Bianca Amoako

#include <iostream>

const int maxStackSize = 10;

template<class T>
struct Node {
    T data;
    Node<T>* next;
};

template<class T>
class Stack {
public:
   
    Stack() {
        this->topPtr = nullptr;
        this->size = 0;
    }

    ~Stack() {
        while (!this->isEmpty()) {
            this->pop();
        }
    }

    Stack(const Stack& org) {
        Node<T>* tmp = org.topPtr;
        this->topPtr = nullptr;
        this->size = 0;
        Stack tmpStack;
       
        while (tmp != nullptr) {
            tmpStack.push(tmp->data);
            tmp = tmp->next;
        }
       
        while (tmpStack.topPtr != nullptr) {
            this->push(tmpStack.top());
            tmpStack.pop();
        }
    }

    Stack<T>& operator=(const Stack& rhs) {
        if (this != &rhs) {
            Node<T>* tmp = rhs.topPtr;
            while (this->topPtr != nullptr) {
                this->pop();
            }
           
            Stack tmpStack;
            while (tmp != nullptr) {
                tmpStack.push(tmp->data);
                tmp = tmp->next;
            }
           
            while (tmpStack.topPtr != nullptr) {
                this->push(tmpStack.top());
                tmpStack.pop();
            }

        }
        return *this;
    }


    void push(T value) {
        if (!this->isFull()) {
            Node<T>* tmp = this->topPtr;
            this->topPtr = new Node<T>;
            this->topPtr->data = value;
            this->topPtr->next = tmp;
            ++(this->size);
        } else
            exit(1);
    }

    void pop() {
        if (!this->isEmpty()) {
            Node<T>* tmp = this->topPtr->next;
            delete this->topPtr;
            this->topPtr = tmp;
            --(this->size);
        } else
            exit(1);
       
    }

    T top() const {
        if (!this->isEmpty())
            return this->topPtr->data;
        else
            exit(1);
    }


    bool isEmpty() const {
        bool empty = false;
        if (this->topPtr == nullptr)
            return true;
        return empty;
    }


    bool isFull() const {
        bool full = false;
        if (this->size == maxStackSize)
            full = true;
        return full;
    }

    void swap(Stack<T>& lhs, Stack<T>& rhs) {
        Stack tmp = lhs;
        lhs = rhs;
        rhs = tmp;
    }

   
private:
    Node<T>* topPtr;
    int size;
};




int main() {
   
   
    //get input and remove spaces for convenience
    std::cout << "Enter an Infix Expression: ";
    Stack<char> exp;
    char tmp[maxStackSize];
    int count = 0;
    char ch;
    std::cin.get(ch);
    while (ch != '\n') {
        if (ch != ' ') {
            tmp[count] = ch;
            count++;
        }
        std::cin.get(ch);
    }
   
   
    //check to see if expression is valid before attempting to convert
    int leftCount = 0, rightCount = 0;
    char previousChar = 'X';
    for (int i = 0; i < count; i++) {
        if (i > 0) {
            previousChar = tmp[i - 1];
        }
       
        if (!(tmp[i] >= '1' && tmp[i] <= '9') && !(tmp[i] == '*' || tmp[i] == '%' || tmp[i] == '/' || tmp[i] == '+' || tmp[i] == '-' || tmp[i] == '(' || tmp[i] == ')') &&(tmp[i] >= 'a' && tmp[i] <= 'z')) {
            std::cout << "ERROR INVALID EXPRESSION\n";
            exit(1);
        }
       
        if (tmp[i] == '(') {
            leftCount++;
        }
        else if (tmp[i] == ')') {
            rightCount++;
        }
       
        if (tmp[i] == '*' || tmp[i] == '%' || tmp[i] == '/' || tmp[i] == '+' || tmp[i] == '-') {
            if (previousChar == '*' || previousChar == '%' || previousChar == '/' || previousChar == '+' || previousChar == '-') {
                std::cout << "ERROR INVALID EXPRESSION\n";
                exit(1);
            }
            else if (i == count - 1) {
                std::cout << "ERROR INVALID EXPRESSION\n";
                exit(1);
            }
        }
       
       
        if (tmp[i] >= '1' && tmp[i] <= '9') {
            if (previousChar >= '1' && previousChar <= '9') {
                std::cout << "ERROR INVALID EXPRESSION\n";
                exit(1);
            }
            else if (previousChar == ')') {
                std::cout << "ERROR INVALID EXPRESSION\n";
                exit(1);
            }
        }
       
       
    }
    if (rightCount != leftCount) {
        std::cout << "ERROR INVALID EXPRESSION\n";
        exit(1);
    }
   
   
    //convert from infix to postfix
    for (int i = 0; i < count; i++) {

        if (tmp[i] >= '1' && tmp[i] <= '9') {
            std::cout << tmp[i] << ' ';
        }
       
        else if (tmp[i] == '(') {
            exp.push(tmp[i]);
        }
       
        else if (tmp[i] == '*' || tmp[i] == '%' || tmp[i] == '/') {
            while ((!exp.isEmpty()) && (exp.top() == '*' || exp.top() == '%' || exp.top() == '/')) {
                std::cout << exp.top() << ' ';
                exp.pop();
            }
            exp.push(tmp[i]);
        }
           
       
        else if (tmp[i] == '+' || tmp[i] == '-') {
            while ((!exp.isEmpty()) && (exp.top() == '*' || exp.top() == '%' || exp.top() == '/' || exp.top() == '+' || exp.top() == '-')) {
                std::cout << exp.top() << ' ';
                exp.pop();
            }
            exp.push(tmp[i]);
        }
       
        else if (tmp[i] == ')') {
            while (exp.top() != '(') {
                std::cout << exp.top() << ' ';
                exp.pop();
            }
            exp.pop();
        }
       
    }
   
    while (!exp.isEmpty()) {
        std::cout << exp.top() << ' ';
        exp.pop();
    }
   
    std::cout << std::endl;
   
}
