#ifndef NODE_H
#define NODE_H

#include "Picture.h"

class Node {
protected:
    Picture picture;
    int mask;
    void applyMask();

public:
    Node();
    void asignarPicture(const Picture& p);
    void setMask(int m);
    int getMask() const;
};

#endif // NODE_H
