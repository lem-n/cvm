# CVM
A pretty basic virtual machine executing bytecode instructions from given file.

Example printing 9999 to the console.
```
iconst 999
print
halt
```

Run with: 
`cvm <filepath> [memory slots = 512]`