# CVM
A pretty basic virtual machine executing bytecode instructions from given file.

Example bytecode printing 9999 to the console.
```
0A 270F     // ICONST 9999
10          // PRINT
00          // HALT
```

Run with: 
`cvm <filepath> <memory slots>`