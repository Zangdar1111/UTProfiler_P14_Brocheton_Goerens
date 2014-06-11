#ifndef ENUM_H_INCLUDED
#define ENUM_H_INCLUDED

#include "includes.h"

enum Saison
{
    Printemps,
    Automne
};

enum Note
{
    A,
    B,
    C,
    D,
    E,
    F,
    FX,
    RES, /*Reserve*/
    ABS, /*Absent*/
    EC   /*En Cours*/
};

enum Categorie
{
    CS,
    TM,
    TSH,
    SP
};

QString NotetoQString(Note n);

Note QStringtoNote(QString note);


#endif // ENUM_H_INCLUDED
