# Tests Directory

This directory contains test files and resources for the Monty bytecode interpreter project.

![Monty](https://i.pinimg.com/736x/eb/45/99/eb459997151d6a9d0e4cd1a619bde051.jpg)

## Running Tests

To run the Monty interpreter on test files:

```bash
# Basic usage
./monty test_file.m

# Run from project root
./monty tests/test_file.m

# Run multiple tests
./monty tests/basic_ops.m
./monty tests/arithmetic.m
./monty tests/edge_cases.m
```

## Test Categories

### Basic Operations
- Stack manipulation (push, pop, pall, pint)
- Basic arithmetic (add, sub, mul, div, mod)
- Stack utilities (swap, nop)

### Edge Cases
- Empty stacks
- Single element operations
- Invalid arguments
- Division by zero
- Stack underflow conditions

### Error Handling
- Invalid opcodes
- Malformed input
- File handling errors
- Memory edge cases

### Advanced Features
- String operations (pchar, pstr)
- Stack rotations (rotl, rotr)
- Queue mode switching
- Comment handling
- Complex bytecode sequences

## Test File Structure

Test files use the `.m` extension and contain Monty bytecode instructions:

```
push 1
push 2
pall
add
pint
```

## Adding New Tests

When creating new test files:
- Use descriptive filenames
- Include both valid and invalid cases
- Test boundary conditions
- Document expected behavior in comments when helpful

## Notes

- Tests should cover both successful execution and error conditions
- Consider testing with various input sizes and edge cases
- Verify proper memory management and cleanup
- Test files can be organized into subdirectories as needed
