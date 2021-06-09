#include <iostream>
using namespace std;

class Sudoku{
public:
    Sudoku(int Pole [9][9], int Diff=0)
    : Diff(Diff)
    {}
    int Pole [9][9];
    int Diff;


};

void GetBasePole (int (&Pole) [9][9]){
    int Base[18];
    for (int i = 0; i < 2; i++) {
        for (int j = 1; j < 10; j++)
            Base[j - 1 + 9 * i] = j;
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 9; j++) {
            Pole[i * 3][j] = Base[i + j];
            Pole[1 + i * 3][j] = Base[i + 3 + j];
            Pole[2 + i * 3][j] = Base[i + 6 + j];
        }
    }
}

void Transpose (int (&Pole) [9][9] ){
    int Clone [9][9];
    for (int i=0; i<9; i++){
        for (int j=0; j<9; j++){
            Clone [i][j] = Pole [i][j];
        }
    }
    for (int i=0; i<9; i++){
        for (int j=0; j<9; j++){
            Pole [i][j] = Clone [j][i];
        }
    }
}

void ChangeLine (int (&Pole) [9][9], int iA, int iB){
    for (int j=0; j<9; j++){
        int Zam = Pole [iA][j];
        Pole [iA][j] = Pole [iB][j];
        Pole [iB][j] = Zam;
    }
}
void ChangeColumn (int (&Pole) [9][9], int jA, int jB){
    for (int i=0; i<9; i++){
        int Zam = Pole [i][jA];
        Pole [i][jA] = Pole [i][jB];
        Pole [i][jB] = Zam;
    }
}

void ChangeBlockLine (int (&Pole) [9][9], int a, int b){
    for (int n =0; n< 3; n++){
        for (int j=0; j<9; j++){
            int Zam = Pole [(a-1)*3+n][j];
            Pole [(a-1)*3+n][j] = Pole [(b-1)*3+n][j];
            Pole [(b-1)*3+n][j] = Zam;
        }
    }
}

void ChangeBlockColumn (int (&Pole) [9][9], int a, int b){
    for (int n =0; n< 3; n++){
        for (int i=0; i<9; i++){
            int Zam = Pole [i][(a-1)*3+n];
            Pole [i][(a-1)*3+n] = Pole [i][(b-1)*3+n];
            Pole [i][(b-1)*3+n] = Zam;
        }
    }
}


int main () {

    int Pole[9][9];

    GetBasePole(Pole);
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++)
            cout << Pole[i][j] << " ";
        cout << '\n';
    }
    cout << '\n';



}
