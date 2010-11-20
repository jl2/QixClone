#ifndef QIXWINDOW_H
#define QIXWINDOW_H

#include <QMainWindow>
#include <QDateTime>
#include <ctime>

#include "qixwidget.h"

class QAction;
class QLabel;
class QIcon;
class QMenu;
class QCloseEvent;
class QSettings;
class QTimer;

class QixWindow : public QMainWindow {
    Q_OBJECT;

public:
    QixWindow();
    ~QixWindow();

private slots:
    void newGame();
    void about();
    void winGame();
    void loseGame();
    void showHighScores();

    void readHighScores();
    void startTimer();

    void update();
  
protected:
    // Initialization functions
    void createActions();
    void createMenus();
    void closeEvent(QCloseEvent *event);

private:
    QAction *newGameAction;
    QAction *aboutAction;
    QAction *aboutQtAction;
    QAction *quitAction;
  
    QAction *highScoresAction;

    QAction *timeAction;
  
    QMenu *gameMenu;
    QMenu *optionsMenu;
    QMenu *helpMenu;
    QSettings *qset;

    std::time_t start_time;

    // This could be implemented a little better
    // int best_times[NUM_DIFFICULTIES];
    // QString best_names[NUM_DIFFICULTIES];
    // QDateTime best_dates[NUM_DIFFICULTIES];
  
    // True = game lost
    bool lost;

    QTimer *theTimer;

    QixWidget *qixwid;
};

#endif
