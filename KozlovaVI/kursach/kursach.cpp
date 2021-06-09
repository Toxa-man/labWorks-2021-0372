#include <iostream>
#include <cmath>
using namespace std;

int const size = 16;
int const sq = sqrt(size);

class Sudoku{
private:
    int Diff;
    int Pole [size][size];
    bool InviseablePoleMAsk[size][size]; //true -> скрыто
    int put=0;
public:
    Sudoku(int Diff=5){
        this->Diff =  Diff;
        int Base[size*2];
        for (int i = 0; i < 2; i++) {
            for (int j = 1; j <=size; j++)
                Base[j - 1 + size * i] = j;

        }
        for (int i = 0; i < sq ; i++) {
            for (int j = 0; j < size; j++) {
                int kol = 0;
                while (kol<sq){
                    Pole[kol + i * sq][j] = Base[i + j + sq*kol];
                    kol++;
                }
            }
        }
        int random;

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                random = rand()%Diff+1;
                InviseablePoleMAsk[i][j] = (random == Diff);
                if (InviseablePoleMAsk[i][j]){
                    put++;
                }
            }
        }
        cout << "Количество пробелов: " << put << endl;
    }

    void Transpose (){
        int Clone [size][size];
        for (int i=0; i<size; i++){
            for (int j=0; j<size; j++){
                Clone [i][j] = Pole [i][j];
            }
        }
        for (int i=0; i<size; i++){
            for (int j=0; j<size; j++){
                Pole [i][j] = Clone [j][i];
            }
        }
    }

    void ChangeLine (int iA, int iB){
        for (int j=0; j<size; j++){
            int Zam = Pole [iA][j];
            Pole [iA][j] = Pole [iB][j];
            Pole [iB][j] = Zam;
        }
    }

    void ChangeColumn (int jA, int jB){
        for (int i=0; i<size; i++){
            int Zam = Pole [i][jA];
            Pole [i][jA] = Pole [i][jB];
            Pole [i][jB] = Zam;
        }
    }

    void ChangeBlockLine (int a, int b){
        for (int n = 0; n < sq; n++){
            for (int j = 0; j < size; j++){
                int Zam = Pole [(a-1)*sq+n][j];
                Pole [(a-1)*sq+n][j] = Pole [(b-1)*sq+n][j];
                Pole [(b-1)*sq+n][j] = Zam;
            }
        }
    }

    void ChangeBlockColumn (int a, int b){
        for (int n = 0; n < sq; n++){
            for (int i = 0; i < size; i++){
                int Zam = Pole [i][(a-1)*sq+n];
                Pole [i][(a-1)*sq+n] = Pole [i][(b-1)*sq+n];
                Pole [i][(b-1)*sq+n] = Zam;
            }
        }
    }

//    void PrintField(){
//        cout << " " << "\t";
//        for (int i = 0; i < size; i++){
//            cout << i << "\t";
//        }
//        cout << "\n";
//        for (int i = 0; i < size; i++) {
//            cout << i << "\t";
//            for (int j = 0; j < size; j++)
//                cout << Pole[i][j] << "\t";
//            cout << '\n';
//        }
//        cout << '\n';
//    }

    void PrintFieldWithMask(){
        cout << "    ";
        for (int i = 0; i < size; i++){
            if (i%sq==0)
                cout << "  " << "\t";
            cout << i+1 << "\t";
        }
        cout << "\n";
        for (int i = 0; i < size; i++) {
            if(i%sq == 0){
                cout <<"____\n";
            }
            cout << i+1 << "\t";
            for (int j = 0; j < size; j++) {
                if (j%sq == 0){
                    cout << "|" << "\t";
                }
                if (InviseablePoleMAsk[i][j]) {
                    cout << "*" << "\t";
                } else {
                    cout << Pole[i][j] << "\t";
                }
            }
            cout << '\n';

        }
        cout << '\n';
    }

    void GetAnswer (){
        int i, j, answer;
        cin >> i >> j >> answer;
        if (Pole[i-1][j-1]==answer){
            InviseablePoleMAsk[i-1][j-1]= false;
            PrintFieldWithMask();
            cout << "Yep" << endl;
        }
        else {
            cout << "No" << endl;
        }
        if (getNull()==0){
            cout << "U are win" << endl;
        }
    }

    int getNull(){
        int null =0;
        for (int i=0; i<size; i++){
            for (int j=0; j<size; j++){
                if (InviseablePoleMAsk[i][j]){
                    null++;
                }}}
        return null;
    }

    void Change (){
        for (int i=0; i<10; i++){
            int random = rand()%9+1;
            switch (random) {
                case 1:
                    Transpose();
                    break;
                case 2:
                    ChangeLine(rand()%sq, rand()%sq);
                    break;
                case 3:
                    ChangeLine(rand()%sq+sq, rand()%sq+sq);
                    break;
                case 4:
                    ChangeLine(rand()%sq+sq*2, rand()%sq+sq*2);
                    break;
                case 5:
                    ChangeColumn(rand()%sq, rand()%sq);
                    break;
                case 6:
                    ChangeColumn(rand()%sq+sq, rand()%sq+sq);
                    break;
                case 7:
                    ChangeColumn(rand()%sq+sq*2, rand()%sq+sq*2);
                    break;
                case 8:
                    ChangeBlockLine(rand()%sq+1, rand()%sq+1);
                    break;
                case 9:
                    ChangeBlockColumn(rand()%sq+1, rand()%sq+1);
                    break;
            }
        }
    }
};

class Decision{
private:
    int Pole [size][size];
    int kolNul; //Тут будет храниться количество нулей в судоку
    int I [40]; //Массив координат i для нулей
    int J [40]; //Массив координат j для нулей
public:
    Decision() {
        kolNul = 0;
        for (int i = 0; i < size; i++) {  //Тут у нас заполнение судоку. Причем места, где нет цифр надо проставить нулями
            for (int j = 0; j < size; j++) {
                cin >> Pole[i][j];
                if (Pole[i][j] == 0) {  //Сразу, как найдется нуль, координаты заносятся в массив, а количество нулей подсчитывается
                    I[kolNul] = i;
                    J[kolNul] = j;
                    kolNul++;
                }
            }
        }
        if (!check ()){
            cout << "Судоку не имеет решения" << endl;
        }
    }

    bool check (){
        for (int i = 0; i < size; i++){  //По идее это проверка на реальность судоку
            for (int j = 0; j < size-1; j++){
                for (int k = j+1; k < size; k++) {
                    if ((Pole[i][j] == Pole[i][k] && Pole[i][j] != 0) || Pole [i][j] > size || Pole [i][k] > size){
                        return false;
                    }
                    if ((Pole[j][i] == Pole[k][i] && Pole[j][i] != 0) || Pole[j][i] > size || Pole [k][i] > size){
                        return false;
                    }
                }
            }
        }
        for (int m = 0; m < sq; m++){
            for (int n = 0; n < sq; n++){
                for (int a = 0; a < size-1; a++){
                    int i = a/sq;
                    int j = a%sq;
                    for (int k = a+1; k < size; k++){
                        for (int l = a+1; l < sq; l++){
                            if ((Pole[i+(m*sq)][j+(n*sq)] == Pole [(k/sq)+(m*sq)][(l%sq)+(n*sq)])&& Pole[i+(m*sq)][j+(n*sq)]!=0) {
                                return false;
                            }
                        }
                    }
                }
            }
        }
        return true;
    }

    void decide(){
        int i = I[kolNul-1];
        int j = J[kolNul-1];
        if ( Pole[i][j]==0){
            Pole [i][j] = 1;
        }
        while (!check() && Pole[i][j] < size) {
            Pole[i][j] = Pole[i][j]+1;
        }
        if (check()){
            kolNul--;
        }
        else {
            Pole[i][j]=0;
            kolNul++;
            decide();
        }

        if (kolNul==0 && check()){
            cout << "Судоку решено" << endl;
            for (int a = 0; a < size; a++){
                for (int b = 0; b < size; b++){
                    cout << Pole [a][b] << " ";
                }
                cout << endl;
            }
        }
        else {
            if (check()) decide();
        }
    }
};


int main () {

    cout << "Выберите режим:" << endl;
    cout << "1. Решить судоку" << endl << "2. Ввести судоку для решения программы" <<endl;
    int koef;
    cin >> koef;
    if (koef==1){
        auto Playground = new Sudoku(5);
        Playground->Change();
        Playground->PrintFieldWithMask();
        while (Playground->getNull()!=0){
            cout << "Вам осталось угадать чисел: " << Playground->getNull() << endl;
            Playground->GetAnswer();
        }}
    else {
        cout << " Введите таблицу судоку, проставив в пустые поля 0. Учтите, что должно быть не более 40 нулей для единственного решения." << endl;
        auto Polenko = new Decision;
        Polenko->check();
        Polenko->decide();
    }

    return 0;
}

