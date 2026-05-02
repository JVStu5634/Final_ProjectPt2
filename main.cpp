// Joseph Valdez
// 5/1/2026
//  This is an updated version of the first program that takes daily quiz scores and displays the highest and lowest scores. 
// This program now contains a menu that allows the user to choose whether to look at the data currently saved, add new student names,
// search for students by name and save new data added by the user.

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

struct Student {
string name;
int score;
};

void findMinMax(Student students[], int count);
void displayData(Student students[], int count);
void searchEntry(Student students[], int count);
void saveData(Student students[], int count, string filename);

int main() {
  const int MAX_SIZE = 100;
  Student students[MAX_SIZE];
  int count = 0;
  string filename = "output.txt";

ifstream inFile(filename);







