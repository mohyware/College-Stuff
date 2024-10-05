# Social Media Basic Version (with CLI)

This project is a **Command-Line Interface (CLI)** application that allows managing users, browsing users, and showing statistical activity of users. The program is built in **C++** and uses various inline **data structures** to manage these functionalities efficiently.

## Table of Contents
- [Features](#features)
- [Data Structures](#data-structures)
- [How It Works](#how-it-works)
- [Acknowledgements](#acknowledgements)

## Features

1. **User Management**: Add, delete, and modify users from the system.
2. **User Browsing**: View the list of users with simple navigation.
3. **User Activity Statistics**: Display detailed statistics on user activity.
4. **Interactive Menu**: Navigate through the system via an intuitive console-based menu system with keyboard inputs.

## Data Structures

The project uses multiple data structures to efficiently handle its core functionalities:

- **Vectors**: 
  Used to hold a dynamic list of menu options.

- **Maps and Unordered Maps**: 
  For efficient lookup and storage of user-related data.

- **Queues and Stacks**: 
  To manage temporary storage and retrieval during browsing and statistics operations.

- **Pairs and Sets**: 
  For unique collections and paired data storage, enabling quick operations on unique users.

- **Custom Y-Combinator Function Template**:
  This template enables recursion in lambda functions to make certain operations cleaner.

## How It Works

The program begins with an interactive main menu that allows users to choose between managing users, browsing users, checking statistics, or exiting the program.

- The **Main Menu** is navigable via the keyboard arrows (UP and DOWN keys).
- On selecting an option (by pressing Enter), it calls different methods to handle the respective functionality.
  
    - **Manage Users**: Interacts with user data to add, modify, or delete users.
    - **Browse Users**: Lists all users and enables scrolling through them.
    - **Statistics**: Displays statistics on user activity.

## Acknowledgements

**Contributors**: Thanks to [Ammar Yasser](https://github.com/AmarYasser1) and [Mahmoud Wadea](https://github.com) for their valuable contributions.