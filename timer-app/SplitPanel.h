#ifndef SPLITPANEL_H
#define SPLITPANEL_H

#include <QWidget>
#include <QListWidget>
#include <QPushButton>

class SplitPanel : public QWidget {
    Q_OBJECT

public:
    explicit SplitPanel(QWidget* parent = nullptr);

    void add(const QString& time);
    void deleteAll();

    QPushButton* getDeleteAllButton() const { return deleteAllButton; }


signals:
    void deleteAllClicked();

private:
    QListWidget* splits;
    QPushButton* deleteAllButton;
};

#endif // SPLITPANEL_H
