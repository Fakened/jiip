#ifndef RETURNWINDOW_H
#define RETURNWINDOW_H
#include <QMainWindow>

namespace Ui
{
    class returnWindow;
}

class returnWindow: public QMainWindow
{
    Q_OBJECT

    public:
        explicit returnWindow(QWidget *parent = nullptr);
    ~returnWindow();

    private slots:
        void on_back_b_clicked();

    void on_return_b_clicked();

    void setTable();

    private:
        Ui::returnWindow * ui;
};


#endif	// RETURNWINDOW_H
