# Machine Problem 1

## Description

> For submission on Numerical Methods class only

## Initial Setup

Build using VS Code for both Linux and Macos. For Windows, please proceed to mp1-win branch.

## Installation

In Visual Studio Code, you can just go the extensions and install directly from there the C/C++ extensions.

Please follow the instructions here:

###### LINUX OS
https://code.visualstudio.com/docs/cpp/config-linux

###### MACOS
https://code.visualstudio.com/docs/cpp/config-clang-mac

## Running the code

### For User
As a user, you don't need to build or compile. You just run in the terminal. Make sure that the current directory path of your terminal is at mp1/bin

##### LINUX OS

./mp1-linux

##### MACOS

./mp1-macos.out


> Note: It was tested using Linux and MACOS but if there is an error running the files above, please proceed to installation first.


### For developer


#### Linux OS

1. Open the repository in VS Code.
2. Change anything in the code (mp1.cpp) to test then build the code.

    > Press CTRL+SHIFT+B for building the mp1.cpp code. It will create a binary file mp1. This is the same executable file located in mp1/bin - mp1-linux.

3. You can just run ./mp1 in the terminal. 
    > Note that the binary file will be created in the same directory path of your current terminal.
    ```
     ./mp1
    ```

#### MACOS:

1. Open the repository in VS Code.
2. Change anything in the code (mp1.cpp) to test then build the code.

    > Run the command in the terminal:
    ```
        g++ -std=c++11 mp1.cpp
    ```
    
     It will create a obj file a.out. This is the same executable file located in mp1/bin - mp1-macos.out.
    
3. You can just run ./a.out in the terminal. a.out is just a sample name, but eventually it will generate a file with extension of .out after you build the code. 
    > Note that the binary file will be created in the same directory path of your current terminal.
    ```
    ./a.out
    ```
