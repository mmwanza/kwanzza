#define N 4
#include <stdlib.h>
#include <stack>
#include <iostream>
int board[N][N];
int row;
int column;

//stack<Queen> s;
class Queen{
	int row;
	int column;
	public:
	Queen(int row,int column){
	this->row = row;
	this->column = column;
	}//end queen
};//end queen class	
std::stack<Queen> s;

//create a function that prints the output
void PrintQueens(int board[N][N]){
	for(int i = 0; i<N;i++){
		for(int j=0; j<N; j++){
			std::cout<< board[i][j]<<" ";
		}//end for
		std::cout<<"\n";
	}//end for
}//end printQueens

//create a function that checks each row and column and each direction
bool CheckQueens(int row, int column){
  int i,j,k,l;
	//create a check system to see if there are queens there
	//check if there is a queen on the left
	for(i =0; i< N; i++){
		if(board[row][i]==1){
			return false;	
			}//end for loop
		}//end for loop
		//this loop sees if there is a queen below on the left
	for(i=0; i<N; i++){
	    if(board[i][column]==1){
	        return false;
	    }
	}
	//iterate through each row and column to see if there is a queen diagonal
 for(i=row, j=column; i>=0 && j>=0; i--, j--){
        if(board[i][j]==1){
            return false;
        }
    }
    //diagonal check to the lower left
    for(i=row, j=column; j>=0 && i<N; i++, j--){
        if(board[i][j]==1){
            return false;
        }
    }
	Queen q(row,column);
	s.push(q);
	return true;
	
}//end bool


bool SolveQueen(int board[N][N],int column){
	int filled = 0;
	int i, j;
	int Position;
	    //iterate through the rows and collumns and place the queens
		for(int i = 0; i < N; i++){
			for(int j =0; j<N; j++){
				if(CheckQueens(i,j) == true){
				    if(j != Position){
				    board[i][j]=1;   
				    filled = filled + 1;
					Queen q(i,j);
					s.push(q);
					std::cout<<"\n";
					PrintQueens(board);
					std::cout<<"\n";
					}//end if
				}//end if
				}//end for
			}//end for
			//check if the board is full
			if(filled == N){
			    PrintQueens(board);
			       return true;
			}
			//filled = filled + 1;
			Position = - 1;
			i +=1;
	       		 j =0;
	  
		if(j >=N){
			s.pop();
			board[i][j]=0;
			filled = filled- 1;
			Position = j;
			Position+=1;
			std::cout<<"\n";
			PrintQueens(board);
			std::cout<<"\n";
			}//end if
			return true;
} 


			
int main(){
	for(int i=0; i<N;i++){
		for(int j = 0; j<N; j++){
			board[i][j] = 0;
		}//end for
	}//end for

	if(SolveQueen(board,0)==false){
		std::cout<<"No Queens";
		return false;
	}
	PrintQueens(board);
		
}
