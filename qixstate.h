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

class Dot {
public:
    Dot(int x, int y);
    virtual ~Dot();
    virtual void draw() = 0;
    int xPos();
    int yPos();
    int move(int dx, int dy);

private:
    int _xPos;
    int _yPos;
};

class Player : public Dot {
public:
    Player(int x, int y);
    virtual ~Player();
    virtual void draw();
private:
};

class Spark : public Dot {
public:
    Spark(int x, int y, bool hyper=false);
    virtual ~Spark();
    virtual void draw();
private:
    bool _hyper;
};

class QixState {
public:
    QixState();
    ~QixState();

    void startGame();
    void update();

    bool isStarted() { return started; }
    
protected:
    
private:
    bool started;
};

#endif
