#include<iostream>
using namespace std;
class TicTacToe{
	public:
	char list[10];
	    void print_board(){
			cout <<\
			"     ▇▇     ▇▇     \n"\
			"  "<<list[0]<<"  ▇▇  "<<list[1]<<"  ▇▇  "<<list[2]<<"   \n"\
			"     ▇▇     ▇▇     \n"\
			"▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇\n"\
			"     ▇▇     ▇▇     \n"\
			"  "<<list[3]<<"  ▇▇  "<<list[4]<<"  ▇▇  "<<list[5]<<"   \n"\
			"     ▇▇     ▇▇     \n"\
			"▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇\n"\
			"     ▇▇     ▇▇     \n"\
			"  "<<list[6]<<"  ▇▇  "<<list[7]<<"  ▇▇  "<<list[8]<<"   \n"\
			"     ▇▇     ▇▇     \n\n";
		}
    	void run() {
	    	int input;
    		int player = 1;
    		for(int i = 1; i < 10; i++) {
    			list[i-1] = i+'0';
    		}
    		for(int count = 0; count < 9; count++) {
	    		cout << "\n\n-- Tic Tac Toe -- CSIE@CGU\nPlayer 1 (x)  -  Player 2 (O)\n\n";
		    	print_board();
		    	cout<<"Player "<<player<<", please input a number in range \"1~9\":  ";
		    	while(cin >> input) {
			    	if(list[input-1] < '1' or list[input-1] >'9') {
						cout << "\nwrong input, please input a number: ";
						cin >> input;
					}else if(list[input-1]-'0' != input) {
						cout << "\nthe number has been used, please input another number: ";
						cin >> input;
	    			}else{
		    			break;
			    	}
    			}
    			if(player == 1) {
	    			list[input-1] = 'X';
		    	} else{
			    	list[input-1] = 'O';
    			}
	    		if(((list[0] == list[1]) and (list[1] == list[2])) or\
		    	   ((list[3] == list[4]) and (list[4] == list[5])) or\
	    		   ((list[6] == list[7]) and (list[7] == list[8])) or\
    			   ((list[0] == list[3]) and (list[3] == list[6])) or\
	    		   ((list[1] == list[4]) and (list[4] == list[7])) or\
		    	   ((list[2] == list[5]) and (list[5] == list[8])) or\
		    	   ((list[0] == list[4]) and (list[4] == list[8])) or\
    			   ((list[2] == list[4]) and (list[4] == list[6]))) {
	    			if(player == 1) {
					cout << "\n\n-- Tic Tac Toe -- CSIE@CGU\nPlayer 1 (x)  -  Player 2 (O)\n\n";
		    	        print_board();
		    			cout << "==> Player 1 win";
			    		return;
					}else {
					cout << "\n\n-- Tic Tac Toe -- CSIE@CGU\nPlayer 1 (x)  -  Player 2 (O)\n\n";
		    	        print_board();
    					cout << "==> Player 2 win";
	    				return;
			    	}
	    		}
		    	if(count == 8) {
			    	cout << "\n\n-- Tic Tac Toe -- CSIE@CGU\nPlayer 1 (x)  -  Player 2 (O)\n\n";
    				print_board();
    				cout << "==> Game draw";
	    			return;
		    	} else if(player==1){
			    	player=2;
    			} else {
	    			player=1;
		    	}
	    	}
    	}
};

int main() {
	TicTacToe game;
	game.run();
	return 0;
}
