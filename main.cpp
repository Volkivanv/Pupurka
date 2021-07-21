#include <iostream>
//#include <vector>
//#include <string>
using namespace std;

void inputMatrix( bool m[][12]){
    for(int i = 0; i < 12; i++){
        for(int j = 0; j < 12; j++){
            m[i][j] = true;
        }
    }
}


int outputMatrix( bool m[][12]){
    int popped = 0;
    for(int i = 0; i < 12; i++){
        for(int j = 0; j < 12; j++){
            if(m[i][j]){
                cout << "o" <<" ";
            } else {
                cout << "x" <<" ";
                popped++;
            }
        }
        cout << endl;
    }
    return popped;
}

void pop(bool m[][12],int x1, int y1, int x2, int y2){
    for(int i = y1; i <= y2; i++){
        for(int j = x1; j <= x2; j++){
            if(m[i][j]) cout << "Pop!" << endl;
            m[i][j] = false;
        }
    }

}

int main() {
    bool massA[12][12];
    int popp;
    int x1,x2,y1,y2;

    cout << " matrix A"<< endl;
    inputMatrix(massA);
    popp = outputMatrix(massA);
    while(popp < 144) {
        cout << "Input coordinates x1,y1,x2,y2!" << endl;
        cin >> x1 >> y1 >> x2 >> y2;
        if((x1 >= 0)&&(x1 < 12)&&(y1 >= 0)&&(y1 < 12)&&
           (x2 >= x1)&&(x2 < 12)&&(y2 >= y1)&&(y2 < 12)){
            pop(massA, x1, y1, x2, y2);
            popp = outputMatrix(massA);
            cout << popp << " popped!" << " ";
        } else {
            cout << "Invalid Input. Try Again!" << endl;
        }
    }
    cout << "THE END!" << " ";

    return 0;
}
