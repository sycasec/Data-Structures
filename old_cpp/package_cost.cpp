#include <iostream>
#include <iomanip>

class package
{
protected:
    double weight, cost_per_kilo;

public:

    package()
    {
        this->weight = 0;
        this->cost_per_kilo = 0;
    }

    package(double& weight, double& cost_per_kilo){
        this->weight = weight;
        this->cost_per_kilo = cost_per_kilo;
    }

    double calculate_cost(){
        return this-> weight * this->cost_per_kilo;
    }

};

class two_day_package : public package
{
private:
    double flat_fee;

public:
    two_day_package(double weight, double cost_per_kilo, double fee)
    
    {
        this->weight = weight;
        this->cost_per_kilo = cost_per_kilo;
    }

    double calculate_cost(){
        return package::calculate_cost() + this->flat_fee;
    }
};

class overnight_package : public package{
private:
    double additional_fee;

public:
    overnight_package(double weight, double cost_per_kilo, double fee)
    :additional_fee(fee)
    {
        this->weight = weight;
        this->cost_per_kilo = cost_per_kilo;
    }
    
    double calculate_cost(){
        return package::calculate_cost() + (this->weight * this->additional_fee);
    }

};

int main()
{
    double weight, cost_per_kilo, flat_fee, additional_fee;
    double package_cost, two_day_package_cost, overnight_package_cost;

    std::cin >> weight >> cost_per_kilo >> flat_fee >> additional_fee;

    package pack(weight, cost_per_kilo);
    two_day_package t_pack(weight, cost_per_kilo, flat_fee);
    overnight_package o_pack(weight, cost_per_kilo, additional_fee);

    std::cout << std::setprecision(2) << std::fixed;
    std::cout << pack.calculate_cost()<< " " << t_pack.calculate_cost() << " " << o_pack.calculate_cost() << std::endl;
    
    return 0;
}