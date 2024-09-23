# Simple Brainfuck Interpreter in C
This repository contains a simple Brainfuck interpreter written in C.
The interpreter reads Brainfuck code from a file, parses it, and executes the commands in a memory buffer.

## Features
- Supports all standard Brainfuck commands (`>`, `<`, `+`, `-`, `.`, `,`, `[`, `]`).
- Handles loops using `[` and `]` efficiently.
- Uses a fixed-size memory buffer of 30000 cells.

## How does brainfuck works?
If you're here, you probably already know that, but here you go:
The interpreter reads a file, then processes each character based on a instruction set:

- `>`: Move the memory pointer to the right.
- `<`: Move the memory pointer to the left.
- `+`: Increment the value at the current memory cell.
- `-`: Decrement the value at the current memory cell.
- `.`: Output the character at the current memory cell.
- `,`: Read a character and store it at the current memory cell.
- `[`: Jump to the corresponding `]` if the current memory cell value is `0`.
- `]`: Jump back to the corresponding `[` if the current memory cell value is non-zero.

### Compilation
To compile the program, use a C compiler like `gcc`:

```bash
gcc fuck.c -o interpreter
```

### Running the Program
To run the interpreter, provide a brainfuck file as an argument:

```bash
./interpreter example.bf
```

Where `example.bf` is a file containing brainfuck code.
There is a Hello World program in the repository as example.

```brainfuck
++++++++++[>++++++++>+++++++++++>++++++++++>++++>+++>++++++++>++++++++++++>+++++++++++>++++++++++>+++++++++++>+++>+<<<<<<<<<<<<-]>-.>--.>---.>++++.>++.>---.>---.>.>.>+.>+++.>.
```

## Memory
The interpreter uses a static memory array of 30000 bytes.
The memory pointer starts at the beginning of the array and can move left or right during execution.

## Limitations
- Memory is fixed at 30000 cells.
- No input validation for brainfuck programs, so ensure valid syntax in your `.bf` files.

Have fun <3
