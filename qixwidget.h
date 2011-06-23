/*
  qixwidget.h
  
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

#ifndef QIX_WIDGET_INCLUDE
#define QIX_WIDGET_INCLUDE

#include <QtGui>
#include <QtOpenGL>
#include <QGLWidget>

#ifdef __APPLE_CC__
#include <gl.h>
#include <glu.h>
#else
#include <GL/gl.h>
#include <GL/glu.h>
#endif

#include "qixstate.h"

class QixWidget : public QGLWidget {
    Q_OBJECT;

public:
    QixWidget(QWidget *parent = 0);
    ~QixWidget();
  
    void startNewGame();

signals:
    void gameLost();
    void gameWon();

protected:
    void initializeGL();
    void resizeGL(int width, int height);
    void paintGL();

    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    void timerEvent(QTimerEvent *event);
  
private:
    // Error handler for OpenGL errors
    void handleGLError(size_t ln);
  
    // Set to true when the game is lost
    bool lost;

    int timerId;

    QixState *qixGame;
};

#endif
