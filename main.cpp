#include <iostream>
#include <windows.h>
using namespace std;

//zadanie 1
void zadanie1() {
    double bak[2] = { 300, 1000 };
    double ves1[3] = { 750, 1500, 2000 };
    double rashod1[3] = { 1, 4, 7 };
    double ves2[3] = { 1000, 2000, 3000 };
    double rashod2[3] = { 2, 4, 6 };
    double dopBak = 100;

    int nomer;
    double ab, bc, gruz;

    cout << "nomer samoleta (1 ili 2): ";
    cin >> nomer;
    if (nomer != 1 && nomer != 2) {
        cout << "takogo samoleta net" << "\n";
        return;
    }
    cout << "rasstoyanie A-B (km): ";
    cin >> ab;
    cout << "rasstoyanie B-C (km): ";
    cin >> bc;
    cout << "ves gruza (kg): ";
    cin >> gruz;

    double ves[3];
    double rashod[3];
    double extra = 0;
    for (int i = 0; i < 3; i++) {
        if (nomer == 1) {
            ves[i] = ves1[i];
            rashod[i] = rashod1[i];
        }
        else {
            ves[i] = ves2[i];
            rashod[i] = rashod2[i];
        }
    }
    if (nomer == 2) extra = dopBak;
    double mainBak = bak[nomer - 1];

    double r = -1;
    for (int i = 0; i < 3; i++) {
        if (gruz <= ves[i]) {
            r = rashod[i];
            break;
        }
    }
    if (r < 0) {
        cout << "samolet ne podnimaet takoy gruz, polet nevozmozhen" << "\n";
        return;
    }

    double needAB = ab * r;
    double needBC = bc * r;

    if (needAB > mainBak + extra) {
        cout << "polet po takomu marshrutu nevozmozhen" << "\n";
        return;
    }

    double extraOst = extra;
    double mainOst = mainBak;
    if (needAB <= extra) {
        extraOst = extra - needAB;
    }
    else {
        mainOst = mainBak - (needAB - extra);
        extraOst = 0;
    }

    double izMain = needBC - extraOst;
    if (izMain < 0) izMain = 0;

    if (izMain > mainBak) {
        cout << "polet po takomu marshrutu nevozmozhen" << "\n";
        return;
    }

    double dozapravka = izMain - mainOst;
    if (dozapravka < 0) dozapravka = 0;

    cout << "nuzhno dozapravit v tochke B: " << dozapravka << " l" << "\n";
}

//zadanie 2
void zadanie2() {
    double bak[2] = { 300, 1000 };
    double ves[2][3] = {
        { 750, 1500, 2000 },
        { 1000, 2000, 3000 }
    };
    double rashod[2][3] = {
        { 1, 4, 7 },
        { 2, 4, 6 }
    };
    double dopBak = 100;

    int nomer;
    double ab, bc, gruz;

    cout << "nomer samoleta (1 ili 2): ";
    cin >> nomer;
    if (nomer != 1 && nomer != 2) {
        cout << "takogo samoleta net" << "\n";
        return;
    }
    cout << "rasstoyanie A-B (km): ";
    cin >> ab;
    cout << "rasstoyanie B-C (km): ";
    cin >> bc;
    cout << "ves gruza (kg): ";
    cin >> gruz;

    int p = nomer - 1;

    double r = -1;
    for (int i = 0; i < 3; i++) {
        if (gruz <= ves[p][i]) {
            r = rashod[p][i];
            break;
        }
    }
    if (r < 0) {
        cout << "samolet ne podnimaet takoy gruz, polet nevozmozhen" << "\n";
        return;
    }

    double mainBak = bak[p];
    double extra = 0;
    if (nomer == 2) extra = dopBak;

    double needAB = ab * r;
    double needBC = bc * r;

    if (needAB > mainBak + extra) {
        cout << "polet po takomu marshrutu nevozmozhen" << "\n";
        return;
    }

    double extraOst = extra;
    double mainOst = mainBak;
    if (needAB <= extra) {
        extraOst = extra - needAB;
    }
    else {
        mainOst = mainBak - (needAB - extra);
        extraOst = 0;
    }

    double izMain = needBC - extraOst;
    if (izMain < 0) izMain = 0;

    if (izMain > mainBak) {
        cout << "polet po takomu marshrutu nevozmozhen" << "\n";
        return;
    }

    double dozapravka = izMain - mainOst;
    if (dozapravka < 0) dozapravka = 0;

    cout << "nuzhno dozapravit v tochke B: " << dozapravka << " l" << "\n";
}

int main() {
    SetConsoleCP(CP_UTF8);
    cout << "zadanie 1" << "\n";
    zadanie1();
    cout << "\n" << "zadanie 2" << "\n";
    zadanie2();
    system("pause");
    return 0;
}