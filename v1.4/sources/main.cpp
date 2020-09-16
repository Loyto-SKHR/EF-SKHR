#include <QApplication>
#include <QtWidgets>
#include <string>
#include "FenPrincipale.h"
#include <iostream>
#include <unistd.h>

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

    string userName = getenv("HOME");

    string cheminConfig = userName + "/.SKHR/EF-SKHR/config.skhr";

    ifstream fichierC(cheminConfig);

    if(not fichierC)
    {
        fichierC.close();
        system("mkdir ~/.SKHR");
        system("mkdir ~/.SKHR/EF-SKHR");
        ofstream fichierC(cheminConfig);
        fichierC << "theme: 0\n" << endl;
    }

    fichierC.close();

    fenetre.setConfigFile(cheminConfig);
    fenetre.theme();

    fenetre.show();

    return app.exec();
}
