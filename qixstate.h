/*
  qixstate.h
  
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

#ifndef QIX_STATE_H
#define QIX_STATE_H

#include <vector>

struct qpoint {
public:
    qpoint() : x(0), y(0) {}
    int x;
    int y;
};

class Drawable {
public:
    Drawable();
    virtual ~Drawable();
    virtual void draw() = 0;
};
class Dot : public Drawable {
public:
    Dot(qpoint p = qpoint());
    virtual ~Dot();
    virtual void draw() = 0;
    void move(qpoint dp);

private:
    qpoint _pos;
};

class Player : public Dot {
public:
    Player(qpoint pos = qpoint());
    virtual ~Player();
    virtual void draw();

private:
};

class Spark : public Dot {
public:
    Spark(qpoint pos = qpoint(), bool hyper=false);
    virtual ~Spark();
    virtual void draw();

private:
    bool _hyper;
};

class Qix : public Drawable {
public:
    Qix(qpoint p1 = qpoint(), qpoint p2 = qpoint(), qpoint p3 = qpoint());
    ~Qix();
    virtual void draw();

private:
    qpoint _pos1;
    qpoint _pos2;
    qpoint _pos3;

    qpoint _next;
    qpoint _prev;
};

class QixState {
public:
    QixState();
    ~QixState();

    void startGame();
    void update();

    bool isStarted() { return started; }
    
protected:
    std::vector<Spark> sparks;
    std::vector<Qix> qixs;
    Player thePlayer;

private:
    bool started;
};

#endif
