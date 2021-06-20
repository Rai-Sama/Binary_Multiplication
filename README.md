# Binary_Multiplication
This is my mini project for the course Computer Organization and Architecture (Sem-IV)

The project aims to implement unsigned binary multiplication in C

## Introduction
* Multiplication involves the generation of partial products, one for each digit in the multiplier. These partial products are then summed to produce the final product.
* For unsigned binary multiplication, the partial products are defined as: When the multiplier bit is 0, the partial product is 0. When the multiplier is 1, the partial product is the multiplicand.
* The total product is produced by summing the partial products. For this operation, each successive partial product is shifted one position to the left relative to the preceding partial product.
* The multiplication of two n-bit binary integers results in a product of up to 2n bits in length.
* Therefore, this multiplication uses n shifts and adds to multiply n-bit binary numbers. The combinational circuit implemented to perform such multiplication is called as an array multiplier or combinational multiplier.

## Flow
![Picture1](https://user-images.githubusercontent.com/48092867/122667372-322aca80-d1d0-11eb-9237-55387d4b04d4.png)

## Detailed logic
* Compared with the pencil-and-paper approach, there are several things we can do to make computerized multiplication more efficient. First, we can perform a running addition on the partial products rather than waiting until the end. This eliminates the need for storage of all the partial products; fewer registers are needed. Second, we can save some time on the generation of partial products. 
* For each 1 on the multiplier, an add and a shift operation are required; but for each 0, only a shift is required. 
* The multiplier and multiplicand are loaded into two registers (Q and M). A third register, the A register, is also needed and is initially set to 0. There is also a 1-bit C register, initialized to 0, which holds a potential carry bit resulting from addition. 
* The operation of the multiplier is as follows - 
  * Control logic reads the bits of the multiplier one at a time. 
  * If Q0 is 1, then the multiplicand is added to the A register and the result is stored in the A register, with the C bit used for overflow. 
  * Then all of the bits of the C, A, and Q registers are shifted to the right one bit, so that the C bit goes into An-1, A0 goes into Qn-1, and Q0 is lost.
  *  If Q0 is 0, then no addition is performed, just the shift. 
  *  This process is repeated for each bit of the original multiplier. The resulting 2n-bit product is contained in the A and Q registers. 
  *  If on the second cycle, the multiplier bit is 0, there is no add operation.
