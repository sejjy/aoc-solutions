## aoc-solutions

Solutions to programming puzzles from
[Advent of Code](https://adventofcode.com/)

### Structure

```text
.
├── year
│   ├── day_#
│   │   ├── README.md
│   │   ├── input.txt
│   │   ├── part_#.c
│   │   └── ...    (other parts)
│   └── ...    (other days)
└── ...    (other years)
```

### Compile and run

Use your preferred C compiler (in my case, [`gcc`](https://gcc.gnu.org/)):

```sh
$ gcc -o part_# part_#.c
$ ./part_#
```

or use the [`car`](./car)
(<ins>c</ins>ompile
 <ins>a</ins>nd
 <ins>r</ins>un) script:

```text
$ ./car year day_# part_# [args...]
```
