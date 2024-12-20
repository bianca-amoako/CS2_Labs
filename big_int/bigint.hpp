#ifndef bigint_HPP
#define bigint_HPP

#include <iostream>

const int CAPACITY = 400;

class bigint {
public:

  void initialize();

  bigint();
  
  bigint(int);
  
  bigint(const char[]);
  
  void debugPrint(std::ostream&) const;
  
  friend std::ostream& operator<<(std::ostream&, const bigint&);
  
  friend std::istream& operator>>(std::istream&, bigint&);
  
  bool operator==(const bigint&);
  
  bigint operator+(const bigint&) const;
  
  //bigint timesDigit(int) const;
  
 // bigint times10(int) const;
  
  //bigint operator*(bigint) const;
  
  int operator[](int) const;
  
private:
  int numArray[CAPACITY];
};
#endif