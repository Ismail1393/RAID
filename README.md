# RAID mapping

In this project, you'll implement a program that maps the location of sectors in a RAID device into the sectors of the hard disks that compose it. For this project, you must read the input from the standard input and print the result in the standard output. Please follow the format precisely, otherwise your solution will not be considered correct.

## Task description

Given a scenario composed of a RAID level `T` (`"0"`, `"1"`, `"01"`, `"10"`, `"4"`, or `"5"`), the number of hard disks `N`, the size of the chunks `C` (in sectors), the number of sectors per disk `S`, you will be asked `Q` queries. Each query is a valid sector number in the RAID device, and your program must specify which hard disk and stripe contain the queried sector, and which other disk has a copy of (RAID levels 1, 01, and 10) or a parity for (RAID levels 4 and 5) this sector. You will have 1 second to answer all queries.

### Restrictions in the test cases (test cases always follow the restrictions):

- Hard disks are numbered from `0` to `N-1`. `N` is in the range `[2,16]`.
  - `N` is always `2` for RAID level `1`.
  - `N` is always an even number greater than `3` for RAID levels `01` and `10`.
  - `N` is always greater than `2` for RAID levels `4` and `5`.
- Chunk size `C` is a number in the range `[1,16]` for RAID level `0`.
  - `C` is always `1` for other RAID levels.
- Stripes and disk sectors are numbered from `0` to `S-1`.
  - The number of sectors per disk `S` is greater than `1` and is always a multiple of `C`.
  - `S` is in the order of billions.
- The number of queries `Q` is in the order of millions.

## Input format

The first line of input has 5 items in this order: `T`, `N`, `C`, `S`, and `Q`. Follow `Q` lines, each with the queried sector number.

## Output format

For each query, print one line in the output. Each line has two or three numbers. The first number is the hard disk number (`[0,N-1]`) that contains the queried sector. If more than one disk has a copy of the queried sector, print the one with the smaller number (for RAID levels `1`, `01`, and `10`). The second number is the stripe (`[0,S-1]`) that contains the queried sector. The third number is the hard disk number (`[0,N-1]`) that contains the second copy of the queried sector for RAID levels `1`, `01`, and `10`, or the hard disk number (`[0,N-1]`) that contains the parity affected by the queried sector for RAID levels `4` and `5`.
