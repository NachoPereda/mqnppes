/**
 * Project TFG Ignacio Pereda
 */

#ifndef _VALIDATION_H
#define _VALIDATION_H

#include "Network.h"
#include <regex>

class Validation : public Network
{
public:
    void validate(Picture picture);
    void validateiterator();
};

#endif //_VALIDATION_H