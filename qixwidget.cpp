#include <QMainWindow>
#include <iostream>
#include <sstream>
#include <stdexcept>

#include "qixwidget.h"

QixWidget::QixWidget(QWidget*) : lost(false), timerId(0), qixGame(0) {
    QGLFormat qf = QGLFormat(QGL::DoubleBuffer | QGL::DepthBuffer | QGL::SampleBuffers);
    qf.setSampleBuffers(2);
    setFormat(qf);
    setFocusPolicy(Qt::StrongFocus);
    timerId = startTimer(1000.0/60);

    qixGame = new QixState();
}

QixWidget::~QixWidget() {
    if (qixGame) {
        delete qixGame;
        qixGame = 0;
    }
}

void QixWidget::startNewGame() {
    lost = false;
    delete qixGame;
    qixGame = new QixState();
}

/*!
  Initializes OpenGL by enabling required features and loading materials/lights/display lists
*/
void QixWidget::initializeGL() {
    // Enable stuff
    qglClearColor(Qt::black);
  
    glShadeModel(GL_FLAT);
    
    glPolygonMode(GL_FRONT, GL_FILL);
    
    glEnable(GL_POLYGON_OFFSET_FILL);
    
    glEnable(GL_DEPTH_TEST);
}


/*!
  Called automatically when the window is rezied
*/
void QixWidget::resizeGL(int width, int height) {
    glViewport(0,0, (GLsizei) width, (GLsizei)height);
  
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10.0,10.0,-10.0,10.0);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

/*!
  Called by the system to draw the display
*/
void QixWidget::paintGL() {

    // Rotate/translate the projection matrix
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();

    // Draw something here
    glColor3f(0.0,1.0,0.0);
    glBegin(GL_QUADS);
    glVertex2f(-1.0,-1.0);
    glVertex2f(1.0,-1.0);
    glVertex2f(1.0,1.0);
    glVertex2f(-1.0,1.0);
    glEnd();

    // Reset to how we found things
    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    
    glMatrixMode(GL_MODELVIEW);
    glFlush();
}

/*!
  Debug function that will display information about OpenGL errors.
  The argument is the line number of the error
*/
inline void QixWidget::handleGLError(size_t ln) {
    GLenum ec = glGetError();
    // Do nothing if there's no error
    if (ec== GL_NO_ERROR) return;
  
    // Get the error information in a string
    std::ostringstream err;
    err << (const char*)gluErrorString(ec) << " : " << ln;

    // Print info to stdout and throw an exception
    //std::cout << err.str() << "\n";
    throw new std::runtime_error(err.str());
}


void QixWidget::timerEvent(QTimerEvent *event) {
    if (event->timerId() == timerId) {
        // std::cout << "Timer update!\n";
        update();
    } else {
        QWidget::timerEvent(event);
    }
}

void QixWidget::keyPressEvent(QKeyEvent *event) {
    double dy=0.0, dx=0.0;
    switch (event->key()) {

    case (Qt::Key_Up):       dy = -1.0; break;
    case (Qt::Key_Down):     dy = 1.0; break;
    case (Qt::Key_Right):    dx = 1.0; break;
    case (Qt::Key_Left):     dx = -1.0; break;

    case (Qt::Key_Space):    if (!qixGame->isStarted()) {
            qixGame->startGame();
            break;
        }

    default:
        QWidget::keyPressEvent(event);
    }
    std::cout << "dx: " << dx << ", dy: " << dy << "\n";
    //  update();
}

void QixWidget::keyReleaseEvent(QKeyEvent *event) {
    double dy=0.0, dx=0.0;
    switch (event->key()) {

    case (Qt::Key_Up):       dy = 0.0; break;
    case (Qt::Key_Down):     dy = 0.0; break;
    case (Qt::Key_Right):    dx = 0.0; break;
    case (Qt::Key_Left):     dx = 0.0; break;
        
    default:
        QWidget::keyPressEvent(event);
    }
    std::cout << "dx: " << dx << ", dy: " << dy << "\n";
    //  update();
}
