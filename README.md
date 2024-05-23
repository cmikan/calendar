# Calendar
A simple calendar that renders in the terminal, written in C for Linux.

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

Change the displayed month with **o** (previous month) and **p** (next month).
Use the arrow keys to arrow keys to select a day.