#include "includes.h"

//A supprimer par la suite
void CursusPrincipal::afficher(){
    afficherCursus();
    cout<<"Cursus Principal\n"
       <<"Nombre total de credits a valider : "<<Credits_Total<<"\n"
      <<"Nombre credits CS a valider : "<<Credits_CS<<"\n"
     <<"Nombre credits TM a valider : "<<Credits_TM<<"\n"
    <<"Nombre credits CS + TM a valider : "<<Credits_CSTM<<"\n"
    <<"Nombre credits TSH a valider : "<<Credits_TSH<<"\n"
    <<"Nombre credits SP a valider : "<<Credits_SP<<"\n"
    <<"******\n";
}
