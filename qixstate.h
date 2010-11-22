#ifndef QIX_STATE_H
#define QIX_STATE_H

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
