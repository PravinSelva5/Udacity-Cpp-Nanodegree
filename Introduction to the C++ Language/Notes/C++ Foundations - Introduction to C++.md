# C++ Foundations - Introduction to C++

Created: January 6, 2023 6:25 PM

- C++ is used for the foundation parts of anything we do. It lies between the higher level software and the hardware.
- C++ works really well with hardware and it has powerful abstraction mechanisms so that the user doesn’t have to deal with low level stuff all the time.
- **Where is C++ used?**
    - camera, mars rover, telescope, finance industry, networking, games industry (graphics, animations), automotive
- **Best strategy for learning C++?**
    - Get an overview of the language before going deep into it.
- **What should students focus on?**
    - think of the lauguage as a modern one.
    - see how to use the abstraction mechanisms.
    - use the libraries
- **Core Guidelines**
    - [https://github.com/isocpp/CppCoreGuidelines](https://github.com/isocpp/CppCoreGuidelines)

- When running a new C++ program, it is a two step process:
    1. Compile your code with a complier
    2. Run the executable file that the compiler outputs

- In C++, every program contains a `main` function which is executed automatically when the program is run. Every part of a C++ program is run directly or indirectly from `main`, and the most basic program that will compile in C++ is just a `main` function with nothing else.

- **Advantages & Disadvantages of Compiled Languages**
    - To build software that is stable & as close to error-free, the compiler is your best friend!
        - it will check if you followed your own rules and the programming language’s rules
    - With a compiled language, the code is typically cleaner because the programmer needs to make sure it is correct for the compiler to run.
    - For a scripting language, you need to rely on complete testing your program

- **Advantages of Dynamic Language**
    - you can get to run quickly
    - faster iterations with smaller datasets

- `using std::cout;`
    - Namespaces are a way in C++ to group identifiers (names) together. They provide context for identifiers to avoid naming collisions.
    - The `std` namespace is the namespace used for the standard library.
    - The `using` command adds `std::cout` to the global scope of the program.
    - `cout` is an output stream you will use to send output to the notebook or to a terminal.

- The program author must specify the variable type in the declaration in C++.
- In C++, once a variable is declared, it can not be redeclared in the same scope.

- What is a vector?
    - sequence of elements of a single type
        - can use methods to find size, check if its empty, and add elements to the vector.
    
    ```cpp
    #include <iostream>
    #include <vector>
    using std::vector;
    using std::cout;
    
    int main() {
        // Three ways of declaring and initializing vectors.
        vector<int> v_1{0, 1, 2};
        vector<int> v_2 = {3, 4, 5};
        vector<int> v_3;
        v_3 = {6};
        cout << "Everything worked!" << "\n";
    }
    ```
    
    - 2D vectors
        
        ```cpp
        #include <iostream>
        #include <vector>
        using std::vector;
        using std::cout;
        
        int main() {
            // Creating a 2D vector.
            vector<vector<int>> v {{1,2}, {3,4}};
            cout << "Great! A 2D vector has been created." << "\n";
        }
        ```
        

- Comments should explain the WHAT and WHY a code is being written in a higer level.

```cpp
// You can use two forward slashes for single line comments.

/*
For longer comments, you can enclose the text with an opening
slash-star and closing star-slash.
*/
```

- To have the type automatically determined, use the `auto` keyword

```cpp
#include <iostream>
#include <vector>
using std::vector;
using std::cout;

int main() {
    auto i = 5;
    auto v_6 = {1, 2, 3};
    cout << "Variables declared and initialized without explicitly stating type!" << "\n";
}
```

- It is helpful to manually declare the type of a variable if you want the variable type to be clear for reader of your code, or if you want to be explicit about the number precision being used; C++ has several number types with different levels of precision, and this precision might not be clear from the value being assigned.

```cpp
#include <iostream>
#include <vector>
using std::vector;
using std::cout;

int main() {
    // Declare and initialize v using auto here.
    auto v = {7,8,9,10};
    for(auto i : v)
        cout << i << " ";
    cout << "\n";
}
```

- For loops
    
    ```cpp
    #include <iostream>
    using std::cout;
    
    int main() {
        for (int i=0; i < 5; i++) {
          cout << i << "\n";
        }
    }
    ```
    
    - There is also a *pre-increment operator* which is used before a variable, as well as *pre* and *post decrement* operators: `-`. The difference between *pre* and *post* lies in what value is returned by the operator when it is used.
    
    ```cpp
    #include <iostream>
    using std::cout;
    
    int main() {
        auto i = 1;
    
        // Post-increment assigns i to c and then increments i.
        auto c = i++;
    
        cout << "Post-increment example:" << "\n";
        cout << "The value of c is: " << c << "\n";
        cout << "The value of i is: " << i << "\n";
        cout << "\n";
    
        // Reset i to 1.
        i = 1;
    
        // Pre-increment increments i, then assigns to c.
        c = ++i;
    
        cout << "Pre-increment example:" << "\n";
        cout << "The value of c is: " << c << "\n";
        cout << "The value of i is: " << i << "\n";
        cout << "\n";
    
        // Decrement i;
        i--;
        cout << "Decrement example:" << "\n";
        cout << "The value of i is: " << i << "\n";
    }
    ```
    
- For Loop with a Container
    
    ```cpp
    #include <iostream>
    #include <vector>
    using std::cout;
    using std::vector;
    
    int main() {
        // Add your code here.
        vector<int> a {1, 2, 3, 4, 5};
        for (int i: a) {
            cout << i << "\n";
        }
    }
    ```
    
    ```cpp
    #include <iostream>
    #include <vector>
    using std::cout;
    using std::vector;
    
    int main() {
        // Add your code here.
        vector<vector<int>> b {{1, 2},
                               {3, 4},
                               {5, 6}};
    
        // Write your double loop here.
        for (auto v : b){
            for (int i : v){
                cout << i << "\n";
            }
        }
        
    }
    ```
    
- Functions
    - Basic syntax for a function in C++
        
        ```cpp
        return_type FunctionName(parameter_list) {
          // Body of function here.
        }
        ```
        
        ```cpp
        #include <iostream>
        using std::cout;
        
        // Function declared and defined here.
        int AdditionFunction(int i, int j) 
        {
            return i + j;
        }
        
        int main() 
        {
            auto d = 3;
            auto f = 7;
            cout << AdditionFunction(d, f) << "\n";
        }
        ```
        
    - If a function doesn’t need to return a value, the `void` type can be used for the return type.
        
        ```cpp
        #include <iostream>
        #include <string>
        using std::cout;
        using std::string;
        
        // Write the PrintStrings function here.
        void PrintStrings(string a, string b)
        {
            cout << a << " " << b << "\n";
        }
        
        int main() {
            string s1 = "C++ is ";
            string s2 = "super awesome.";
        
            PrintStrings(s1, s2);
        }
        ```
        

- Print Board Challenge
    
    ```cpp
    #include <iostream>
    #include <vector>
    using std::cout;
    using std::vector;
    
    // TODO: Add PrintBoard function here.
    void PrintBoard(vector<vector<int>> board) {
    	for (auto i : board) {
          for (int j : i) {
            cout << j;
          }
          cout << '\n';
    	}
    }
    
    int main() {
      vector<vector<int>> board{{0, 1, 0, 0, 0, 0},
                                {0, 1, 0, 0, 0, 0},
                                {0, 1, 0, 0, 0, 0},
                                {0, 1, 0, 0, 0, 0},
                                {0, 0, 0, 0, 1, 0}};
      // TODO: Call PrintBoard function here.
      PrintBoard(board);
      
    }
    ```
    
    ![Untitled](C++%20Foundations%20-%20Introduction%20to%20C++%20cc77d14865b6416d9803e20e52e62278/Untitled.png)
    

- fstream
    - you can use `std::ifstream` object to handle input file streams.
        
        ```cpp
        #include <fstream>
        #include <iostream>
        #include <string>
        
        int main()
        {
            // new input stream object is declared and initialized.
            std::ifstream my_file;
            my_file.open("files/1.board");
            if (my_file) {
              std::cout << "The file stream has been created!" << "\n";
            }    
        }
        ```
        
- Reading data from the stream
    - Once the input stream has been initialized, you can read using the `getline` method.
        
        ```cpp
        #include <fstream>
        #include <iostream>
        #include <string>
        
        int main() {
            std::ifstream my_file;
            my_file.open("files/1.board");
            if (my_file) {
                std::cout << "The file stream has been created!" << "\n";
                std::string line;
                while (getline(my_file, line)) {
                    std::cout << line << "\n";
                }
            }
        }
        ```
        

### Recap

To recap, there are essentially four steps to reading a file:

1. `#include <fstream>`
2. Create a `std::ifstream` object using the path to your file.
3. Evaluate the `std::ifstream` object as a `bool` to ensure that the stream creation did not fail.
4. Use a `while` loop with `getline` to write file lines to a string.

## Processing Strings

- In C++ strings can be streamed into temporary variables, similarly to how files can be streamed into strings. Streaming a string allows us to work with each character individually.
- One way to stream a string is to use an input string stream object `istringstream` from the `<sstream>` header.
- Once an `istringstream` object has been created, parts of the string can be streamed and stored using the "extraction operator": `>>`. The extraction operator will read until **whitespace is reached or until the stream fails.**

```cpp
#include <iostream>
#include <sstream>
#include <string>

using std::istringstream;
using std::string;
using std::cout;

int main () 
{
    string a("1 2 3");

    istringstream my_stream(a);

    int n;
    my_stream >> n;
    cout << n << "\n";
}

// OUTPUT -> 1
```

- the `istringstream` object can also be used as a boolean if the last extraction operation failed.

```cpp
#include <iostream>
#include <sstream>
#include <string>

using std::istringstream;
using std::string;
using std::cout;

int main() 
{
    string a("1 2 3");

    istringstream my_stream(a);

    int n;
    
    // Testing to see if the stream was successful and printing results.
    while (my_stream) {
        my_stream >> n;
        if (my_stream) {
            cout << "That stream was successful: " << n << "\n";
        }
        else {
            cout << "That stream was NOT successful!" << "\n";            
        }
    }
}

// OUPTUT
/*
That stream was successful: 1
That stream was successful: 2
That stream was successful: 3
That stream was NOT successful!
*/
```

- The extraction operator `>>` writes the stream to the variable on the right of the operator and returns the `istringstream` object, so the entire expression `my_stream >> n` is an `istringstream` object and can be used as a boolean! Because of this, a common way to use `istringstream` is to use the entire extraction expression in a while loop.

### Strings with Mixed Types

- If the string has mixed types, **more care is needed to process the string**. In the following example, the type `char` is used, which is a type that can hold only a single ASCII character.
    
    ```cpp
    #include <iostream>
    #include <sstream>
    #include <string>
    
    using std::istringstream;
    using std::string;
    using std::cout;
    
    int main() 
    {
        string b("1,2,3");
    
        istringstream my_stream(b);
    
        char c;
        int n;
    
        while (my_stream >> n >> c) {
          cout << "That stream was successful:" << n << " " << c << "\n";
        }
        cout << "The stream has failed." << "\n";
    }
    ```
    

### Adding Data to a Vector

- You can store the results of the processing in a `vector` using the `push_back` method.
    
    ```cpp
    #include <vector>
    #include <iostream>
    using std::vector;
    using std::cout;
    
    int main() {
        // Initial Vector
        vector v {1, 2, 3};
        
        // Print the contents of the vector
        for (int i=0; i < v.size(); i++) {
          cout << v[i] << "\n";
        }
        
        // Push 4 to the back of the vector
        v.push_back(4);
    
        // Print the contents again
        for (int i=0; i < v.size(); i++) {
          cout << v[i] << "\n";
        }
        
    }
    ```
    

### Enums

- C++ allows you to define a custom type which has values **limited to a specific range** you list or "enumerate". This custom type is called an "enum".
    
    ```cpp
    #include <iostream>
    using std::cout;
    
    int main() 
    {
        // Create the enum Color with fixed values.
        enum class Color {white, black, blue, red};
    
        // Create a Color variable and set it to Color::blue.
        Color my_color = Color::blue;
    
        // Test to see if my car is red.
        if (my_color == Color::red) {
            cout << "The color of my car is red!" << "\n";
        } else {
            cout << "The color of my car is not red." << "\n";
        }
    }
    ```
    
    ```cpp
    #include <iostream>
    using std::cout;
    
    int main()
    {
        enum class Direction {kUp, kDown, kLeft, kRight};
    
        Direction a = Direction::kUp;
    
        switch (a) {
          case Direction::kUp : cout << "Going up!" << "\n";
            break;
          case Direction::kDown : cout << "Going down!" << "\n";
            break;
          case Direction::kLeft : cout << "Going left!" << "\n";
            break;
          case Direction::kRight : cout << "Going right!" << "\n";
            break;
        }
    }
    ```
    
- Store the Board Using the State Enum Challenge
    
    ```cpp
    #include <fstream>
    #include <iostream>
    #include <sstream>
    #include <string>
    #include <vector>
    using std::cout;
    using std::ifstream;
    using std::istringstream;
    using std::string;
    using std::vector;
    
    enum class State {kEmpty, kObstacle};
    
    auto ParseLine(string line) {
        istringstream sline(line);
        int n;
        char c;
        
        vector<State> row;
        while (sline >> n >> c && c == ',') {
          if ( n == 0){
          	row.push_back(State::kEmpty);
          } else {
          	row.push_back(State::kObstacle);
          }
        }
        return row;
    }
    
    vector<vector<State>> ReadBoardFile(string path) {
      ifstream myfile (path);
      vector<vector<State>> board{};
      if (myfile) {
        string line;
        while (getline(myfile, line)) {
          vector<State> row = ParseLine(line);
          board.push_back(row);
        }
      }
      return board;
    }
    
    string CellString(State cell) {
      switch(cell) {
        case State::kObstacle: return "⛰️   ";
        default: return "0   "; 
      }
    }
    
    void PrintBoard(const vector<vector<State>> board) {
      for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
          cout << CellString(board[i][j]);
        }
        cout << "\n";
      }
    }
    
    int main() {
      auto board = ReadBoardFile("1.board");
      PrintBoard(board);
    }
    ```
    
    OUTPUT
    
    ![Untitled](C++%20Foundations%20-%20Introduction%20to%20C++%20cc77d14865b6416d9803e20e52e62278/Untitled%201.png)