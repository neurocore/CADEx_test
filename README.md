# CADEx_test

Test application on junior developer/mathematician position for CAD Ex company

## Features

Compiled with VS 2019, required C++14 

- [x] Steps 1-6 implementation
- [x] Step 7 - curves library
- [x] Step 8 - parallel computation

## Structure

- CADEx_curves - dynamic library that compiles into dll and lib
- CADEx_app - application that uses library and compiles into exe

## Building

Sequentially build both projects of solution. In case of linkage errors make \
sure you have specified correct paths to curves' includes and library and \
repeat compilation again.
