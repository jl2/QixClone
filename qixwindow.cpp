#include <QtGui>
#include <QSettings>

#include <sstream>
#include <cstdlib>

#include "qixwindow.h"

QixWindow::QixWindow() : QMainWindow(), lost(false), qixwid(0) {
  
    std::srand(std::time(0));

    lost = true;
  
    qset = new QSettings(QSettings::IniFormat, QSettings::UserScope,
                         "Qix", "Qix");

    readHighScores();
  
    // // Make the QMinefield the central widget
    qixwid = new QixWidget(this);
    setCentralWidget(qixwid);

    // Initialize GUI stuff
    setWindowTitle(tr("Qix"));
    setWindowIcon(QIcon(":/images/icon.png"));
    createActions();
    createMenus();
    
    start_time = 0;
  
    theTimer = new QTimer(this);

    // Connect some signals
    // connect(qmf, SIGNAL(gameLost()), this, SLOT(loseGame()));
    // connect(qmf, SIGNAL(gameWon()), this, SLOT(winGame()));
    connect(theTimer, SIGNAL(timeout()), this, SLOT(update()));
}

QixWindow::~QixWindow() {
    if (qixwid) {
        delete qixwid;
    }
    // Delete everything
    delete newGameAction;
    delete aboutAction;
    delete aboutQtAction;
    delete quitAction;

    delete gameMenu;
    delete optionsMenu;
    delete helpMenu;
}

/*!
  Initializes all of the QActions used by the game
*/
void QixWindow::createActions() {
    // New game
    newGameAction = new QAction(tr("&New"), this);
    newGameAction->setIcon(QIcon(":/images/new.png"));
    newGameAction->setShortcut(tr("Ctrl+N"));
    newGameAction->setStatusTip(tr("Start a new game"));
    connect(newGameAction, SIGNAL(triggered()), this, SLOT(newGame()));

    // About
    aboutAction = new QAction(tr("About"), this);
    aboutAction->setIcon(QIcon(":/images/about.png"));
    aboutAction->setShortcut(tr("Ctrl+A"));
    aboutAction->setStatusTip(tr("About Qix"));
    connect(aboutAction, SIGNAL(triggered()), this, SLOT(about()));

    // About QT
    aboutQtAction = new QAction(tr("About QT"), this);
    aboutQtAction->setIcon(QIcon(":/images/about.png"));
    aboutQtAction->setStatusTip(tr("About Qix"));
    connect(aboutQtAction, SIGNAL(triggered()), qApp, SLOT(aboutQt()));

    // Exit
    quitAction = new QAction(tr("Exit"), this);
    quitAction->setIcon(QIcon(":/images/quit.png"));
    quitAction->setShortcut(tr("Ctrl+Q"));
    quitAction->setStatusTip(tr("Quit"));
    connect(quitAction, SIGNAL(triggered()), this, SLOT(close()));//quit()));

    // Show High Scores dialog box
    highScoresAction = new QAction(tr("High Scores"), this);
    highScoresAction->setStatusTip(tr("Show high scores"));
    connect(highScoresAction, SIGNAL(triggered()), this, SLOT(showHighScores()));

    timeAction = new QAction(tr("0"), this);
    timeAction->setStatusTip(tr("Time"));
}

/*!
  Initialize menus
*/
void QixWindow::createMenus() {
    // Game menu
    gameMenu = menuBar()->addMenu(tr("&File"));
    gameMenu->addAction(newGameAction);
    gameMenu->addSeparator();
    gameMenu->addAction(highScoresAction);
    gameMenu->addSeparator();
    gameMenu->addAction(quitAction);

    // Help menu
    helpMenu = menuBar()->addMenu(tr("&Help"));
    helpMenu->addAction(aboutAction);
    helpMenu->addSeparator();
    helpMenu->addAction(aboutQtAction);
}

/*!
  Creates a new game in response to the newGame action being triggered
*/
void QixWindow::newGame() {
    // Prompt first
    if (!start_time || lost || QMessageBox::warning(this, tr("Qix"),
                                                    tr("Really start a new game?"),
                                                    QMessageBox::Yes | QMessageBox::Default,
                                                    QMessageBox::No, QMessageBox::Cancel | QMessageBox::Escape)==QMessageBox::Yes) {
        lost = false;
        qixwid->startNewGame();
        start_time = 0;
    }
}

/*!
  Display the about box
*/
void QixWindow::about() {
    QMessageBox::about(this, tr("About Qix"),
                       tr("<h2>Qix</h2>"
                          "<p>Copyright &copy; 2010 Jeremiah LaRocco</p>"
                          "<p>Qix clone!</p>"));
}

/*!
  Prompt before closing
*/
void QixWindow::closeEvent(QCloseEvent *event) {
    // if (QMessageBox::warning(this, tr("Qix"),
    //                          tr("Really quit?"),
    //                          QMessageBox::Yes | QMessageBox::Default,
    //                          QMessageBox::No, QMessageBox::Cancel | QMessageBox::Escape)==QMessageBox::Yes) {
    //     // delete qmf;
        event->accept();
    // } else {
    //     event->ignore();
    // }
}

/*!
  Triggered when the user has won the game
*/
void QixWindow::winGame() {
}

/*!
  Triggered when the user has lost the game
*/
void QixWindow::loseGame() {
    lost = true;
    theTimer->stop();
}

void QixWindow::readHighScores() {
    qset->sync();
    // best_times[DIF_EASY] = qset->value("easy_time", 1000).toInt();
    // best_times[DIF_MEDM] = qset->value("medm_time", 10000).toInt();
    // best_times[DIF_HARD] = qset->value("hard_time", 10000).toInt();

    // best_names[DIF_EASY] = qset->value("easy_name", tr("Anon")).toString();
    // best_names[DIF_MEDM] = qset->value("medm_name", tr("Anon")).toString();
    // best_names[DIF_HARD] = qset->value("hard_name", tr("Anon")).toString();
  
    // best_dates[DIF_EASY] = qset->value("easy_date", QDateTime(QDate(2000, 1,1))).toDateTime();
    // best_dates[DIF_MEDM] = qset->value("medm_date", QDateTime(QDate(2000, 1,1))).toDateTime();
    // best_dates[DIF_HARD] = qset->value("hard_date", QDateTime(QDate(2000, 1,1))).toDateTime();
}


/*!
  Displays the high scores dialog box.
*/
void QixWindow::showHighScores() {

    readHighScores();
    // QMessageBox::information(this, tr("Qix"),
    //                          QString(tr("Easy   : %1 : %2 : %3\n"
    //                                     "Medium : %4 : %5 : %6\n"
    //                                     "Hard   : %7 : %8 : %9\n"))
    //                          .arg(best_times[DIF_EASY]).arg(best_names[DIF_EASY]).arg(best_dates[DIF_EASY].toString())
    //                          .arg(best_times[DIF_MEDM]).arg(best_names[DIF_MEDM]).arg(best_dates[DIF_MEDM].toString())
    //                          .arg(best_times[DIF_HARD]).arg(best_names[DIF_HARD]).arg(best_dates[DIF_HARD].toString()),
    //                          QMessageBox::Ok | QMessageBox::Default);
}

/*!
  Set the game start time.
*/
void QixWindow::startTimer() {
    start_time = std::time(0);
    theTimer->start(1000);
}

/*!
  Update the timer
*/
void QixWindow::update() {
    // if (start_time) {
    //     std::time_t end_time = std::time(0);
    //     double elapsed = difftime(end_time, start_time);
    
    //     // timeAction->setText(tr("%1").arg(elapsed));
    // } else {
    //     timeAction->setText(tr("0"));
    // }
}
