#include <iostream>
#include <string>
#include "minesweeper.h"

Minesweeper::Minesweeper(){}
Minesweeper::~Minesweeper(){
        for(int i = 0; i < mHeight; i++){
                delete[] mMap[i];
                delete[] playMap[i];
        }
        delete[] mMap;
        delete[] playMap;
}

void Minesweeper::dynAlloc(size_t w, size_t h){
        mMap = new string*[h];
        playMap = new string*[h];
        for(int i = 0; i < h; i++){
                mMap[i] = new string[w];
                playMap[i] = new string[w];
        }
}

bool Minesweeper::setMap(size_t _width, size_t _height, string**& _map){
        mWidth = _width;
        mHeight = _height;
        /*mMap = new string*[_height];
        playMap = new string*[_height];
        for(int i = 0; i < mHeight; i++){
                mMap[i] = new string[mWidth];
                playMap[i] = new string[mWidth];
        }*/
        for(int i = 0; i < _height; i++){
                for(int j = 0; j < _width; j++){
                        mMap[i][j] = _map[i][j];
                        playMap[i][j] = mMap[i][j];
                        if(_map[i][j] != "." && _map[i][j] != "*"){
                                onPlay = false;
                                return false;
                        }
                }
        }
        onPlay = true;
        return true;
        //return false when input is incorrect
}

bool Minesweeper::toggleMine(int _x, int _y){
        if(get(_x, _y) == ' '){
                return false;
        }
        if(playMap[_y][_x] != "*"){
                playMap[_y][_x] = "*";
        }
        else if(playMap[_y][_x] == "*"){
                playMap[_y][_x] = "0";
        }
        //Minesweeper a;
        return Minesweeper::setPlay();
        //return false when input is incorrect
}

size_t Minesweeper::width() const{
        return mWidth;
}

size_t Minesweeper::height() const{
        return mHeight;
}

char Minesweeper::get(int _x, int _y) const{
        if(_x >= mWidth || _y >= mHeight || _x < 0 || _y < 0){
                return ' ';
        }
        return ':';
        //return map width, height, and char, return ' ' if input is illegal
}

bool Minesweeper::setPlay(){
        if(onPlay == true){
                for(int i = 0; i < mHeight; i++){
                        for(int j = 0; j < mWidth; j++){
                                if(playMap[i][j] != "*"){
                                        int count = 0;
                                        if(i == 0){
                                                if(j != 0 && j != mWidth-1){
                                                        if(playMap[i][j-1] == "*"){
                                                                count++;
                                                        }
                                                        if(playMap[i][j+1] == "*"){
                                                                count++;
                                                        }
                                                        if(playMap[i+1][j-1] == "*"){
                                                                count++;
                                                        }
                                                        if(playMap[i+1][j] == "*"){
                                                                count++;
                                                        }
                                                        if(playMap[i+1][j+1] == "*"){
                                                                count++;
                                                        }
                                                }
                                                else if(j == 0){
                                                        if(playMap[i][j+1] == "*"){
                                                                count++;
                                                        }
                                                        if(playMap[i+1][j] == "*"){
                                                                count++;
                                                        }
                                                        if(playMap[i+1][j+1] == "*"){
                                                                count++;
                                                        }
                                                }
                                                else if(j == mWidth-1){
                                                        if(playMap[i][j-1] == "*"){
                                                                count++;
                                                        }
                                                        if(playMap[i+1][j-1] == "*"){
                                                                count++;
                                                        }
                                                        if(playMap[i+1][j] == "*"){
                                                                count++;
                                                        }
                                                }
                                        }
                                        else if(i == mHeight-1){
                                                if(j != 0 && j != mWidth-1){
                                                        if(playMap[i][j-1] == "*"){
                                                                count++;
                                                        }
                                                        if(playMap[i-1][j-1] == "*"){
                                                                count++;
                                                        }
                                                        if(playMap[i-1][j] == "*"){
                                                                count++;
                                                        }
                                                        if(playMap[i-1][j+1] == "*"){
                                                                count++;
                                                        }
                                                        if(playMap[i][j+1] == "*"){
                                                                count++;
                                                        }
                                                }
                                                else if(j == 0){
                                                        if(playMap[i-1][j] == "*"){
                                                                count++;
                                                        }
                                                        if(playMap[i-1][j+1] == "*"){
                                                                count++;
                                                        }
                                                        if(playMap[i][j+1] == "*"){
                                                                count++;
                                                        }
                                                }
						else if(j == mWidth-1){
                                                        if(playMap[i][j-1] == "*"){
                                                                count++;
                                                        }
                                                        if(playMap[i-1][j-1] == "*"){
                                                                count++;
                                                        }
                                                        if(playMap[i-1][j] == "*"){
                                                                count++;
                                                        }
                                                }
                                        }
                                        else if(j != 0 && j != mWidth-1){
                                                if(playMap[i-1][j-1] == "*"){
                                                        count++;
                                                }
                                                if(playMap[i-1][j] == "*"){
                                                        count++;
                                                }
                                                if(playMap[i-1][j+1] == "*"){
                                                        count++;
                                                }
                                                if(playMap[i][j-1] == "*"){
                                                        count++;
                                                }
                                                if(playMap[i][j+1] == "*"){
                                                        count++;
                                                }
                                                if(playMap[i+1][j-1] == "*"){
                                                        count++;
                                                }
                                                if(playMap[i+1][j] == "*"){
                                                        count++;
                                                }
                                                if(playMap[i+1][j+1] == "*"){
                                                        count++;
                                                }
                                        }
                                        else if(j == 0){
                                                if(playMap[i-1][j] == "*"){
                                                        count++;
                                                }
                                                if(playMap[i-1][j+1] == "*"){
                                                        count++;
                                                }
                                                if(playMap[i][j+1] == "*"){
                                                        count++;
                                                }
                                                if(playMap[i+1][j+1] == "*"){
                                                        count++;
                                                }
                                                if(playMap[i+1][j] == "*"){
                                                        count++;
                                                }
                                        }
                                        else if(j == mWidth-1){
                                                if(playMap[i-1][j] == "*"){
                                                        count++;
                                                }
                                                if(playMap[i-1][j-1] == "*"){
                                                        count++;
                                                }
                                                if(playMap[i][j-1] == "*"){
                                                        count++;
                                                }
                                                if(playMap[i+1][j-1] == "*"){
                                                        count++;
                                                }
                                                if(playMap[i+1][j] == "*"){
                                                        count++;
                                                }
                                        }
                                        playMap[i][j] = to_string(count);
                                }
                        }
                }
		//Minesweeper a;
                Minesweeper::printPlayMap();
                return true;
        }
        else{
                return false;
        }
        //return false when map is not set
}

/*
bool touchMap(int _x, int _y){
        //return true when dead
}

bool Minesweeper::touchCount(){

}
*/
void Minesweeper::printPlayMap() const{
        for(int i = 0; i < mHeight; i++){
                for(int j = 0; j < mWidth; j++){
                        cout << playMap[i][j];
                }
                cout << endl;
        }
}
