# matrix-multiplication-in-C
I'm trying to study the pthread of C language here ༼ つ ◕_◕ ༽つ

## Explain 
First of all, let's talk about the definition. </br>
Let A be an m × n matrix, and B an n × p matrix </br>
Let C be the product of matrix A and B, which C = AB and C is m × p matrix </br></br>
<img src="https://user-images.githubusercontent.com/50576299/177719265-4586bad6-f581-4576-be96-16d6b89d9997.png" width="45%"> </br></br>
such that </br>
The entry of matrix C can compute by </br></br>
<img src="https://user-images.githubusercontent.com/50576299/177721552-8b7d056b-5234-4cff-bb41-ec9ea159f427.png" width="30%"> 
</br></br>

Time complexity of matrix multiplication will be O(m × n × p) </br>
but in this program i use square matrix therefore time complexity is O(n^3) where n is size of matrix

## How to use
This program i use g++ version 9.3.0 </br>
complie file with

```bash
$ make
```
and, run it
```bash
$ ./main
```
