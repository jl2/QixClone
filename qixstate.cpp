/*
  qixstate.cpp
  
  Copyright (c) 2011, Jeremiah LaRocco jeremiah.larocco@gmail.com

  Permission to use, copy, modify, and/or distribute this software for any
  purpose with or without fee is hereby granted, provided that the above 
  copyright notice and this permission notice appear in all copies. 

  THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES 
  WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF 
  MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR 
  ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES 
  WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN 
  ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF 
  OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*/

#include "qixstate.h"

#include <iostream>

Drawable::Drawable() {}
Drawable::~Drawable() {}

Dot::Dot(qpoint p) : Drawable() {
    _pos.x = p.x;
    _pos.y = p.y;
}
Dot::~Dot() {}

void Dot::move(qpoint dp) {
    _pos.x += dp.x;
    _pos.y += dp.y;
}

Player::Player(qpoint pos) : Dot(pos) {
}

Player::~Player() {}
    
void Player::draw() {
}

Spark::Spark(qpoint pos, bool hyper) : Dot(pos), _hyper(hyper) {
}

Spark::~Spark() {}

void Spark::draw() {
}

Qix::Qix(qpoint p1, qpoint p2, qpoint p3) : Drawable() {
    _pos1.x = p1.x;
    _pos1.y = p1.y;

    _pos2.x = p2.x;
    _pos2.y = p2.y;

    _pos3.x = p3.x;
    _pos3.y = p3.y;
}

Qix::~Qix() {}

void Qix::draw() {
}

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
