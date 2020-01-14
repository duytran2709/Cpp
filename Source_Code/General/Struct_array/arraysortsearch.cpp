#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <fstream>
using std::ifstream;
using std::ofstream;

#include <string>
using std::getline;
using std::string;

#include <algorithm>
using std::swap;

#include <cstdlib> // for atoi and atof

const int CAPACITY = 5;


void printScores(int []);
// void printScores(int scoresList[]); 

int main()
{
  int scores [CAPACITY] = {}; // init all to 0
  
  string buf; // for using the string buffer method
  for (int i = 0; i < CAPACITY; i++)
  {
    cout << "Enter a score [" << i << "]: ";
    cin >> buf; scores[i] = atof(buf.c_str());
  }
  
  cout << "List of scores you entered: " << endl;
  for (int i = 0; i < CAPACITY; i++) // reusing the name "i"
    cout << "scores[" << i << "] = " << scores[i] << endl;
  
  // find the minimum and maximum scores
  double maxScore = scores[0];
  double minScore = scores[0];
  for (int index = 1; index < CAPACITY; index++) // starting at index 1
  {
    if (maxScore < scores[index]) maxScore = scores[index];
    if (scores[index] < minScore) minScore = scores[index];
  }
  cout << "Min score = " << minScore << " \t Max score = " << maxScore << endl;
  
  // count matching values
  int nPerfectScores = 0;
  for (int index = 0; index < CAPACITY; index++)
    if (scores[index] == 100)
      ++nPerfectScores;

  // find any match
  bool hasPerfectScore = false;
  for (int index = 0; index < CAPACITY; index++)
    if (scores[index] == 100 )
    {
      hasPerfectScore = true;
      break; // no need to keep looking
    }

  // find any match, another way
  hasPerfectScore = false;
  for (int index = 0; index < CAPACITY && !hasPerfectScore; index++)
    if (scores[index] == 100)
      hasPerfectScore = true;

  // sort the values lo-to-hi
  for (int i = 0; i < CAPACITY; i++)
    for (int j = i + 1; j < CAPACITY; j++)
      if (scores[j] < scores[i])
        swap(scores[i], scores[j]);

  cout << "After sorting from low to high:" << endl;
  printScores(scores);
	
  // sort the values hi-to-lo
  for (int i = 0; i < CAPACITY; i++)
    for (int j = i + 1; j < CAPACITY; j++)
      if (scores[i] < scores[j])
        swap(scores[i], scores[j]);
	
  cout << "After sorting from high to low:" << endl;
  printScores(scores);
	
  // C++ 11 Extention
  // find the minimum and maximum values
  for (auto value:scores) // starting at index 1
  {
    if (maxScore < value) maxScore = value;
    if (value < minScore) minScore = value;
	cout << "value = " << value << endl;
  }
  cout << "Min score = " << minScore << " \t Max score = " << maxScore << endl;
   
  
  // count matching values
  nPerfectScores = 0;
  for (auto value:scores)
    if (value == 100)
      ++nPerfectScores;
  cout << "Number of perfect scores = " << nPerfectScores << endl;
  
  // find any match
  hasPerfectScore = false;
  for (auto value:scores)
    if (value == 100)
    {
      hasPerfectScore = true;
      break; // no need to keep looking
    }

  if (hasPerfectScore)
    cout << " Scores has at least 1 perfect score. " << endl;
  else
	cout << " Scores has no perfect score. " << endl;

  // Copy array
  int scoresCopy [CAPACITY];
  for (int i = 0; i < CAPACITY; i++)
	scoresCopy[i] = scores[i];
  
  printScores(scoresCopy);
  
  return 0;
}


void printScores(int scoreArray[])
{
  cout << "Score array contents: " << endl;
  for (int i = 0; i < CAPACITY; i++)
    cout << "scoreArray[" << i << "] = " << scoreArray[i] << endl;
}