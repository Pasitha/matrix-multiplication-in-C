# matrix-multiplication-in-C
I'm trying to study the pthread of C language here ༼ つ ◕_◕ ༽つ

## Explan
First of all let's talk about what is matrix multiplication </br>
Let A is m × n matrix, B is n × p matrix </br>
Let C is product of matrix A, B which mean C = AB and C is m × p matrix </br>
<img src="https://user-images.githubusercontent.com/50576299/177719265-4586bad6-f581-4576-be96-16d6b89d9997.png" width="45%"> </br>
such that </br>
The entry of matrix c can compute by </br>
<img src="https://user-images.githubusercontent.com/50576299/177721552-8b7d056b-5234-4cff-bb41-ec9ea159f427.png" width="30%"> 
</br></br>

Time complexity of matrix multiplication will be O(m × n × p) </br>
but in this program i use square matrix therefore time complexity is O(n^3) where n is size of matrix
