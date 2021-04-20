#pragma once

#include <iostream>

class SomeClass {
public:
   SomeClass() = default;
   SomeClass(int intArg, char charArg, float floatArg) : m_intArg(intArg), m_charArg(charArg), m_floatArg(floatArg) {}

   void output() const {
      std::cout << "SomeClass: " << m_intArg << " " << m_charArg << " " << m_floatArg;
   }

private:
   int m_intArg;
   char m_charArg;
   float m_floatArg;
};
