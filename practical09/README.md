## Practical 9
### Files
- `magic_square.h` - given header file containing function that checks if a matrix is a magic square or not
- `check_magic_square_file_input.c` - Driver code to read in a matrix from a file and then use `magic_square.h` to check if the matrix is a magic square or not
- `check_magic_square_usr_input.c` - Same as above but input is given on the command line by user for the matrix. 
- `magic_square.txt` - Text file contaning a magic square to test `check_magic_square_file_input.c`
- `non_magic_square.txt` - Text file that does not contain a magic square to test `check_magic_square_file_input.c`
- 
```bash
# Compile
gcc -o check_magic_square_file_input check_magic_square_file_input.c
gcc -o check_magic_square_usr_input check_magic_square_usr_input.c
# Run 
./check_magic_square_file_input
./check_magic_square_usr_input
```

The practical pdf asks about the big-theta complexity of the algorithm in `isMagicSquare.h`. This is probably `Θ(n^2)` due to the double for loop needed to iterate over all the elements of the matrix
