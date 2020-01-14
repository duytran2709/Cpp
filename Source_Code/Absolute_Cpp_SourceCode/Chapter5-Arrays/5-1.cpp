//Absolute Cpp
//Display 5.1 Program Using an Array
//Reads in five scores and shows how much each
//score differs from the highest score.
#include <iostream>

using namespace std;

int main()
{
    int i, score[5], max;
    cout << "Enter 5 scores: \n";
    cin >> score[0];
    max = score[0];
    for (i = 1; i < 5; i++)
    {
        cin >> score[i];
        if (score[i] > max)
            max = score[i];
        //max is the largest of the values score[0]
    }

    cout << "the highest score is " << max << endl
         << "The scores and their \n"
         << "differences from the highest are: \n ";
    for (i = 0; i < 5; i++)
        cout << score[i] << " off by" << (max - score[i]) << endl;

    return 0;
}
