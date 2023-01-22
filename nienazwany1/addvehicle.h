#ifndef ADDVEHICLE_H
#define ADDVEHICLE_H
#include <QDialog>

namespace Ui
{
    class addVehicle;
}

class addVehicle: public QDialog
{
    Q_OBJECT

    public:
        explicit addVehicle(QWidget *parent = nullptr);
    ~addVehicle();

    private slots:
        void on_BackButton_b_clicked();

    void on_addCar_b_clicked();

    void on_addScooter_b_clicked();

    void on_addMotorbike_b_clicked();

    void on_addOther_b_clicked();

    void on_addBike_b_clicked();

    private:
        Ui::addVehicle * ui;
};


#endif	// ADDVEHICLE_H
