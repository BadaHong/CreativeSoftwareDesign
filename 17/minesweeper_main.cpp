Last login: Thu Oct  6 11:02:42 on console
badahong@Badaui-MacBookAir ~ % cd github
badahong@Badaui-MacBookAir github % ls
CreativeSoftwareDesign
badahong@Badaui-MacBookAir github % cd CreativeSoftwareDesign 
badahong@Badaui-MacBookAir CreativeSoftwareDesign % ls
10.cpp	11.cpp	12.cpp	13.cpp	14.cpp	15.cpp	16	8.cpp	9.cpp
badahong@Badaui-MacBookAir CreativeSoftwareDesign % vi 16.cpp































badahong@Badaui-MacBookAir CreativeSoftwareDesign % mkdir 17
badahong@Badaui-MacBookAir CreativeSoftwareDesign % ls  
10.cpp	11.cpp	12.cpp	13.cpp	14.cpp	15.cpp	16	16.cpp	17	8.cpp	9.cpp
badahong@Badaui-MacBookAir CreativeSoftwareDesign % vi 16.cpp












#include <iostream>
#include <string>
#include "minesweeper.h"

Minesweeper::Minesweeper(){}
Minesweeper::~Minesweeper(){
        for(int i = 0; i < mHeight; i++){
                delete[] mMap[i];
                delete[] playMap[i];
                delete[] tMap[i];
        }
        delete[] mMap;
        delete[] playMap;
        delete[] tMap;
}
/*
void Minesweeper::dynAlloc(size_t w, size_t h){
        mMap = new string*[h];
        playMap = new string*[h];
        for(int i = 0; i < h; i++){
                mMap[i] = new string[w];
                playMap[i] = new string[w];
        }
}*/

bool Minesweeper::setMap(size_t _width, size_t _height, string**& _map){
        mWidth = _width;
        mHeight = _height;
        mMap = new string*[_height];
        playMap = new string*[_height];
        tMap = new string*[_height];
        for(int i = 0; i < mHeight; i++){
                mMap[i] = new string[mWidth];
                playMap[i] = new string[mWidth];
                tMap[i] = new string[mWidth];
        }
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
"16.cpp" 300L, 13789B

