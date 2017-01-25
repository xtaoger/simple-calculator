#include "calculator.h"
#include <iostream>
#include <cassert>
#include <cstdlib>

Stack_char S_c_all;/*先将所有符号push进这个栈*/
Stack_int S_i_all;/*先将所有符号push进这个栈*/
Stack_char S_c_deal;/*放置处理过程中的数据*/
Stack_int S_i_deal;/*放置处理过程中的数据*/

/* Stack_char */
void Stack_char::push(char c){
	if(this->top + 1 >= this->size) {
		if(this->size == 0) {
			this->size = STACK_INIT_SIZE;
			this->stack = (char*)malloc(this->size);
		}
		while(this->top + 1 >= this->size)
			this->size += this->size >> 1;
		this->stack = (char*)realloc(this->stack, this->size);	
	}
	this->top += 1;
	stack[top] = c;
	std::cout << "char\t\t\tPUSH\t\t" << c << std::endl;
}
char Stack_char::pop() {
	if(top == 0)
		return 'z';
	assert(this->top >0);
	std::cout << "char\t\t\tPOP\t\t" << stack[top] << std::endl;
	return this->stack[top--];
}
char Stack_char::show_the_top() {
	if(top == 0)
		return 'z';
	return this->stack[top];
}
char Stack_char::show_the_second_top() {
	return this->stack[top-1];
}
/* Stack_chat ^ */

/* Stack_int */
void Stack_int::push(int num){
    if(this->top + 1 >= this->size) {
        if(this->size == 0) {
            this->size = STACK_INIT_SIZE;
            this->stack = (int*)malloc(this->size);
        }
        while(this->top + 1 >= this->size)
            this->size += this->size >> 1;
        this->stack = (int*)realloc(this->stack, this->size);  
    }
    this->top += 1;
    stack[top] = num;
	std::cout << "\t\tPUSH\t\t" << num << std::endl;
}
int Stack_int::pop() {
    assert(this->top >0);
	std::cout << "\t\tPOP\t\t" << stack[top] << std::endl;
    return this->stack[top--];
}
/* Stack_int ^ */

void separate(std::string str) {
	std::string str_num = "";
	for(auto &c : str) {
		if(isdigit(c)) {
			str_num += c;
			if(isdigit(*(&c+1)))
				continue;
			else {
				S_i_all.push(stoi(str_num));
				str_num = "";
			}
		}
		else
			S_c_all.push(c);
	}
}

inline unsigned int priority(const char &c) {
	switch(c) {
		case '=' :
			return 1;
		case '+' :
			return 2;
		case '-' :
			return 3;
		case '*' :
			return 4;
		case '/' :
			return 5;
		case 'z' :
			return 0;
		default :
			std::cerr << "priority error!" << std::endl;
	}
}

inline int operation(char c) {
		std::cout << __func__ << __LINE__ << std::endl;
	switch(c) {
		case '+' :
			return S_i_all.pop() + S_i_deal.pop();
		case '-' :
			return S_i_all.pop() - S_i_deal.pop();
		case '*' :
			return S_i_all.pop() * S_i_deal.pop();
		case '/' :
			return S_i_all.pop() / S_i_deal.pop();
		default :
			std::cerr << "operation error!" << std::endl;
	}
}

int calculator_deal() {
	char c = S_c_all.pop();
	//S_i_deal.push(S_i_all.pop());
	while (1) {/*用break来跳出循环*/
		std::cout << __func__ << __LINE__ << std::endl;
		std::cout << "c:" << c << std::endl;
		std::cout << S_c_deal.show_the_top() << std::endl;
		std::cout << "S_c_all.top\t" << S_c_all.show_the_top() << std::endl;
		if(priority(c) < priority(S_c_deal.show_the_top())) {
			std::cout << __func__ << __LINE__ << std::endl;
			S_c_all.push(c);
			S_c_all.push(S_c_deal.pop());
			S_i_all.push(S_i_deal.pop());
			c = S_c_all.pop();
			continue;
		} else{
			std::cout << __func__ << __LINE__ << std::endl;
			if(priority(c) <= priority(S_c_all.show_the_top())) {
				std::cout << __func__ << __LINE__ << std::endl;
				S_c_deal.push(c);
				S_i_deal.push(S_i_all.pop());
				c = S_c_all.pop();
				std::cout << __func__ << __LINE__ << std::endl;
				continue;
			} else {
				std::cout << __func__ << __LINE__ << std::endl;
				if(c == '=')
					break;
				/*开始处理*/
				std::cout << __func__ << __LINE__ << std::endl;
				S_i_deal.push(operation(c));
				//std::cout << S_i_deal.show_the_top() << std::endl;
				std::cout << __func__ << __LINE__ << std::endl;
			}
		}
		std::cout << __func__ << __LINE__ << std::endl;
		c = S_c_all.pop();
	}
	//S_c_all.pop();
	std::cout << __func__ << __LINE__ << std::endl;
	return S_i_all.pop();
}

int calculator(const std::string str) {
	separate(str);
	return calculator_deal();
}










