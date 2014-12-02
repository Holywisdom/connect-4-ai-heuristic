//
//  main.cpp
//  ISNELab2-14
//
//  Created by Thanongkiat Tamtai on 11/25/2557 BE.
//  Copyright (c) 2557 Thanongkiat Tamtai. All rights reserved.
//

#include <iostream>
using namespace std ;

    string ar[6][7] ;
    string copy[6][7] ;

void init(string ar[6][7]) {

    for(int i = 0 ; i< 6 ; i++) {
        
        for(int j =0 ; j < 7 ; j++) {
            
            ar[i][j] = " " ;
        }
    }
}

void draw(string ar[6][7]) {
    
    for(int i = 0 ; i< 6 ; i++) {
        cout << " " ;
        for(int j =0 ; j < 7 ; j++) {
            
            cout << ar[i][j] << " | " ;
        }
        
        cout << endl ;
    }
    
    cout << "--- --- --- --- --- --- ---" ;
    cout <<  endl ;
    
}

int checkempty(string ar[6][7],int pos) {
    
    int count = 0   ;
    
    for(int i = 0 ; i < 6 ; i++  ) {
        
        if(ar[i][pos] == "X" || ar[i][pos] == "O"  ){
            count++ ;
        }
    }
    
    count =  5 - count ;

    return count ;
}

string checkwin(string ar[6][7]) {
    
    
    for(int i = 0 ; i< 6 ; i++) {
        
        for(int j =0 ; j < 7 ; j++) {
            
            if(ar[i][j] != " ") {
                
                if(j<3) {
                    
                    if(ar[i][j]==ar[i][j+1]&&ar[i][j]==ar[i][j+2]&&ar[i][j]==ar[i][j+3]){
                        return ar[i][j] ;
                    }
                    
                    if(ar[i][j]==ar[i+1][j]&&ar[i][j]==ar[i+2][j]&&ar[i][j]==ar[i+3][j]){
                        return ar[i][j] ;
                    }
                    
                    if(i>2) {
                        
                        if(ar[i][j]==ar[i-1][j+1]&&ar[i][j]==ar[i-2][j+2]&&ar[i][j]==ar[i-3][j+3]){
                            return ar[i][j] ;
                        }
                    
                    }
                    
                    
                }
                
                if(j>3) {
                    
                    if(ar[i][j]==ar[i][j-1]&&ar[i][j]==ar[i][j-2]&&ar[i][j]==ar[i][j-3]){
                        return ar[i][j] ;
                    }
                    
                    if(ar[i][j]==ar[i+1][j]&&ar[i][j]==ar[i+2][j]&&ar[i][j]==ar[i+3][j]){
                        return ar[i][j] ;
                    }
                    
                    if(i>2) {
                        
                        if(ar[i][j]==ar[i-1][j-1]&&ar[i][j]==ar[i-2][j-2]&&ar[i][j]==ar[i-3][j-3]){
                            return ar[i][j] ;
                        }
                        
                    }
                    
                }
                
                if(j==3) {
                    
                    if(ar[i][j]==ar[i+1][j]&&ar[i][j]==ar[i+2][j]&&ar[i][j]==ar[i+3][j]){
                        return ar[i][j] ;
                    }
                    
                    if(i>2) {
                        
                        if(ar[i][j]==ar[i-1][j+1]&&ar[i][j]==ar[i-2][j+2]&&ar[i][j]==ar[i-3][j+3]){
                            return ar[i][j] ;
                        }
                        
                        if(ar[i][j]==ar[i-1][j-1]&&ar[i][j]==ar[i-2][j-2]&&ar[i][j]==ar[i-3][j-3]){
                            return ar[i][j] ;
                        }
                        
                    }

                    
                    
                }
                

                }
                
            }
                
        }
    return "n";
    }


void input (string ar[6][7]) {
    
    int pos, empty_pos = 0  ;
    
    cout << "Input number between 1-7 : " ;
    cin >> pos  ;
    
    pos = pos - 1 ;
    
    empty_pos = checkempty(ar, pos) ;
    
  //  cout << empty_pos <<  endl ;
    
    if(empty_pos==-1){
        cout << "This colum is full " << endl ;
    }
    
    else { ar[empty_pos][pos] = "X" ; }
    
}

int iii ;

void com_move (string ar[6][7]) {
    
    int empty_pos = 0  ;
    
    
    empty_pos = checkempty(ar, iii) ;
    
   //  cout << empty_pos <<  endl ;
    
    if(empty_pos==-1){
        cout << "This colum is full " << endl ;
    }
    
    else { ar[empty_pos][iii] = "O" ; }
    
}

int minimax(int depth, int d, bool maxturn) {
    string w = checkwin(ar);
    
    if (w=="O") return 1;
    else if(w=="X") return -1;
    
    if (d==0) {
        return 0;
    }
    
    if (maxturn) {
        int maxx = 0;
        for (int i=0;i<7;i++) {
            int j = checkempty(ar, i);
            if (j==-1) continue;
            ar[j][i] = "O";
            int tt = minimax(depth, d-1, !maxturn);
            maxx = max(maxx, tt);
            
            if (tt==maxx && depth==d) iii=i;
            
            if (depth==d) cout << " " << tt << " ";
            ar[j][i] = " ";
        }
        if (depth==d) cout << endl;
        return maxx;
    } else {
        int minn = 9999999;
        for (int i=0;i<7;i++) {
            int j = checkempty(ar, i);
            if (j==-1) continue;
            ar[j][i] = "X";
            int tt = minimax(depth, d-1, !maxturn);
            minn = min(minn, tt);
            
            ar[j][i] = " ";
        }
        return minn;
    }
}


int main(int argc, const char * argv[]) {
    

    init(ar) ;
    draw(ar) ;
    
    while (1) {

        input(ar);
        draw(ar) ;
        checkwin(ar) ;
        minimax(8, 8, true) ;
        com_move(ar);
        draw(ar) ;
    }
    
    return 0;
}
