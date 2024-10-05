# Product Management System in C++

## Overview
This C++ program implements a **Product Management System** using custom data structures like a **Stack**, **Queue**, and **LinkedList**. The system allows users to manage products by adding new products, viewing all products, and removing products. The products are managed using stacks, and these stacks are stored in a linked list that acts as a queue, providing a structured way to manage multiple product entries.

The system provides a simple menu-based interface for interacting with the product catalog.

## Features
The **Product Management System** provides the following functionalities:

### Main Menu:
1. **New Product**: Adds a new product stack to the system. The stack is enqueued in the linked list queue.
2. **Print All Products**: Prints all products in the system, showing the details of each product stack.
3. **Remove a Product**: Removes the first product stack from the linked list queue.
4. **Quit**: Exits the program.

### Input Validation:
The program includes input validation to ensure only numeric input is accepted for menu choices. If the user enters invalid input, an error message is shown, and the user is prompted to try again.

### Timed Operations:
The program incorporates a timed wait functionality, which clears the screen and counts down before displaying the next menu or operation result.