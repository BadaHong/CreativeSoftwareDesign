#include <iostream>
#include <string>
#include <vector>
#include "canvas.h"

using namespace std;

int main(){
        int col, row;
        cin >> col >> row;
        Canvas canvas(row, col);
        canvas.Print();
        vector<Shape*> object;
        vector<string> list;
        string input;
        while(1){
                cin >> input;
                if(input == "add"){
                        cin >> input;
                        if(input == "rect"){
                                int x, y, w, h;
                                char brush;
                                cin >> x >> y >> w >> h >> brush;
                                object.push_back(new Rectangle(x, y, w, h, brush));
                                list.push_back(" rect " + to_string(x) + " " + to_string(y) + " " + to_string(w) + " " + to_string(h) + " " + brush);
                        }
                        else if(input == "diamond"){
                                int x, y, d;
                                char brush;
                                cin >> x >> y >> d >> brush;
                                object.push_back(new Diamond(x, y, d, brush));
                                list.push_back(" diamond " + to_string(x) + " " + to_string(y) + " " + to_string(d) + " " + brush);
                        }
                        else if(input == "tri_up"){
                                int x, y, h;
                                char brush;
                                cin >> x >> y >> h >> brush;
                                object.push_back(new UpTriangle(x, y, h, brush));
                                list.push_back(" tri_up " + to_string(x) + " " + to_string(y) + " " + to_string(h) + " " + brush);
                        }
                        else if(input == "tri_down"){
                                int x, y, h;
                                char brush;
                                cin >> x >> y >> h >> brush;
                                object.push_back(new DownTriangle(x, y, h, brush));
                                list.push_back(" tri_down " + to_string(x) + " " + to_string(y) + " " + to_string(h) + " " + brush);
                        }
                }
                else if(input == "delete"){
                        int index;
                        cin >> index;
                        if(index < object.size()){
                                list.erase(list.begin() + index, list.begin()+index+1);
                                object.erase(object.begin() + index, object.begin()+index+1);
                        }
                }
                else if(input == "draw"){
                        canvas.Clear();
                        for(int i = 0; i < object.size(); i++){
                                object[i]->Draw(&canvas);
                        }
                        canvas.Print();
                }
                else if(input == "dump"){
                        for(int i = 0; i < object.size(); i++){
                                cout << i << list[i] << endl;
                        }
                }
                else if(input == "resize"){
                        int nW, nH;
                        cin >> nW >> nH;
                        canvas.Resize(nW, nH);
                }
                else if(input == "quit"){
                        break;
                }
        }
        return 0;
}

