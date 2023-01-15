# C++ Implementation of Algorithms and Data Structures

This repo is collect my C++ implementation of algorithms and data structures. Further, the codes implemented here shall follow (Google C++ Style Guide)[https://google.github.io/styleguide/cppguide.html].

Why algorithms and data structures? Because both are important for us who want to work on machine learning research and engineering. More importantly, it is a lot of fun. :-)

## How to Compile C++ Codes?
- Install `g++` on Macbook: just type `g++` in Terminal and then execute it. If it does not work, intall Xcode toolkit:
  ```bash
  # Install Xcode toolkit.
  xcode-select --install

  # If it does not work, force to reset.
  sudo xcode-select --reset
  ```
- Write your C++ scripts and save it to the file `<file>.cc` in file extension `.cc`.
- Compile the file by running the following scripts; this step will produce an executable output file `<file>.out`.
  ```bash
  # Compile code in C++17 and recommend to turn on warning.
  g++ -std=c++17 -W <file>.cc -o <file>.out
  ```
- Finally, execute the output file.
  ```bash
  ./<file>.out
  ```
