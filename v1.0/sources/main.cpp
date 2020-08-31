#include <QApplication>
#include <QtWidgets>
#include <string>
#include "FenPrincipale.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QString cheminArg = "";

    FenPrincipale fenetre;


    if(argc == 2)
    {
        cheminArg = argv[1];
        fenetre.setFichierArg(cheminArg);
    }

    fenetre.show();

    return app.exec();
}
