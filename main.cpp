//
//  main.cpp
//  Assignment #19 for Interest Calculator
//
//  Created by rayuan lee on 12/6/16.
//  Copyright © 2016 rayuan lee. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

/// interest calculator class
class InterestCalculator
{
protected:
    /// data members
    double savings;
    double rate;
    double years;
public:
    /// constructors
    InterestCalculator(){}
    InterestCalculator(double savings, double rate, double years)
    {
        this->rate = rate;
        this->savings = savings;
        this->years = years;
    }
    
    /// getters
    double getSavings()
    {
        return savings;
    }
    double getRate()
    {
        return rate;
    }
    double getYears()
    {
        return years;
    }
    
    /// setters
    void setSavings(double savings)
    {
        this->savings = savings;
    }
    void setRate(double rate)
    {
        this->rate = rate;
    }
    void setYears(double years )
    {
        this->years = years;
    }
};

/// This is simple interest calculator to calculate simple interst
class SimpleInterestCalculator : public InterestCalculator
{
public:
    SimpleInterestCalculator(){};
    SimpleInterestCalculator(double savings, double rate, double years) : InterestCalculator(savings,rate,years) {}
    
    /// method to return simple interest
    double getInterest()
    {
        return (savings * rate * years)/100.0;
    }
};

/// s compound interest calculator to calculate compound interst
class CompoundInterestCalculator : public InterestCalculator
{
private:
    int compounded;
public:
    CompoundInterestCalculator(){};
    CompoundInterestCalculator(double savings, double rate, double years, int compounded) : InterestCalculator(savings,rate,years)
    {
        this->compounded = compounded;
    }
    
    int getCompounded()
    {
        return compounded;
    }
    
    void setCompounded(int compounded)
    {
        this->compounded = compounded;
    }
    
    /// method to return compound interest
    double getInterest()
    {
        return (savings * ( pow( 1+rate/(100.0 * years),compounded * years ) - 1 ));
    }
};

int main()
{
    cout << "**************************************" << endl;
    cout << "* Main Menu: *" << endl;
    cout << "* Enter # to run program or Quit *" << endl;
    cout << "* 1) Yearly Interest Calculator *" << endl;
    cout << "* 2) Compound Interest Calculator *" << endl;
    cout << "* 3) Quit *" << endl;
    cout << "**************************************" << endl;
    
    int choice;
    do
    {
        cout << "Enter choice : ";
        cin >> choice;
    }
    while( choice < 1 || choice > 3);
    
    if( choice == 3 )
        return 0;
    
    cout << "Please enter $ in savings." << endl;
    double amount;
    cin >> amount;
    
    if( amount < 0 )
    {
        cout << "Terminating program!";
        return 1;
    }
    
    
    if( choice == 1 )
    {
        cout << "Please enter number of years" << endl;
        double years;
        cin >> years;
        
        cout << "Please enter interest rate" << endl;
        double rate;
        cin >> rate;
        
        SimpleInterestCalculator s(amount,rate,years);
        
        for( int i=1; i<=3; i++)
        {
            double interest = s.getInterest();
            s.setSavings( s.getSavings() + interest );
            
            cout << "Year " << i << " = $" << s.getSavings() << endl;
        }
    }
    else
    {
        cout << "Please enter number of years" << endl;
        double years;
        cin >> years;
        
        cout << "Please enter interest rate" << endl;
        double rate;
        cin >> rate;
        
        cout << "Number of times compounded" << endl;
        int  comp;
        cin >> comp;
        
        CompoundInterestCalculator c(amount,rate,years,comp);
        
        
        for( int i=1; i<=3; i++)
        {
            double interest = c.getInterest();
            c.setSavings( c.getSavings() + interest );
            
            cout << "Principle Compounded " << i << " = $" << c.getSavings() << endl;
        }
        cout << endl;
    }
    
    return 0;
}
