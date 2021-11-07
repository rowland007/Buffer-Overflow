/************************************************************************
 Program:       Buffer Overflow Activity
 Author:        Randall Rowland (https://github.com/rowland007)
 Class:         CS-405-T2676 Secure Coding 21EW2
 Instructor:    Mr. Trevor Hodde
 Date:          2021-07-09
 Description:   This assignment presents code that collects a number from the user and then displays the number and a secret account number. 
                Entering too many characters triggers the overwrite of the account number 
 Input:         PythonWithExploit.py || PythonWithoutExploit.py
 Output:
 Known bugs:    Fixed overwrite of account_number from user input
 Missing features:
    The source code has been commented with TODOs to explain the detailed rules
 you must follow. There are comments that mark code that must be changed. There
 may be more than one way to solve this problem, so be sure to demonstrate that
 you can detect an underflow or overflow, prevent it, and communicate it back to
 the calling function. Remember to leverage capabilities provided by the
 standard C++ library to help you achieve success.

 License:           GNU General Public License v3.0
 Modifications:
   Date                      Comment
 ---------   ------------------------------------------------
 2021JUL07   Add a const buffer limit and use cin.width to restrict user input
 2021NOV07   Update comments for new course code and instructor [no code change]
 ************************************************************************/

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
