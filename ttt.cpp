#include <iostream>
#include <vector>
#include <string>

bool ffull (std::vector <char> c_s){  //tested
        for (int i=0; i<9; i++){
            if (c_s[i]==' '){return false;}
        }
        return true;
    }
bool string_in_vector(std::string str,std::vector <std::string> vec){
    for (int i=0;i<vec.size();i++){
        if (vec[i]==str){return true;}
    }
    return false;
}

bool if_first_won (std::vector <char> c_s){
        if((c_s[0]=='x' && c_s[1]=='x' &&c_s[2]=='x') || (c_s[3]=='x' && c_s[4]=='x' && c_s[5]=='x') || 
        (c_s[6]=='x' && c_s[7]=='x' &&c_s[8]=='x') || (c_s[0]=='x' && c_s[3]=='x' &&c_s[6]=='x') ||
        (c_s[1]=='x' && c_s[4]=='x' &&c_s[7]=='x') || (c_s[2]=='x' && c_s[5]=='x' &&c_s[8]=='x')  ||
        (c_s[0]=='x' && c_s[4]=='x' &&c_s[8]=='x') || (c_s[2]=='x' && c_s[4]=='x' &&c_s[6]=='x')) {
            return true;
        }
        return false;
    }
bool if_second_won (std::vector <char> c_s){ 
    if((c_s[0]=='0' && c_s[1]=='0' &&c_s[2]=='0') || (c_s[3]=='0' && c_s[4]=='0' && c_s[5]=='0') || 
    (c_s[6]=='0' && c_s[7]=='0' &&c_s[8]=='0') || (c_s[0]=='0' && c_s[3]=='0' &&c_s[6]=='0') ||
    (c_s[1]=='0' && c_s[4]=='0' &&c_s[7]=='0') || (c_s[2]=='0' && c_s[5]=='0' &&c_s[8]=='0')  ||
    (c_s[0]=='0' && c_s[4]=='0' &&c_s[8]=='0') || (c_s[2]=='0' && c_s[4]=='0' &&c_s[6]=='0')) {
        return true;
    }
    return false;
}
int end_of_game (std::vector <char> c_s){
    int u=0;
    if (if_first_won(c_s)){ u=1;}
    else if (if_second_won(c_s)){u=2;}
    else if (ffull(c_s)){u=3;}
    else {u=0;}
    return u;
}
int get_number_of_square(std::string code1){
    if (code1=="a1"){return 6;}
    else if (code1=="a1"){return 6;}
    else if (code1=="a2"){return 3;}
    else if (code1=="a3"){return 0;}
    else if (code1=="b1"){return 7;}
    else if (code1=="b2"){return 4;}
    else if (code1=="b3"){return 1;}
    else if (code1=="c1"){return 8;}
    else if (code1=="c2"){return 5;}
    else if (code1=="c3"){return 2;}
    return 9;
}
int turn (int player_number, std::vector <char> b){
    std::vector <std::string> possible_options={"a1","a2","a3","b1","b2","b3","c1","c2","c3"};
    std::vector <std::string> player={" "," "};
    bool cond1=false; bool cond2=false;
    char j;
    switch (player_number){
        case 0:
            j='x';
            break;
        case 1:
            j='0';
            break;
    }
    std::cout<<"Player "<<player_number<<"(\""<<j<<"\")"<<", your turn:";
    while (cond1==false || cond2==false){
        cond1=false;
        cond2=false;
        std::cin>>player[player_number];
        for (int k=0;k<player[player_number].size();k++){
            player[player_number][k]=tolower(player[player_number][k]);
        }
        cond1=(string_in_vector(player[player_number],possible_options));
        if (!cond1){
            std::cout<<"Wrong square code!\n";  
        }    
        else { 
            if(b[get_number_of_square(player[player_number])]!=' '){
                std::cout<<"This square is occupied!\n";
            } else {cond2=true;} 

        }
        
    }
    return get_number_of_square(player[player_number]);
} 
void board(std::vector<char> b){
    std::cout<<"  -------------\n";
    std::cout<<"3 | "<<b[0]<<" | "<<b[1]<<" | "<<b[2]<<" |\n";
    std::cout<<"  -------------\n";
    std::cout<<"2 | "<<b[3]<<" | "<<b[4]<<" | "<<b[5]<<" |\n";
    std::cout<<"  -------------\n";
    std::cout<<"1 | "<<b[6]<<" | "<<b[7]<<" | "<<b[8]<<" |\n";
    std::cout<<"  -------------\n";
    std::cout<<"    a   b   c\n";
}

int main(){
    char c='y';
    while (c!='n'){
        std::vector <char> b={' ',' ',' ',' ',' ',' ',' ',' ',' '};
        while (end_of_game(b)==0){
            board (b);
            b[turn(0,b)]='x';
            board(b);
            if (end_of_game(b)==0){
                b[turn(1,b)]='0';

        }
        }
        switch (end_of_game(b)){
            case 1:
                std::cout<<"First (\"x\") won\n";
                break;
            case 2:
                std::cout<<"Second (\"0\") won\n";
                break;
            case 3:
                std::cout<<"Draw\n";
                break;
        }    
        c='q';
        while (c!='y' && c!='n'){
            std::cout<<"Next game? y/n ";
            std::cin>>c;
        }
    }
}