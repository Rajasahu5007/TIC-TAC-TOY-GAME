// this is project number 3 which is (tic tac toy) game...

#include<iostream>
#include<cstdlib>
using namespace  std;
void initilize_board(char TTT[3][3]);
void Display_Board(char TTT[3][3]);
void play_Game(char TTT[3][3],char  player_sign[2]);
bool illigalmove(char TTT[3][3],int row,int col);
/// @brief 
/// @param TTT 
/// @return 
bool winning_condition_check(char TTT[3][3]);
bool draw_condition(char TTT[3][3]);
int main(){
    char TTT[3][3];
    char response;
    do{
    initilize_board(TTT);
    Display_Board(TTT);

    char player_sign[2]={'x','o'};
    play_Game(TTT,player_sign);
    cout<<"do you want to play again? (y/n):";
    cin>>response;
    }while(response=='y' || response =='y' );
    return 0;
}

void initilize_board(char TTT[3][3]){


    for(int ri=0;ri<3;ri++){
        for(int ci=0;ci<3;ci++){
            TTT[ri][ci]= '_';
        }
    }
}
void Display_Board(char TTT[3][3]){
    for(int ri=0;ri<3;ri++){
        for(int ci=0;ci<3;ci++){
            cout<<TTT[ri][ci]<<" ";
        }
        cout<<endl;
    }
}

void play_Game(char TTT[3][3],char  player_sign[2]){
    //generating random number for turns of player first turm.
int random=rand()%2;
int player_turn=random;
bool draw_condition_var = false;

//win----draw;
for(; winning_condition_check(TTT) && draw_condition_var != true ;){
    cout<<"enter row and collumn number on which you want to  put"<<endl;
    cout<<"player->"<<player_turn + 1 <<"turn->";
    int row=0,col=0;
    // -  -  -
    // -  -  -
    // -  -  -
    
    cin>>row;
    cin>>col;
    row--;
    col--;
if(illigalmove(TTT,row,col)){
    TTT[row][col] = player_sign[player_turn];
    if(player_turn == 1){
        player_turn--;
    }
    else{
        player_turn++;
    }
    system("CLS");
Display_Board(TTT);
}
else{
    do{
        system("CLS");
        Display_Board(TTT);
    cout<<"------------------->>>>>>>>>illigle move<<<<<<<<<<<<<<"<<endl;
    cout<<"------------------->>>>>>>>>illigle move<<<<<<<<<<<<<<"<<endl;
    cout<<"------------------->>>>>>>>>illigle move<<<<<<<<<<<<<<"<<endl;
    cout<<"------------------->>>>>>>>>illigle move<<<<<<<<<<<<<<"<<endl;
    cout<<"enter row and collumn number on which you want to  put your sign with a spech:"<<endl;
    cout<<"player->"<<player_turn + 1 <<"turn->";
    cin>>row;
    cin>>col;
    row--;
    col--;
    
}while(!illigalmove(TTT,row,col));
  TTT[row][col]=player_sign[player_turn];
  if(player_turn == 1)
  {
    player_turn--;
  }
  else{
    player_turn++;
  }

system("CLS");
Display_Board(TTT);

}
 if(draw_condition(TTT)){
draw_condition_var = true;
 }

}

if(draw_condition_var == true){
    system("CLS");
Display_Board(TTT);
    cout<<">>>>>>>>>>GAME - DRAW<<<<<<<<<"<<endl;
}
else{
      if(player_turn == 1)
  {
    player_turn--;
  }
  else{
    player_turn++;
  }

system("CLS");
Display_Board(TTT);
cout<<"THE GAME HAS WON BY PLAYER->"<<player_turn+1<<endl;
    
}

}
bool illigalmove(char TTT[3][3],int row,int col){
    if(TTT[row][col] == '_'){
        return true;
    }
    return false;
}
bool winning_condition_check(char TTT[3][3]){
    //player - 1 winiig conditio
//sign -> 'x'
    //HORIZONTAL CONDITION
     if(TTT[0][0]=='x' && TTT[0][0] == TTT[0][1] && TTT[0][1]==TTT[0][2]){
     //player -1 wins
     return false;
}
else if(TTT[1][0]=='x' && TTT[1][0] == TTT[1][1] && TTT[1][1]==TTT[1][2]){
    return false;
}
else if(TTT[2][0]=='x' && TTT[2][0] == TTT[2][1] && TTT[2][1]==TTT[2][2]){
    return false;
}

//vertical  CONDITION
else if(TTT[0][0]=='x' && TTT[0][0] == TTT[1][0] && TTT[1][0]==TTT[2][0]){
     //player -1 wins
     return false;
}
else if(TTT[0][1]=='x' && TTT[0][1] == TTT[1][1] && TTT[1][1]==TTT[2][1]){
    return false;
}
else if(TTT[0][2]=='x' && TTT[0][2] == TTT[1][2] && TTT[1][2]==TTT[2][2]){
    return false;
}
//Digonal condition
else if(TTT[0][0]=='x' && TTT[0][0] == TTT[1][1] && TTT[1][0]==TTT[2][2]){
     //player -1 wins
     return false;
}
else if(TTT[0][2]=='x' && TTT[0][2] == TTT[1][1] && TTT[1][1]==TTT[2][0]){
     //player -1 wins
     return false;
     }

//player - 2 winiig conditio
//sign -> 'o'
    //HORIZONTAL CONDITION
     if(TTT[0][0]=='o' && TTT[0][0] == TTT[0][1] && TTT[0][1]==TTT[0][2]){
     //player -1 wins
     return false;
}
else if(TTT[1][0]=='o' && TTT[1][0] == TTT[1][1] && TTT[1][1]==TTT[1][2]){
    return false;
}
else if(TTT[2][0]=='o' && TTT[2][0] == TTT[2][1] && TTT[2][1]==TTT[2][2]){
    return false;
}

//vertical  CONDITION
else if(TTT[0][0]=='o' && TTT[0][0] == TTT[1][0] && TTT[1][0]==TTT[2][0]){
     //player -1 wins
     return false;
}
else if(TTT[0][1]=='o' && TTT[0][1] == TTT[1][1] && TTT[1][1]==TTT[2][1]){
    return false;
}
else if(TTT[0][2]=='o' && TTT[0][2] == TTT[1][2] && TTT[1][2]==TTT[2][2]){
    return false;
}
//Digonal condition
else if(TTT[0][0]=='o' && TTT[0][0] == TTT[1][1] && TTT[1][0]==TTT[2][2]){
     //player -1 wins
     return false;
}
else if(TTT[0][2]=='o' && TTT[0][2] == TTT[1][1] && TTT[1][1]==TTT[2][0]){
 return false;
}
}

bool draw_condition(char TTT[3][3]){
    for(int ri=0;ri<3;ri++){
        for(int ci=0;ci<3;ci++){
            if(TTT[ri][ci]=='_'){
                return false;
            }

    }
}
return true;
}