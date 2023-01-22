#ifndef RENTVEHICLE_H
#define RENTVEHICLE_H
#include <QMainWindow>
#include <QDialog>

namespace Ui
{
    class rentVehicle;
}

class rentVehicle: public QMainWindow
{
    Q_OBJECT

    public:
        explicit rentVehicle(QWidget *parent = nullptr);
    ~rentVehicle();

    private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void setTable();

    private:
        Ui::rentVehicle * ui;
};


#endif	// RENTVEHICLE_H
