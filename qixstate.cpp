
#include "qixstate.h"

#include <iostream>

QixState::QixState(): started(false) {
    std::cout << "Creating Qix game!\n";
}

QixState::~QixState() {
    std::cout << "Destroying Qix game!\n";
}

void QixState::startGame() {
    std::cout << "Starting game!\n";
    started = true;
}

void QixState::update() {
}
