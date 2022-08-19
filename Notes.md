# Overview

## Headers covered

- <variant>
- <stdexcept>

## Operators


double& operator[](int i) {return elem[i];}     // Element access

## Chapter 1

Function declaration: Declaration of name

Elem* next_elem();
void exit(int);
...

- Function overloading
    - Convention: Implement same semantics

    print(string)
    print(int)


Type: Set of possible values/operations
Object: Memory that holds a value
Value: Set of bits interpreted according to a type
Variable: Named object

### Fundamental Types

Use (') to separate digits


Evaluation:
    Expression - left-to-right
    Assignment - right-to-left


Initialization

- Convention: Use generally '{}' initializer

Narrowing conversion
    - Allowed with '='
    - Not applied with '{}'


**auto**: Type inference
    Not use auto:
        - want to make type clearly visible
        - explicit about type (e.g. double/float)


Local scope: Function/Lambda
Class scope
Namespace scope


### Constants

**const**: Value not changed
    - mainly used for interfaces (functions)
    - promise not to change value
**constexpr**: Evaluated at compile time


constexpr function: when called with non-constant-expression arguments then not constant expression

### Pointers, Arrays, References

- Reference similar to a pointer
    - no dereferencing necessary

**nullptr**: represents absence of object
    - only one nullptr


Loops/Conditionals:
    **for**
    **while**
    **foreach** -> **for(auto& x : <collection>)**
    **switch**


No uninitialized reference allowed

Distinction: Initialization/Assignment



## Chapter 2

User-defined types:
    - classes
    - enums

new operator: allocate memory (heap)
delete/ delete[] operator: free allocated memory


**Fixed-size handle refers to a variable amount of data elsewhere**

struct is a class with members public

### Unions

union is a struct which all members are allocated at the same address

- use of "naked" unions (access) should be minimized

- using variant



enum-class: Represent small sets of integer values
    - class after enum -> strongly typed & enumerators scoped (e.g. red in multiple enumes can be used multiple times)

    enum class Color {red, blue, green};
    enum class TrafficLight {red, yellow, green};

    Color x = red       // Not working
    Color y = TrafficLight::red     // Not working

    - no mix: integer <-> enum

    - but explicit initialization
        Color y{2}

## Chapter 3

- Specification of interfaces by declarations

**May be many declarations but only one definition**

### Modules (C++ 20)

- Module system supported in C++ 20; Not working with g++


### Namespaces

- namspace NAME {...}
- using namespace NAME
    - makes name from NAME available without specifying namespace


### Error Handling

Exception

**Use exception when error is OUTSIDE program (e.g. fetching resource failed)**

throw: std::out_of_range("MESSAGE");

try {
    CODE
} catch (std::out_of_range& err) {
    ... err.what()
}

- Error handling :RAII (Resource Acquisition is Initialization)
    - Constructor aquire all resources necessary
    - Destructor release all resources


**noexcept**: Function that should never throw an exception
    - if thrown --> std::terminate() is called

- Constructor --> establish invariant

- Alternative error handling: error code
    - when error is expected

### Function Arguments and Return Values

- Default: *pass-by-copy*
- Want to refer to object in caller's environment -> *pass-by-reference*

Performance:
    - Small objects: pass-by-copy (2/3 values, e.g. small class/struct)
    - Large objects: pass-by-reference

Declaring arguments *const* -> no modification


- Default argument: void print(int value, int base = 10)


#### Return

- Default: return-by-copy
- Want to grant caller access to something that is not local:
    return-by-reference

- Local variable disappears when function returns -> not return pointer/reference

- Move constructor: move large amounts of data
    - No need for manual memory management

- Return multiple values bundled in struct/class

- Structured binding: >= C++17


## Chapter 4 - Classes

### Concrete Classes

- behave just like built-in types

- functions defined in class are inlined by default

- Otherwise: **inline** keyword
    - For simple functions defined outside (e.g. operator*=, ...)


Container:
    - holding collection of elements

Destructor: ~Constructor

delete:   deletes individual object
delete[]: deletes an array

**Resource Acquisition Is Initialization (RAII)**
    - allocate memory in constructor
    - deallocate memory in destructor

    - Avoid "naked" new/delete


Initializing container:
    - Initializer-list
    - push_back -> add new element at end of sequence


- When using {}-list -> compiler will create object of type initializer_list to give to the program

e.g. Vector v1 = {1,2,3,4,5}    // v1 has 5 elements

- Standard-library: unsigned integers for sizes/subscripts
    - static_cast

**Casting**:
    - *reinterpret_cast* --> treat object as sequence of bytes
    - *const_cast* --> casting away const

### Abstract Types

- Insulates (hides) a user from implementation details
- Size not known
    -> Work through reference/pointers


**virtual** function
    - may be redefined later in a class derived from this

    - *=0* --> **pure virtual**
        - class derived from Container must define function

Polymorphic type: class that provides interface to a variety of other classes

virtual Destructor

**:public** -> "is derived from"

**override** -> explicit to make clear to override method


### Virtual Functions

see sheet

### Class Hierarchies

- dynamic_cast<Type>(obj)
    - returns nullptr if obj has not type Type 
    
    - dynamic cast to reference -> std::bad_cast thrown if type mismatch

- no "naked" pointers
    - *unique_ptr<Shape>*


Implementation vs interface inheritance

## Chapter 5

X(Sometype)             -> ordinary constructor
X()                     -> default constructor
X(const X&)             -> copy constructor
X(X&&)                  -> move constructor
X& operator=(const X&)  -> copy assignment
X& operator=(X&&)       -> move assignment
~X()                    -> destructor

- *either define all operations or none*

**=default**: use default constructor
**=delete**: indicate that operation is not generated

### Conversions

- **explicit** : only explicit conversion is allowed


- Copying can be costly for large containers
    => Move constructor

*&&* -> rvalue reference
    rvalue : can't assign to
    rvalue reference : "steal" value from it

Move operation: Applied when rvalue reference is used as initializer or as right-hand side of assignment

Move constructor: remove value from its argument


### Conventional Operations

X a = ...;
X b = a;
assert(a == b);


iostreams -> '<<' (output) '>>' (input)

- user-defined literals (UDLs)

Ex.:
    constexpr complex<double> operator""i(long double arg) {
        return {0,arg};
    }



## Chapter 6 - Templates

template : make general

template<typename T>
    - for all types T
    - makes T parameter of declaration it prefixes

    - Older code: template<class T>


Templates are compile-time mechanism
    - no run-time overhead


- requirement on type
template<TYPE T> -> for all T such that TYPE(T)
    - TYPE is a predicate

- template can take values
    template<typename T, int N>


- type of C-style string literal: const char*

- deduction guide

- 3 ways of expressing operation parameterized by types/values:
    - function template
    - function object
    - lambda expression


- Function object (functor)
    - define objects like functions

**Lambda expressions**
    [&](ARGUMENTS) {BODY}
     ^
     Capture list: all local names used in lambda body will be accessed through references

     [&A] -> only capture A
     [=A] -> give a copy of A
     []   -> Capture nothing


    - good for small functions


argument is considered to initialize the formal parameter in a call

- lambda with auto parameter : **generic lambda**


#### Template Mechanisms

- values dependt on type: variable templates


Aliases:

**using Type = Another Type**

