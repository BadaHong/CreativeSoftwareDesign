#include <iostream>
#include "minesweeper.h"

using namespace std;

int main(){
        bool setmap, setplay, togMine, setplay2, touch;
        Minesweeper play;
        string start;
        cin >> start;
        while(1){
                if(start == ":quit"){
                        break;
                }
                size_t h, w;
                int pos1, pos2;
                if(start == ":set"){
                        cin >> w >> h;
                        string** arr = new string*[h];
                        for(int i = 0; i < h; i++){
                                arr[i] = new string[w];
                        }
                        for(int i = 0; i < h; i++){
                                for(int j = 0; j < w; j++){
                                        cin >> arr[i][j];
                                }
                        }
                        setmap = play.Minesweeper::setMap(w, h, arr);
                        setplay = play.Minesweeper::setPlay();
                        for(int i = 0; i < h; i++){
                                delete[] arr[i];
                        }
                        delete[] arr;
                }
                else if(start == ":play"){
                        setplay2 = play.Minesweeper::setPlay2();
                        cin >> start;
                        int set = 0;
                        while(1){
                                if(start == ":touch"){
                                        cin >> pos1 >> pos2;
                                        touch = play.Minesweeper::touchMap(pos1, pos2);
                                        if(touch == true){
                                                break;
                                        }
                                }
                                else{
                                        if(start == ":quit" || start == ":set"){
                                                set = 1;
                                                break;
                                        }
                                }
                                cin >> start;
                        }
                        if(set == 1){
                                continue;
                        }
                }
                else if(start == ":toggle"){
                        cin >> pos1 >> pos2;
                        togMine = play.Minesweeper::toggleMine(pos1, pos2);
                }
                cin >> start;
        }
        return 0;
}
