//
// Created by User on 29.12.1022.
//
#include "vehicle.h"
#include <utility>

Vehicle::Vehicle(int id, string name, float price, bool rent, string date, string who): id(id), name(std::move(name)), price(price), rent(rent), date(std::move(date)), who(std::move(who))
{
    if (!this)
    {
        throw runtime_error("Error: Unable to create Vehicle object");
    }
}

string Vehicle::getVType() const
{
    return vType;
}

void Vehicle::setDay()
{
    if (date == "-")
    {
        day = 0;
    }
    else
    {
        tm past;
        try
        {
            int mday, month, year;
            regex date_regex("(\\d{1,2})-(\\d{1,2})-(\\d{4})");
            smatch match;
            if (regex_match(date, match, date_regex))
            {
                mday = stoi(match[1]);
                month = stoi(match[2]);
                year = stoi(match[3]);
            }
            else
            {
                throw exception("Failed to parse date");
            }

            past.tm_year = year - 1900;
            past.tm_mon = month - 1;
            past.tm_mday = mday;
            past.tm_hour = 0;
            past.tm_min = 0;
            past.tm_sec = 0;
            past.tm_isdst = -1;
            time_t pTime = mktime(&past);
            time_t nTime = time(nullptr);
            double diff = difftime(nTime, pTime) / (60 * 60 *24);
            day = int(diff);
        }

        catch (exception & e)
        {
            cout << e.what() << endl;
        }
    }
}

int Vehicle::getDay() const
{
    return day;
}

void Vehicle::doCost()
{
    cost = price * day;
}

float Vehicle::getCost() const
{
    return cost;
}

Vehicle::Vehicle()
{
    name = "default";
    id = -1;
    price = 0;
    date = "1990-01-01";
    who = "nobody";
}

Vehicle::~Vehicle() = default;

const string &Vehicle::getName() const
{
    return name;
}

float Vehicle::getPrice() const
{
    return price;
}

bool Vehicle::isRent() const
{
    return rent;
}

const string &Vehicle::getDate() const
{
    return date;
}

const string &Vehicle::getWho() const
{
    return who;
}

void Vehicle::setName(const string &name)
{
    Vehicle::name = name;
}

void Vehicle::setPrice(float price)
{
    Vehicle::price = price;
}

void Vehicle::setRent(bool rent)
{
    Vehicle::rent = rent;
}

void Vehicle::setDate(const string &date)
{
    Vehicle::date = date;
}

void Vehicle::setWho(const string &who)
{
    Vehicle::who = who;
}

bool Vehicle::is(const string &type)
{
    if (type == vType)
    {
        return true;
    }

    return false;
}

void Vehicle::saveToFile(ofstream &fd, char vt)
{
    if (!fd.is_open())
    {
        throw runtime_error("Error: Unable to open file");
        return;
    }

    if (fd.good())
    {
        size_t hold;
        fd.write((char*) &vt, sizeof(const char));
        fd.write((char*) &id, sizeof(int));
        hold = name.size();
        fd.write((char*) &hold, sizeof(hold));
        fd.write((char*) &name[0], hold);
        fd.write((char*) &price, sizeof(price));
        fd.write((char*) &rent, sizeof(rent));
        hold = date.size();
        fd.write((char*) &hold, sizeof(hold));
        fd.write((char*) &date[0], hold);
        hold = who.size();
        fd.write((char*) &hold, sizeof(hold));
        fd.write((char*) &who[0], hold);
    }
}

void Vehicle::readFromFile(ifstream & fd)
{
    if (!fd.is_open())
    {
        throw runtime_error("Error: Unable to open file");
        return;
    }

    if (fd.good())
    {
        size_t hold;
        fd.read((char*) &id, sizeof(int));
        fd.read((char*) &hold, sizeof(hold));
        name.resize(hold);
        fd.read((char*) &name[0], hold);
        fd.read((char*) &price, sizeof(price));
        fd.read((char*) &rent, sizeof(rent));
        fd.read((char*) &hold, sizeof(hold));
        date.resize(hold);
        fd.read((char*) &date[0], hold);
        fd.read((char*) &hold, sizeof(hold));
        who.resize(hold);
        fd.read((char*) &who[0], hold);
    }
}

int Vehicle::getId() const
{
    return id;
}

void Vehicle::setWho(const Person &p)
{
    who = p.name;
}

ostream &operator<<(ostream &os, const Vehicle &vehicle)
{
    os << vehicle.id << setw(20) << vehicle.name << setw(10) << vehicle.price << setw(10) << (vehicle.rent ? "true" : "false") << setw(15) << vehicle.date << setw(20) << vehicle.who;
    return os;
}

void Vehicle::print(const Vehicle &vehicle)
{
    cout << vehicle << endl;
}

bool Vehicle::is()
{
    return true;
}
