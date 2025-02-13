//井字游戏

#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

//分类思想，弄清楚每个情况

bool win(vector<string> &board, string flag){
    for(int i=0; i<3; i++){
        //纵向三连
        string col;
        col += board[0].at(i)+board[1].at(i)+board[2].at(i);
        if(!flag.compare(col)){ //compare比较相等返回的是0；
            return true;
        }

        //横向三连
        if (!flag.compare(board[i])){
            return true;
        }
    }
    //主对角线三连
    string diag1;
    diag1+=board[0].at(0)+board[1].at(1)+board[2].at(2);
    if(!flag.compare(diag1)){
       return true;
    }
    //反角线三连
    string diag2;
    diag2+=board[0].at(2)+board[1].at(1)+board[2].at(0);
    if(!flag.compare(diag2)){
        return true;
    }
    return false;
}

bool validBoard(vector<string> &board){
    //x赢了         x-o=1       xxx
    //o赢了         x-o=0       ooo
    //胜负未分      x-o=1或者0
    int xCount=0, oCount=0;
    for (auto row : board){
        for (auto c : row){
            if(c=='x') xCount++;
            if(c=='o') oCount++;
        }
    }
    if(xCount != oCount && xCount-oCount!=1) return false;
    bool xWin = win(board, "xxx");
    bool oWin = win(board, "ooo");
    if (xWin&&oWin) return false;//不可能同时赢
    //x赢了但是两者棋数相等
    if(win(board, "xxx") && xCount-oCount!=1)   return false;
    //o赢了但是两者棋数差一
    if(win(board, "ooo") && xCount-oCount!=0)   return false;
    return true;
}


int main()
{
    vector<string> well = {"xxx","oxo","  o"};
    cout <<( validBoard(well)?"true":"false" )<<endl;
}