// BufferOverflow.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
  std::cout << "Buffer Overflow Example" << std::endl;

  //  The user can type more than 20 characters and overflow the buffer, resulting in account_number being replaced -
  //  even though it is a constant and the compiler buffer overflow checks are on.
  //  You need to modify this method to prevent buffer overflow without changing the account_order
  //  variable, and its position in the declaration. It must always be directly before the variable used for input.

  //  Added a constant max buffer size to the beginning of the program that will set the limit of the user_input
  //  array size and the buffer cin size. Using this constant will keep both of them "synchronized" together.
  const int MAX_BUFFER_SIZE = 20;
  const std::string account_number = "CharlieBrown42";
  char user_input[MAX_BUFFER_SIZE]; // Changed the literal to the constant declared from above
  std::cout << "Enter a value: ";
  std::cin.width(MAX_BUFFER_SIZE);  // Added the cin.width with constant size to only read the first 20 characters
  std::cin >> user_input;

  std::cout << "You entered: " << user_input << std::endl;
  std::cout << "Account Number = " << account_number << std::endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
