#include <iostream>
#include "minesweeper.h"

using namespace std;

int main(){
        bool setmap, setplay, togMine;
        Minesweeper play;
        while(1){
                string start;
                cin >> start;
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
                        //cout << arr[0][0] << arr[0][3] << endl;
                        play.Minesweeper::dynAlloc(w, h);
                        setmap = play.Minesweeper::setMap(w, h, arr);
                        //play.Minesweeper::setMap(w, h, arr);
                        //cout << setmap << endl;
                        setplay = play.Minesweeper::setPlay();
                        //play.Minesweeper::setPlay();
                        //cout << setplay << endl;
                        for(int i = 0; i < h; i++){
                                delete[] arr[i];
                        }
                        delete[] arr;
                }
                else if(start == ":toggle"){
                        cin >> pos1 >> pos2;
                        togMine = play.Minesweeper::toggleMine(pos1, pos2);
                }
        }
        return 0;
}
