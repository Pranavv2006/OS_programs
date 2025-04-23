# OS_programs


## Exp4 Understanding fork()

The `fork()` system call is used to create a new process by duplicating the calling process. This results in two processes:

- **Parent Process**: The original process that invoked `fork()`. It receives the Process ID (PID) of the newly created child.
- **Child Process**: A near-identical copy of the parent. It receives `0` as the return value of `fork()`.

### Key Concepts:

1. **Copy-on-Write Memory Duplication**: The child process shares the parent's memory pages until one of them modifies it.
2. **Unique Identification**: The child process is assigned a new PID and has its Parent PID (PPID) set to the PID of the parent.
3. **Return Values of fork()**:
   - Positive integer: Returned in the parent, indicating the PID of the child.
   - Zero: Returned in the child, used to distinguish it from the parent.
   - -1: Indicates failure to create a new process (e.g., due to resource limitations).

