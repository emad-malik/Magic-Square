#include<iostream>
using namespace std;
void SquareMagic(int**, int); //protoype
void SquareMagic(int **magic_sq, int squareDim) //header
{
  int tuples= 0, attributes= squareDim/2, dim_sqr= squareDim * squareDim;
  for (int iter= 1; iter <= dim_sqr; iter++) 
  {
    magic_sq[tuples][attributes] = iter;
    tuples--;
    attributes++;
    if(iter % squareDim== 0) //this condition checks that numbers are not going out of bounds of the square.
    {
        //this is done to place the number two rows below and one one column to the left as per the algorithm
        tuples+= 2;
        attributes--;
    } 
    else 
    {
        if(attributes== squareDim) //if col value is equals to squareDim, it is changed to 0. 
        {
             //this is to ensure that numbers dont go out of the bounds of the square
            attributes= 0;
        } 
        else if(tuples < 0) //if row value is -ve, it is changed to squareDim-1, to ensure that numbers dont go out of the bounds of the square
        {
            tuples= squareDim - 1;
        }
    }
  }   
}
int main() 
{
  int squareDim= 0;
  cout<<"Enter the dimension of the magic square: ";
  cin>>squareDim;
  //dynamically allocating nxn size square to play with. 
  //Using double pointer
  int **magic_sq= new int*[squareDim];
  for (int i= 0; i<squareDim; i++) 
  {
    magic_sq[i]= new int[squareDim];
  }
  SquareMagic(magic_sq, squareDim); //calling the function which solves the magic square
  cout <<"A square whose sum of rows, columns, and both of the diagonals results in the same number is called Magic Square."<<endl;
  cout<<"A magic square of "<<squareDim<<"X"<<squareDim<<" dimensions is being printed below: "<<endl;
  for(int i = 0; i<squareDim; i++)
  {
    for(int j= 0; j<squareDim; j++) 
    {
        cout<<magic_sq[i][j]<<" ";
    }
    cout<<endl;
  }
  //FREEING the dynamically allocated memory
  for(int free= 0; free<squareDim; free++)
        delete[] magic_sq[free];
    
    delete[] magic_sq;
  return 0;
}
