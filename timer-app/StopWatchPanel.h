#ifndef STOPWATCHPANEL_H
#define STOPWATCHPANEL_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>

class StopWatchPanel : public QWidget {
    Q_OBJECT

public:
    QLabel* stopWatchLabel;
    QPushButton* startButton;
    QPushButton* resetButton;
    QPushButton* splitButton;
    QPushButton* showButton;

    explicit StopWatchPanel(QWidget* parent = nullptr);

    void setDisplay(const QString& display);
    void setCommandText(const QString& text);

    void disableShowButton();
    void enableShowButton();
    void disableSplitButton();
    void enableSplitButton();

    void setDisplayBackground(const QColor& color);

    QString getCommandText() const {
        return startButton->text();
    }

    QPushButton* getStartButton() const { return startButton; }
    QPushButton* getResetButton() const { return resetButton; }
    QPushButton* getSplitButton() const { return splitButton; }
    QPushButton* getShowButton() const { return showButton; }



signals:
    void startClicked();
    void resetClicked();
    void splitClicked();
    void showClicked();

private:

};

#endif // STOPWATCHPANEL_H
