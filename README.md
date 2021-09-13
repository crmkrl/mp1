# Machine Problem 1

## Description

This branch is for Windows User only.

> For submission on Numerical Methods class only

## Installation

In Visual Studio Code, you can just go to the extensions and install directly from there the C/C++ extensions.

Please follow the instructions here: https://code.visualstudio.com/docs/cpp/config-mingw

## Running the code

### For User
As a user, you don't need to build or compile. You just need to run the exe file.

Double click the mp1-win.exe. 

>Note: It was tested using Windows. You can follow the video tutorial in docs/mp1-win-as-user. If errors occur, please install C++ compiler first and try again.

### For developer

1. Install C++ Compiler. On the tutorial, MingW was used. It is located on the link provided in the Installation.

2. Open the repository in VS Code.
3. Add anything in the code (mp1.cpp) if you want then build the code. Build the code in the terminal using this command.

    ```
     mingw32-make.exe
    ```
    > Note: Make sure that you are in the correct directory path. The code will build for a couple of minutes, you just need to wait until the exe file is generated.

4. You can just run by double clicking or run as admin the mp1.exe. This is the same exe file - mp1-win.exe. 
    > Note: The binary file will be created in the same directory path of your current terminal.
