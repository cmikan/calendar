# Calendar
A simple calendar that renders in the terminal, written in C.

```sh
   May 2024
 mo tu we th fr sa su
        1  2  3  4  5
  6  7  8  9 10 11 12
 13 14 15 16 17 18 19
 20 21 22 23 24 25 26
 27 28 29 30 31
```

## Compilation
To compile the project, simply use the Makefile.
```
make
./calendar
```

## Usage
Calling the application without any parameters display the calendar for the current month and the current year.

You can also input a date with the format dd/mm/yyyy.
``` sh
~$ calendar 15/02/1042
   February 1042
 mo tu we th fr sa su
  1  2  3  4  5  6  7
  8  9 10 11 12 13 14
 15 16 17 18 19 20 21
 22 23 24 25 26 27 28
```