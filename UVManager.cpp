#include "includes.h"
/*
void UVManager::addUV(string code, string t, ...)
{
    if (TabUV.exist(code))
        editUV(...);
    else
        UV(code);
        TabUV.add(code);
        editUV(string code, ...);
}
void UVManager::deleteUV(string code)
{
    tabUV.delete(code);
}

void UVManager::check_integrity()
{
    ifstream fichier("./data/uv.txt", ios::app);  // on ouvre le fichier en écriture seule
    if(fichier)  // si l'ouverture a réussi
    {
        int stop=0;
        string contenu,code="DEBUT FICHIER";
        while(getline(fichier, contenu))
        {
            if (contenu!= "#"){stop=1;cout<<"Erreur: Fichier Corrompu. Verifiez a partir de l'UV "<<code<<"."<<endl; break;}
            cout<<contenu<<endl;
            getline(fichier,code);cout<<code<<endl;
            for (unsigned int i=0;i<8;i++)
            {
                getline(fichier,contenu);cout<<contenu<<endl;
                if (contenu=="#")
                {
                    stop=1;
                    break;
                }
            }
            if (stop==1) {cout<<"Erreur: Fichier Corrompu. Verifiez a partir de l'UV "<<code<<"."<<endl; break;}
        }
        if (stop==0) {cout<<"Aucuns Problemes !";}
        fichier.close();
    }
    else
    cout << "Check_Integrity: Impossible d'ouvrir le fichier !" << endl;
}

*/
