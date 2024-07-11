/**
 * Project TFG Ignacio Pereda
 */

#ifndef _EVAL2_H
#define _EVAL2_H

#include "Network.h"

class Eval2 : public Network
{
public:
    void quadraticEvaluation(Picture picture);
    void quadraticEvaluationiterator();
    void setMask() override;
};

#endif //_EVAL2_H