# PA2-second-project
The task is to implement a class CBigInt, which will represent integers (positive and negative) with (almost) unlimited range.

Integers of type int, long long int, ... have a fixed size, i.e. a limited range. If we need calculations with a larger range of values, we need to create our own data type for them. The class implementing this data type will store the number in an internal representation, which it will stretch (allocate more space) as needed. Your task is to implement such a class. To simplify the implementation, the following constraints apply:

Store only integers (positive, zero, and negative). We do not deal with the decimal part.
Among mathematical operations, we implement only addition, multiplication and comparison.
Therefore, the implemented class must satisfy the following interfaces:

an implicit constructor
    initializes an object that will represent the value 0,
a constructor with the integer parameter int
    initializes an object representing that number,

constructor with string parameter (ASCIIZ)
    initializes the object with the value whose decimal representation is in the passed string. If the given string is invalid (does not contain a valid decimal number), the constructor throws an std::invalid_argument exception. The exception is part of the standard           library, its declaration is in the stdexcept header file. When throwing the std::invalid_argument exception, a string with a more detailed description of the cause of the error can be passed to its constructor; the content of this string is not restricted for this         task,
the copying constructor
    will be implemented if the internal structures of your class require it,
destructor
    will be implemented if the internal structures of your class require it,
overloaded operator =
    will allow assignment from integer, string and other CBigInt instances,
operator <<
    will allow the object to be output to the C++ stream. The mandatory tests require output in decimal representation without unnecessary leading zeros. In the bonus tests, the operator must also interact with the stream and, depending on the handler used, display the      result in either decimal or hexadecimal (octal output is not tested). Hexadecimal output uses lower case and does not display unnecessary leading zeros.
Operator >>
    will allow reading from the input stream (the input will be in decimal notation). Reading will behave the same as reading integers in the standard library, i.e. it will stop at the first character that can no longer be a valid part of the number being read.
The + operator
    allows to add two numbers of type:
    CBigInt + CBigInt,
    CBigInt + int,
    CBigInt + ASCIIZ string,
    int + CBigInt and
    ASCIIZ string + CBigInt. 
perator +=
    allows to add another CBigInt number, integer or ASCIIZ string to a CBigInt number.
operator *
    allows you to multiply two numbers in the same notation combinations as the addition operator.
operator *=
    allows a number of type CBigInt to be multiplied by another CBigInt number, an integer or an ASCIIZ string.
relational operators (< <=, > >=, == and !=)
    allow you to compare large numbers against each other, again the comparison must handle all combinations like addition and multiplication.    
    
    
