//
// COMP2711,8801 Computer Programming 2
// Flinders University
//

#include <iostream>
#include <string>
#include <unistd.h>

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
auto report = true;	//report mode

void rolodex()
{
    string word;
    Rolodex rolodex;
    RolodexStats statistics = {0, 0, 0, 0, 0};
    while (cin >> word) {


        auto delete_check = false; //delete words

        switch (word.at(0)) {
            case '-':
                delete_check = true;
                word.erase(0, 1);
                break;
        }

         if (word.length() == 0)
            continue; // ignore empty words


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
                    statistics.duplication++;
                    statistics.deletions++;
                    if (verbose)
                        cerr << "delete (forward)\n";
                }
            } else if (duplicates || rolodex.isAfterLast() || rolodex.currentValue() != word) {
                rolodex.insertBeforeCurrent(word);
                statistics.insertions++;
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
                    statistics.duplication++;
                    statistics.deletions++;
                    if (verbose)
                        cerr << "delete (backward)\n";
                }
            } else if (duplicates || rolodex.isBeforeFirst() || rolodex.currentValue() != word) {
                rolodex.insertAfterCurrent(word);
                statistics.insertions++;
                if (verbose)
                    cerr << "insertAfterCurrent\n";
            }
        }
    }

    if (printCurrent) {
        cout << rolodex.currentValue() << '\n';
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
    int c;
    while ((c = getopt(argc, argv, "dvc")) != EOF) {
        switch (c) {
        case 'v':
            verbose = true;
            break;
        case 'c':
            printCurrent = true;
            break;
        case 'd':
        	duplicates = false;
        	break;
        case 'r':
        	report = true;
        	break;
    	}
	}

    argc -= optind;
    argv += optind;
    rolodex();
    return 0;
}
