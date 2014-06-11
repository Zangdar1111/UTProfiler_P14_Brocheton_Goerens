#include "includes.h"

QString NotetoQString(Note n){
    QString note;
    switch(n)
    {
        case 0: note="A";   break;
        case 1: note="B";   break;
        case 2: note="C";   break;
        case 3: note="D";   break;
        case 4: note="E";   break;
        case 5: note="F";   break;
        case 6: note="FX";  break;
        case 7: note="RES"; break;
        case 8: note="ABS"; break;
        case 9: note="EC";  break;
    }
    return note;
}

Note QStringtoNote(QString note){
    Note nott=EC;
    if (note=="A")
        nott=A;
    else if(note=="B")
        nott=B;
    else if(note=="C")
        nott=C;
    else if(note=="D")
        nott=D;
    else if(note=="E")
        nott=E;
    else if(note=="F")
        nott=F;
    else if(note=="FX")
        nott=FX;
    else if(note=="EC")
        nott=EC;
    else if(note=="ABS")
        nott=ABS;
    else if(note=="RES")
        nott=RES;
    return nott;
}
