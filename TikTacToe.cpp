#include <iostream>
# include <unistd.h>
using namespace std;
//Array for the board
char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
//Variable Declaration
int choice;
int row,column;
char turn = 'X';
bool draw = false;

//Function to show the current status of the gaming board

void display_board(){
	system("Color 0E");
	system("cls");
    cout<<"\t\t\t\t                      _                         "<<endl;                                                     
	        cout<<"\t\t\t\t   __      __   ___  | |   ___    ___    _ __ ___     ___  "<<endl;
		
			cout<<"\t\t\t\t   \\ \\ /\\ / /  / _ \\ | |  / __|  / _ \\  | '_ ` _ \\   / _ \\ "<<endl;
		
			cout<<"\t\t\t\t    \\ V  V /  |  __/ | | | (__  | (_) | | | | | | | |  __/ "<<endl;
		
			cout<<"\t\t\t\t     \\_/\\_/    \\___| |_|  \\___|  \\___/  |_| |_| |_|  \\___| "<<endl;
  
    cout<<"T I C K -- T A C -- T O E -- G A M E\t\t\t";
    cout<<"\n***** FOR 2 PLAYERS *****\n\n\n";
     
    cout<<"PLAYER - 1 [X]\t PLAYER - 2 [O]\n\n";
	cout<<"\t\t\t\t\t\t     |     |     \n";
    cout<<"\t\t\t\t\t\t  "<<board[0][0]<<"  | "<<board[0][1]<<"   |  "<<board[0][2]<<" \n";
    cout<<"\t\t\t\t\t\t ____|_____|____\n";
    cout<<"\t\t\t\t\t\t     |     |     \n";
    cout<<"\t\t\t\t\t\t  "<<board[1][0]<<"  | "<<board[1][1]<<"   |  "<<board[1][2]<<" \n";
    cout<<"\t\t\t\t\t\t ____|_____|____\n";
    cout<<"\t\t\t\t\t\t     |     |     \n";
    cout<<"\t\t\t\t\t\t  "<<board[2][0]<<"  | "<<board[2][1]<<"   |  "<<board[2][2]<<" \n";
    cout<<"\t\t\t\t\t\t     |     |     \n";
}
//Function to get the player input and update the board

void player_turn(){
    if(turn == 'X'){
        cout<<"\nPlayer - 1 [X] turn : ";
    }
    else if(turn == 'O'){
        cout<<"\nPlayer - 2 [O] turn : ";
    }
    //Taking input from user
    //updating the board according to choice and reassigning the turn Start

    cin>> choice;

    //switch case to get which row and column will be update

    switch(choice){
        case 1:
		 row=0; column=0; break;
        case 2:
		 row=0; column=1; break;
        case 3:
		 row=0; column=2; break;
        case 4:
		 row=1; column=0; break;
        case 5:
		 row=1; column=1; break;
        case 6:
		 row=1; column=2; break;
        case 7:
		 row=2; column=0; break;
        case 8:
		 row=2; column=1; break;
        case 9:
		 row=2; column=2; break;
        default:
            cout<<"Invalid Move\n";
    }

    if(turn == 'X' && board[row][column] != 'X' && board[row][column] != 'O'){
        //updating the position for 'X' symbol if
        //it is not already occupied
        board[row][column] = 'X';
        turn = 'O';
    }else if(turn == 'O' && board[row][column] != 'X' && board[row][column] != 'O'){
        //updating the position for 'O' symbol if
        //it is not already occupied
        board[row][column] = 'O';
        turn = 'X';
    }else {
        //if input position already filled
        cout<<"Box already filled!n Please choose another!!\n\n";
        player_turn();
    }
    /* Ends */
    display_board();
}

//Function to get the game status e.g. GAME WON, GAME DRAW GAME IN CONTINUE MODE

bool gameover(){
    //checking the win for Simple Rows and Simple Column
    for(int i=0; i<3; i++)
    if(board[i][0] == board[i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i])
    return false;

    //checking the win for both diagonal

    if(board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][2] == board[2][0])
    return false;

    //Checking the game is in continue mode or not
    for(int i=0; i<3; i++)
    for(int j=0; j<3; j++)
    if(board[i][j] != 'X' && board[i][j] != 'O')
    return true;

    //Checking the if game already draw
    draw = true;
    return false;
}
struct Feedback {
    char name[100];
    int rating;
    char comments[200];
};

class SimpleQueue {
private:
    static const int MAX_SIZE = 100;
    Feedback data[MAX_SIZE];
    int frontIndex;
    int rearIndex;

public:
    SimpleQueue() : frontIndex(-1), rearIndex(-1) {}

    bool push(const Feedback& feedback) {
        if ((rearIndex + 1) % MAX_SIZE == frontIndex) {
            cout << "Queue overflow!\n";
            return false;
        }
        if (frontIndex == -1) {
            frontIndex = rearIndex = 0;
        } else {
            rearIndex = (rearIndex + 1) % MAX_SIZE;
        }
        data[rearIndex] = feedback;
        return true;
    }

    Feedback front() {
        if (frontIndex == -1) {
            cout << "Queue is empty!\n";
            return {};
        }
        return data[frontIndex];
    }

    void pop() {
        if (frontIndex == -1) {
            cout << "Queue is empty!\n";
            return;
        }
        if (frontIndex == rearIndex) {
            frontIndex = rearIndex = -1;
        } else {
            frontIndex = (frontIndex + 1) % MAX_SIZE;
        }
    }

    bool empty(){
        return frontIndex == -1;
    }
};

class SimpleStack {
private:
    static const int MAX_SIZE = 100;
    Feedback data[MAX_SIZE];
    int topIndex;

public:
    SimpleStack() : topIndex(-1) {}

    bool push(const Feedback& feedback) {
        if (topIndex >= MAX_SIZE - 1) {
            cout << "Stack overflow!\n";
            return false;
        }
        data[++topIndex] = feedback;
        return true;
    }

    Feedback top() {
        if (topIndex < 0) {
            cout << "Stack is empty!\n";
            return {};
        }
        return data[topIndex];
    }

    void pop() {
        if (topIndex >= 0) {
            topIndex--;
        } else {
            cout << "Stack is empty!\n";
        }
    }

    bool empty() const {
        return topIndex < 0;
    }
};

void feedbackSystem() {
    SimpleQueue feedbackQueue;

    Feedback userFeedback;

    cout << "Enter your name: ";
    cin.ignore(); // Ignore any previous newline characters
    cin.getline(userFeedback.name, sizeof(userFeedback.name));

    cout << "Rate your experience (1-5): ";
    while (!(cin >> userFeedback.rating) || userFeedback.rating < 1 || userFeedback.rating > 5) {
        cout << "Invalid input. Please enter a number between 1 and 5: ";
        cin.clear(); // Clear the error state
    }
    cin.ignore(); // Ignore the newline character left in the input buffer

    cout << "Add comments (optional): ";
    cin.getline(userFeedback.comments, sizeof(userFeedback.comments));

    feedbackQueue.push(userFeedback);
    

    cout << "\n\n****************************************************";
    cout << "\n*     Thank you for your valuable feedback, " << userFeedback.name << "!\n";
    cout << "*     Rating: " << userFeedback.rating << endl;
    cout << "*     Comments: " << userFeedback.comments << endl;
    cout << "****************************************************";
}


//Program Main Method

int main()

{   
    while(gameover()){
        display_board();
        player_turn();
        gameover();
    }
   cout<<"                     ,---.           ,---.   "<<endl;
	usleep(150000);
cout<<"                    / /^`.\\.--''''-./,'^\\ \\	"<<endl;
	usleep(150000);
cout<<"                    \\ \\    _       _    / /	"<<endl;
	usleep(150000);
cout<<"                     `./  / __   __ \\  \\,'	"<<endl;
	usleep(150000);
cout<<"                      /    /_O)_(_O\\    \\	"<<endl;
	usleep(150000);
cout<<"                      |  .-'  ___  `-.  |	"<<endl;
	usleep(150000);
cout<<"                   .--|       \\_/       |--.	"<<endl;
	usleep(150000);
cout<<"                 ,'    \\   \\   |   /   /    `."<<endl;
	usleep(150000);
cout<<"                /       `.  `--^--'  ,'       \\"<<endl;
cout<<"              .-^^^^^-.    `--.___.--'     .-^^^^^-."<<endl;
	usleep(150000);
cout<<".-----------/         \\------------------/         \\--------------"<<endl;
	usleep(150000);
cout<<"| .---------\\         /------------------\\         /------------. |"<<endl;
	usleep(150000);
cout<<"| |          `-`--`--'                    `--'--'-'             | |"<<endl;             
	usleep(150000);
cout<<"| |";if(turn == 'X' && draw == false)
{ cout<<"Congratulations!Player with 'O' has won the game";}
 else if(turn == 'O' && draw == false)
 { cout<<"Congratulations!Player with 'X' has won the game";}
 else 
 cout<<"GAME DRAW!!!";
	usleep(150000);
cout<<"             | |"<<endl;
	usleep(150000);
cout<<"| |                                                             | |"<<endl;
	usleep(150000);
cout<<"| |_____________________________________________________________| |"<<endl;
	usleep(150000);
cout<<"|_________________________________________________________________|"<<endl;
	usleep(150000);
cout<<"                   )__________|__|__________("<<endl;
	usleep(150000);
cout<<"                  |            ||            |"<<endl;
	usleep(150000);
cout<<"                  |____________||____________|"<<endl;
	usleep(150000);
cout<<"                    ),-----.(      ),-----.("<<endl;
	usleep(150000);
cout<<"                  ,'   ==.   \\    /  .==    `."<<endl;
	usleep(150000);
cout<<"                 /            )  (            \\"<<endl;
	usleep(150000);
cout<<"                 `==========='    `==========='  "<<endl;
feedbackSystem();
}

