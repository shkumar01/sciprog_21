## Practical 7
### Files
- `calculate_e.c` - Calculates the constant `e` using a polynomial expansion. The user can choose the order of the polynomial expansion used. 
- `dyn_array_fns.c` - Contains some function to explore the allocating, initializing, deleting of integer arrays dynamically. 
### Compiling and running 
```bash
# Compile
gcc -o calculate_e calculate_e.c -lm 
gcc -o dyn_array_fns dyn_array_fns.c 
# Run 
./calculate_e
./dyn_array_fns
```

In the practical pdf a question was asked that why does the estiamte for e get worse with higher order polynomials. Here's the output of the program for `order=20`
| Order       | Error       |
| ----------- | ----------- |
|0  | 1.71828182845904509080|
|1  | 0.71828182845904509080|
|2  | 0.21828182845904509080|
|3  | 0.05161516179237857216|
|4  | 0.00994849512571205352|
|5  | 0.00161516179237874979|
|6  | 0.00022627290348964380|
|7  | 0.00002786020507672404|
|8  | 0.00000305861777505356|
|9  | 0.00000030288585284310|
|10 |  0.00000002731266057765|
|11 |  0.00000000226055218988|
|12 |  0.00000000017287637988|
|13 |  -0.00000000034470781785|
|14 |  -0.00000000112660192286|
|15 |  -0.00000000162552682426|
|16 |  -0.00000000212448192372|
|17 |  0.00000000134145539121|
|18 |  0.00000000245450459957|
|19 |  -0.00000000666611033040|
|20 |  -0.00000000619040285699|

The estiamtes stop improving around the 13th order and then fluctates. I believe this is due to the way the factorial function is written in the tutorial code. The factorial function is said to return an integer, which is 4 bytes long, therefore the maximum value it can hold is `2^31-1 = 2,147,483,647`. The factorial of 13 `fact(13) = 6,227,020,800` is larger than this value. Thus it overflows. Therefore the factorial computed isn't accurate and therefore the estimate of `e` is impacted as well. If you use a type that hold higher value (e.g `long int`) for computing the factorial we see that the error goes down once again as the order increases.  
