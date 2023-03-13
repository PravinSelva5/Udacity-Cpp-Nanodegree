# Object-Oriented Programming - Intro to OOP

Created: February 21, 2023 5:27 PM

## Classes and OOP

- classes allow you to create **user-defined** types.

## Jupyter Notebooks

- To compile C++17 standard code
    
    ```cpp
    g++ -std=c++17 ./code/filename.cpp
    ```
    
    ```cpp
    ./a.out
    ```
    

## Structures

- Structures allow developers to create their own types (**"user-defined" types**) to aggregate data relevant to their needs.
- For example:
    
    ```cpp
    struct Rectangle {
      float length;
      float width;
    };
    ```
    
- C++ includes [fundamental types](https://en.cppreference.com/w/cpp/language/types), such as `int`and `float`. These fundamental types are sometimes called ["primitives"](https://www.geeksforgeeks.org/c-data-types/).
- Another example, is if a programmer wanted to store a date:
    
    ```cpp
    struct Date {
    	int day;
    	int month;
    	int year;
    };
    
    // Create an instance
    Date date;
    
    // Initialize the attributes of Date
    date.day = 1;
    date.month = 10;
    date.year = 2021;
    ```
    

## Member Initialization

- We would like all members of an object to be in a valid state once the object is instantiated.
- We can change the values of the members later, but we want to avoid any situation in which the members are ever in an invalid state or undefined.
    
    ```cpp
    struct Date {
      int day{1};
      int month{1};
      int year{0};
    };
    ```
    

## Access Specifiers

- Members of a struct can be specified as `public` or `private`. By default, members are `public`.
- Public members can be changed directly, by any user of the object, whereas private members can only be changed by the object itself.
- Once members are specified as `private`, we create accessors (getters) and mutators (setters).
    
    ```cpp
    struct Date {
     public:
      int Day() { return day; }
      void Day(int day) { this.day = day; }
      int Month() { return month; }
      void Month(int month) { this.month = month; }
      int Year() { return year; }
      void Year(int year) { this.year = year; }
    
     private:
      int day{1};
      int month{1};
      int year{0};
    };
    ```
    
- There is a third access modifier called `protected`, which implies that members are accessible from other member functions of the same class (or from their "friends"), and also from members of their derived classes.
- Challenge
    
    ```cpp
    #include <cassert>
    #include <iostream>
    
    // TODO: Define public accessors and mutators for the private member variables
    struct Date {
     public:
        int Day(){ return day; }
        void Day(int d) { day = d;}
        int Month(){ return month; }
        void Month(int m){ month = m;}
        int Year(){ return year;}
        void Year(int y){ year = y;}
     private:
      int day{1};
      int month{1};
      int year{0};
    };
    
    int main() {
      Date date;
      date.Day(29);
      date.Month(8);
      date.Year(1981);
      assert(date.Day() == 29);
      assert(date.Month() == 8);
      assert(date.Year() == 1981);
      std::cout << date.Day() << "/" << date.Month() << "/" << date.Year() << "\n";
    }
    ```
    
    > "A trivial getter or setter adds no semantic value; the data item could just as well be public.”
    > 

## Classes

- By convention, programmers use structures when member variables are independent of each other, and [use classes when member variables are related by an "invariant"](http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#c2-use-class-if-the-class-has-an-invariant-use-struct-if-the-data-members-can-vary-independently).
- An “invariant” is a rule that limits the values of member variables.
- All members of a class default to `private`.
    
    ```cpp
    class Date {
     public:
      int Day() { return day; }
      void Day(int d) {
        if (d >= 1 && d <= 31) day_ = d;
      }
    
     private:
      int day_{1};
      int month_{1};
      int year_{0};
    };
    ```
    
- Classes challenge
    
    ```cpp
    #include <iostream>
    #include <cassert>
    
    class Date {
     public:
      int Day() { return day; }
      void Day(int d) {
        if (d >= 1 && d <= 31) day = d;
      }
        int Month() { return month; }
        void Month(int m) {
            if(m >= 1 && m <= 12)
                month = m;
        }
        int Year() { return year; }
        void Year(int y) {
            year = y;
        }
    
     private:
      int day{1};
      int month{1};
      int year{0};
    };
    
    // Test in main
    int main()
    {
        Date date;
        date.Day(-1);
        date.Month(14);
        date.Year(2000);
        assert(date.Day() != -1);
        assert(date.Month() != 14);
        assert(date.Year() == 2000);
        std::cout << date.Day() << "/" << date.Month() << "/" << date.Year() << "\n";
    }
    ```
    

## Encapsulation and Abstraction

- Encapsulation is bundling related properties together in a single class.
- Abstraction means the users of our class only need to be familiar with the interfaces of the class. The user doesn’t need to know how we ********store member data or implement member functions.********

## Constructors

- Constructors are member functions of a class or struct that initalizes the object.
    
    > *constructor*: an operation that initializes (“constructs”) an object. Typically a constructor establishes an invariant and often acquires resources needed for an object to be used (which are then typically released by a destructor).
    > 
- Constructor Exercise
    
    ```cpp
    #include <cassert>
    
    class Date {
     public:
      // Implement a constructor for Date
      Date(int d, int m, int y) {
          Day(d);
          Month(m);
          Year(y);
      }
      int Day() { return day; }
      void Day(int d) {
        if (d >= 1 && d <= 31) day = d;
      }
      int Month() { return month; }
      void Month(int m) {
        if (m >= 1 && m <= 12) month = m;
      }
      int Year() { return year; }
      void Year(int y) { year = y; }
    
     private:
      int day{1};
      int month{1};
      int year{0};
    };
    
    // Test in main
    int main() {
      Date date(8,29,1981);
      assert(date.Day() == 8);
      assert(date.Month() == 29);
      assert(date.Year() == 1981);
    }
    ```
    

- If an constructor isn’t explicity defined, the compiler will define a default constructor. This default constructor doesn’t accept any arguments. **********************************************************************However, it is best practice to ALWAYS initialize a class by calling a constructor.**********************************************************************

## Scope Resolution

- Scope resolution is the process of identifying which identifier to use.
- `::` is the [scope resolution operator](https://www.ibm.com/support/knowledgecenter/en/ssw_ibm_i_74/rzarg/cplr175.htm). We can use this operator to specify which namespace or class to search in order to resolve an identifier.
    
    ```cpp
    Person::move(); \\ Call the move function that is a member of the Person class.
    std::map m; \\ Initialize the map container from the C++ Standard Library.
    ```
    
- [Namespaces](https://en.cppreference.com/w/cpp/language/namespace) allow programmers to group logically related variables and functions together. Namespaces also help to avoid conflicts between to variables that have the same name in different parts of a program.
    
    ```cpp
    namespace English {
    void Hello() { std::cout << "Hello, World!\n"; }
    }  // namespace English
    
    namespace Spanish {
    void Hello() { std::cout << "Hola, Mundo!\n"; }
    }  // namespace Spanish
    
    int main() {
      English::Hello();
      Spanish::Hello();
    }
    ```
    
- Scope Resolution Exercise
    
    ```cpp
    #include <cassert>
    
    class Date {
     public:
      int Day() const { return day; }
      void Day(int day);
      int Month() const { return month; }
      void Month(int month);
      int Year() const { return year; }
      void Year(int year);
    
     private:
      int day{1};
      int month{1};
      int year{0};
    };
    
    // TODO: Define Date::Day(int day)
    void Date::Day(int d){
        if(d >= 1 && d <= 31){
            Date::day = d;
        }
    }
    // TODO: Define Date::Month(int month)
    void Date::Month(int m){
        if(m >= 1 && m <= 12){
            Date::month = m;
        }
    }
    // TODO: Define Date::Year(int year)
    void Date::Year(int y){
            Date::year = y;
    }
    // Test in main
    int main() {
      Date date;
      date.Day(29);
      date.Month(8);
      date.Year(1981);
      assert(date.Day() == 29);
      assert(date.Month() == 8);
      assert(date.Year() == 1981);
    }
    ```
    

## Initializer List

- [Initializer lists](https://en.cppreference.com/w/cpp/language/initializer_list), initialize member variables to specific values, just before the class constructor runs. This initialization ensures that class members are automatically initialized when an instance of the class is created.
    
    ```cpp
    Date::Date(int day, int month, int year) : year_(y) {
      Day(day);
      Month(month);
    }
    ```
    
- In general, [prefer initialization to assignment](http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#c49-prefer-initialization-to-assignment-in-constructors). Initialization sets the value as soon as the object exists, whereas assignment sets the value only after the object comes into being. This means that assignment creates an opportunity to accidentally use a variable before its value is set.
    
    ```cpp
    #include <assert.h>
    #include <string>
    
    // TODO: Define class Person
    class Person {
    public:
      // TODO: Define a public constructor with an initialization list
      Person(std::string name) : name(name) {}
      // TODO: Define a public member variable: name
      std::string name;  
    };
    
    // Test
    int main() {
      Person alice("Alice");
      Person bob("Bob");
      assert(alice.name != bob.name);
    }
    ```
    

## Initializing Constant Members

- Initializer lists exist for a number of reasons.
    1. Compiler can optimize initialization faster from an initialization list than from within the constructor.
    2. If you have a `const` class attribute, **you can only initialize it using an initialization list.** Otherwise, you would violate the `const` keyword simply by initializing the member in the constructor!
    3. Attributes defined as [references](http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#S-glossary) must use initialization lists
    
    ```cpp
    #include <assert.h>
    #include <string>
    
    struct Person {
    public:
      // TODO: Add an initialization list
      Person(std::string const & n) : name(n) {}
      std::string const name;
    };
    
    // Test
    int main() {
      Person alice("Alice");
      Person bob("Bob");
      assert(alice.name != bob.name);
    }
    ```
    

## Encapsulation

- Encapsulation is the grouping **together of data and logic** into a single unit.
- It’s important to limit member functions to only those functions that **need direct access to the representation of a class.**
    - Encapsulation Exercise
        
        ```cpp
        #include <cassert>
        
        class Date {
        public:
          Date(int day, int month, int year);
          int Day() const { return day_; }
          void Day(int day);
          int Month() const { return month_; }
          void Month(int month);
          int Year() const { return year_; }
          void Year(int year);
        
        private:
          bool LeapYear(int year) const;
          int DaysInMonth(int month, int year) const;
          int day_{1};
          int month_{1};
          int year_{0};
        };
        
        Date::Date(int day, int month, int year) {
          Year(year);
          Month(month);
          Day(day);
        }
        
        bool Date::LeapYear(int year) const {
            if(year % 4 != 0)
                return false;
            else if(year % 100 != 0)
                return true;
            else if(year % 400 != 0)
                return false;
            else
                return true;
        }
        
        int Date::DaysInMonth(int month, int year) const {
            if(month == 2)
                return LeapYear(year) ? 29 : 28;
            else if(month == 4 || month == 6 || month == 9 || month == 11)
                return 30;
            else
                return 31;
        }
        
        void Date::Day(int day) {
          if (day >= 1 && day <= DaysInMonth(Month(), Year()))
            day_ = day;
        }
        
        void Date::Month(int month) {
          if (month >= 1 && month <= 12)
            month_ = month;
        }
        
        void Date::Year(int year) { year_ = year; }
        
        // Test
        int main() {
          Date date(29, 2, 2016);
          assert(date.Day() == 29);
          assert(date.Month() == 2);
          assert(date.Year() == 2016);
            
          Date date2(29, 2, 2019);
          assert(date2.Day() != 29);
          assert(date2.Month() == 2);
          assert(date2.Year() == 2019);
        }
        ```
        

## Accessor Functions

- Accessors should only retrieve data. **They should not change the data stored in the object.**
- Core C++ guidelines suggest, if the getters/setters are only retreiving data, then the variables should be made `public`.
    - Bank Account Class
        
        ```cpp
        #include <iostream>
        #include <string>
        
        class BankAccount
        {
          public:
            int number;
            std::string owner;
            long funds;
        };
        
        int main(){
            // TODO: instantiate and output a bank account
            BankAccount account;
            account.number = 123456789;
            account.owner = "David Silver";
            account.funds   = 1000000.01;
                
            std::cout << "Account Information\n";
            std::cout << "-------------------\n";
            std::cout << "ID: " << account.number << "\n";
            std::cout << "Owner: " << account.owner << "\n";
            std::cout << "Funds: $" << account.funds << "\n";
        }
        ```
        
    - Another solution set
        
        ```cpp
        // Example solution for creating a BankAccount class
        #include <iostream>
        #include <string>
        
        class BankAccount
        {
          private:
              // Class attributes:
              
              long int number;
              std::string owner;
              float amount;
        
          public:
              // Set  methods:
              void setNumber(long int number);
              void setOwner(std::string owner);
              void setAmount(float amount);
              // Get methods:
              long int getNumber() const;
              std::string getOwner() const;
              float getAmount() const;
        };
        
        // Implementation of Set methods:
        void BankAccount::setNumber(long int number) {
            // Changing attribute to incoming value
            BankAccount::number = number;
        }
        
        void BankAccount::setOwner(std::string owner) {
            BankAccount::owner = owner;
        }
        
        void BankAccount::setAmount(float amount) {
            BankAccount::amount = amount;
        }
        
        // Implementation of Get methods:
        long int BankAccount::getNumber() const {
            // Getting specified attribute
            return BankAccount::number;
        }
        
        std::string BankAccount::getOwner() const {
            return BankAccount::owner;
        }
        
        float BankAccount::getAmount() const {
            return BankAccount::amount;
        }
        
        // main function
        int main(){
          BankAccount ba;
          ba.setAmount(100);
        
          std::cout << ba.getAmount() << std::endl;
        }
        ```
        

## Mutator Functions

- Mutator function can apply logic when updating member data.
- `std::string::c_str()` converts a string to an array of characters with a null character at the end.
- Car Class Exercise
    
    ```cpp
    #include <string>
    #include <cstring>
    #include <iostream>
    
    class Car {
        // TODO: Declare private attributes
        private:
            int horsepower;
            int weight;
            char *brand; 
            
        // TODO: Declare getter and setter for brand
        public:
            void SetBrand(std::string brand_name);
            std::string GetBrand() const;
            
            
    };
    
    // Define setters
    void Car::SetBrand(std::string brand_name) {
        // Initialization of char array
        Car::brand = new char[brand_name.length() + 1];
        // copying every character from string to char array;
        strcpy(Car::brand, brand_name.c_str());
    }
    
    // Test in main()
    int main() 
    {
        Car car;
        car.SetBrand("Peugeot");
        std::cout << car.GetBrand() << "\n";   
    }
    ```
    

## Quiz: Classes in C++

1. **The constructor function of a class is a special member function that defines any input parameters or logic that must be included upon instantiation of a class. From what you've seen so far is it required to define a constructor in C++ classes?**
    1. Answer: No, if undefined C++ will define a default constructor.
2. **What are the three options for access modifiers in C++?**
    1.  **Public** (access to anyone), **Private** (access only within the class) and **Protected** (access in friend classes)
3. **Why does it make sense to specify private member variables with accessor and mutator functions, instead of public member variables?**
    1. Often times you want to limit the user's access to class member variables, possibly because of an invariant.

## Pyramid Class

```cpp
#include <cassert>
#include <stdexcept>

// TODO: Define class Pyramid
class Pyramid {
 public:
  // constructor
  Pyramid(int length, int width, int height)
      : length_(length), width_(width), height_(height) {
    Validate();
  }

  // accessors
  int Length() const { return length_; }
  int Width() const { return width_; }
  int Height() const { return height_; }

  // mutators
  void Length(int length) {
    length_ = length;
    Validate();
  }
  void Width(int width) {
    width_ = width;
    Validate();
  }
  void Height(int height) {
    height_ = height;
    Validate();
  }

  // public Volume() function
  // the const keyword is used because the function doesn't change the member/object state.
  float Volume() const { return Length() * Width() * Height() / 3.0; }

  // private class members
 private:
  int length_;
  int width_;
  int height_;
  void Validate() {
    if (length_ <= 0 || width_ <= 0 || height_ <= 0)
      throw std::invalid_argument("negative dimension");
  }
};

// Test
int main() {
  Pyramid pyramid(4, 5, 6);
  assert(pyramid.Length() == 4);
  assert(pyramid.Width() == 5);
  assert(pyramid.Height() == 6);
  assert(pyramid.Volume() == 40);

  bool caught{false};
  try {
    Pyramid invalid(-1, 2, 3);
  } catch (...) {
    caught = true;
  }
  assert(caught);
}
```

## Student Class Exercise

```cpp
#include <cassert>
#include <stdexcept>
#include <string>

using std::string;

// TODO: Define "Student" class
class Student {
 public:
  // constructor
    Student(string name, int grade, float gpa) : name_(name), grade_(grade), gpa_(gpa){};
  // accessors
    string getName() const { return name_; }
    int getGrade() const { return grade_; }
    float getGPA() const { return gpa_; }
  // mutators
    void setName(string name){
        name_ = name;
    }
    void setGrade(int grade){
        if( grade >= 0 && grade <= 12){
            grade_ = grade;
        }
    }
    void setGPA(float gpa){
        if( gpa >= 0.0 && gpa <= 4.0){
            gpa_ = gpa;
        }
    }

 private:
  // name
    string name_;
  // grade
    int grade_;
  // GPA
    float gpa_;
};

// TODO: Test
int main() {
    Student student("Pravin", 10, 3.4);
    assert(student.getName() == "Pravin");
    assert(student.getGrade() == 10);
    assert(student.getGPA() == 3.4);
		bool caught{false};
		try {
			student.setGrade(114);
		}
		catch(...){
			caught = true;
		}
		assert(caught);
}
```

## Encapsulation in C++

1. **In the context of object oriented programming, encapsulation refers to:**
    1. The notion that data and logic can be packaged together and passed around within a program as a single object.
2. **Invoking the `const` keyword in an accessor function allows you to:**
    1. Ensure the user cannot do anything to change the private attributes of the object.
3. **Making class attributes private and assigning them with a mutator function allows you to:**
    1. Invoke logic that checks whether the input data are valid before setting attributes.
    

## Bjarne on Abstraction

> Abstraction is basically getting away from the hardware. Building addresses from primitive data types such as strings is a form of abstraction.
> 

## Abstraction

> Abstraction refers to the separation of a class’ interface from the details of its implementation. The interface provides a way to interact with an object, while hiding the details and implementaiton of how the class works.
> 
- Example of abstraction with the string method  in the Date class.
    
    ```cpp
    #include <cassert>
    #include <string>
    #include <vector>
    
    class Date {
     public:
      Date(int day, int month, int year);
      int Day() const { return day_; }
      void Day(int day);
      int Month() const { return month_; }
      void Month(int month);
      int Year() const { return year_; }
      void Year(int year);
      std::string String() const;
    
     private:
      bool LeapYear(int year) const;
      int DaysInMonth(int month, int year) const;
      int day_{1};
      int month_{1};
      int year_{0};
    };
    
    Date::Date(int day, int month, int year) {
      Year(year);
      Month(month);
      Day(day);
    }
    
    bool Date::LeapYear(int year) const {
      if (year % 4 != 0)
        return false;
      else if (year % 100 != 0)
        return true;
      else if (year % 400 != 0)
        return false;
      else
        return true;
    }
    
    int Date::DaysInMonth(int month, int year) const {
      if (month == 2)
        return LeapYear(year) ? 29 : 28;
      else if (month == 4 || month == 6 || month == 9 || month == 11)
        return 30;
      else
        return 31;
    }
    
    void Date::Day(int day) {
      if (day >= 1 && day <= DaysInMonth(Month(), Year())) day_ = day;
    }
    
    void Date::Month(int month) {
      if (month >= 1 && month <= 12) month_ = month;
    }
    
    void Date::Year(int year) {
      year_ = year;
    }
    
    std::string Date::String() const {
      std::vector<std::string> months{"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
      return months[Month()-1] + " " + std::to_string(Day()) + ", " + std::to_string(Year());
    }
    
    // Test
    int main() {
      Date date(29, 8, 1981);
      assert(date.String() == "August 29, 1981");
    }
    ```
    
    ## Exercise: Sphere Class
    
    ```cpp
    #include <cassert>
    #include <cmath>
    #include <stdexcept>
    
    // TODO: Define class Sphere
    class Sphere {
     public:
      // Constructor
      Sphere(int radius) : radius_(radius), volume_(pi_ * 4/3 * pow(radius_,3)) {
          if(radius <= 0) throw std::invalid_argument("radius needs to be a positive number");
      }
    
      // Accessors
      int Radius() const { return radius_; }
      int Volume() const { return volume_; }
    
     private:
      // Private members
      float const pi_{3.14159};
      int const radius_;
      float const volume_;
    };
    
    // Test
    int main(void) {
      Sphere sphere(5);
      assert(sphere.Radius() == 5);
      assert(abs(sphere.Volume() - 523.6) < 1);
    }
    ```
    

## Exercise: Private Method

> Abstraction is used to expose only relevant information to the user. By hiding implementation details, we give ourselves flexibility to modify how the program works.
> 

```cpp
#include <cassert>
#include <cmath>
#include <stdexcept>

class Sphere {
 public:
  Sphere(int radius) : radius_(radius), volume_(pi_ * 4 / 3 * pow(radius_, 3)) {
    if (radius <= 0) throw std::invalid_argument("radius must be positive");
  }

  int Radius() const { return radius_; }
  int Volume() const { return volume_; }

  // TODO: mutator
  void Radius(int radius) {
    if (radius <= 0) throw std::invalid_argument("radius must be positive");
    radius_ = radius;
    volume_ = pi_ * 4 / 3 * pow(radius_, 3);
  }

 private:
  float const pi_{3.14159};
  int radius_;
  float volume_;
};

// Test
int main(void) {
  Sphere sphere(5);
  assert(sphere.Radius() == 5);
  assert(abs(sphere.Volume() - 523.6) < 1);

  sphere.Radius(3);
  assert(sphere.Radius() == 3);
  assert(abs(sphere.Volume() - 113.1) < 1);

  bool caught{false};
  try {
    sphere.Radius(-1);
  } catch (...) {
    caught = true;
  }
  assert(caught);
}
```

## Exercise: Static Members

- Class members can be declared `static`, which means the member belongs to the entire class, instead of a specific instance of the class.
    - In other words, it is only created **ONCE** and shared by all instances (objects)
- That means that if the `static`member gets changed, either by a user of the class or within a member function of the class itself, then all members of the class will see that change the next time they access the `static` member.

- Quiz Question
    - Imagine you have a `class Sphere` with a `static int counter` member. `Sphere`
     increments `counter` in the constructor and uses this to track how many `Spheres`
    have been created. What would happen if you instantiated a new classes (`Cube`, for instance) that also had a `static int counter`? Would the two `counters` conflict?
        - No, because the new static attribute `counter` is defined within the `Cube` class, it has nothing to do with `Sphere::counter`.

- `Static` members are declared within their `class` but in most cases they must be **********************defined********************** within the global scope.
    - Memory is allocated for `static` variables immediately when the program begins, at the same time any global variables are initialized.
- `constexpr` is a keyword used to indicate that an expression can be evaluated at compile time.
    - By evaluating expressions at compile time, you can potentially improve the performance of your code by reducing the amount of work that needs to be done at runtime.
    - Constant expressions: **`constexpr`** is also used to **declare constant expressions**, which are expressions that can be evaluated at compile time and produce a result that is known at compile time. This can be useful for defining constants in your code.
    

## Exercise: Static Methods

- C++ supports `static` member functions, these functions are **instance-independent**.
- Before refactoring Sphere Class:
    
    ```cpp
    #include <cassert>
    #include <cmath>
    #include <stdexcept>
    
    class Sphere {
     public:
      Sphere(int radius) : radius_(radius), volume_(pi_ * 4 / 3 * pow(radius_, 3)) {
        if (radius <= 0) throw std::invalid_argument("radius must be positive");
      }
    
      int Radius() const { return radius_; }
      int Volume() const { return volume_; }
    
      void Radius(int radius) {
        if (radius <= 0) throw std::invalid_argument("radius must be positive");
        radius_ = radius;
        volume_ = pi_ * 4 / 3 * pow(radius_, 3);
      }
    
     private:
      static float constexpr pi_{3.14159};
      int radius_;
      float volume_;
    };
    
    // Test
    int main(void) {
      assert(abs(Sphere::Volume(5) - 523.6) < 1);
    }
    ```
    
    - Refactored code where we can now calculate the volume of a sphere without instantiating a new Sphere object.
        
        ```cpp
        #include <cassert>
        #include <cmath>
        #include <stdexcept>
        
        class Sphere {
         public:
           static float Volume(int radius) {
               return pi_ * 4/3 * pow(radius,3);
           }
        
         private:
          static float constexpr pi_{3.14159};
        };
        
        // Test
        int main(void) {
          assert(abs(Sphere::Volume(5) - 523.6) < 1);
        }
        ```