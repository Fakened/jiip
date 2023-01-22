#ifndef EDITVEHICLE_H
#define EDITVEHICLE_H
#include <QMainWindow>

namespace Ui
{
    class editVehicle;
}

class editVehicle: public QMainWindow
{
    Q_OBJECT

    public:
        explicit editVehicle(QWidget *parent = nullptr);
    ~editVehicle();

    private slots:
        void on_back_b_clicked();

    void setTable();

    void on_remove_b_clicked();

    void on_edit_b_clicked();

    void editOther(int id);

    void editCar(int id);

    void editScooter(int id);

    void editBike(int id);

    void editMotorbike(int id);

    bool isLeapYer(int year);

    private:
        Ui::editVehicle * ui;
};


#endif	// EDITVEHICLE_H
