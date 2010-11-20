#include <QApplication>
#include <iostream>

#include "qixwindow.h"
#include "qixwidget.h"

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);
  if (!QGLFormat::hasOpenGL()) {
    std::cerr << "This system has no OpenGL support" << std::endl;
    return 1;
  }

  QixWindow *mainWin = new QixWindow;
  mainWin->resize(500,500);
  mainWin->show();

  return app.exec();
}
