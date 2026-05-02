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

struct Student {        // Changed struct from Class to Student 
string name;
int score;
};
// Function Prototypes
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
if (inFile) {
    while (count < MAX_SIZE && inFile >> students[count].name >> students[count].score) {
          count++;
    }
    inFile.close();
    cout << "Loaded " << count << " student scores from " << filename << endl;
} else {
    cout << "No existing file found. Please try again.\n";
}

int choice;

do {
    cout << "\n--- Daily Quiz Menu ---\n";
    cout << "1. View Data\n";
    cout << "2. Add Entry\n";
    cout << "3. Search Entry\n";
    cout << "4. Save Data\n";
    cout << "5. Exit\n";
    cout << "Enter choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            displayData(students, count);
            findMinMax(students, count);
            break;
        case 2:
            if (count < MAX_SIZE) {
                cout << "Enter name: ";
                cin >> students[count].name;
                cout << "Enter score: ";
                cin >> students[count].score;
                count++;
            } else {
                cout << "Classroom is full!\n";
            }
            break;
        case 3:
              searchEntry(students, count);
            break;
        case 4:
              saveData(students, count, filename);
            break;
        case 5:
              cout << "Exiting program... See you tomorrow!\n";
            break;
        default:
              cout << "Invalid choice. Please try again..\n";
      }
  } while (choice != 5);

  return 0;
}

void findMinMax(Student students[], int count) {
  if (count == 0) return;

  int maxIdx = 0, minIdx = 0;

  for (int i = 1; i < count; i++) {
      if (students[i].score > students[maxIdx].score)
        maxIdx = i;
      if (students[i].score < students[minIdx].score)
        minIdx = i;
  }
  cout << "\nDaily Stats:\n";
  cout << "Todays Highest Score: " << students[maxIdx].name << " (" << students[maxIdx].score << ")\n";
  cout << "Todays Lowest Score: " << students[minIdx].name << " (" << students[minIdx].score << ")\n";
}
void displayData(Student students[], int count) {
  cout << "\n" << left << setw(15) << "Name" << "Score" << endl;
  cout << "----------------------\n";
  for (int i = 0; i < count; i++) {
      cout << left << setw(15) << students[i].name << students[i].score << endl;
  }
}
void searchEntry(Student students[], int count) {
  string query;
  cout << "Enter name to search: ";
  cin >> query;
  bool found = false;
  for (int i = 0; i < count; i++) {
      if (students[i].name == query) {
        cout << "Found: " << students[i].name << " - Score: " << students[i].score << endl;
        found = true;
        break;
      }
  }
  if (!found) 
    cout << "Record not found.\n";
}
void saveData(Student students[], int count, string filename) {
  ofstream outFile(filename);
  for (int i = 0; i < count; i++) {
      outFile << students[i].name << " " << students[i].score << endl;
  }
  outFile.close();
  cout << "Data successfully saved to " << filename << endl;
}

        
