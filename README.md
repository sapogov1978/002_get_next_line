# 002_get_next_line
## Function which returns a line read from a file descriptor. Calling function in a loop will then allow to read the text available on a file descriptor one line at a time until the EOF.

>_This project will not only allow you to add a very convenient function to your collection, but it will also make you learn a highly interesting new concept in C programming: static variables._

![GitHub code size in bytes](https://img.shields.io/github/languages/code-size/sapogov1978/002_get_next_line?style=for-the-badge)
![Lines of code](https://img.shields.io/tokei/lines/github/sapogov1978/002_get_next_line?style=for-the-badge)
![GitHub language count](https://img.shields.io/github/languages/count/sapogov1978/002_get_next_line?style=for-the-badge)
![GitHub top language](https://img.shields.io/github/languages/top/sapogov1978/002_get_next_line?style=for-the-badge)

## Usage

### Requirements

The project is written in C language and thus needs the **`gcc` compiler** and some standard **C libraries** to run.

### Instructions

**1. Compiling**

To compile the library, run:

```shell
$ cd [path/to/project] && make
```

**2. Running**

To use the functions:

```shell
./gnl test_cases/[any_case]
```
Also some extrimal cases collected in [`narco.tar.gz`](test_cases/narco.tar.gz) archive
