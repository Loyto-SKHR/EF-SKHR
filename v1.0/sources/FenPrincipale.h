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
    void setFichierArg(QString cheminArg);
    void ouvrirFichierF();
    void sauvegarderF();

    public slots:
    //Menu_Fichier:
    void nouveauFichier();
    void ouvrirFichier();
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
    bool sauvegarder;
    QString cheminFichier;
    QString afficheCheminFichier;
    QTextEdit *zoneTexte;
};

#endif
