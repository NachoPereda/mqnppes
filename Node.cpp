#include "Node.h"

Node::Node() : mask(0) {}

void Node::asignarPicture(const Picture& p) {
    picture = p;
}

void Node::setMask(int m) {
    mask = m;
    applyMask();
}

int Node::getMask() const {
    return mask;
}

void Node::applyMask() {
    // Implementación para aplicar la máscara según sea necesario
    // Por ejemplo, aquí puedes aplicar una lógica para modificar la imagen en función de la máscara
}
