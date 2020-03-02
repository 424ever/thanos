# thanos
Some thanos utilities

## Installation
### Requirements
- C compiler (change the line ```CC = gcc``` in the ```Makefile```, if you are not using gcc)
- GNU make
- ```strfile``` (usually distributed alongside ```fortune```)
```
git clone https://github.com/424ever/thanos.git
cd thanos
make
sudo make install
```

## Usage
### thanos
```thanos ```

Prints out random thanos quotes found in the ```quotes``` file. All arguments are ignored.

### thanoscat
```thanoscat [FILE]```

Reads ```FILE```, or if no argument is given from ```stdin```, only printing half of the non-space characters to ```stdout```.
