#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
using namespace std;
int main() {
  srand(time(NULL));
  cout << endl << "Hi!" << endl << "Can you crack the code?" << endl << "In this logic-based game, you will have" << endl << "a limited number of guesses to figure out" << endl << "a randomly generated code of numerical digits." << endl << endl << "You will have 3n+7 attempts for an n-digit code." << endl << "After every attempt, you will be given information" << endl << "about the digits you entered." << endl << endl << "Type to continue...." << endl << endl;
  string continuee;
  cin >> continuee;
  cout << endl <<"Note: you can end a game anytime by typing " << '"' << "End" << '"' << " instead of a guess." << endl;
  string continuegame = "Yes";
  int guesscount;
  string m;
  char mchk;
  int mlength, mfail;
  double nn;
  int n;
  int gameover;
  char digit;
  char digitcheck;
  char digitmatch, digitcode;
  int sum;
  int digita, digitb;
  int ii;
  int c0, c1, c2, c3, c4, c5, c6, c7, c8, c9;
  int cc0, cc1, cc2, cc3, cc4, cc5, cc6, cc7, cc8, cc9;
  int d0, d1, d2, d3, d4, d5, d6, d7, d8, d9;
  int ch1, ch2, ch3, ch4, ch5, ch6, ch7, ch8;
  int correctdp, corrd;
  int illegalmove, illegallength, bplay;
  int guesslength;
  string gplay;
  vector<char> code;
  while (continuegame != "No" && continuegame != "no") {
    if (continuegame == "No" || continuegame == "no") break;
    if (continuegame != "Yes" && continuegame != "yes") {
      cout << endl << "I'll take that as a yes." << endl;
    }
    mfail = 0;
    cout << endl << "Please enter the value of n, where 0 < n < 8." << endl << endl;
    cin >> m;
    mlength = m.length();
    mchk = m[0];
    if (isdigit(mchk) == 0 || mchk == '0' || mchk == '9') {
      mfail = mfail+1;
    }
    while (mfail > 0 || mlength != 1) {
      if (mfail == 0 && mlength == 1) break;
      cout << "You must've misunderstood the instructions." << endl << "Please enter a valid value for n." << endl << endl;
      cin >> m;
      mlength = m.length();
      mchk = m[0];
      if (isdigit(mchk) == 0 || mchk == '0' || mchk == '9') {
        mfail = mfail+1;
      }
      else {mfail = 0;}
    }
    nn = std::stod(m);
    n = int(nn);
    guesscount = 3*n;
    guesscount = guesscount+7;
    gameover = 0;
    c0 = 0;
    c1 = 0;
    c2 = 0;
    c3 = 0;
    c4 = 0;
    c5 = 0;
    c6 = 0;
    c7 = 0;
    c8 = 0;
    c9 = 0;
    ii = 0;
    illegalmove = 0;
    bplay = 0;
    illegallength = 0;
    corrd = 0;
    correctdp = 0;
    code.clear();
    while (ii < n) {
      ch1 = rand() %300;
      ch2 = rand() %300 +2;
      ch3 = rand() %300 +3;
      ch4 = rand() %300 +4;
      ch5 = rand() %300 +5;
      ch6 = rand() %300 +6;
      ch7 = rand() %300 +7;
      ch8 = rand() %300 +8;
      sum = ch1+ch2+ch3+ch4+ch5+ch6+ch7+ch8;
      digita = sum % 100;
      digitb = int(digita/10);
      digit = '0'+digitb;
      ii++;
      if (digitb == 0) {
        c0 = c0+1;
      }
      if (digitb == 1) {
        c1 = c1+1;
      }
      if (digitb == 2) {
        c2 = c2+1;
      }
      if (digitb == 3) {
        c3 = c3+1;
      }
      if (digitb == 4) {
        c4 = c4+1;
      }
      if (digitb == 5) {
        c5 = c5+1;
      }
      if (digitb == 6) {
        c6 = c6+1;
      }
      if (digitb == 7) {
        c7 = c7+1;
      }
      if (digitb == 8) {
        c8 = c8+1;
      }
      if (digitb == 9) {
        c9 = c9+1;
      }
      code.push_back(digit);
    }
    cout << endl << "The code has been generated." << endl << "You may begin cracking it." << endl << "There are no spaces, letters, or special symbols." << endl << endl << "You have " << guesscount << " guesses." << endl << endl;
    //gameplay begins below
    while (gameover == 0) {
      if (gameover > 0) break;
      cin >> gplay;
      cc0 = 0;
      cc1 = 0;
      cc2 = 0;
      cc3 = 0;
      cc4 = 0;
      cc5 = 0;
      cc6 = 0;
      cc7 = 0;
      cc8 = 0;
      cc9 = 0;
      correctdp = 0;
      corrd = 0;
      if (gplay == "end" || gplay == "End") break;
      guesslength = gplay.length();
      if (guesslength != n) {
        illegallength = n-guesslength;
        bplay = 10;
      }
      for (int i = 0; i < guesslength; i++) {
        digitcheck = gplay[i];
        if (isdigit(digitcheck) == 0) {
          illegalmove = illegalmove+1;
          bplay = 10;
        }
      }
      //the code below only runs if the player is stupid
      while (bplay > 0) {
        if (gplay == "End" || gplay == "end") break;
        if (bplay == 0) break;
        if (illegallength > 0) {
          cout << endl << "Your input is too short." << endl << "The code is " << n << " digits long." << endl;
        }
        if (illegallength < 0 && n == 1) {
          cout << endl << "Your input is too long." << endl << "The code is only 1 digit long." << endl;
        }
        if (illegallength < 0 && n > 1) {
          cout << endl << "Your input is too long." << endl << "The code is only " << n << " digits long." << endl;
        }
        if (illegalmove > 0) {
          cout << endl << "Please allow me to remind you:" << endl << "There are no spaces, letters, or special symbols." << endl;
        }
        cout << endl << "Please try again with a valid guess." << endl << "No attempts have been deducted." << endl << endl;
        bplay = 0;
        illegalmove = 0;
        illegallength = 0;
        cin >> gplay;
        guesslength = gplay.length();
        for (int ii = 0; ii < guesslength; ii++) {
          digitcheck = gplay[ii];
          if (isdigit(digitcheck) == 0) {
            illegalmove = illegalmove+1;
            bplay = 10;
          }
        }
        if (guesslength != n) {
          illegallength = n-guesslength;
          bplay = 10;
        }
      }
      if (gplay == "End" || gplay == "end") break;
      for (int ij = 0; ij < n; ij++) {
        digitmatch = gplay[ij];
        digitcode = code[ij];
        if (digitmatch == digitcode) {
          correctdp = correctdp+1;
        }
        if (digitmatch == '0') {
          cc0 = cc0+1;
        }
        if (digitmatch == '1') {
          cc1 = cc1+1;
        }
        if (digitmatch == '2') {
          cc2 = cc2+1;
        }
        if (digitmatch == '3') {
          cc3 = cc3+1;
        }
        if (digitmatch == '4') {
          cc4 = cc4+1;
        }
        if (digitmatch == '5') {
          cc5 = cc5+1;
        }
        if (digitmatch == '6') {
          cc6 = cc6+1;
        }
        if (digitmatch == '7') {
          cc7 = cc7+1;
        }
        if (digitmatch == '8') {
          cc8 = cc8+1;
        }
        if (digitmatch == '9') {
          cc9 = cc9+1;
        }
        d0 = min(c0, cc0);
        d1 = min(c1, cc1);
        d2 = min(c2, cc2);
        d3 = min(c3, cc3);
        d4 = min(c4, cc4);
        d5 = min(c5, cc5);
        d6 = min(c6, cc6);
        d7 = min(c7, cc7);
        d8 = min(c8, cc8);
        d9 = min(c9, cc9);
      }
      corrd = d0+d1+d2+d3+d4+d5+d6+d7+d8+d9;
      if (correctdp == n) {
        gameover = gameover+1;
      }
      if (correctdp != n) {
        guesscount = guesscount-1;
      }
      if (guesscount == 0) {
        gameover = gameover+1;
      }
      if (gameover == 0) {
        if (corrd == 0) {
          cout << endl << "Nothing is correct." << endl << endl;
        }
        if (corrd == 1 && correctdp == 0) {
          cout << endl << "You have identified 1 of the " << n << " required digits." << endl << "However, it is incorrectly placed." << endl;
        }
        if (corrd == 1 && correctdp == 1) {
          cout << endl << "You have identified 1 of the " << n << " required digits." << endl << "It is correctly placed." << endl;
        }
        if (corrd > 1 && correctdp == 0) {
          cout << endl << "You have identified " << corrd << " of the " << n << " required digits." << endl << "Unfortunately, none of them are correctly placed." << endl;
        }
        if (corrd > 1 && correctdp == 1) {
          cout << endl << "You have identified " << corrd << " of the " << n << " required digits." << endl << "Of those " << corrd << ", only 1 is correctly placed.";
        }
        if (corrd > 1 && correctdp > 1 && corrd != correctdp) {
          cout << endl << "You have identified " << corrd << " of the " << n << " required digits." << endl << "Of those " << corrd << ", only " << correctdp << " are correctly placed." << endl;
        }
        if (corrd > 1 && correctdp == corrd) {
          cout << endl << "You have identified " << corrd << " of the " << n << " required digits." << endl << "All of them are correctly placed." << endl;
        }
        if (guesscount < 5) {
          if (guesscount == 1) {
            cout << endl << "I hope you know the correct answer by now." << endl << "You only have 1 attempt left!" << endl << endl;
          }
          else {
            cout << endl << "You only have " << guesscount << " attempts left." << endl << "You'd better be getting close to the answer!" << endl << endl;
          }
        }
        if (guesscount > 4) {
          cout << endl << "You have " << guesscount << " attempts left to crack the code." << endl << endl;
        }
      }
      if (gameover > 0) {
        if (correctdp != n) {
          cout << endl << "Unfortunately, you have failed to crack the code." << endl << "The correct code is ";
          for (int jj = 0; jj < n; jj++) {
            cout << code[jj];
          }
          cout << "." << endl;
        }
        if (correctdp == n) {
          cout << "Congratulations!" << endl << "You have cracked the code!" << endl << "Well done!" << endl;
        }
      }
    }
    if (gplay == "End" || gplay == "end") {
      cout << endl << "The answer is ";
      for (int jjj = 0; jjj < n; jjj++) {
        cout << code[jjj];
      }
      cout << "." << endl;
    }
    cout << endl << "Thank you for playing!" << endl << "Would you like to play another game?" << endl << endl;
    cin >> continuegame;
    if (continuegame != "No" && continuegame != "no") {
      for (int iij = 0; iij < 50; iij++) {
        cout << endl;
      }
    }
  }
  for (int iji = 0; iji < 30; iji++) {
    cout << endl;
  }
  for (int ji = 0; ji < 32; ji++) {
    cout << " ";
  }
  cout << "Goodbye!" << endl;
  for (int jii = 0; jii < 33; jii++) {
    cout << " ";
  }
  cout << "^ - ^";
  for (int jij = 0; jij < 20; jij++) {
    cout << endl;
  }
}
/*

*///