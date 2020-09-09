#include "FenPrincipale.h"
#include <iostream>

using namespace std;

FenPrincipale::FenPrincipale()
{
    //Variable:
    QString cheminFichier = "";
    QString afficheCheminFichier = "";


    //Menu:
    //-Fichier:
    menuFichier = menuBar()->addMenu("&Fichier");

    //--Nouvel_onglet:
    QAction *actionNouvelOnglet = new QAction("Nou&vel onglet", this);
    menuFichier->addAction(actionNouvelOnglet);

    //--Fermer_onglet:
    QAction *actionFermerOnglet = new QAction("Fe&rmer l'onglet", this);
    menuFichier->addAction(actionFermerOnglet);

    //--Nouveau:
    QAction *actionNouveau = new QAction("&Nouveau", this);
    menuFichier->addAction(actionNouveau);

    //--Ouvrir:
    QAction *actionOuvrir = new QAction("&Ouvrir", this);
    menuFichier->addAction(actionOuvrir);

    //--Ouvrir_nouvel_onglet:
    QAction *actionOuvrirNouvelOnglet = new QAction("Ouvr&ir dans un nouvel onglet", this);
    menuFichier->addAction(actionOuvrirNouvelOnglet);

    //--Sauvegarder:
    QAction *actionSauvegarder = new QAction("&Sauvegarder", this);
    menuFichier->addAction(actionSauvegarder);

    //--Sauvegarder_sous:
    QAction *actionSauvegarderSous = new QAction("Sauve&garder Sous", this);
    menuFichier->addAction(actionSauvegarderSous);

    //--Changer_le_theme:
    QAction *actionChangerTheme = new QAction("Changer le thème", this);
    menuFichier->addAction(actionChangerTheme);

    //--Quitter:
    QAction *actionQuitter = new QAction("&Quitter", this);
    menuFichier->addAction(actionQuitter);

    //-Edition:
    menuEdition = menuBar()->addMenu("&Edition");

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
    menuAPropos = menuBar()->addMenu("&?");

    //--A_propos_de_EF-SKHR:
    QAction *actionAProposSKHR = new QAction("A propos de EF-&SKHR");
    menuAPropos->addAction(actionAProposSKHR);

    //--A_propos_de_QT:
    QAction *actionAProposQt = new QAction("A propos de &QT", this);
    menuAPropos->addAction(actionAProposQt);

    //Raccourcis:

    //-Menu_Fichier:

    //--Nouvel_onglet:
    actionNouvelOnglet->setShortcut(QKeySequence("Ctrl+T"));

    //--Fermer_onglet:
    actionFermerOnglet->setShortcut(QKeySequence("Ctrl+W"));

    //--Nouveau:
    actionNouveau->setShortcut(QKeySequence("Ctrl+N"));

    //--Ouvrir:
    actionOuvrir->setShortcut(QKeySequence("Ctrl+O"));

    //--Ouvrir_nouvel_onglet:
    actionOuvrirNouvelOnglet->setShortcut(QKeySequence("Ctrl+Shift+O"));

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

    //--Onglets:
    onglets = new QTabWidget;
    onglets->addTab(creeOnglet(QString("")), QString("Sans titre"));

    //Slots:

    //-Onglets:
    connect(onglets, SIGNAL(currentChanged(int)), this, SLOT(changementOnglet(int)));

    //-Menu_Fichier:

    //--Nouvel_onglet:
    connect(actionNouvelOnglet, SIGNAL(triggered()), this, SLOT(nouvelOnglet()));

    //--Fermer_onglet:
    connect(actionFermerOnglet, SIGNAL(triggered()), this, SLOT(fermerOnglet()));

    //--Nouveau:
    connect(actionNouveau, SIGNAL(triggered()), this, SLOT(nouveauFichier()));

    //--Ouvrir:
    connect(actionOuvrir, SIGNAL(triggered()), this, SLOT(ouvrirFichier()));

    //--Ouvrir_nouvel_onglet:
    connect(actionOuvrirNouvelOnglet, SIGNAL(triggered()), this, SLOT(ouvrirFichierNouvelOnglet()));

    //--Sauvegarder:
    connect(actionSauvegarder, SIGNAL(triggered()), this, SLOT(sauvegarderFichier()));

    //--Sauvegarder_sous:
    connect(actionSauvegarderSous, SIGNAL(triggered()), this, SLOT(sauvegarderSousFichier()));

    //--Changer_le_theme:
    connect(actionChangerTheme, SIGNAL(triggered()), this, SLOT(changerTheme()));

    //--Quitter:
    connect(actionQuitter, SIGNAL(triggered()), this, SLOT(fermerApp()));

    //-Menu_Edition:

    //--Annuler:
    connect(actionAnnuler, SIGNAL(triggered()), this, SLOT(annuler()));

    //--Refaire:
    connect(actionRefaire, SIGNAL(triggered()), this, SLOT(refaire()));

    //--Tout-selectionner:
    connect(actionSelectAll, SIGNAL(triggered()), fichierActuelle(), SLOT(selectAll()));

    //--Copier:
    connect(actionCopier, SIGNAL(triggered()), fichierActuelle(), SLOT(copy()));

    //--Couper:
    connect(actionCouper, SIGNAL(triggered()), fichierActuelle(), SLOT(cut()));

    //--Coller:
    connect(actionColler, SIGNAL(triggered()), fichierActuelle(), SLOT(paste()));

    //-Menu_A_propos:

    //--A_propos_de_EF-SKHR:
    connect(actionAProposSKHR, SIGNAL(triggered()), this, SLOT(aProposSKHR()));

    //--A_propos_de_QT:
    connect(actionAProposQt, SIGNAL(triggered()), qApp, SLOT(aboutQt()));

    //-Evenement:

    //Affichage:
    setMinimumSize(QSize(350, 450));
    setWindowTitle("Sans titre | EF-SKHR");
    setWindowIcon(QIcon("/usr/share/icons/ef-skhr/ef-skhr-logo.png"));
    setCentralWidget(onglets);
    actionAnnuler->setDisabled(true);
    actionRefaire->setDisabled(true);

    afficheCheminFichier = cheminFichier + " (enregistré)";
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
        fichierActuelle()->setText(textFichier);

        onglets->setTabToolTip(onglets->currentIndex(), cheminArg);
        cheminFichier = cheminArg;
        afficheCheminFichier = cheminFichier + " (enregistré)";
        statusBar()->showMessage(afficheCheminFichier);

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

    if (titre.size() > 20)
    {
            titre = titre.left(20) + "...";
    }

    onglets->setTabText(onglets->currentIndex(), titre);
    titre += " | EF-SKHR";
    setWindowTitle(titre);
}

//-Menu_Fichier (SLOT):

//--creeOnglet:
QWidget *FenPrincipale::creeOnglet(QString texte)
{
    QWidget *pageOnglet = new QWidget;
    QTextEdit *zoneTexte = new QTextEdit();

    QVBoxLayout *layout = new QVBoxLayout;
    layout->setContentsMargins(0,0,0,0);
    layout->addWidget(zoneTexte);
    pageOnglet->setLayout(layout);

    zoneTexte->setText(texte);
    zoneTexte->setAcceptRichText(false);

    //--Texte_editer:
    connect(zoneTexte, SIGNAL(textChanged()), this, SLOT(nonSauvegarder()));

    //--Non_annuler:
    connect(zoneTexte, SIGNAL(undoAvailable(bool)), this, SLOT(nonAnnuler(bool)));

    //--Non_refaire:
    connect(zoneTexte, SIGNAL(redoAvailable(bool)), this, SLOT(nonRefaire(bool)));

    return pageOnglet;
}

//--fichierActuelle:
QTextEdit *FenPrincipale::fichierActuelle()
{
    return onglets->currentWidget()->findChild<QTextEdit *>();
}

//--nouvelOnglet (SLOT):
void FenPrincipale::nouvelOnglet()
{
    onglets->addTab(creeOnglet(QString("")), QString("Sans titre"));
    onglets->setCurrentIndex(onglets->count() - 1);
}

//--fermerOnglet:
void FenPrincipale::fermerOnglet()
{
    QString titre = onglets->tabText(onglets->currentIndex());
    int tailleTitre = titre.length() - 1;

    if(titre[tailleTitre] != "*")
    {
        if(onglets->count() != 1)
        {
            onglets->removeTab(onglets->currentIndex());
        }
        else
        {
            exit(0);
        }
    }
    else
    {
        int reponse = QMessageBox::question(this, "Fermeture d'onglet", "Le fichier n'est pas sauvegardé, si vous fermez l'onglet les modifications serrons perdut!\nVoulez-vous sauvegarder le fichier?", QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);

        if(QMessageBox::Yes == reponse)
        {
            sauvegarderF();
            if(onglets->count() != 1)
            {
                onglets->removeTab(onglets->currentIndex());
            }
            else
            {
                exit(0);
            }
        }
        else if(QMessageBox::No == reponse)
        {
            if(onglets->count() != 1)
            {
                onglets->removeTab(onglets->currentIndex());
            }
            else
            {
                exit(0);
            }
        }
    }


}

//--nouveauFichier:
void FenPrincipale::nouveauFichier()
{
    QString titre = onglets->tabText(onglets->currentIndex());
    int tailleTitre = titre.length() - 1;

    if(titre[tailleTitre] != "*")
    {
        fichierActuelle()->setText(QString(""));
    }
    else
    {
        int reponse = QMessageBox::question(this, "Ouverture de fichier", "Le fichier n'est pas sauvegardé, si vous ouvrer un nouveau fichier les modifications serrons perdut!\nVoulez-vous sauvegarder le fichier?", QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);

        if(QMessageBox::Yes == reponse)
        {
            sauvegarderF();
            fichierActuelle()->setText(QString(""));
        }
        else if(QMessageBox::No == reponse)
        {
            fichierActuelle()->setText(QString(""));
        }
    }

    setWindowTitle(QString("Sans titre | EF-SKHR"));
    onglets->setTabText(onglets->currentIndex(), QString("Sans titre"));
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
        fichierActuelle()->setText(textFichier);

        cheminFichier = fichier;
        onglets->setTabToolTip(onglets->currentIndex(), fichier);
        afficheCheminFichier = cheminFichier + " (enregistré)";
        statusBar()->showMessage(afficheCheminFichier);

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

    if (titre.size() > 20)
    {
            titre = titre.left(20) + "...";
    }

    onglets->setTabText(onglets->currentIndex(), titre);
    titre += " | EF-SKHR";
    setWindowTitle(titre);
}

//--ouvrirFichier (SLOT):
void FenPrincipale::ouvrirFichier()
{
    QString titre = onglets->tabText(onglets->currentIndex());
    int tailleTitre = titre.length() - 1;

    if(titre[tailleTitre] != "*")
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

//--ouvrirFichierNouvelOnglet:
void FenPrincipale::ouvrirFichierNouvelOnglet()
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

        afficheCheminFichier = cheminFichier + " (enregistré)";
        statusBar()->showMessage(afficheCheminFichier);

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

    if (titre.size() > 20)
    {
            titre = titre.left(20) + "...";
    }

    onglets->addTab(creeOnglet(textFichier), titre);
    onglets->setCurrentIndex(onglets->count() - 1);
    onglets->setTabToolTip(onglets->currentIndex(), fichier);
    cheminFichier = fichier;
    titre += " | EF-SKHR";
    setWindowTitle(titre);
}

//--sauvegarderF:
void FenPrincipale::sauvegarderF()
{
    QString texte = fichierActuelle()->toPlainText();
    QString titre;
    int nmbs = 0;
    int dNmbs = 0;
    int posPCT = 0;

    if(cheminFichier != QString(""))
    {
        string const nomFichier(cheminFichier.toStdString());

        ofstream monFlux(nomFichier.c_str());

        if(monFlux)
        {
            monFlux << texte.toStdString() << endl;

            afficheCheminFichier = cheminFichier + " (enregistré)";
            statusBar()->showMessage(afficheCheminFichier);

            QString titre = onglets->tabText(onglets->currentIndex());
            int tailleTitre = titre.length() - 1;

            if(titre[tailleTitre] == "*")
            {
                titre = titre.left(tailleTitre);
            }

            onglets->setTabText(onglets->currentIndex(), titre);
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

            onglets->setTabToolTip(onglets->currentIndex(), fichier);

            cheminFichier = fichier;
            afficheCheminFichier = cheminFichier + " (enregistré)";
            statusBar()->showMessage(afficheCheminFichier);

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

            if (titre.size() > 20)
            {
                    titre = titre.left(20) + "...";
            }

            onglets->setTabText(onglets->currentIndex(), titre);
            titre += " | EF-SKHR";
            setWindowTitle(titre);
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
    QString titre;
    int nmbs = 0;
    int dNmbs = 0;
    int posPCT = 0;
    QString texte = fichierActuelle()->toPlainText();

    QString fichier = QFileDialog::getSaveFileName(this, "Sauvegarder un fichier", QString(), "Texte (*.*)");
    string const nomFichier(fichier.toStdString());

    ofstream monFlux(nomFichier.c_str());

    if(monFlux)
    {
        monFlux << texte.toStdString() << endl;

        cheminFichier = fichier;
        onglets->setTabToolTip(onglets->currentIndex(), fichier);

        afficheCheminFichier = cheminFichier + " (enregistré)";
        statusBar()->showMessage(afficheCheminFichier);

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

        if (titre.size() > 20)
        {
                titre = titre.left(20) + "...";
        }

        onglets->setTabText(onglets->currentIndex(), titre);
        titre += " | EF-SKHR";
        setWindowTitle(titre);
    }
    else
    {
        QMessageBox::critical(this, "Erreur d'écriture!", "Sauvegarde du fichier impossible!");
    }
}

//--fermerApp (SLOT):
void FenPrincipale::fermerApp()
{
    int vExit = 0;
    for(int i(0); i < onglets->count(); i++)
    {
        onglets->setCurrentIndex(i);
        QString titre = onglets->tabText(onglets->currentIndex());
        int tailleTitre = titre.length() - 1;

        if(titre[tailleTitre] != "*")
        {
            vExit = 1;
        }
        else
        {
            int reponse = QMessageBox::question(this, "Fermeture du logiciel", "Le fichier n'est pas sauvegardé, si vous quittez les modifications serrons perdut!\nVoulez-vous sauvegarder le fichier?", QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);

            if(QMessageBox::Yes == reponse)
            {
                sauvegarderF();
                vExit = 1;
            }
            else if(QMessageBox::No == reponse)
            {
                vExit = 1;
            }
            else
            {
                vExit = 0;
                i = 1000;
            }
        }
    }

    if(vExit == 1)
    {
        exit(0);
    }
}

//-Menu_Edition:

//--annuler (SLOT):
void FenPrincipale::annuler()
{
    fichierActuelle()->undo();
    actionRefaire->setDisabled(false);
}

//--refaire (SLOT):
void FenPrincipale::refaire()
{
    fichierActuelle()->redo();
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

//--changementOnglet:
void FenPrincipale::changementOnglet(int index)
{
    cheminFichier = onglets->tabToolTip(onglets->currentIndex());

    QString titre = onglets->tabText(onglets->currentIndex());
    int tailleTitre = titre.length() - 1;

    if(titre[tailleTitre] == "*")
    {
        afficheCheminFichier = cheminFichier + " (non enregistré)";

        int tailleTitre = titre.length() - 1;

        if(titre[tailleTitre] == "*")
        {
            titre = titre.left(tailleTitre);
        }

        setWindowTitle(titre +" | EF-SKHR");
    }
    else
    {
        afficheCheminFichier = cheminFichier + " (enregistré)";
        setWindowTitle(titre +" | EF-SKHR");
    }

    statusBar()->showMessage(afficheCheminFichier);
}

//--fermer:
void FenPrincipale::closeEvent(QCloseEvent* event)
{
    int vExit = 0;
    for(int i(0); i < onglets->count(); i++)
    {
        onglets->setCurrentIndex(i);
        QString titre = onglets->tabText(onglets->currentIndex());
        int tailleTitre = titre.length() - 1;

        if(titre[tailleTitre] != "*")
        {
            vExit = 1;
        }
        else
        {
            int reponse = QMessageBox::question(this, "Fermeture du logiciel", "Le fichier n'est pas sauvegardé, si vous quittez les modifications serrons perdut!\nVoulez-vous sauvegarder le fichier?", QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);

            if(QMessageBox::Yes == reponse)
            {
                sauvegarderF();
                vExit = 1;
            }
            else if(QMessageBox::No == reponse)
            {
                vExit = 1;
            }
            else
            {
                vExit = 0;
                i = 1000;
            }
        }
    }

    if(vExit == 1)
    {
        event->accept();
    }
    else
    {
        event->ignore();
    }
}

//--nonSauvegarder (SLOT):
void FenPrincipale::nonSauvegarder()
{
    QString titre = onglets->tabText(onglets->currentIndex());
    int tailleTitre = titre.length() - 1;

    if(titre[tailleTitre] != "*")
    {
        afficheCheminFichier = cheminFichier + " (non enregistré)";
        statusBar()->showMessage(afficheCheminFichier);
        titre += "*";
        onglets->setTabText(onglets->currentIndex(), titre);
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

//-Parametres:
//--setConfigFile:
void FenPrincipale::setConfigFile(string fichier)
{
    fichierConfig = fichier;
}

//--changerTheme (SLOT):
void FenPrincipale::changerTheme()
{
    string ligne;
    string texteConfig = "";

    ifstream fichierC(fichierConfig);

    if(fichierC)
    {
        while(getline(fichierC, ligne))
        {
            texteConfig += ligne + "\n";
        }

        int nR = 0;
        string texteConfigN = "";

        for(int i(0); i < texteConfig.length(); i++)
        {
            if(texteConfig[i] == '\n')
            {
                nR += 1;
            }

            if(nR < 1)
            {
                if(texteConfig[i] == '0')
                {
                    texteConfigN += "1";
                }
                else if(texteConfig[i] == '1')
                {
                    texteConfigN += "0";
                }
                else
                {
                    texteConfigN += texteConfig[i];
                }
            }
            else
            {
                texteConfigN += texteConfig[i];
            }
        }

        fichierC.close();

        ofstream fichierConf(fichierConfig);

        if(fichierConf)
        {
            fichierConf << texteConfigN;

            QMessageBox::information(this, "Changer le thème", "Pour que le thème change, il faut redémarrer l'application.");

            fichierConf.close();
        }
    }
}

//--theme
void FenPrincipale::theme()
{
    string ligne;
    ifstream fichierC(fichierConfig);

    if(fichierC)
    {
        getline(fichierC, ligne);
        valeur = ligne[ligne.length() - 1];

        if(valeur == '0')
        {
            //fenetre
            QPalette fenetreC;
            fenetreC.setColor(QPalette::Background, Qt::white);
            fenetreC.setColor(QPalette::Text, Qt::black);
            setPalette(fenetreC);

            //Menu:
            QPalette menuC;
            menuC.setColor(QPalette::Base, Qt::white);
            menuFichier->setPalette(menuC);
            menuEdition->setPalette(menuC);
            menuAPropos->setPalette(menuC);

            //onglets:
            QPalette ongletC;
            ongletC.setColor(QPalette::Button, Qt::white);
            ongletC.setColor(QPalette::Background, Qt::white);
            ongletC.setColor(QPalette::Base, Qt::white);
            ongletC.setColor(QPalette::Text, Qt::black);
            onglets->setPalette(ongletC);
        }
        else if(valeur == '1')
        {
            //fenetre
            QPalette fenetreC;
            fenetreC.setColor(QPalette::Background, QColor(70, 70, 70));
            fenetreC.setColor(QPalette::Text, Qt::black);
            this->setPalette(fenetreC);

            //Menu:
            QPalette menuC;
            menuC.setColor(QPalette::Base, QColor(70, 70, 70));
            menuFichier->setPalette(menuC);
            menuEdition->setPalette(menuC);
            menuAPropos->setPalette(menuC);

            //onglets:
            QPalette ongletC;
            ongletC.setColor(QPalette::Button, QColor(80, 80, 80));
            ongletC.setColor(QPalette::Background, Qt::black);
            ongletC.setColor(QPalette::Base, QColor(50, 50, 50));
            ongletC.setColor(QPalette::Text, QColor(220, 220, 220));
            onglets->setPalette(ongletC);
        }
    }

    fichierC.close();
}
