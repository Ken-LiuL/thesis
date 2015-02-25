#include <iostream>
#include <string>
#include <cstdlib>

//define pieces
const int pawn = 100;
const int bishop = 305;
const int knight = 300;
const int rook  = 500;
const int queen = 900;
const int king = 2000;

//define board, the data type of board and piece must be the sane
int board[8][8];

//start up of the board
const int startup[8][8] = {rook, knight, bishop, queen, king, bishop, knight, rook, pawn, pawn,pawn,pawn,pawn,pawn,pawn, pawn, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -pawn, -pawn, -pawn, -pawn, -pawn, -pawn, -pawn, -pawn, -rook, -knight, -bishop, -queen, -king, -bishop, -knight, -rook};

//setup the board as the start
void setup(){
	int i,j;
	for (i=0;i<8;i++){
		for (j=0;j<8;j++)
			board[i][j] = startup[i][j];
	}
	
}

//display chess board graphically
//white as uppercase and black as lowercase 
void printb(){
	using namespace std;
	int a,b;
	string piece;
	for (a=7;a>-1;a--){
		cout << endl;
		for (b=0;b<8;b++){
			switch(board[a][b]){
				case 0:
				piece = "X";break;
				case pawn:
				piece = "P";break;
				case knight:
				piece = "K";break;
				case bishop:
				piece = "B";break;
				case rook:
				piece = "R";break;
				case queen:
				piece = "Q";break;
				case king:
				piece = "N";break;
				case -pawn:
				piece = "p";break;
				case -knight:
				piece = "n";break;
				case -bishop:
				piece = "b";break;
				case -rook:
				piece = "r";break;
				case -queen:
				piece = "q";break;
				case -king:
				piece = "k";break;
				
			}
			cout << " " << piece << " ";
		}
	}
	cout << endl << endl;
}


//main function
int main(){
	using namespace std;
	string command;
	setup();
	printb();
	
	while(1){
		getline(cin,command);
		if(command.substr(0,4)=="exit" || command.substr(0,5)=="abort" || command.substr(0,4) == "quit")
			break;
		if(command.substr(0,3)=="new"){
			setup();
			printb();
			continue;
		}	
		int a,b,c,d;
		a = command[0]-'a';
		b = command[1]-'1';
		c = command[2]-'a';
		d = command[3]-'1';
		cout << a << " " << b << " " << c <<" "<<d<<endl;
		board[d][c] = board[b][a];
		board[b][a] = 0;
		
		printb();
	}
}

