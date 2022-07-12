// week07.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;
struct Bowler {

    int scores[5];
    int averageScores;
    string names;
};
// get the bowling scores
void GetBowlingData(Bowler bowlingPlayers[]) {
    int i = 0;
    ifstream fs;
    fs.open("BowlingScores.txt");
    while (!fs.eof()) {
        // the names which are strings are stored in names and the integers will be stored in scores. 
        while (fs >> bowlingPlayers[i].names) {
            for (int j = 0; j < 5; j++) {
                fs >> bowlingPlayers[i].scores[j];
            }
            i++;
        }
    }


}
// to get the average we have to nest the loop to be able to loop each number
void GetAverageScore(Bowler bowlingPlayers[]) {
    float averageScores = 0;
    float scoreAmount = 5;
    for (int i = 0; i < 10; i++) {

        averageScores = 0;
        for (int j = 0; j < 5; j++) {
            // for index 0 it will calculate the whole first line then keep going down until the tenth line which is the 9th element
            averageScores += bowlingPlayers[i].scores[j];

        }

        bowlingPlayers[i].averageScores= averageScores / scoreAmount;

    }


}
void PrettyPrintResults(Bowler bowlingPlayers[]) {


    // this is the same loop as the getaveragescore function it is a nested loop. the names will all be on the left column then each score will be displayed with space between them
    for (int i = 0; i < 10; i++) {

        cout << left << setw(10) << bowlingPlayers[i].names;

        for (int j = 0; j < 5; j++)

            cout << bowlingPlayers[i].scores[j] << "\t";
        // after the average score it end the line and go back to printing the name
        cout << bowlingPlayers[i].averageScores << endl;
    }

}
int main() {
    // declaring all of the variables and calling the functions with their arguments.
    
    const int size = 50;
    
    Bowler bowlingPlayers[size];
    GetBowlingData(bowlingPlayers);

    GetAverageScore(bowlingPlayers);

    PrettyPrintResults(bowlingPlayers);

}