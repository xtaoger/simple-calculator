#ifndef __CALCULATOR_H
#define __CALCULATOR_H
#include "calculator.h"
#include <iostream>
#include <cassert>
#include <cstdlib>


#define STACK_INIT_SIZE 255;

/*类定义区*/
class Stack_char{
private: 
    char *stack;
    size_t size = 0, top = 0;
public:
    void push(char c);
    char pop();
	char show_the_top();
	char show_the_second_top();
	void free_the_stack();
};

class Stack_int{
private:
	int *stack;
	size_t size = 0;
public:
	size_t top = 0;
	void push(int num);
	int pop();
	void free_the_stack();
};

/*函数声明区*/
void separate(std::string str);
unsigned int priority(const char &c);
int operation(char c);
int calculator_deal();
int calculator(const std::string str);
void TEST();






#endif
