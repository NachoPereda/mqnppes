/**
 * Project TFG Ignacio Pereda
 */

#ifndef _EVAL1_H
#define _EVAL1_H

#include "Network.h"

class Eval1 : public Network
{
public:
    void linearEvaluation(Picture picture);
    void linearEvaluationiterator();
    void setMask() override;
};

#endif //_EVAL1_H