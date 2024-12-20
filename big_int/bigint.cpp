#include "bigint.hpp"
#include <iostream>
#include <cassert>

void bigint::initialize() {
  for (int i = 0; i < CAPACITY; ++i) {
    numArray[i] = 0;
  }
}

bigint::bigint() {
  initialize();
}

bigint::bigint(int numbers) {
	initialize();
  //int i = 0;
	/*while (numbers > 0) {
		numArray[i] = numbers % 10;
		numbers = numbers / 10;
		i++;
	}*/
	for(int i = 0; numbers > 0; ++i){
		numArray[i] = numbers % 10;
		numbers = numbers / 10;
	}
}

bigint::bigint(const char characters[]) {
  initialize();
	int i = 0;
	int j = 0;
	while (characters[i] != '\0') {
		i++;
	}
	while (i > 0) {
		numArray[j] = characters[--i] - '0';
		j++;
	}
	for(i = 0; characters[i] == '\0'; ++i){
		for( j = 0; characters[i] == '\0'; ++j){
			if(i > 0){
				numArray[j] = characters[--i] - '0';
				j++;
			}
		}
	}
}

void bigint::debugPrint(std::ostream& out) const {
	for (int i = 0; i < CAPACITY; ++i) {
		if (i == 0) {
			out << numArray[i];
		}
		else{
			out << numArray[i] << '|';
		}
	}
}

std::ostream& operator<<(std::ostream& out, const bigint& obj) {
	int i = CAPACITY - 1;
	while ((obj.numArray[i] == 0) && (i >= 0)) {
		i--;
	}
 	if (i < 0) {
 	   i++;
  	}
	for (; i >= 0; i--) {
		if ((i % 80) != 0) {
			out << obj.numArray[i];
		}
		else {
			out << obj.numArray[i] << std::endl;
		}
	}
	return out;
}

std::istream& operator>>(std::istream& in, bigint& obj) {
	char num;
	char temp[CAPACITY];
	/*for (int i = 0; i < CAPACITY; i++) {
		temp[i] = 0;
	}*/
	in >> num;
	for (int j = 0; (j < CAPACITY) && (num != ';'); j++) {
		temp[j] = num;
		in >> num;
	}
	obj = bigint(temp);
	return in;
}

bool bigint::operator==(const bigint& obj) {
	for (int i = 0; i < CAPACITY; i++) {
		if (numArray[i] != obj.numArray[i]) {
			return false;
		}
	}
	return true;
}


bigint bigint::operator+(const bigint& x) const {
	bigint ans;
	int number = 0;
	bool remain = false;
	for (int i = 0; i < CAPACITY; ++i){
		number = 0;
		if(remain){
			remain = false;
			//++number;
		}
		number = numArray[i] + x.numArray[i] + number;
		if(number >= 10){
			remain = true;
			number %= 10;
		}
		ans.numArray[i] = number;
	}
	return ans;
}
/*
bigint bigint::timesDigit(int x) const {
	bigint temp;
	int rem = 0, result = 0;
	for (int i = 0; i < CAPACITY; i++) {
		rem = numArray[i] * x + rem;
		result = rem % 10;
		rem /= 10;
		temp.numArray[i] = result;
	}
	return temp;
}

bigint bigint::times10(int x) const {
	bigint temp;
	for (int i = CAPACITY - 1 - x; i >= 0; i--) {
		temp.numArray[i + x] = numArray[i];
	}
	for (int j = 0; j < x; j++) {
		temp.numArray[j] = 0;
	}
	return temp;
}

bigint bigint::operator*(bigint obj) const{
	bigint product = 0;
	bigint temp;
	for (int i = 0; i < CAPACITY; i++) {
		temp = obj.timesDigit(numArray[i]);
		product = product + temp.times10(i);
	}
	return product;
}
*/
int bigint::operator[](int i) const {
	return numArray[i];
}


