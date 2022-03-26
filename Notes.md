# Overview

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

