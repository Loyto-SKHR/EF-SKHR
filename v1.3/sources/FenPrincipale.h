#ifndef HEADER_FENPRINCIPALE
#define HEADER_FENPRINCIPALE

#include <QtWidgets>
#include <QStatusBar>
#include <QMessageBox>
#include <QColor>

#include <fstream>
#include <string>

using namespace std;

class FenPrincipale : public QMainWindow
{
    Q_OBJECT

    public:
    FenPrincipale();
    QWidget *creeOnglet(QString texte);
    QTextEdit *fichierActuelle();
    void setFichierArg(QString cheminArg);
    void ouvrirFichierF();
    void sauvegarderF();
    void setConfigFile(string fichier);
    void theme();

    public slots:
    //Menu_Fichier:
    void changementOnglet(int index);
    void nouvelOnglet();
    void fermerOnglet();
    void nouveauFichier();
    void ouvrirFichier();
    void ouvrirFichierNouvelOnglet();
    void sauvegarderFichier();
    void sauvegarderSousFichier();
    void fermerApp();

    //Menu_Edition:
    void annuler();
    void refaire();

    //Menu_A_propos:
    void aProposSKHR();

    //Evenement:
    void nonSauvegarder();
    void nonAnnuler(bool pAnnuler);
    void nonRefaire(bool pRefaire);

    //Parametres:
    void changerTheme();

    protected :
    void closeEvent(QCloseEvent* event);

    private:
    QMenu *menuFichier;
    QMenu *menuEdition;
    QMenu *menuAPropos;
    QAction *actionAnnuler;
    QAction *actionRefaire;
    QString cheminFichier;
    QString afficheCheminFichier;
    QTabWidget *onglets;
    string fichierConfig;
    char valeur;
};

#endif
