## aoc-solutions

Solutions to programming puzzles from
[Advent of Code](https://adventofcode.com/)

### Structure

```text
> tree
.
├── 2015
│   ├── day_01
│   │   ├── input.txt
│   │   ├── part_1.c
│   │   ├── part_2.c
│   │   └── README.md
│   └── ...    # other days
└── ...    # other years
```

### Compile and run

Use your preferred C compiler (in my case, `gcc`):

```sh
$ gcc -o part_1 part_1.c
$ ./part_1
```

Or use the [`car`](./car)
(<ins>c</ins>ompile
 <ins>a</ins>nd
 <ins>r</ins>un) script:

```text
$ ./car <year> <day> <part> [args...]
```
