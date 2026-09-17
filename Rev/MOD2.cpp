// Structure, Union, Enum, Typedef, and Type Alias
// structure: user defined data type that groups related variables of different types under a single name
// union: user defined data type that allows storing different data types in the same memory location
// enum: user defined data type that consists of a set of named integral constants
// typedef: keyword used to create an alias for a data type
// type alias: a way to create an alias for a data type using the 'using'

// 1. Structure: stores different types of data under a single name but with individual memory allocation for each member
// It has public access specifier by default but we can change it to private or protected using access specifiers
// The size of a structure is equal to the sum of the sizes of its members along with padding


// 2. Union: stores different types of data under a single name but with shared memory allocation for all members
// It has public access specifier by default but we can change it to private or protected using access specifiers
// The size of an union is equal to the size of its largest member 