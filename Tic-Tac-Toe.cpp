#include<iostream>
using namespace std;

int winner(char grid[])
{
    if (grid[1] == grid[2] && grid[2] == grid[3])
        return 1;
    else if (grid[4] == grid[5] && grid[5] == grid[6])
        return 1;
    else if (grid[7] == grid[8] && grid[8] == grid[9])
        return 1;
    else if (grid[1] == grid[4] && grid[4] == grid[7])
        return 1;
    else if (grid[2] == grid[5] && grid[5] == grid[8])
        return 1;
    else if (grid[3] == grid[6] && grid[6] == grid[9])
        return 1;
    else if (grid[1] == grid[5] && grid[5] == grid[9])
        return 1;
    else if (grid[3] == grid[5] && grid[5] == grid[7])
        return 1;
    else if (grid[1] != '1' && grid[2] != '2' && grid[3] != '3' &&
             grid[4] != '4' && grid[5] != '5' && grid[6] != '6' &&
             grid[7] != '7' && grid[8] != '8' && grid[9] != '9')
        return 0;
    else
        return -1;
}

void board(char grid[],char sign1, char sign2)
{
	
	system("cls");
    cout << "\t\t\t\t\tWelcome to Tic-Tac-Toe!\n\n";
    
	cout<<"\nPlayer 1 is "<<sign1<<" and Player 2 is "<<sign2<<" !\n\n";
		
		for(int i= 1; i<=9; i+=3){
		cout << "	" << grid[i] << "	|	" << grid[i+1] << "	|	" << grid[i+2] << endl;

		}
    cout<<"\n\n\n";

}

void winbox(char sign1, char sign2, int player){
	
	system("cls");
    cout << "\t\t\t\t\tWelcome to Tic-Tac-Toe!\n\n";
    
	cout<<"\nPlayer 1 is "<<sign1<<" and Player 2 is "<<sign2<<" !\n\n";
	
	if(player == 1){
	
	for(int i= 1; i<=9; i+=3){
		
    cout << "	" << sign1 << "	|	" << sign1 << "	|	" << sign1 << endl;
	}
	
	cout<<"\n\n";
	}

	if(player==2){
		
	for(int i= 1; i<=9; i+=3){
	
	cout << "	" << sign2 << "	|	" << sign2 << "	|	" << sign2 << endl;
	}
	
	cout<<"\n\n";
	
	}
	
	cout << "\t\t  Player " <<player << " Won!\n\n";  
	cout<<"CONGRATULATIONS!!! \n\n";
    	
}
int main()
{
    int player = 1, i, choice,a;
    char mark;
    char repeat = 'y';
	char sign1,sign2;
   

while(repeat== 'y'){

	system("cls");
	char grid[10] = {'o','1','2','3','4','5','6','7','8','9'};

    cout << "\t\t\t\t\t\tWelcome to Tic-Tac-Toe!\n\n";
    
	cout<<"X\tOR\tO\n\nPlayer 1 choose your sign: ";
	cin>>sign1;

	if(sign1 == 'X'){	
		sign2 = 'O';
	}
	
	if(sign1 == 'O'){	
		sign2 = 'X';
	}
	
	if(sign1 != 'X'  && sign1!=  'O'){
		cout<<"\n\n\t\t\t\t\tYou have entered an INVALID choice!\n\n";
		break;
	}
		
		cout<<"\nPlayer 1 is "<<sign1<<" and Player 2 is "<<sign2<<" !\n\n";
    do {
       
	    board(grid,sign1,sign2);
        
        player = player % 2 ? 1 : 2;
        
        cout << "Player " << player << ", Enter a number to place your sign: ";
        cin >> choice;

        mark = (player == 1) ? sign1 : sign2;

        if (choice == 1 && grid[1] == '1')
        {
            grid[1] = mark;
        }
        else if (choice == 2 && grid[2] == '2')
        {
            grid[2] = mark;
        }
        else if (choice == 3 && grid[3] == '3')
        {
            grid[3] = mark;
        }
        else if (choice == 4 && grid[4] == '4')
        {
            grid[4] = mark;
        }
        else if (choice == 5 && grid[5] == '5')
        {
            grid[5] = mark;
        }
        else if (choice == 6 && grid[6] == '6')
        {
            grid[6] = mark;
        }
        else if (choice == 7 && grid[7] == '7')
        {
            grid[7] = mark;
        }
        else if (choice == 8 && grid[8] == '8')
        {
            grid[8] = mark;
        }
        else if (choice == 9 && grid[9] == '9')
        {
            grid[9] = mark;
        }
        
		else
        {
            cout << "INVALID MOVE \n";
            player--;
            cin.ignore();
            cin.get();
        }
        
        i = winner(grid);
        player++;
    } 
	while (i == -1);
	
    if (i == 1)
    {
    	--player;
        winbox(sign1, sign2,player);
    }
    
    else
    {
    	board(grid,sign1,sign2);
    cout << "\n\nThe Game is DRAW, WELL PLAYED! \n\n";
    }
     
    
    cout<<"Do you want to play again? \n\n";
    cout<<"Enter y for Yes and n for No: ";
    cin>>repeat;
   
    
}

    
return 0;
}