# C++ Foundations - Writing Multifile Programs

Created: January 19, 2023 8:04 AM

### Header Files

- The compiler considers a header declaration a **"promise"** that the definition will be found later in the code, so if the compiler reaches a function that hasn't been defined yet, it can continue on compiling until the definition is found.
- In C++, the header file will have filetype `.h`, and the contents of the header file must be included at the top of the `.cpp` file.
    
    ```cpp
    // The header file with just the function declarations.
    #ifndef HEADER_EXAMPLE_H
    #define HEADER_EXAMPLE_H
    
    void OuterFunction(int);
    void InnerFunction(int);
    
    #endif
    ```
    
    ```cpp
    // The contents of header_example.h are included in 
    // the corresponding .cpp file using quotes:
    #include "header_example.h"
    
    #include <iostream>
    using std::cout;
    
    void OuterFunction(int i) 
    {
        InnerFunction(i);
    }
    
    void InnerFunction(int i) 
    {
        cout << "The value of the integer is: " << i << "\n";
    }
    
    int main() 
    {
        int a = 5;
        OuterFunction(a);
    }
    ```
    
    - The function declarations in the header file don't need variable names, just variable types. You can put names in the declaration, however, and doing this often makes the code easier to read.
    - the **quotes tell the preprocessor to look for the file in the same directory as the current file** - not in the usual set of directories where libraries are typically stored.
    - `#ifndef` checks if the header file has already been included. If its been included already, the conditional will be false & the preprocessor will skip the contents of the file.
    - if `#ifndef` is true, `#define` will define the new header file.
- Another header file exercise
    
    ```cpp
    // This file will be saved as "header_practice.h"
    #ifndef HEADER_PRACTICE_H
    #define HEADER_PRACTICE_H
    
    #include <vector>
    using std::vector;
    
    int IncrementAndComputeVectorSum(vector<int> v);
    void AddOneToEach(vector<int> &v);
    
    #endif
    ```
    
    ```cpp
    #include <iostream>
    #include <vector>
    #include "header_practice.h"
    using std::vector;
    using std::cout;
    
    int IncrementAndComputeVectorSum(vector<int> v) 
    {
        int total = 0;
        AddOneToEach(v);
    
        for (auto i: v) {
            total += i;
        }
        return total;
    }
    
    void AddOneToEach(vector<int> &v) 
    {
        // Note that the function passes a reference to v
        // and the for loop below uses references to 
        // each item in v. This means the actual
        // ints that v holds will be incremented.
        for (auto& i: v) {
            i++;
        }
    }
    
    int main() 
    {
        vector<int> v{1, 2, 3, 4};
        int total = IncrementAndComputeVectorSum(v);
        cout << "The total is: " << total << "\n";
    }
    ```
    

### Using Header Files with Multiple Files

- As long as the header file is included, the corresponding function declarations will be included. When the compiler finds an undefined function, it has already seen the function's declaration. This means the compiler can continue on without error until it finds the definition of the function, regardless of where that definition is.
- Each file is compiled alone and must have all the declarations and libraries necessary to compile, so the necessary libraries must be included. This is another reason why [include guards](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#Rs-guards)
 are important - if multiple headers were included in `main`, each with the same `#include <vector>`
 statement, you wouldn't want the `vector` header pasted multiple times into the code.

```
g++ -std=c++17 ./code/main.cpp ./code/increment_and_sum.cpp ./code/vect_add_one.cpp && ./a.out
```

> When compiling, each of the relevant .cpp files must be included in the compile command. The -std=c++17 specifies that we are using the C++ 17 standard (which happens automatically in the terminal).
> 

### Bjarne on Build Systems

### CMake and Make

- Many larger C++ projects use a build system to manage all the files udirng the build process. The build system allows for large projects to be compiled with a few commands, and build systems are able to do this efficently.
    
    ### Object Files
    
    - Objext files are platform-specifc machine code that will be used to create an executable.
    - The object files are linked together to make a single executable.
    - If you’ve made changes to your code. You can re-compile the file that you’ve changed & link the non-changed object files to create a new executable.
    
    ### CMakeLists.txt
    
    - CMakeList.txt files are simple text configuration files that tell CMake how to build your project.
    - There can be many CMakeList text files, it can be included in each directory of a project.
    - `Make` will be able to keep track of which files have changed and compiled only those that need to be compiled before building.

### References

- On the left hand side of any variable declaration, the `&` operator can be used to declare a reference.

### Pointers

- *A C++ pointer is just a variable that stores the memory address of an object in your program.*
    
    > they essentially keep track of *where* a variable is stored in the computer's memory.
    > 
- Pointers give you better contorl over how your program uses memory.
- For a given variable, the memory address can be accessed using an **ampersand** in front of the variable.
    
    ```cpp
    #include <iostream>
    using std::cout;
    
    int main() {
        int i = 5;
        int j = 6;
        
        // Print the memory addresses of i and j
        cout << "The address of i is: " << &i << "\n";
        cout << "The address of j is: " << &j << "\n";
    }
    ```
    

> **The symbols `&` and `*` have a different meaning, depending on which side of an equation they appear.**
> 
- If **&** appears on the left side of the equation, it means that the variable is **declared as a reference**.
- If & appears to the right side of an equation, or before an already defined variable, it is used ********************to return a memory address.********************
- A pointer can be declared by the * operator in the declaration.
    
    ```cpp
    #include <iostream>
    using std::cout;
    
    int main() 
    {
        int i = 5;
        // A pointer pointer_to_i is declared and initialized to the address of i.
        int* pointer_to_i = &i;
        
        // Print the memory addresses of i and j
        cout << "The address of i is:          " << &i << "\n";
        cout << "The variable pointer_to_i is: " << pointer_to_i << "\n";
    }
    ```
    
- To retrieve the object it is pointing to, the * can be used but it will appear at the **right hand side of an equation or infront of an already defined variable.**
    
    ```cpp
    #include <iostream>
    using std::cout;
    
    int main() 
    {
        int i = 5;
        // A pointer pointer_to_i is declared and initialized to the address of i.
        int* pointer_to_i = &i;
        
        // Print the memory addresses of i and j
        cout << "The address of i is:          " << &i << "\n";
        cout << "The variable pointer_to_i is: " << pointer_to_i << "\n";
        cout << "The value of the variable pointed to by pointer_to_i is: " << *pointer_to_i << "\n";
    }
    ```
    

### Pointers Continued

```cpp
#include <iostream>
#include <vector>
using std::cout;
using std::vector;

int main() {
    // Vector v is declared and initialized to {1, 2, 3}
    vector<int> v {1, 2, 3};
    
    // Declare and initialize a pointer to the address of v here:
    vector<int> *pointer_to_v = &v;

    // The following loops over each int a in the vector v and prints.
    // Note that this uses a "range-based" for loop: https://www.geeksforgeeks.org/range-based-loop-c/
    for (int a: v) {
        cout << a << "\n";
    }
    
    // Dereference your pointer to v and print the int at index 0 here (note: you should print 1):
    cout << "The first element of v is: " << (*pointer_to_v)[0] << "\n";
}
```

- If the pointer is pointing to a large object, it can be **much more efficient to pass the pointer** to a function than to pass a copy of the object as with pass-by-value.
    
    ```cpp
    #include <iostream>
    using std::cout;
    
    void AddOne(int* j)
    {
        // Dereference the pointer and increment the int being pointed to.
        (*j)++;
    }
    
    int main() 
    {
        int i = 1;
        cout << "The value of i is: " << i << "\n";
        
        // Declare a pointer to i:
        int* pi = &i;
        AddOne(pi);
        cout << "The value of i is now: " << i << "\n";
    }
    ```
    

### Bjarne on Pointers

> Fundamentally, a pointer is a machine address with a type. So is a reference.
> 

### References vs Pointers

| References | Pointers |
| --- | --- |
| References must be initialized when thy are declared. This means that a reference will always point to data that was intentionally assigned to it. | Pointers can be declared without being initialized, which is dangerous. If this happens mistakenly, the pointer could be pointing to an arbitrary address in memory, and the data associated with that address could be meaningless, leading to undefined behaviour and difficult-to-resolve bugs. |
| References can not be null. This means that a reference should point to meaningful data in the program. | Pointers can be null. In fact, if a poiner is not initialized immediately, it is often best practice to initialize to nullptr, a special type which indicates that the pointer is null. |
| When used in a function for pass-by-reference, the reference can be used jsut as a variable of the same type would be. | When used in a function for pass-by-reference, a pointer must be dereferenced in order to access the underlying object. |

> As a rule of thumb, references should be used in place of pointers when possible.
> 
- There are situations where this not possible.
    - Object Initialization
        - If you want one object to store a reference to another object. However, if one of the objects hasn’t been declared yet, it will need to be initalized as a null pointer because references CANNOT be null.

### Bjarne on References

### Maps

- Container data structures are fantastic for storing ordered data.
- Classes are useful for grouping related data and functions together.
- Maps are useful for storing associated data.
    - A map is a data structure that uses *********key/value********* pairs to store data. It provides efficient lookup and insertion of the data.

- To create an unordered_map in C++, you must include <unordered_map> header, and the syntax for declaring an unordered_map is as follows:

```cpp
unordered_map <key_type, value_type> variable_name;
```

- Methods used in the example:
    - `.find()` method that will check if a key is in the unordered_map
        - if key doesn’t exist then we return an `unordered_map::end()`
        - if the key does exist, the method will return a C++ iterator, which is a pointer that points to the beginning of the iterable key-value pair.
        
        ```cpp
        #include <iostream>
        #include <vector>
        #include <unordered_map>
        #include <string>
        using std::vector;
        using std::cout;
        using std::unordered_map;
        using std::string;
        
        int main() {
            // Create strings to use in the hash table.
            string key = "word";
            string def_1 = "a unit of language, consisting of one or more spoken sounds or their written representation, that functions as a principal carrier of meaning";
            string def_2 = "speech or talk: to express one's emotion in words";
            string def_3 = "a short talk or conversation: 'Marston, I'd like a word with you.'";
            string def_4 = "an expression or utterance: a word of warning";
            unordered_map <string, vector<string>> my_dictionary;
        
            // Check if key is in the hash table.
            if (my_dictionary.find(key) == my_dictionary.end()) {
                cout << "The key 'word' is not in the dictionary." << "\n";
                cout << "Inserting a key-value pair into the dictionary." << "\n\n";
                // Set the value for the key.
                my_dictionary[key] = vector<string> {def_1, def_2, def_3, def_4};
            }
        
            // The key should now be in the hash table. You can access the
            // value corresponding to the key with square brackets [].
            // Here, the value my_dictionary[key] is a vector of strings.
            // We iterate over the vector and print the strings.
            cout << key << ": \n";
            auto definitions = my_dictionary[key];
            for (string definition : definitions) {
                cout << definition << "\n";
            }
        }
        ```
        

### Classes and Object-Oriented Programming

- OOP is a style of coding that collects related **data** (object attributes) and **functions** (object methods) together to form a single data structure, called an **object**.

```cpp
#include <iostream>
#include <string>
using std::string;
using std::cout;

class Car {
  public:
    void PrintCarData() 
    {
        cout << "The distance that the " << color << " car " << number << " has traveled is: " << distance << "\n";
    }

    void IncrementDistance() 
    {
        distance++;
    }
    
    // Adding a constructor here:
    Car(string c, int n) 
    {
        // Setting the class attributes with
        // The values passed into the constructor.
        color = c;
        number = n;
    }
    
    string color;
    int distance = 0;
    int number;
};

int main() 
{
    // Create class instances for each car.
    Car car_1 = Car("green", 1);
    Car car_2 = Car("red", 2);
    Car car_3 = Car("blue", 3);

    // Increment car_1's position by 1.
    car_1.IncrementDistance();

    // Print out the position and color of each car.
    car_1.PrintCarData();
    car_2.PrintCarData();
    car_3.PrintCarData();
}
```

- It is also possible for a class to use methods and attributes from another class using **********************************class inheritance.**********************************
    
    ```cpp
    class Sedan : public Car {
        // Sedan class declarations/definitions here.
    };
    ```
    

### Classes and OOP Continued

- If you are building a larger program, it is better to put your class definition and function declarations into a separate file.
- There are two things to note in the code below.
    - the ******scope resolution operator `::`* must be used to indicate which class the method belongs to.
        - for example: `void Car::PrintCarData()`
        - this avoids any compiler issues if there are two classes with methods that have the same name
    - constructor now uses an initializer list:
        - `Car(string c, int n) : color(c), number(n) {}`
        - The members are initialized before the body of the constructor.
        - It is a quick way to initialize many class attributes in the constructor.
        - If the class attribute is a reference, it must be initialized using an initializer list.
    - variables that don’t need to be visible outside of the class are set as `private`.
    
    ```cpp
    /* car.h */
    #ifndef CAR_H
    #define CAR_H
    
    #include <string>
    using std::string;
    using std::cout;
    
    class Car {
      public:
        void PrintCarData();
        void IncrementDistance();
        
        // Using a constructor list in the constructor:
        Car(string c, int n) : color(c), number(n) {}
      
      // The variables do not need to be accessed outside of
      // functions from this class, so we can set them to private.
      private:
        string color;
        int distance = 0;
        int number;
    };
    
    #endif
    
    ```
    
    ```cpp
    /* car.cpp */
    #include <iostream>
    #include "car.h"
    
    // Method definitions for the Car class.
    void Car::PrintCarData() 
    {
        cout << "The distance that the " << color << " car " << number << " has traveled is: " << distance << "\n";
    }
    
    void Car::IncrementDistance() 
    {
        distance++;
    }
    ```
    
    ```cpp
    /* car_main.cpp */
    #include <iostream>
    #include <string>
    #include "car.h"
    using std::string;
    using std::cout;
    
    int main() 
    {
        // Create class instances for each car.
        Car car_1 = Car("green", 1);
        Car car_2 = Car("red", 2);
        Car car_3 = Car("blue", 3);
    
        // Increment car_1's position by 1.
        car_1.IncrementDistance();
    
        // Print out the position and color of each car.
        car_1.PrintCarData();
        car_2.PrintCarData();
        car_3.PrintCarData();
    
    }
    ```
    
- The arrow operator `→` is used to simultaneously:
    - dereference a pointer to an object and
    - access an attribute or method
    
    ```cpp
    // Simultaneously dereference the pointer and 
    // access IncrementDistance().
    cp->IncrementDistance();
    
    // Dereference the pointer using *, then 
    // access IncrementDistance() with traditional 
    // dot notation.
    (*cp).IncrementDistance();
    ```
    
- The `new` operator allocates memory on the ‘heap’ for a new Car. In general, this memory must be manually managed (deallocated).

### This Pointer

- Using the `this` pointer, which points to the currrent class instance. Using `this` can sometimes be helpful to add clarity to more complicated code:
    
    ```cpp
    // The Car class
    class Car {
      public:
        // Method to print data.
        void PrintCarData() {
            cout << "The distance that the " << this->color << " car " << this->number << " has traveled is: " << this->distance << "\n";
        }
    
        // Method to increment the distance travelled.
        void IncrementDistance() {
            this->distance++;
        }
    
        // Class/object attributes
        string color;
        int distance = 0;
        int number;
    };
    ```
