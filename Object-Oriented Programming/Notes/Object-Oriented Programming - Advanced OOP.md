# Object-Oriented Programming - Advanced OOP

## Polymorphism and Inheritance

- Inheritance is one way classes can relate to each other.
- Polymorphism allows an interface to interact with many different types.

## Inheritance

```cpp
#include <iostream>

class Animal {
public:
	void Talk() const { std::cout << "Talk\n"; }
};

class Human : public Animal {
public:
	void Talk() const { std::cout << "Hello!\n"; }
	void Walk() const { std::cout << "I'm walking\n"; }
};

int main() {
	Animal animal;
	animal.Talk();
	Human human;
	human.Talk();
	human.Walk();
}

/*
------
OUTPUT
------
Talk 
Hello!
I'm walking
*/
```

- Vehicle Inhertiance Example
    
    ```cpp
    #include <iostream>
    #include <string>
    using std::string;
    
    class Vehicle {
    public:
        int wheels = 0;
        string color = "blue";
        string make  = "generic";
        
        void Print() const
        {
            std::cout << "This " << color << " " << make << " vehicle has " << wheels << " wheels!\n";
        }
    };
    
    class Car : public Vehicle {
    public:
        bool sunroof = false;
    };
    
    class Bicycle : public Vehicle {
    public:
        bool kickstand = true;
    };
    
    class Scooter : public Vehicle {
    public:
        bool electric = false;
    };
    
    int main() 
    {
        Scooter scooter;
        scooter.wheels = 2;
        scooter.Print();
    };
    ```
    

## Access Specifiers

- Just as access specifiers define which class members **************users can access**************, the same access modifiers also define ***which class members users of a derived class can access***.
    - [Public inheritance:](https://en.cppreference.com/w/cpp/language/derived_class#Public_inheritance) the public and protected members of the base class listed after the specifier keep their member access in the derived class.
    - [Protected inheritance:](https://en.cppreference.com/w/cpp/language/derived_class#Protected_inheritance) the public and protected members of the base class listed after the specifier are protected members of the derived class.
    - [Private inheritance:](https://en.cppreference.com/w/cpp/language/derived_class#Private_inheritance) the public and protected members of the base class listed after the specifier are private members of the derived class.
        
        ```cpp
        // This example demonstrates the privacy levels
        // between parent and child classes
        #include <iostream>
        #include <string>
        using std::string;
        
        class Vehicle {
        public:
            int wheels = 0;
            string color = "blue";
            
            void Print() const
            {
                std::cout << "This " << color << " vehicle has " << wheels << " wheels!\n";
            }
        };
        
        class Car : public Vehicle {
        public:
            bool sunroof = false;
        };
        
        class Bicycle : protected Vehicle {
        public:
            bool kickstand = true;
            void Wheels(int w)
            {
                wheels = w;
            }
        };
        
        class Scooter : private Vehicle {
        public:
            bool electric = false;
            void Wheels(int w)
            {
                wheels = w;
            }
        };
        
        int main() 
        {
            Car car;
            car.wheels = 4;
            Bicycle bicycle;
            bicycle.Wheels(2);
            Scooter scooter;
            scooter.Wheels(1);
        };
        ```
        
    
    ## Exercise: Animal Class
    
    ```cpp
    #include <iostream>
    #include <string>
    
    using std::string;
    using std::cout;
    
    // Define base class Animal
    class Animal {
        public:
            string color = "yellow";
            string name = "cheetah";
            int age = 12;
    };
    
    // Declare derived class Snake
    class Snake : public Animal {
        public:
            int length = 12;
            void MakeSound(string sound){
                cout << sound << "\n";
            }
    };
    
    // Declare derived class Cat
    class Cat : public Animal {
        public:
            int height = 4;
            void MakeSound(string sound){
                cout << sound << "\n";
            }
    };
    
    // Test in main()
    int main() 
    {
        Snake snake;
        Cat cat;
        
        snake.length;
        snake.MakeSound("sssssss");
        snake.name = "albert";
    
        cat.height;
        cat.age =  44;
        cat.MakeSound("mewwww");
    };
    ```
    

## Composition

- Composition involves constructing classes from other classes, instead of inheriting traits froma  parent class.

> **From the standpoint of composition**, a cat ***"has a"*** head and ***"has a"*** set of paws and ***"has a"*** tail.
> 
> 
> **From the standpoint of inheritance**, a cat ***"is a"*** mammal.
> 
- In general, if a class needs only extend a small amount of functionality beyond what is already offered by another class, it makes sense to **inherit** from that other class.
- ************However,************ if a class needs to contain functionality from a variety of otherwise unrelated
    
    ```cpp
    // Example solution for Circle class
    #include <iostream>
    #include <cmath>
    #include <assert.h>
    // Define PI
    #define PI 3.14159;
    
    // Define LineSegment struct
    struct LineSegment {
    // Define attribute length
    public:
        double length;
    };
    
    // Define Circle class
    class Circle {
    public:
        Circle(LineSegment& radius);
        double Area();
    
    private:
        LineSegment& radius_;
    };
    
    // Declare Circle class
    Circle::Circle(LineSegment& radius) : radius_(radius) {}
    
    double Circle::Area() 
    {
        return pow(Circle::radius_.length, 2) * PI;
    }
    
    // Test in main()
    int main() 
    {
        LineSegment radius {3};
        Circle circle(radius);
        assert(int(circle.Area()) == 28);
    }
    ```
    

## Exercise: Class Hierarchy

- An example of a multi-layer class hierarchy:

```cpp
#include <cassert>

// TODO: Declare Vehicle as the base class
class Vehicle {
    public:
        int wheels  = 4;
};
// TODO: Derive Car from Vehicle
class Car : public Vehicle{
    public:
        int seats = 4;
};
// TODO: Derive Sedan from Car
class Sedan : public Car {
    public:
        bool trunk = true;
};
// TODO: Update main to pass the tests
int main() {
  Sedan sedan;
  assert(sedan.trunk == true);
  assert(sedan.seats == 4);
  assert(sedan.wheels == 4);
}
```

## Exercise: Friends

- `friend` classes provide an alternative inheritance mechanism to derived classes.
- The difference betwee classical inheritance vs `friend` inheritance is that friend class can ********************access private members of the base class.********************
- In classical inheritance, the derived class can only access public and protected members of the base class.
    
    ```cpp
    // Example solution for Rectangle and Square friend classes
    #include <assert.h>
    
    // Declare class Rectangle
    class Rectangle;
    
    // Define class Square as friend of Rectangle
    class Square {
    // Add public constructor to Square, initialize side
    public:
        Square(int s) : side(s) {}
    
    private:
        // Add friend class Rectangle
        friend class Rectangle;
        // Add private attribute side to Square
        int side;
    };
    
    // Define class Rectangle
    class Rectangle {
    // Add public functions to Rectangle: area() and convert()
    public:
        Rectangle(const Square& a);
        int Area() const;
    
    private:
        // Add private attributes width, height
        int width {0};
        int height {0};
    };
    
    // Define a Rectangle constructor that takes a Square
    // We pass a reference to the Square object because we rectangle is a 'friend' of square 
    //   which allows us to access private attribute - side.
    Rectangle::Rectangle(const Square& a) : width(a.side), height(a.side) {}
    
    // Define Area() to compute area of Rectangle
    int Rectangle::Area() const
    {
        return width * height;
    }
    
    // Update main() to pass the tests
    int main()
    {
        Square square(4);
        Rectangle rectangle(square);
        assert(rectangle.Area() == 16); 
    }
    ```
    

## Polymorphism: Overloading

- Polymorphism == **“assuming many forms”**.
    - A functon will preform differently based on its inputs.
    
    > Polymorphism can be achieved in two ways in C++: ************************************overloading************************************  and *********************************overriding.*********************************
    > 
- Overloading requires that we leave the function name the same, but we modify the function signature.
    - For example, we might define the same function name with multiple different configurations of input arguments.

```cpp
#include <ctime>

class Date {
public:
    Date(int day, int month, int year) : day_(day), month_(month), year_(year) {}
    Date(int day, int month) : day_(day), month_(month)  
			// automatically sets the Date to the current year
    {
        time_t t = time(NULL);
        tm* timePtr = localtime(&t);
        year_ = timePtr->tm_year;
    }

private:
    int day_;
    int month_;
    int year_;
};
```

- Polymorphism Example 1
    
    ```cpp
    #include <iostream>
    
    using std::cout;
    
    // TODO: Write hello() function
    void hello(){
        cout << "Hello, World!" << "\n";
    }
    
    // TODO: Overload hello() three times
    class Human {};
    class AI {};
    class Dog {};
    
    void hello(Human human){ cout << "Hello, Human" << "\n"; }
    void hello(AI chatgpt){ cout << "Hello, ChatGPT!" << "\n"; }
    void hello(Dog leia){ cout << "Hello, Leia!" << "\n"; }
    
    // TODO: Call hello() from main()
    int main(){
        hello();
        AI chatgpt;
        Dog Leia;
        hello(chatgpt);
        hello(Leia);
    }
    ```
    

## Polymorphism: Operator Overloading

- In order to overload an operator, use the `operator` keyword in the function signature:
    
    ```cpp
    Complex operator+(const Complex& addend) {
      //...logic to add complex numbers
    }
    ```
    
- Operator Overloading Exercise
    
    ```cpp
    #include <assert.h>
    
    // TODO: Define Point class
    class Point {
    public:
      // TODO: Define public constructor
      Point(int x = 0, int y = 0) : x(x), y(y) {}
    
      // TODO: Define + operator overload
      Point operator+(const Point& addend) {
        Point sum;
        sum.x = x + addend.x;
        sum.y = y + addend.y;
        return sum;
      }
    
      // TODO: Declare attributes x and y
      int x, y;
    };
    
    // Test in main()
    int main() {
      Point p1(10, 5), p2(2, 4);
      Point p3 = p1 + p2; // An example call to "operator +";
      assert(p3.x == p1.x + p2.x);
      assert(p3.y == p1.y + p2.y);
    }
    ```
    

## Virtual Functions

- Virtual functions means that derived functions can override the base function.
    - Base virtual functions can be equal to 0, which means that the programmer has not defined the virtual function and it can be override.
    
    > A [pure virtual function](http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#S-glossary) is a [virtual function](http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#S-glossary) that the base class [declares](http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#S-glossary) but does not [define](http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#S-glossary).
    > 
    
    ```cpp
    class Shape {
        public:
            Shape() {}
    				// pure virtual functions
            virtual double Area() const = 0;
            virtual double Perimeter() const = 0;
    }
    ```
    
- Virtual Function Question
    
    ```cpp
    // Example solution for Shape inheritance
    #include <assert.h>
    #include <cmath>
    
    // TODO: Define pi
    #define PI 3.14159;
    
    // TODO: Define the abstract class Shape
    class Shape {
       // TODO: Define public virtual functions Area() and Perimeter()
      // TODO: Append the declarations with = 0 to specify pure virtual functions
        public:
            virtual double Area() const  = 0;
            virtual double Perimeter() const = 0;  
    };
    
    // TODO: Define Rectangle to inherit publicly from Shape
    class Rectangle: public Shape {
        public:
        // TODO: Declare public constructor
        // TODO: Override virtual base class functions Area() and Perimeter()
            Rectangle(double width, double height) : width_(width), height_(height) {};
        
            virtual double Area() const override {
                return width_ * height_;
            }
        
            virtual double Perimeter() const override {
                return 2 * (width_ + height_);
            }
        
        
        private:
        // TODO: Declare private attributes width and height
            double width_;
            double height_;
        
    };
    
    class Circle: public Shape {
        public:
        // TODO: Declare public constructor
        // TODO: Override virtual base class functions Area() and Perimeter()
            Circle(double radius) : radius_(radius) {};
        
            virtual double Area() const override {
                return (radius_, 2) * PI;
            }
        
            virtual double Perimeter() const override {
                return 2 * radius_ * PI;
            }
        
        
        private:
        // TODO: Declare private member variable radius
            double radius_;
        
    };
    
    // Test in main()
    int main() {
      double epsilon = 0.1; // useful for floating point equality
    
      // Test circle
      Circle circle(12.31);
      assert(abs(circle.Perimeter() - 77.35) < epsilon);
      assert(abs(circle.Area() - 476.06) < epsilon);
    
      // Test rectangle
      Rectangle rectangle(10, 6);
      assert(rectangle.Perimeter() == 32);
      assert(rectangle.Area() == 60);
    }
    ```
    

## Polymorphism: Overriding

- **********************Overriding**********************  a function occurs when::
    - A base class declared a `virtual` function.
    - A derived class overrides that `virtual` function by defining its own implementaiton with an identical function signature.
    
    ```cpp
    class Animal {
    public:
      virtual std::string Talk() const = 0;
    };
    
    class Cat {
    public:
      std::string Talk() const { return std::string("Meow"); }
    };
    ```
    
    - Overriding Exercise
        
        ```cpp
        #include <assert.h>
        #include <string>
        
        class Animal {
        public:
          virtual std::string Talk() const = 0;
        };
        
        // TODO: Declare a class Dog that inherits from Animal
        class Dog : public Animal {
        public:
            std::string Talk() const { return std::string("Woof"); }
        };
        
        int main() {
          Dog dog;
          assert(dog.Talk() == "Woof");
        }
        ```
        
- ****************Function Hiding****************
    - closely related, but distinct form, overriding.
    - A derived class hides a base class function, as opposed to overriding it, if the base class function is not specified to be `virtual`.
        
        ```cpp
        class Cat { // Here, Cat does not derive from a base class
        public:
          std::string Talk() const { return std::string("Meow"); }
        };
        
        class Lion : public Cat {
        public:
          std::string Talk() const { return std::string("Roar"); }
        };
        ```
        
        > The distinction between *overriding* and *hiding* is subtle and not terribly significant, but in certain situations *hiding*
         [can lead to bizarre errors](https://isocpp.org/wiki/faq/strange-inheritance),  particularly when the two functions have slightly different function signatures.
        > 

## Override

- "Overriding" a function occurs when a derived class defines the implementation of a `virtual` function that it inherits from a base class.
    
    ```cpp
    class Shape {
    public:
      virtual double Area() const = 0;
      virtual double Perimeter() const = 0;
    };
    
    class Circle : public Shape {
    public:
      Circle(double radius) : radius_(radius) {}
      double Area() const override { return pow(radius_, 2) * PI; } // specified as an override function
      double Perimeter() const override { return 2 * radius_ * PI; } // specified as an override function
    
    private:
      double radius_;
    };
    ```
    
    - Override Exercise
        
        ```cpp
        #include <assert.h>
        #include <cmath>
        
        // TODO: Define PI
        #define PI 3.14159
        
        // TODO: Declare abstract class VehicleModel
        class VehicleModel {
        public:
          // TODO: Declare virtual function Move()
            virtual double Move(double v, double phi) = 0;
        };
        
        // TODO: Derive class ParticleModel from VehicleModel
        class ParticleModel : public VehicleModel {
        public:
            // TODO: Override the Move() function
            double Move(double v, double phi) override {
                theta_ = phi;
                x_ = v * cos(theta_);
                y_ = v * sin(theta_);
            }
            
            // TODO: Define x, y, and theta
            double x_;
            double y_;
            double theta_;
        
        };
        
        // TODO: Derive class BicycleModel from ParticleModel
        class BicycleModel : public ParticleModel {
        public:
          // TODO: Override the Move() function
            double Move(double v, double phi) override {
                theta_ = v / L * tan(phi);
                x_ = v * cos(theta_);
                y_ = v * sin(theta_);
            }
        
            double L  = 1;
        };
        
        // TODO: Pass the tests
        int main() {
          // Test function overriding
          ParticleModel particle;
          BicycleModel bicycle;
          particle.Move(10, PI / 9);
          bicycle.Move(10, PI / 9);
          assert(particle.x_ != bicycle.x_);
          assert(particle.y_ != bicycle.y_);
          assert(particle.theta_ != bicycle.theta_);
        }
        ```
        
    
    ## Generic Programming
    
    - this is an example of **************polymorphism.**************
    - By using a C++ facility called ************template,************ you can generate classes and functions that can be used in multiple applications.
        - vector is an example of generic programming.
    
    ## Templates
    
    - `template` allows us to define a generic type.
    - templates use **************************************************************************************************************************************************************types************************************************************************************************************************************************************** as parameters so that the same implementaion can operate on different data types**************************************************************************************************************************************************************.**************************************************************************************************************************************************************
        - Example with type `double`
            
            ```cpp
            template <typename Type> Type Sum(Type a, Type b) { return a + b; }
            
            int main() { std::cout << Sum<double>(20.0, 13.7) << "\n"; }
            ```
            
        - When the program calls `Sum()` with `double` as parameters, the function expands to become:
            
            ```cpp
            double Sum(double a, double b) {
                return a+b;
            }
            ```
            
        - Example with type `char`
            
            ```cpp
            std::cout << Sum<char>(‘Z’, ’j’) << "\n";
            ```
            
            ```cpp
            char Sum(char a, char b){
            	return a+b;
            }
            ```
            
    - Generic code is the term for code that is independent of types.
    - The keyword `typename` (or, alternatively, `class` ) specifies the generic type in the function prototype.
    - The parameters that follow `typename` or `class` represent generic types in the function declaration.
    
    > Templates is C++’s support for generic programming. Templates is something you can parametrize with types or values.
    > 
    - C++ will have a new feature called ******************concepts.******************
    
    ## Exercise: Comparison Operation
    
    ```cpp
    #include <assert.h>
    
    // TODO: Declare a generic, templatized function Max()
    template <typename Type> Type Max (Type a, Type b){
        if (a > b){
            return a;
        } else {
            return b;
        }
    }
    
    int main() { 
      assert(Max(10, 50) == 50);
      assert(Max(5.7, 1.436246) == 5.7);
    }
    
    // ANOTHER SOLUTION
    #include <assert.h>
    
    // TODO: Declare a generic, templatized function Max()
    template <typename T> T Max(T a, T b) {
        return a > b ? a : b;
    }
    
    int main() { 
      assert(Max(10, 50) == 50);
      assert(Max(5.7, 1.436246) == 5.7);
    }
    ```
    
    ## Deduction
    
    - Deduction occurs when you instantiate an object without explicitly identifying the types.
    - This can be helpful for writing code that is generic and can handle a variety of inputs.
        
        ```cpp
        #include <assert.h>
        
        // TODO: Declare a generic, templatized average function
        template <typename Type> 
        Type average(Type A, Type B){
            return (A + B) / 2;
        }
        
        int main() { assert(average(2.0,5.0) == 3.5); }
        ```
        
    
    ## Exercise: Class Template
    
    - Templates **support** the creation of **generic classes**.
    - You need to include two generic types: `KeyName` and `ValueName`
        - Example with a Mapping class
            
            ```cpp
            #include <assert.h>
            #include <string>
            #include <sstream>
            
            // TODO: Add the correct template specification
            template <typename KeyType, typename ValueType>
            class Mapping {
            public:
              Mapping(KeyType key, ValueType value) : key(key), value(value) {}
              std::string Print() const {
                std::ostringstream stream;
                stream << key << ": " << value;
                return stream.str();
              }
              KeyType key;
              ValueType value;
            };
            
            // Test
            int main() {
              Mapping<std::string, int> mapping("age", 20);
              assert(mapping.Print() == "age: 20");
            }
            ```
            

## Summary

- Classses are how C++ groups information
- Members of those classes store data and provide functions
- Constructors instantiate objects of the class
- Classes encapsulate data and abstract how that data is used.
- Users of the class only need to know how its interface. The way the data is stored and how the function is implemented isn’t information they need to know.
- Inheritance heirarchy define how classes are related to each other and any member they may inherit.
- Polymorphism (i.e. Generic Programming) allow the same code to work with multiple system and user defined types.
    - This makes the code more **reusable and saves a programmers time.**
