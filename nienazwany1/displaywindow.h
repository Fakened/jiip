#ifndef DISPLAYWINDOW_H
#define DISPLAYWINDOW_H
#include <QMainWindow>

namespace Ui
{
    class displaywindow;
}

class displaywindow: public QMainWindow
{
    Q_OBJECT

    public:
        explicit displaywindow(QWidget *parent = nullptr);
    ~displaywindow();

    private slots:

        void on_back_b_clicked();

    void on_all_b_clicked();

    void setTable();

    void on_others_b_clicked();

    void on_motorbikes_b_clicked();

    void on_scooters_b_clicked();

    void on_bikes_b_clicked();

    void on_cars_b_clicked();

    private:
        Ui::displaywindow * ui;
};


#endif	// DISPLAYWINDOW_H
