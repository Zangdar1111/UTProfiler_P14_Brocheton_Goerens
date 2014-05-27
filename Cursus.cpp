#include "includes.h"

bool Cursus::operator==(const Cursus* cur) const{
    if (Code!=cur->getCode()) return false;
    return true;
}
