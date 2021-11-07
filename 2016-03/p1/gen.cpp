#include <iostream>
#include <time.h>

using namespace std;

int main (int argc, char *argv[]) {
    srand(time(0));

    int subtask = atoi(argv[1]), n = ((rand()%20)+1);
    cout << n << endl;

    switch (subtask) {
        case 0 :
            for (int i = 0; i < n; i++)
                cout << rand()%101 << ((i!=(n-1)) ? " " : "\n");
            break;
        case 1 :
            for (int i = 0; i < n; i++)
                cout << rand()%60 << ((i!=(n-1)) ? " " : "\n");
            break;
        default :
            for (int i = 0; i < n; i++)
                cout << (60 + rand()%41) << ((i!=(n-1)) ? " " : "\n");
    }
    return 0;
}