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
  
private:
    // Error handler for OpenGL errors
    void handleGLError(size_t ln);
  
    // Set to true when the game is lost
    bool lost;
};

#endif
