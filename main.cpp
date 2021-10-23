//
// COMP2711,8801 Computer Programming 2
// Flinders University
//

#include <iostream>
#include <sstream>
#include <unistd.h>
#include <string.h>

#include "Rolodex.h"

using namespace std;

    struct RolodexStats{
        int insertions;
        int duplication;
        int deletions;
        int forward_rotations;
        int backward_rotations;
    };


auto verbose      = false; // Log Rolodex actions
auto printCurrent = false; // Output only the current Rolodex card
auto duplicates = false;	//allows duplicates
auto report = false;	//report mode

void rolodex(std::string input)
{
    Rolodex rolodex;
    RolodexStats statistics = {0, 0, 0, 0, 0};

    std::stringstream ss(input);
    std::string word;

    while (ss >> word) {
         auto delete_check = false; //delete words

         if (word.length() == 0)
            continue; // ignore empty words

         if (word.at(0) == '-')
         {
            delete_check = true;
            word.erase(0, 1);
         }
         else
         {
            statistics.insertions++;
         }

         if (rolodex.isBeforeFirst() || rolodex.currentValue() <= word) {
            while (!rolodex.isAfterLast() && rolodex.currentValue() < word) {
                rolodex.rotateForward();
                statistics.forward_rotations++;
                if (verbose)
                    cerr << "rotateForward\n";
            }

            if (delete_check) {
                if (!rolodex.isAfterLast() && rolodex.currentValue() == word) {
                    rolodex.delete_current();
                    statistics.deletions++;
                    statistics.insertions--;
                    if (verbose)
                        cerr << "delete (forward)\n";
                }
            } else if (duplicates && rolodex.currentValue() == word) {
                statistics.duplication++;
                statistics.insertions--;
                if (verbose)
                    cerr << "wordOmitted\n";
            } else if (rolodex.isAfterLast() || rolodex.currentValue() != word) {
                rolodex.insertBeforeCurrent(word);
                if (verbose)
                    cerr << "insertBeforeCurrent\n";
            }
        } else if (rolodex.isAfterLast() || rolodex.currentValue() >= word) {
            while (!rolodex.isBeforeFirst() && rolodex.currentValue() > word) {
                rolodex.rotateBackward();
                statistics.backward_rotations++;
                if (verbose)
                    cerr << "rotateBackward\n";
            }

            if (delete_check) {
                if (!rolodex.isBeforeFirst() && rolodex.currentValue() == word) {
                    rolodex.delete_current();
                    statistics.deletions++;
                    statistics.insertions--;
                    if (verbose)
                        cerr << "delete (backward)\n";
                }
            } else if (duplicates && rolodex.currentValue() == word) {
                statistics.duplication++;
                statistics.insertions--;
                if (verbose)
                    cerr << "wordOmitted\n";
            } else if (rolodex.isBeforeFirst() || rolodex.currentValue() != word) {
                rolodex.insertAfterCurrent(word);
                if (verbose)
                    cerr << "insertAfterCurrent\n";
            }
        } else {
            cerr << "Unknown case scenario" << endl;
        }
    }

    if (printCurrent) {
        cout << "Current value: " << rolodex.currentValue() << '\n';
    }

    else if (report)
    {
        cout << statistics.insertions<<" "
             << statistics.duplication << " "
             << statistics.deletions << " "
             << statistics.forward_rotations << " "
             << statistics.backward_rotations << endl;
    }

    else { // Output all Rolodex card values (default)
        while (!rolodex.isBeforeFirst())
        {
            rolodex.rotateBackward();
        }
        rolodex.rotateForward(); // Go to the first card
        while (!rolodex.isAfterLast())
        {
            cout << rolodex.currentValue() << '\n';
            rolodex.rotateForward();
        }
    }
}

int main(int argc, char** argv)
{
    for (int i = 2; i < argc; i++)
    {
        if (strcmp(argv[i], "-v") == 0)
            verbose = true;
        else if (strcmp(argv[i], "-c") == 0)
            printCurrent = true;
        else if (strcmp(argv[i],"-d") == 0)
            duplicates = true;
        else if (strcmp(argv[i], "-r") == 0)
            report = true;
    }

    rolodex(argv[1]);
    return 0;
}
