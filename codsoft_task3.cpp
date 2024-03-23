#include<iostream>
using namespace std;

char board[3][3];
char currentPlayer='X';


//function initiate the board
void initialize_the_board(){
	for(int i=0;i<3;++i){
		for(int j=0;j<3;++j){
			board[i][j]= ' ';
		}
	}
}

//function to display current state of the board
void display_the_board(){
	cout<<"-------------"<<endl;
	for(int i=0; i<3; ++i){
		cout<<"| ";
		for(int j=0;j<3;++j){
			cout<<board[i][j]<<" | ";
		}
	cout<<endl<<"-------------"<<endl;
	}
}

//funtion to check if current player won
bool check_win(){
	for (int i = 0; i < 3; ++i) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return true;
    }
    for (int j = 0; j < 3; ++j) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ')
            return true;
        
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return true;
    
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return true;
    return false;
}

bool check_draw(){
	for (int i=0; i<3;++i){
		for (int j=0;j<3;j++){
		if(board[i][j]==' ')
			return false;
		
	}
	}
	return true;
}

void switchPlayer(){
	currentPlayer= (currentPlayer=='X')? 'O':'X';
}

void playersMove(){
    int row,col;
	cout<<"Player "<<currentPlayer<<" Kindly enter your move according to the direction(row space column): ";
	cin>>row>>col;
	
	while(row<0 || row>2 ||col<0 || col>2 || board[row][col] != ' '){
		cout<<"Please enter again as the entered move is invalid";
		cin>>row>>col;
	}
	 board[row][col] = currentPlayer;
}

int main(){
    cout<<"WELCOME TO THE GAME OF TIC TAC TOE!"<<endl;
    cout<<"In the given game the respective rows and columns starts from 0"<<endl;
    cout<<"if u want row1 or column1=input the value as 0 "<<endl;
	cout<<"if u want row2 or column2=input the value 1"<<endl;
	cout<<"if u want row3 or colum3=input the value as 2"<<endl;
	
	initialize_the_board();
	display_the_board();
	
	//the main game
	while(true){
		playersMove();
		display_the_board();
		
		if (check_win()){
			cout<<"Player"<<currentPlayer<<" wins the game"<<endl;
			break;
		}
		if(check_draw()){
			cout<<" Oh! Its a darw!"<<endl;
			break;
		}
		switchPlayer();
	}
	//ask user if wants to play again
	char playAgain;
	cout<<"Do you wish to play again(y/n)";
	cin>>playAgain;
	if(playAgain == 'n' || playAgain=='N'){
	    cout<<"Game Over!";
	}
	else if (playAgain == 'y' || playAgain=='Y'){
	    main(); //restart the game
	}
	return 0;
}
	

