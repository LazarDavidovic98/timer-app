#ifndef ALARMPANEL_H
#define ALARMPANEL_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>

class AlarmPanel : public QWidget {
    Q_OBJECT

public:

    QLabel* timeLabel;
    QLabel* alarmLabel;
    QPushButton* enableButton;
    QPushButton* setButton;
    QPushButton* startButton;

    explicit AlarmPanel(QWidget* parent = nullptr);

    void setTimeDisplay(const QString& display);
    void setAlarmDisplay(const QString& display);
    void setCommandText(const QString& command);
    void setDisabledStyle();
    void setEnabledStyle();
    QString getCommandText() const {
        return startButton->text();
    }
    QPushButton* getEnableButton() const { return enableButton; }
    QPushButton* getSetButton() const { return setButton; }




signals:
    void enableClicked();
    void setClicked();

private:

};

#endif // ALARMPANEL_H
