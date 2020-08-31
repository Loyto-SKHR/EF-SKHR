#ifndef HEADER_FENPRINCIPALE
#define HEADER_FENPRINCIPALE

#include <QtWidgets>
#include <QStatusBar>
#include <QMessageBox>

#include <fstream>
#include <string>

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

    protected :
    void closeEvent(QCloseEvent* event);

    private:
    QAction *actionAnnuler;
    QAction *actionRefaire;
    QString cheminFichier;
    QString afficheCheminFichier;
    QTabWidget *onglets;
};

#endif
