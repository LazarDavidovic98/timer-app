#ifndef TIMERPANEL_H
#define TIMERPANEL_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>

class TimerPanel : public QWidget {
    Q_OBJECT

public:

    QLabel* timerLabel;
    QPushButton* startButton;
    QPushButton* resetButton;
    QPushButton* setButton;

    explicit TimerPanel(QWidget* parent = nullptr);

    void setDisplay(const QString& display);
    void setCommandText(const QString& text);
    QString getCommandText() const {
        return startButton->text();
    }

    QPushButton* getStartButton() const { return startButton; }
    QPushButton* getResetButton() const { return resetButton; }
    QPushButton* getSetButton() const { return setButton; }



signals:
    void startClicked();
    void resetClicked();
    void setClicked();

private:

};

#endif // TIMERPANEL_H


