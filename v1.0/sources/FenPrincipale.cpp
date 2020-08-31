#include "FenPrincipale.h"

using namespace std;

FenPrincipale::FenPrincipale()
{
    //Variable:
    bool sauvegarder = true;
    QString cheminFichier = "";
    QString afficheCheminFichier = "";


    //Menu:
    //-Fichier:
    QMenu *menuFichier = menuBar()->addMenu("&Fichier");

    //--Nouveau:
    QAction *actionNouveau = new QAction("&Nouveau", this);
    menuFichier->addAction(actionNouveau);

    //--Ouvrir:
    QAction *actionOuvrir = new QAction("&Ouvrir", this);
    menuFichier->addAction(actionOuvrir);

    //--Sauvegarder:
    QAction *actionSauvegarder = new QAction("&Sauvegarder", this);
    menuFichier->addAction(actionSauvegarder);

    //--Sauvegarder_sous:
    QAction *actionSauvegarderSous = new QAction("Sauve&garder Sous", this);
    menuFichier->addAction(actionSauvegarderSous);

    //--Quitter:
    QAction *actionQuitter = new QAction("&Quitter", this);
    menuFichier->addAction(actionQuitter);

    //-Edition:
    QMenu *menuEdition = menuBar()->addMenu("&Edition");

    //--Annuler:
    actionAnnuler = new QAction("&Annuler", this);
    menuEdition->addAction(actionAnnuler);

    //--Refaire:
    actionRefaire = new QAction("&Refaire", this);
    menuEdition->addAction(actionRefaire);

    //--Tout-selectionner:
    QAction *actionSelectAll = new QAction("&Tout sélectionner");
    menuEdition->addAction(actionSelectAll);

    //--Copier:
    QAction *actionCopier = new QAction("&Copier", this);
    menuEdition->addAction(actionCopier);

    //--Couper:
    QAction *actionCouper = new QAction("Cou&per", this);
    menuEdition->addAction(actionCouper);

    //--Coller:
    QAction *actionColler = new QAction("Co&ller", this);
    menuEdition->addAction(actionColler);

    //-A_propos:
    QMenu *menuAPropos = menuBar()->addMenu("&?");

    //--A_propos_de_EF-SKHR:
    QAction *actionAProposSKHR = new QAction("A propos de EF-&SKHR");
    menuAPropos->addAction(actionAProposSKHR);

    //--A_propos_de_QT:
    QAction *actionAProposQt = new QAction("A propos de &QT", this);
    menuAPropos->addAction(actionAProposQt);

    //Zone_de_texte:
    zoneTexte = new QTextEdit();

    //Raccourcis:

    //-Menu_Fichier:

    //--Nouveau:
    actionNouveau->setShortcut(QKeySequence("Ctrl+N"));

    //--Ouvrir:
    actionOuvrir->setShortcut(QKeySequence("Ctrl+O"));

    //--Sauvegarder:
    actionSauvegarder->setShortcut(QKeySequence("Ctrl+S"));

    //--Sauvegarder_sous:
    actionSauvegarderSous->setShortcut(QKeySequence("Ctrl+Shift+S"));

    //--Quitter:
    actionQuitter->setShortcut(QKeySequence("Ctrl+Q"));

    //-Menu_Edition:

    //--Annuler:
    actionAnnuler->setShortcut(QKeySequence("Ctrl+Z"));

    //--Refaire:
    actionRefaire->setShortcut(QKeySequence("Ctrl+Y"));

    //--Tout-selectionner:
    actionSelectAll->setShortcut(QKeySequence("Ctrl+A"));

    //--Copier:
    actionCopier->setShortcut(QKeySequence("Ctrl+C"));

    //--Coupper:
    actionCouper->setShortcut(QKeySequence("Ctrl+X"));

    //--Coller:
    actionColler->setShortcut(QKeySequence("Ctrl+V"));

    //Slots:

    //-Menu_Fichier:

    //--Nouveau:
    connect(actionNouveau, SIGNAL(triggered()), this, SLOT(nouveauFichier()));

    //--Ouvrir:
    connect(actionOuvrir, SIGNAL(triggered()), this, SLOT(ouvrirFichier()));

    //--Sauvegarder:
    connect(actionSauvegarder, SIGNAL(triggered()), this, SLOT(sauvegarderFichier()));

    //--Sauvegarder_sous:
    connect(actionSauvegarderSous, SIGNAL(triggered()), this, SLOT(sauvegarderSousFichier()));

    //--Quitter:
    connect(actionQuitter, SIGNAL(triggered()), this, SLOT(fermerApp()));

    //-Menu_Edition:

    //--Annuler:
    connect(actionAnnuler, SIGNAL(triggered()), this, SLOT(annuler()));

    //--Refaire:
    connect(actionRefaire, SIGNAL(triggered()), this, SLOT(refaire()));

    //--Tout-selectionner:
    connect(actionSelectAll, SIGNAL(triggered()), zoneTexte, SLOT(selectAll()));

    //--Copier:
    connect(actionCopier, SIGNAL(triggered()), zoneTexte, SLOT(copy()));

    //--Couper:
    connect(actionCouper, SIGNAL(triggered()), zoneTexte, SLOT(cut()));

    //--Coller:
    connect(actionColler, SIGNAL(triggered()), zoneTexte, SLOT(paste()));

    //-Menu_A_propos:

    //--A_propos_de_EF-SKHR:
    connect(actionAProposSKHR, SIGNAL(triggered()), this, SLOT(aProposSKHR()));

    //--A_propos_de_QT:
    connect(actionAProposQt, SIGNAL(triggered()), qApp, SLOT(aboutQt()));

    //-Evenement:

    //--Texte_editer:
    connect(zoneTexte, SIGNAL(textChanged()), this, SLOT(nonSauvegarder()));

    //--Non_annuler:
    connect(zoneTexte, SIGNAL(undoAvailable(bool)), this, SLOT(nonAnnuler(bool)));

    //--Non_refaire:
    connect(zoneTexte, SIGNAL(redoAvailable(bool)), this, SLOT(nonRefaire(bool)));

    //Affichage:
    setMinimumSize(QSize(350, 450));
    setWindowTitle("Sans titre | EF-SKHR");
    setWindowIcon(QIcon("/usr/share/icons/ef-skhr/ef-skhr-logo.png"));
    setCentralWidget(zoneTexte);
    actionAnnuler->setDisabled(true);
    actionRefaire->setDisabled(true);

    afficheCheminFichier = cheminFichier + " (enregister)";
    statusBar()->showMessage(afficheCheminFichier);
}

//Methode:

//setFichierArg:
void FenPrincipale::setFichierArg(QString cheminArg)
{
    QString textFichier = "";
    QString titre;
    string ligne;
    int nmbs = 0;
    int dNmbs = 0;
    int posPCT = 0;

    ifstream fichierL(cheminArg.toStdString());

    if(fichierL)
    {
        while(getline(fichierL, ligne))
        {
            textFichier += QString::fromStdString(ligne) + "\n";
        }
        zoneTexte->setText(textFichier);

        cheminFichier = cheminArg;
        afficheCheminFichier = cheminFichier + " (enregister)";
        statusBar()->showMessage(afficheCheminFichier);
        sauvegarder = true;

        actionAnnuler->setDisabled(true);
        actionRefaire->setDisabled(true);
    }
    else
    {
        QMessageBox::critical(this, "Erreur de lecture!", "Ouverture du fichier impossible!");
    }

    for(int i(0); i < cheminArg.length(); i++)
    {
        if(cheminArg[i] == "/")
        {
            nmbs++;
        }
    }

    dNmbs = nmbs;
    nmbs = 0;

    for(int i(0); i < cheminArg.length(); i++)
    {
        if(cheminArg[i] == "/")
        {
            nmbs++;

            if(nmbs == dNmbs)
            {
                posPCT = i + 1;
            }
        }
    }

    for(int i(posPCT); i < cheminArg.length(); i++)
    {
        titre += cheminArg[i];
    }

    titre += " | EF-SKHR";
    setWindowTitle(titre);
}

//-Menu_Fichier (SLOT):

//--nouveauFichier:
void FenPrincipale::nouveauFichier()
{
    if(sauvegarder)
    {
        zoneTexte->setText(QString(""));
    }
    else
    {
        int reponse = QMessageBox::question(this, "Ouverture de fichier", "Le fichier n'est pas sauvegardé, si vous ouvrer un nouveau fichier les modifications serrons perdut!\nVoulez-vous sauvegarder le fichier?", QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);

        if(QMessageBox::Yes == reponse)
        {
            sauvegarderF();
            zoneTexte->setText(QString(""));
        }
        else if(QMessageBox::No == reponse)
        {
            zoneTexte->setText(QString(""));
        }
    }
}

//--ouvrirFichierF:
void FenPrincipale::ouvrirFichierF()
{
    QString textFichier = "";
    QString titre;
    string ligne;
    int nmbs = 0;
    int dNmbs = 0;
    int posPCT = 0;

    QString fichier = QFileDialog::getOpenFileName(this, "Ouvrir un fichier", QString(), "Texte (*.*)");

    ifstream fichierL(fichier.toStdString());

    if(fichierL)
    {
        while(getline(fichierL, ligne))
        {
            textFichier += QString::fromStdString(ligne) + "\n";
        }
        zoneTexte->setText(textFichier);

        cheminFichier = fichier;
        afficheCheminFichier = cheminFichier + " (enregister)";
        statusBar()->showMessage(afficheCheminFichier);
        sauvegarder = true;

        actionAnnuler->setDisabled(true);
        actionRefaire->setDisabled(true);
    }
    else
    {
        QMessageBox::critical(this, "Erreur de lecture!", "Ouverture du fichier impossible!");
    }

    for(int i(0); i < fichier.length(); i++)
    {
        if(fichier[i] == "/")
        {
            nmbs++;
        }
    }

    dNmbs = nmbs;
    nmbs = 0;

    for(int i(0); i < fichier.length(); i++)
    {
        if(fichier[i] == "/")
        {
            nmbs++;

            if(nmbs == dNmbs)
            {
                posPCT = i + 1;
            }
        }
    }

    for(int i(posPCT); i < fichier.length(); i++)
    {
        titre += fichier[i];
    }

    titre += " | EF-SKHR";
    setWindowTitle(titre);
}

//--ouvrirFichier (SLOT):
void FenPrincipale::ouvrirFichier()
{
    if(sauvegarder)
    {
        ouvrirFichierF();
    }
    else
    {
        int reponse = QMessageBox::question(this, "Ouverture de fichier", "Le fichier n'est pas sauvegardé, si vous ouvrer un nouveau fichier les modifications serrons perdut!\nVoulez-vous sauvegarder le fichier?", QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);

        if(QMessageBox::Yes == reponse)
        {
            sauvegarderF();
            ouvrirFichierF();
        }
        else if(QMessageBox::No == reponse)
        {
            ouvrirFichierF();
        }
    }
}

//--sauvegarderF:
void FenPrincipale::sauvegarderF()
{
    QString texte = zoneTexte->toPlainText();

    if(cheminFichier != QString(""))
    {
        string const nomFichier(cheminFichier.toStdString());

        ofstream monFlux(nomFichier.c_str());

        if(monFlux)
        {
            monFlux << texte.toStdString() << endl;

            afficheCheminFichier = cheminFichier + " (enregister)";
            statusBar()->showMessage(afficheCheminFichier);
            sauvegarder = true;
        }
        else
        {
            QMessageBox::critical(this, "Erreur d'écriture!", "Sauvegarde du fichier impossible!");
        }
    }
    else
    {
        QString fichier = QFileDialog::getSaveFileName(this, "Sauvegarder un fichier", QString(), "Texte (*.*)");
        string const nomFichier(fichier.toStdString());

        ofstream monFlux(nomFichier.c_str());

        if(monFlux)
        {
            monFlux << texte.toStdString() << endl;


            cheminFichier = fichier;
            afficheCheminFichier = cheminFichier + " (enregister)";
            statusBar()->showMessage(afficheCheminFichier);
            sauvegarder = true;
        }
        else
        {
            QMessageBox::critical(this, "Erreur d'écriture!", "Sauvegarde du fichier impossible!");
        }
    }
}

//--sauvegarderFichier (SLOT):
void FenPrincipale::sauvegarderFichier()
{
    sauvegarderF();
}

//--sauvegarderSousFichier (SLOT):
void FenPrincipale::sauvegarderSousFichier()
{
    QString texte = zoneTexte->toPlainText();

    QString fichier = QFileDialog::getSaveFileName(this, "Sauvegarder un fichier", QString(), "Texte (*.*)");
    string const nomFichier(fichier.toStdString());

    ofstream monFlux(nomFichier.c_str());

    if(monFlux)
    {
        monFlux << texte.toStdString() << endl;

        cheminFichier = fichier;

        afficheCheminFichier = cheminFichier + " (enregister)";
        statusBar()->showMessage(afficheCheminFichier);
        sauvegarder = true;
    }
    else
    {
        QMessageBox::critical(this, "Erreur d'écriture!", "Sauvegarde du fichier impossible!");
    }
}

//--fermerApp (SLOT):
void FenPrincipale::fermerApp()
{
    if(sauvegarder)
    {
        exit(0);
    }
    else
    {
        int reponse = QMessageBox::question(this, "Fermeture du logiciel", "Le fichier n'est pas sauvegardé, si vous quittez les modifications serrons perdut!\nVoulez-vous sauvegarder le fichier?", QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);

        if(QMessageBox::Yes == reponse)
        {
            sauvegarderF();
        }
        else if(QMessageBox::No == reponse)
        {
            exit(0);
        }
    }
}

//-Menu_Edition:

//--annuler (SLOT):
void FenPrincipale::annuler()
{
    zoneTexte->undo();
    actionRefaire->setDisabled(false);
}

//--refaire (SLOT):
void FenPrincipale::refaire()
{
    zoneTexte->redo();
}

//-Menu_A_propos:

//--aProposSKHR:
void FenPrincipale::aProposSKHR()
{
    QDialog aProposSKHRF(this);
    aProposSKHRF.setWindowTitle(QString("A propos de EF-SKHR"));
    aProposSKHRF.setFixedSize(QSize(500, 200));

    QVBoxLayout *layout = new QVBoxLayout;
    aProposSKHRF.setLayout(layout);

    QLabel *texteSKHR = new QLabel();
    texteSKHR->setText("Le logiciel EF-SKHR, à été entièrement développé\n"
                       "par Loyto_SKHR en langage C++ et en utilisant\n"
                       "la bibliothèque QT5.9 pour l'interface graphique.\n\n"
                       "Le code sources: https://github.com/SKHR-Loyto/EF-SKHR");

    layout->addWidget(texteSKHR);

    aProposSKHRF.exec();
}

//-Evenement:

//--fermer:
void FenPrincipale::closeEvent(QCloseEvent* event) {
    if(sauvegarder)
    {
        event->accept();
    }
    else
    {
        int reponse = QMessageBox::question(this,"Fermeture du logiciel", "Le fichier n'est pas sauvegardé, si vous quittez les modifications serrons perdut!\nVoulez-vous sauvegarder le fichier?", QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
        if(reponse == QMessageBox::Yes)
        {
            sauvegarderF();
            event->ignore();
        }
        else if(reponse == QMessageBox::No)
        {
            event->accept();
        }
        else
        {
            event->ignore();
        }
    }
}

//--nonSauvegarder (SLOT):
void FenPrincipale::nonSauvegarder()
{
    if(sauvegarder)
    {
        afficheCheminFichier = cheminFichier + " (non enregister)";
        statusBar()->showMessage(afficheCheminFichier);
        sauvegarder = false;
    }

    actionAnnuler->setDisabled(false);
}

//--nonAnnuler (SLOT):
void FenPrincipale::nonAnnuler(bool pAnnuler)
{
    if(not pAnnuler)
    {
        actionAnnuler->setDisabled(true);
    }
}

//--nonRefaire (SLOT):
void FenPrincipale::nonRefaire(bool pRefaire)
{
    if(not pRefaire)
    {
        actionRefaire->setDisabled(true);
    }
}
