# CVM
A pretty basic virtual machine executing bytecode instructions from given file.

Example printing 110 by adding 99 and 11 to the console.
```
iconst 11
iconst 99
iadd
print
halt
```

Run with: `cvm <filepath> [options...]`  
and check options with `cvm --help`