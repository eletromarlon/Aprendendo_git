#include <iosteam.h>
#include <unistd.h>

using namespace std;

int main ( ) {

    string titulo;

    titulo = "titulo";



    for (int i=0; i < 6; i++)
    {
    sleep(1);
    cout << titulo[i] << endl;
    }

    return 0;
}
