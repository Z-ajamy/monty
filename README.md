# Monty - Bytecode Interpreter

![Monty](https://i.pinimg.com/736x/f8/45/87/f845876e178fc5b62de14de04de2a3fa.jpg)

## Description
Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files. This project is part of the ALX Software Engineering program, focusing on implementing stacks and queues using doubly linked lists in C.

Files containing Monty byte codes usually have the .m extension. Most of the industry uses this standard but it is not required by the specification of the language.

## Learning Objectives
By the end of this project, you should be able to:
- Understand what LIFO (Last In, First Out) and FIFO (First In, First Out) mean
- Implement stacks and queues using doubly linked lists
- Know when to use stacks versus queues
- Understand the common implementations of stacks and queues
- Know the common use cases of stacks and queues
- Parse command line arguments and files
- Handle errors appropriately in C programs

## Requirements
### General
- Allowed editors: vi, vim, emacs
- All files will be compiled on Ubuntu 20.04 LTS using gcc with options: `-Wall -Werror -Wextra -pedantic -std=gnu89`
- All files should end with a new line
- A `README.md` file at the root of the project folder is mandatory
- Your code should use the Betty style (checked using `betty-style.pl` and `betty-doc.pl`)
- You allowed to use a maximum of one global variable
- No more than 5 functions per file
- You are allowed to use the C standard library
- The prototypes of all functions should be included in a header file called `monty.h`
- All header files should be include guarded

## Data Structures
Use these data structures for this project:

```c
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
    char *opcode;
    void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
```

## Compilation & Output
Your code will be compiled this way:
```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o monty
```

Any output must be printed on `stdout`. Any error message must be printed on `stderr`.

## Usage
```bash
./monty file
```
where `file` is the path to the file containing Monty byte code

If the user does not give any file or more than one argument to your program, print the error message `USAGE: monty file`, followed by a new line, and exit with the status `EXIT_FAILURE`.

If, for any reason, it's not possible to open the file, print the error message `Error: Can't open file <file>`, followed by a new line, and exit with the status `EXIT_FAILURE`.

## The Monty Language
There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument. Monty byte code files can contain blank lines (empty or made of spaces only), and any additional text after the opcode or its required argument is not taken into account.

Example:
```
push 0
push 1
push 2
  push 3
                   pall    
push 4
    push 5    
      push    6        
pall
```

## Implemented Opcodes

### Mandatory Tasks

#### 0. push, pall
- **push**: Pushes an element to the stack
  - Usage: `push <int>`
  - If `<int>` is not an integer or if there is no argument given to push, print the error message `L<line_number>: usage: push integer`, followed by a new line, and exit with the status `EXIT_FAILURE`
- **pall**: Prints all the values on the stack, starting from the top of the stack
  - Usage: `pall`
  - If the stack is empty, don't print anything

#### 1. pint
- **pint**: Prints the value at the top of the stack, followed by a new line
  - Usage: `pint`
  - If the stack is empty, print the error message `L<line_number>: can't pint, stack empty`, followed by a new line, and exit with the status `EXIT_FAILURE`

#### 2. pop
- **pop**: Removes the top element of the stack
  - Usage: `pop`
  - If the stack is empty, print the error message `L<line_number>: can't pop an empty stack`, followed by a new line, and exit with the status `EXIT_FAILURE`

#### 3. swap
- **swap**: Swaps the top two elements of the stack
  - Usage: `swap`
  - If the stack contains less than two elements, print the error message `L<line_number>: can't swap, stack too short`, followed by a new line, and exit with the status `EXIT_FAILURE`

#### 4. add
- **add**: Adds the top two elements of the stack
  - Usage: `add`
  - The result is stored in the second top element of the stack, and the top element is removed
  - If the stack contains less than two elements, print the error message `L<line_number>: can't add, stack too short`, followed by a new line, and exit with the status `EXIT_FAILURE`

#### 5. nop
- **nop**: Doesn't do anything
  - Usage: `nop`

### Advanced Tasks

#### 6. sub
- **sub**: Subtracts the top element of the stack from the second top element of the stack
  - Usage: `sub`
  - The result is stored in the second top element of the stack, and the top element is removed
  - If the stack contains less than two elements, print the error message `L<line_number>: can't sub, stack too short`, followed by a new line, and exit with the status `EXIT_FAILURE`

#### 7. div
- **div**: Divides the second top element of the stack by the top element of the stack
  - Usage: `div`
  - The result is stored in the second top element of the stack, and the top element is removed
  - If the stack contains less than two elements, print the error message `L<line_number>: can't div, stack too short`, followed by a new line, and exit with the status `EXIT_FAILURE`
  - If the top element of the stack is 0, print the error message `L<line_number>: division by zero`, followed by a new line, and exit with the status `EXIT_FAILURE`

#### 8. mul
- **mul**: Multiplies the second top element of the stack with the top element of the stack
  - Usage: `mul`
  - The result is stored in the second top element of the stack, and the top element is removed
  - If the stack contains less than two elements, print the error message `L<line_number>: can't mul, stack too short`, followed by a new line, and exit with the status `EXIT_FAILURE`

#### 9. mod
- **mod**: Computes the rest of the division of the second top element of the stack by the top element of the stack
  - Usage: `mod`
  - The result is stored in the second top element of the stack, and the top element is removed
  - If the stack contains less than two elements, print the error message `L<line_number>: can't mod, stack too short`, followed by a new line, and exit with the status `EXIT_FAILURE`
  - If the top element of the stack is 0, print the error message `L<line_number>: division by zero`, followed by a new line, and exit with the status `EXIT_FAILURE`

#### 10. comments
- When the first non-space character of a line is `#`, treat this line as a comment (don't do anything)

#### 11. pchar
- **pchar**: Prints the char at the top of the stack, followed by a new line
  - Usage: `pchar`
  - The integer stored at the top of the stack is treated as the ASCII value of the character to be printed
  - If the value is not in the ASCII table, print the error message `L<line_number>: can't pchar, value out of range`, followed by a new line, and exit with the status `EXIT_FAILURE`
  - If the stack is empty, print the error message `L<line_number>: can't pchar, stack empty`, followed by a new line, and exit with the status `EXIT_FAILURE`

#### 12. pstr
- **pstr**: Prints the string starting at the top of the stack, followed by a new line
  - Usage: `pstr`
  - The integer stored in each element of the stack is treated as the ASCII value of the character to be printed
  - The string stops when either the stack is over, the value of the element is 0, or the value of the element is not in the ASCII table
  - If the stack is empty, print only a new line

#### 13. rotl
- **rotl**: Rotates the stack to the top
  - Usage: `rotl`
  - The top element of the stack becomes the last one, and the second top element of the stack becomes the first one

#### 14. rotr
- **rotr**: Rotates the stack to the bottom
  - Usage: `rotr`
  - The last element of the stack becomes the top element of the stack

#### 15. stack, queue
- **stack**: Sets the format of the data to a stack (LIFO). This is the default behavior of the program
  - Usage: `stack`
- **queue**: Sets the format of the data to a queue (FIFO)
  - Usage: `queue`

When switching mode:
- The top of the stack becomes the front of the queue
- The front of the queue becomes the top of the stack

## Error Handling
The program should handle various error conditions:
- Invalid arguments
- File opening errors
- Invalid opcodes
- Stack underflow
- Division by zero
- Invalid ASCII values
- Memory allocation failures

All error messages should be printed to stderr and the program should exit with `EXIT_FAILURE`.

## Project Structure
```
monty/
├── README.md
├── add.c
├── div.c
├── executor.c
├── free_stack.c
├── mod.c
├── monty.c
├── monty.h
├── mul.c
├── pall.c
├── parsing.c
├── pchar.c
├── pint.c
├── pop.c
├── pstr.c
├── push.c
├── rotl.c
├── rotr.c
├── sub.c
├── swap.c
└── test
    ├── README.md
    ├── monty
    └── test.m
```

## Testing
Test your Monty interpreter with various .m files:
```bash
./monty bytecodes/00.m
./monty bytecodes/01.m
# etc.
```

Create test files with different opcodes and edge cases to ensure your implementation is robust.
