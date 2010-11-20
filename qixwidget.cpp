#include <QMainWindow>

#include <sstream>
#include <stdexcept>

#include "qixwidget.h"

QixWidget::QixWidget(QWidget*) :lost(false) {
    QGLFormat qf = QGLFormat(QGL::DoubleBuffer | QGL::DepthBuffer | QGL::SampleBuffers);
    qf.setSampleBuffers(2);
    setFormat(qf);
}

QixWidget::~QixWidget() {
}

void QixWidget::startNewGame() {
    lost = false;
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
