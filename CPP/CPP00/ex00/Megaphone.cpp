#include <iostream>
#include <string>

using namespace std;

void  Megaphoner(int argc, char **argv)
{
    int     j(1);
    bool    verif(false);
    bool    loud(false);

    for(int j(0); j < argc; j++)
    {
        if (string(argv[j]) == "*" && loud)
            loud = false;
        else if (string(argv[j]) == "*")
            loud = true;
        for (int i = 0; argv[j][i] != '\0'; ++i)
        {
            if (loud || string(argv[j]) == "*")
                break;
            verif = true;
            argv[j][i] = toupper(argv[j][i]);
        }
        if (!loud && string(argv[j]) != "*")
            cout << argv[j];
    }
    if (verif)
        cout << endl;
}

int main(int argc, char **argv)
{
    if (argc > 1)
        Megaphoner(argc, argv);
    else
        cout << "* LOUD AND UNBERABLE FEEDBACK NOISE *\n";
    return 0;
}